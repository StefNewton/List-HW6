
/*
Name:					Stefani Moore
Last Date Modified:			10-03-2016
Assignment:				HW6
*/

//*******************************************************************
//dictionary.cpp
//
//Contains dictionary class implentations 
//
//*******************************************************************

//header file
#include "dictionary.h"



/*****************************************************************************
*								CONSTRUCTOR
******************************************************************************/

dictionary::dictionary()
{}

/*****************************************************************************
*							WORD FILE FUNCTION
*
* Purpose: Reads the contents of a .txt file and adds each element to the end 
*		   of a list with push_back() member function
* Input: string variable that = a file name in the MooreHW6 directory
* Returns: A list of the words from the given fileName
* Requirements: The .txt file elements must be space delimited
*
******************************************************************************/

list<DictEntry> dictionary::wordFile(string fileName)
{
	string dataFile = fileName;
	ifstream readData(dataFile); //open fileName to read from the file

	list<DictEntry> myList; //List of DictEntry types
	wordType wordT;

	if (readData) //If file is opened successfully add contents to a list
	{
		while (readData >> wordT) //continue loop until there are no more words to read in the file
		{
			DictEntry* newEntry = new DictEntry; //allocate memory for a dictionary entry
			newEntry->setWord(wordT);	//set the newEntry to the wordType variable wordT value

			myList.push_back(*newEntry); //dereference the newEntry and add to the end of myList
		}
	}
	else //If file does not open correctly, display fileName and error message
		cout << "Error opening file: " << fileName << endl;

	readData.close(); //close file
	return myList; //return list of words from the given file
}

/*****************************************************************************
*						SEARCH FORWARD FUNCTION
*
* Purpose: Performs a linear search forward through the sorted list of words 
*		   that were given in dictionary.txt
* Inputs: The list of words from dictionary.txt and a wordType (string)
* Returns: -1 if the word is not found or an integer value of >= 1 for the 
*		   number of comparisons needed to find the word
* Requirements: N/A
*
******************************************************************************/

int dictionary::searchForward(list<DictEntry> &wordList, wordType &findString)
{
	list<DictEntry>::iterator foward_it; //create iterator for, for loop
	bool wordFound = false; //bool variable to determine if word is found in the list

	int searchCount = 0; //holds total search count

	//loop from beginning of the word list linearly to the end
	for (foward_it = wordList.begin(); foward_it != wordList.end(); ++foward_it)
	{
		searchCount = searchCount + 1; //add one to the search count for each loop iteration

		if (foward_it->getWord() == findString) //if the word is found break out of the loop
		{
			wordFound = true;
			break;
		}
	}

	if (wordFound)
		return searchCount; //if word is found return the total number of loop iterations or comparisons needed to find the word
	else
		return -1; //if word is not found return -1
}

/*****************************************************************************
*						SEARCH BACKWARD FUNCTION
*
* Purpose: Performs a linear search backwards through the sorted list of words
*		   that were given in dictionary.txt
* Inputs: The list of words from dictionary.txt and a wordType (string)
* Returns: -1 if the word is not found or an integer value of >= 1 for the
*		   number of comparisons needed to find the word
* Requirements: N/A
*
******************************************************************************/

int dictionary::searchBackward(list<DictEntry> &wordList, wordType &findString)
{
	list<DictEntry>::reverse_iterator reverse_it; //create a reverse iterator for the for loop
	bool wordFound = false; //bool variable to determine if word is found in the list

	int searchCount = 0; //holds total search count

	//loop from reverse beginning or end of the list to the reverse end or beginning linearly
	for (reverse_it = wordList.rbegin(); reverse_it != wordList.rend(); ++reverse_it)
	{
		searchCount = searchCount + 1; //add one to the search count for each loop iteration

		if (reverse_it->getWord() == findString) //if the word is found break out of the loop
		{
			wordFound = true;
			break;
		}
	}
	if (wordFound)
		return searchCount; //if word is found return the total number of loop iterations or comparisons needed to find the word
	else
		return -1; //if word is not found return -1
}

/*****************************************************************************
*						REV PRINT LIST FUNCTION
*
* Purpose: Prints a list of entries in reverse alphabetical order to the
*		   revsorted.txt file. Also, prints the contents to the screen.
* Inputs:  Output file stream and the list of words from dictionary.txt
* Returns: Display of contents that were written to the file
* Requirements: N/A
* Note: A list of the dictionary.txt elements was used. Since it was previously 
*		sorted it is easiest to test the behavior of the function
*
******************************************************************************/

void dictionary::revPrintList(ostream& output, list<DictEntry> &wordList)
{
	list<DictEntry>::reverse_iterator reverse_it; //create reverse iterator

	cout << "\nPrinted to revsorted.txt file: \n"; //to display what contents are being printed to the file

	//loop from reverse beginning or end of the list to the reverse end or beginning linearly
	for (reverse_it = wordList.rbegin(); reverse_it != wordList.rend(); ++reverse_it)
	{
		output << reverse_it->getWord() << " "; //write list elements to the file in reverse alphabetical order
		cout << reverse_it->getWord() << " "; //to display what contents are being printed to the file
	}
}

/*****************************************************************************
*						DISPLAY LIST FUNCTION
*
* Purpose: Prints a list of wordType elements to the screen
* Inputs:  A list of elements
* Returns: Display of contents of the list
* Requirements: N/A
*
******************************************************************************/

void dictionary::displayList(list<DictEntry> &wordList)
{
	list<DictEntry>::iterator f_it;

	for (f_it = wordList.begin(); f_it != wordList.end(); ++f_it)
	{
		cout << f_it->getWord() << " ";
	}

	cout << endl;
}
