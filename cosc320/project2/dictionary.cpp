/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 2
 *dictionary.cpp
 *Mar 30, 2020
 */

#include "dictionary.h"

#define RESET "\033[00m"
#define RED "\033[31m"
#define GREEN "\033[32m"

Dictionary::Dictionary()
{
  size = 10000;
  wordcount = 0;
  usedB = 0;

  num_sug1 = num_sug2 = 0;
  isOkay = false;

  time_load = time_find1 = time_find2 = 0;

  Table = new List<std::string>*[size];
  for(int i = 0; i < size; i++)
    Table[i] = new List<std::string>; 
  read(); //start insertion from text file
  startinfo();
}

//private function
void Dictionary::read()
{
  std::ifstream infile;
  infile.open("english.txt");

  stpw.startTime();

  std::string wrd;
  while(!infile.eof())
  {
    infile >> wrd;

    char ch = wrd[0];  
    if(ch >= 'A' && ch <= 'Z')  //un cap
    {
      ch += 32;
      wrd[0] = ch;
    }

    hash_insert(wrd);
    wordcount++;
  }
  infile.close();

  time_load = stpw.endTime();
}

//private function
void Dictionary::countBucket()
{
  int temp, nodeCount = 0, check = 0;
  for(int i = 0; i < size; i++)
  {
    temp = Table[i]->getsize();
    nodeCount += temp;

    if(check == 0 && temp != 0)
    {
      maxB = minB = temp;
      check++;
    }
    if(temp != 0)
      usedB++;
    if(temp < minB && temp != 0)
      minB = temp;
    if(temp > maxB)
      maxB = temp;
  }
  avgN = nodeCount/usedB;
}

//private function
void Dictionary::startinfo()
{
  countBucket();
  std::cout << "Total words = " << wordcount;
  std::cout << "\nBiggest bucket size = " << maxB;
  std::cout << "\nSmallest bucket size = " << minB;
  std::cout << "\nTotal number of buckets = " << size;
  std::cout << "\nNumber of used buckets  = " << usedB;
  std::cout << "\nAverage number of nodes in each bucket = " << avgN << std::endl;
  std::cout << "Total time taken = " << time_load << std::endl;
}

Dictionary::~Dictionary()
{
 for(int i = 0; i < size; i++)
   delete Table[i];
 delete [] Table;
}

size_t Dictionary::hash(std::string x) 
{
  size_t h = 0, temp, ONE = 1;
  for(size_t i = 0; i < x.length(); i++)
  {
    temp = x[i]*(i+1);
    h += temp * (ONE<<i);
  }
  size_t s = size;
  return h%s;
}

void Dictionary::hash_insert(std::string x)
{
  size_t index = hash(x);
  Table[index]->insert(x);
}

void Dictionary::hash_search(std::string x)
{
  size_t index = hash(x);
  std::cout << "[" << x;
  if(Table[index]->find(x))
    std::cout << "] is in the database.\n";
  else std::cout << "] is not in the database!\n";
}

void Dictionary::hash_delete(std::string x)
{
  size_t index = hash(x);
  std::cout << "[" << x;
  if(Table[index]->find(x))
  {
    Table[index]->remove(x);
    wordcount--;
    std::cout << "] has been removed from the database.\n";
  }
  else std::cout << "] is not in the database!\n";
}

//private function
bool Dictionary::isPresent(std::string x)
{
  size_t index = hash(x);
  if(Table[index]->find(x))
    return true;  //in the database
  else return false;  //not in database
}

void Dictionary::error_check(std::string x)
{
  x += " "; //add empty space so last char of word is included
  std::string temp = "";
  char ch;
  char space = ' ';
  for(int i = 0; i < x.length(); i++)
  {
    ch = x[i];
    if(ch == space)
    {
      //undo capitalization
      ch = temp[0];
      if(ch >= 'A' && ch <= 'Z')
      {
        ch += 32;
        temp[0] = ch;
      }

      if(!isPresent(temp))
        mylist.insert(temp);

      temp = "";
      i++; //skip the space
    }

    temp += x[i];
  }

  std::cout << std::endl; //formating
  num_errors = mylist.getsize();

  //if no errors found
  if(num_errors == 0)
  { 
    std::cout << "No corrections are available.\n";
    return;
  }
  
  //print errors found
  for(int i = 0; i < num_errors; i++)
  {
    std::cout << "[" << mylist.iter->data << "] is misspelled! Below are the words within one edit distance\n";
    mylist.iter = mylist.iter->next;
  }
  mylist.reset_iter();
  isOkay = true;  //suggestions1 can now be called in main
}


void Dictionary::suggestions1()
{
  std::cout << "-------------------------------------------------------------\n\n";

  isOkay = false; //when true suggestions2 can be called in main

  //temp list of suggestions for one distance
  sugg = new List<std::string>*[num_errors];
  for(int i = 0; i < num_errors; i++)
    sugg[i] = new List<std::string>;

  stpw.startTime(); //start timer

  //loop for errors
  for(int i = 0; i < num_errors; i++)
  {
    std::string temp = mylist.iter->data;
    std::string temp2 = temp;
    std::string temp3 = "";
    std::string prev = "";  //used to prevent duplicated suggestion, partially works

    //loop through each characters
    for(int j = 0; j < temp.length(); j++)
    {
      //loop changing characters from a~z
      for(char k = char(33); k <= 'z'; k++)
      {
        temp[j] = k;
        if(isPresent(temp) && temp != prev)
        { 
          isOkay = true;
          sugg[i]->insert(temp);
          list1.insert(temp); //list for 1 edit suggestion
          prev = temp;
        }
      }
      temp = temp2; //restore the word back
    }

    //loop with one less character
    for(int j = 0; j < temp.length(); j++)
    {
      for(int k = 0; k < temp.length(); k++)
      {
        if(k != j)  //j is the position of the character thats excluded
          temp3 += temp[k];
      }
      if(isPresent(temp3) && temp3 != prev)
      { 
        isOkay = true;
        sugg[i]->insert(temp3);
        list1.insert(temp3);
        prev = temp3;
     }
      temp3 = ""; //reset temp3
    }

    //loop with one extra character
    for(int j = 0; j < temp2.length()+1; j++)
    {
      //looping character from a~z
      for(char k = char(33); k <= 'z'; k++)
      {
        temp3 += k;
        temp.insert(j,temp3);
        //will insert in from, in between and behind depend on j's value
        if(isPresent(temp) && temp != prev)
        { 
          isOkay = true;
          sugg[i]->insert(temp);  
          list1.insert(temp);
          prev = temp;
        }
        temp = temp2;
        temp3 = "";
      }
      temp = temp2; //restore the word back
    }

    mylist.iter = mylist.iter->next;	//next word in the list
  }//end of 1rst loop

  time_find1 = stpw.endTime();  //stop timer

  mylist.reset_iter();

  //print result
  for(int i = 0; i < num_errors; i++)
  {
      //if no suggestion
      if(sugg[i]->getsize() == 0)
      {	
        std::cout << "Suggestions for " << RED << mylist.iter->data << RESET;
        std::cout << ": no corrections available\n";
      }
      else
      {
        std::cout << "Suggestions for " << RED << mylist.iter->data << RESET << ": ";
      	for(int l = 0; l < sugg[i]->getsize(); l++)
      	{
          std::cout << "[" << GREEN << sugg[i]->iter->data << RESET << "] ";
          sugg[i]->iter = sugg[i]->iter->next;
      	}
        sugg[i]->reset_iter();
      }
      mylist.iter = mylist.iter->next;
      std::cout << "\n\n";
  }

  num_sug1 = list1.getsize();

  //delete list
  for(int i = 0; i < num_errors; i++)
      delete sugg[i];
  delete [] sugg;
}

void Dictionary::suggestions2()
{
  std::cout << "\nThe following are within two edit distances for all words\n";
  std::cout << "-------------------------------------------------------------\n\n";

  //temp list of suggestions for two distance
  sugg = new List<std::string>*[num_sug1];
  for(int i = 0; i < num_sug1; i++)
    sugg[i] = new List<std::string>;

  stpw.startTime();

  //loop for each prev suggestions
  for(int i = 0; i < num_sug1; i++)
  {
    std::string temp = list1.iter->data;
    std::string temp2 = temp;
    std::string temp3 = "";
    std::string prev = "";

    //loop through each characters
    for(int j = 0; j < temp.length(); j++)
    {
      //loop changing characters from a~z
      for(char k = char(33); k <= 'z'; k++)
      {
        temp[j] = k;
        if(isPresent(temp) && temp != prev && temp != temp2)
        { 
          sugg[i]->insert(temp);
          list2.insert(temp); //list for 2 edit distance
          prev = temp;
        }
      }
      temp = temp2; //restore the word back
    }

    //loop with one less character
    for(int j = 0; j < temp.length(); j++)
    {
      for(int k = 0; k < temp.length(); k++)
      {
        if(k != j)  //j is the position of the character thats excluded
          temp3 += temp[k];
      }
      if(isPresent(temp3) && temp3 != prev && temp3 != temp2)
      { 
        sugg[i]->insert(temp3);
        list2.insert(temp3);
        prev = temp3;
     }
      temp3 = ""; //reset temp3
    }

    //loop with one extra character
    for(int j = 0; j < temp2.length()+1; j++)
    {
      //looping character from a~z
      for(char k = char(33); k <= 'z'; k++)
      {
        temp3 += k;
        temp.insert(j,temp3);
        if(isPresent(temp) && temp != prev && temp != temp2)
        { 
          sugg[i]->insert(temp);  
          list2.insert(temp);
          prev = temp;
        }
        temp = temp2;
        temp3 = "";
      }
      temp = temp2; //restore the word back
    }

    list1.iter = list1.iter->next;	//next word in the list
  }//end of 1rst loop

  time_find2 = stpw.endTime();

  list1.reset_iter();

  //print result
  for(int i = 0; i < num_sug1; i++)
  {
      //if no suggestion
      if(sugg[i]->getsize() == 0)
      {	
        std::cout << "Suggestions for " << GREEN << list1.iter->data << RESET;
        std::cout << ": not available\n";
      }
      else
      {
        std::cout << "Suggestions for " << GREEN << list1.iter->data  << RESET << ": ";
      	for(int l = 0; l < sugg[i]->getsize(); l++)
      	{
          std::cout << "[" << sugg[i]->iter->data << "] ";
          sugg[i]->iter = sugg[i]->iter->next;
      	}
        sugg[i]->reset_iter();
      }
      list1.iter = list1.iter->next;
      std::cout << "\n\n";
  }
  std::cout << std::endl; //formating

  num_sug2 = list2.getsize();

  //delete list
  for(int i = 0; i < num_sug1; i++)
      delete sugg[i];
  delete [] sugg;

  isOkay = false; //prevents suggestions functions from being called
}

void Dictionary::summary()
{
  std::cout << "Number of misspelled words = " << num_errors << std::endl;
  std::cout << "Number of suggestions " << num_sug1+num_sug2 << std::endl;
  std::cout << "Time required to find suggestions = " << time_find1+time_find2  << std::endl;
  std::cout << std::endl;
}