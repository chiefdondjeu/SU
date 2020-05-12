/*
 *Florent Dondjeu Tschoufack
 *Cosc 320 - 002
 *Project 2
 *main.cpp
 *Mar 30, 2020
 */

#include "dictionary.h"

#include <iostream>
#include <string>

int main()
{
  std::string bar;
  bar = "-------------------------------------------------------------";

  std::cout << "Welcome to Spell Checker!\n";
  std::cout << bar << std::endl;
  std::cout << "Loading the database...\n";
  std::cout << bar << "\n\n";

  Dictionary A;
  std::cout << bar << "\n";

  std::string text;
  std::cout << "Please enter some text:\n" << bar << "\n\n";
  std::getline(std::cin, text);
  A.error_check(text);
 
  if(A.isOkay == true)
    A.suggestions1();

  if(A.isOkay == true)
    A.suggestions2();

  std::cout << bar << "\nSummary\n" << bar << std::endl;
  A.summary();

  return 0;
}