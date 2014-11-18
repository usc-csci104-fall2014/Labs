CS104 Lab 13 Code Base                         {#mainpage}
======================

|                                                        |
| :------------------------------------------------------|
|  CS 104 FALL 2014									 |
|  Based on a previous homework solution 							 |
|  Solution by: Stephen Tsung-Han Sher and Kaveh Shahabi |
----------------------------------------------------------

This solution involved implemented boolean logic.  For our purposes,
there are many files that are in need of documentation!

###bin

The bin directory holds the .dSYM files 
that results from compiling. It also 
holds the executible files.

###data

This directory holds two text files 
specifically for question 7 (boolean 
parsing). Feel free to add in different 
formulas or variables, however do keep 
in mind the format of the data files. 

###header

This directory holds the following files:

 + arraylist.h
 + arraylistImpl.h
 + doublingarraylist.h
 + doublingarraylistImpl.h
 + ilist.h
 + linkedlist.h
 + linkedlistImpl.h
 + map.h
 + mapImpl.h
 + plusonearraylist.h
 + plusonearraylistImpl.h
 + plustenarraylist.h
 + plustenarraylistImpl.h
 + stack.h
 + stackImpl.h

Please feel free to use these files as reference. 

###src

This directory contains all the .cpp files 
with the main function in them:

 + arraylist_test.cpp		Question 4
 + speed_test.cpp			Question 5
 + boolean.cpp				Question 7

Feel free to read the code. If you have any questions feel free to contact me.

###Makefile

The bin directory is already provided. Simply 
type < make > to compile three executibles:

 + arraylist_test
 + speed_test
 + boolean

Typing < make clean > will remove all the 
executibles and .dSYM files in the bin directory