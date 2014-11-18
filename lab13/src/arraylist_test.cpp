#include <iostream>
#include "ilist.h"
#include "arraylist.h"
#include "linkedlist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"
#include <stdexcept>

using namespace std;

int main()
{
	IList<int>** listArray = new IList<int>*[4];
	listArray[0] = new LinkedList<int>;
	listArray[1] = new PlusOneArrayList<int>;
	listArray[2] = new PlusTenArrayList<int>;
	listArray[3] = new DoublingArrayList<int>;

	IList<int>* testPtr = NULL;

	for (int i = 0 ; i < 4; ++i)
	{
		//set list to test
		testPtr = listArray[i];
		if (i == 0)
		{
			cout << "-----------------------------------------" << endl;
			cout << "|              Linked List              |" << endl;
			cout << "-----------------------------------------" << endl;
			cout << endl;
		}
		if (i == 1)
		{
			cout << "-----------------------------------------" << endl;
			cout << "|             Plus One List             |" << endl;
			cout << "-----------------------------------------" << endl;
			cout << endl;
		}
		if (i == 2)
		{
			cout << "-----------------------------------------" << endl;
			cout << "|             Plus Ten List             |" << endl;
			cout << "-----------------------------------------" << endl;
			cout << endl;
		}
		if (i == 3)
		{
			cout << "-----------------------------------------" << endl;
			cout << "|             Doubling List             |" << endl;
			cout << "-----------------------------------------" << endl;
			cout << endl;
		}

		cout << "-----------------" << endl;
		cout << "| Initial cases |" << endl;
		cout << "-----------------" << endl;

		cout << "-> Testing size function on empty list" << endl;
		cout << "   Size of empty list is: " << testPtr->size() << endl;

		cout << "-> Initializing list with integers from 0 to 9" << endl;
		for (int i = 0; i < 10; ++i)
			testPtr->insert(i,i);
		cout << "   ...Done" << endl;

		cout << endl;
		cout << "-------------------------" << endl;
		cout << "| Testing invalid cases |" << endl;
		cout << "-------------------------" << endl;

		cout << endl;
		cout << "-> Inserting at invalid position" << endl;
		cout << "   Negative position" << endl;
		try
		{
			testPtr->insert(-1,10);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "   Position larger than size (100)" << endl;
		try
		{
			testPtr->insert(100,10);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "-> Getting item at invalid position" << endl;
		cout << "   Negative position" << endl;
		try
		{
			testPtr->get(-1);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "   Position larger than size (100)" << endl;
		try
		{
			testPtr->get(100);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "-> Removing at invalid position" << endl;
		cout << "   Negative position" << endl;
		try
		{
			testPtr->remove(-1);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "   Position larger than size (100)" << endl;
		try
		{
			testPtr->remove(100);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "-> Setting at invalid position" << endl;
		cout << "   Negative position" << endl;
		try
		{
			testPtr->set(-1, 100);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "   Position larger than size (100)" << endl;
		try
		{
			testPtr->set(100, 100);
		}
		catch (const out_of_range & e)
		{
			cout << "      Exception caught: " << e.what() << endl;
		}

		cout << endl;
		cout << "---------------------" << endl;
		cout << "| Testing functions |" << endl;
		cout << "---------------------" << endl;		

		cout << endl;
		cout << "-> Using get() to print out all 10 elements in the list" << endl;
		cout << "   ";
		for (int i = 0; i < 10; ++i)
		{
			cout << testPtr->get(i) << "  ";
		}
		cout << endl;

		cout << endl;
		cout << "-> Setting the first, last, and middle element as 99" << endl;
		testPtr->set(0, 99);
		testPtr->set(5, 99);
		testPtr->set(testPtr->size()-1, 99);
		cout << "   ";
		for (int i = 0; i < 10; ++i)
		{
			cout << testPtr->get(i) << "  ";
		}	
		cout << endl;

		cout << "-> Removing the first last, and middle (5) element" << endl;
		testPtr->remove(5);
		testPtr->remove(0);
		testPtr->remove(testPtr->size()-1);
		cout << "   ";
		for (int i = 0; i < testPtr->size(); ++i)
		{
			cout << testPtr->get(i) << "  ";
		}	
		cout << endl;

		cout << endl;
		cout << "-> Deleting list" << endl;
		delete testPtr;
		cout << "   Use valgrind to test for memory leaks" << endl;
		cout << endl;
	}

	delete [] listArray;

	return 0;
}
