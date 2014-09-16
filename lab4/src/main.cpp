#include <iostream>
#include "Data.h"
#include "BoundedList.h"

template<class T, size_t Capacity>
void printList(lab4::BoundedList<T, Capacity> const & b)
{
	for (size_t i = 0; i < b.size(); ++i)
	{
		std::cout << b.getItem(i) << std::endl;
	}
}

int main()
{
	lab4::BoundedList<lab4::DataC, 3> * l = nullptr;
	try
	{
		l = new lab4::BoundedList<lab4::DataC, 3>();
		lab4::DataC d1("data 1");  // make a new data
		lab4::DataC d2(d1);        // copy the data
		d1.setString("hi");        // changing d1 value but not d2
		auto d3 = d1 + d2;         // add two data
		l->push_back(d1);
		l->push_back(d2);
		l->push_back(d3);

		std::cout << "Print   the list:" << std::endl;
		printList(*l);
	}
	catch (std::exception & ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	// release and finish
	if (l) { delete l; l = nullptr; }

	return 0;
}
