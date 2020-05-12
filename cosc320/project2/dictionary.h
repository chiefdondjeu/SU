/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 2
 *Dictionary.h
 *Mar 30, 2020
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "list.h"
#include "timer.h"

#include <iostream>
#include <string>
#include <fstream>

class Dictionary
{
  private:

    int size; //numbers of buckets
    List<std::string>** Table;
    int wordcount; //total number of words;
    int maxB, minB, usedB; //buckets stats
    int avgN;   //nodes stats

    int num_errors, num_sug1, num_sug2;

    Timer stpw; //object to time functions
    float time_load, time_find1, time_find2;

    List<std::string> mylist; //list of misspell words detected
    List<std::string> list1;  //list of 1 edit suggestions
    List<std::string> list2; //list of 2 edit suggestions

    //temp list of suggestions
    //helps us difer originated suggestion from words
    List<std::string>** sugg;

    //reading fucntion
    //imports the words from text file into table
    void read();

    //gives stats info od the table
    void countBucket();

    //info function
    //output the necessary information at the start of the program
    void startinfo();

    //search function
    //returns true if word is in database
    bool isPresent(std::string);

  public:

    bool isOkay; //if true call suggestions functions, used in main

    //default constructor
    //initialzes variables above and allocate memory
    //also calls read() and startinfo()
    Dictionary();

    //deconstructor
    //frees allocated memory
    ~Dictionary();
    
    //hash function
    //returns an index within the table size 
    size_t hash(std::string);

    //insert function
    //inserts an element into the table
    void hash_insert(std::string);

    //search function
    //searches for an element in the table
    void hash_search(std::string);

    //delete function
    //deletes an element in the table
    void hash_delete(std::string);

    //reads in given string from main and detect errors if any
    void error_check(std::string);

    //1 edit distance
    //finds suggestions for mylist and store in list1
    void suggestions1();

    //2 edit distance
    //finds suggestions for list1 and store in list2
    void suggestions2();

    //prints stats about the text
    void summary();
};

#endif