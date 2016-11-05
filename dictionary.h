/* Dr. Augustine
 dictionary.h
 Last Updated:02/14/2016
 Status: Compiles and all requirements met*/

 /*
 Name:			Stefani Moore
 Last Date Modified:	10-03-2016
 Assignment:		HW6
 */

 //******************************************************
 //dictionary.h File - Provided by Instructor
 //
 //dictionary class declaration
 //
 //******************************************************

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <list>
#include <iostream>
#include <fstream> //included for file stream
#include "DictEntry.h"

using namespace std;

class dictionary
{
public:
    //typedef string wordType;
    dictionary();
    
	/*Read in a list of words from the dictionary file*/
	list<DictEntry> wordFile(string fileName);

    /*Searches the list starting at the front of the list and moving to the back
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    int searchForward(list<DictEntry> &wordList,wordType &findString);
    
    /*Searches the list starting at the back of the list and moving to the front
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    int searchBackward(list<DictEntry> &wordList,wordType &findString);
    
    /*Prints the list of words in reverse alphabetic order to a file*/
    void revPrintList(ostream& output, list<DictEntry> &wordList);

	/*Prints the list of words to the screen*/
	void displayList(list < DictEntry> &wordList);
    
};

/*******************************/



#endif /* dictionary_h */
