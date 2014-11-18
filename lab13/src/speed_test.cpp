// speed_test.cpp
#include <iostream>
#include <ctime>

// list definitions
#include "ilist.h"
#include "linkedlist.h"
#include "arraylist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"

using namespace std;

double MeasureFrontInsertTime(IList<int> * list, int insertCount = 50000)
{
	double time = 0.0;

	clock_t START, FINISH;

	//start the clock
	START = clock();
	for(int i = 0; i < insertCount; ++i) list->insert(0, i);
	
	//stop the clock and calculate time
	FINISH = clock();

	time = (double)(FINISH - START);
	time /= CLOCKS_PER_SEC;
	
	return time;
}

double MeasureBackInsertTime(IList<int> * list, int insertCount = 50000)
{
	double time = 0.0;

	clock_t START, FINISH;

	//start the clock
	START = clock();
	for(int i = 0; i < insertCount; ++i) list->insert(i, i);
	
	//stop the clock and calculate time
	FINISH = clock();

	time = (double)(FINISH - START);
	time /= CLOCKS_PER_SEC;

	return time;
}

int main()
{
	double frontTime = 0.0, backTime = 0.0;
	IList<int> ** lists = new IList<int>*[8];

	// feel free to pass some argument to your constructor or just leave it to the default constructor
	lists[0] = new LinkedList<int>;          // front insert
	lists[1] = new LinkedList<int>;          // back  insert
	lists[2] = new PlusOneArrayList<int>;    // front insert
	lists[3] = new PlusOneArrayList<int>;    // back  insert
	lists[4] = new PlusTenArrayList<int>;    // front insert
	lists[5] = new PlusTenArrayList<int>;    // back  insert
	lists[6] = new DoublingArrayList<int>;   // front insert
	lists[7] = new DoublingArrayList<int>;   // back  insert

	for (int i = 0; i < 8; i += 2)
	{
		frontTime = MeasureFrontInsertTime(lists[i]);
		backTime  = MeasureBackInsertTime (lists[i + 1]);

		// cout the duration in seconds
		if (i == 0)      cout << "--- Linked List ---" << endl;
		else if (i == 2) cout << "--- PlusOneArrayList ---" << endl;
		else if (i == 4) cout << "--- PlusTenArrayList ---" << endl;
		else if (i == 6) cout << "--- DoublingArrayList ---" << endl;

		cout << "     FrontTime: " << frontTime << endl;
		cout << "     BackTime:  " << backTime  << endl;

		// release: you can optionally measure delete (removing all items) duration
		delete lists[i];
		delete lists[i + 1];
	}
	delete [] lists;
	return 0;
}
