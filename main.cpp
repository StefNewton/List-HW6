/*
Name:					Stefani Moore
Last Date Modified:			10-03-2016
Course:					CSCI 2412 - Data Structures
Assignment:				HW6
Description:				Create a dictionary that reads in a list of unsorted words into a <list> STL and sort the list.
					Search that list from the beginning of the list and if found, print (to the screen) how many 
					searches/comparisons you had to make to find the word.  Then you will search from the back of 
					the list and print how many searches you had to make.

Status:					Compiles and runs successfully via Microsoft Visual Studios Community 2015 and the csegrid.

					**Meets all requirements as understood by student**

*/

//header files
#include "DictEntry.h"
#include "dictionary.h"

int main()
{
	list<DictEntry> myDictionary, myWordsToFind; //list,DictEntry> objects
	dictionary wordList; //dictionary object
	wordType words; //wordType or string variable

	ofstream writeData("revsorted.txt");

	int searchForwardCount = 0, reverseSearchCount = 0; //For number of search comparisons
	string fileInput = "dictionary.txt", findWordsInput = "findwords.txt"; //Files to open

	//Read word lists from files
	myDictionary = wordList.wordFile(fileInput);
	myWordsToFind = wordList.wordFile(findWordsInput);

	//Check for errors in opening the files
	//The begin will not = the end for any list if the file is read from correctly
	if (myDictionary.begin() == myDictionary.end() || myWordsToFind.begin() == myWordsToFind.end())
	{
		cout << "Please check your file names and try again.\n";
	}
	else //If the file was read from successfully, then perform program functions
	{
		//Display unsorted dictionary.txt contents
		cout << "Unsorted Dictionary: \n";
		wordList.displayList(myDictionary);

		//Sort dictionary words into alphabetical order
		myDictionary.sort();

		//Display sorted dictionary.txt contents
		cout << "\nSorted Dictionary: \n";
		wordList.displayList(myDictionary);

		//Display findwords.txt contents
		cout << "\nWords to Find: \n";
		wordList.displayList(myWordsToFind);

		//Search for word
		list<DictEntry>::iterator f_it_Word = myWordsToFind.begin(); //start from the beginning of the findwords.txt list

		//continue loop until the iterator reaches the end of the myWordsToFind list
		while (f_it_Word != myWordsToFind.end())
		{
			wordType temp = f_it_Word->getWord(); //temp wordType to hold the word located at f_it_Word
			searchForwardCount = wordList.searchForward(myDictionary, temp); //performs search forward, if found returns an int >= 1, if not returns -1

			if (searchForwardCount == -1) //if -1 word was not found
			{
				cout << "\nWord: " << temp << endl;
				cout << "Not found in the list.\n";
			}
			else //If word is found in forward search, then print out searchForwardCount and perform reverse search/print out reverseSearchCount
			{
				cout << "\nWord: " << temp << endl;
				cout << "Number of Forward Searches: " << searchForwardCount << endl;

				reverseSearchCount = wordList.searchBackward(myDictionary, temp); //performs reverse search, if found returns an int >= 1, if not returns -1
				cout << "Number of Reverse Searches: " << reverseSearchCount << endl;
			}
			++f_it_Word; //increment iterator to search for next word in the list
		}

		wordList.revPrintList(writeData, myDictionary); //print reverse sorted list to revsorted.txt file
	}

	writeData.close(); //close the file opened for output

	cout << "\n\nPress enter to exit the program\n";
	cin.get(); //To pause the program before exiting
	return 0;
}
