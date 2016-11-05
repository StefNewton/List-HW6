# List-HW6

*******************************************************
*  Name      :  Stefani Moore        
*  Student ID:  106789878  
*  Class     :  CSC 2421           
*  HW#       :  6                
*  Due Date  :  Oct. 5, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Create a dictionary that reads in a list of unsorted words into a <list> STL and sort the list.
Search that list from the beginning of the list and if found, print (to the screen) how many 
searches/comparisons you had to make to find the word.  Then you will search from the back of 
the list and print how many searches you had to make.

Note: The dictionary.txt and findwords.txt files must be space delimited for the program to 
	function properly.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read in a list of words, sort the list, and search the list.

Name:  dictionary.h
   Contains the definition for the dictionary class.  

Name: dictionary.cpp
   Defines and implements the dictionary class.  
 
Name:  DictEntry.h
   Contains the function definition for the '<' overload. 
   Also, contains functions for setting and accessing the word 
   and its definition.   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Microsoft Visual
   Studios Community 2015.  It was compiled, run, and tested 
   on the csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [MooreHW6]

   Now you should see a directory named homework with the files:
        main.cpp
        dictionary.h
        dictionary.cpp
	DictEntry.h
	revsorted.txt
	dictionary.txt
	findwords.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [MooreHW6] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[dictionary]

4. Delete the obj files, executables, and core dump by
   %./make clean
