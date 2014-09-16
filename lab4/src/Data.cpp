#include "Data.h"

namespace lab4
{
	DataS::DataS()
	{
		DEBUG_MSG("Making Data Struct")
	}

	std::string DataS::print() const
	{
		return "struct value";
	}

	// destroying DataC with string data
	DataC::~DataC()
	{
		DEBUG_MSG("destroy Data Class")
		delete _data;
	}

	// default constructor
	DataC::DataC() : _data(new std::string("empty data"))
	{
		DEBUG_MSG("Making  empty Data Class")
	}

	// make a new DataC with string data
	DataC::DataC(const std::string & s) : _data(???)
	{
		DEBUG_MSG("Making  Data Class")
	}

	// copy the class
	DataC::DataC(???) : _data(???)
	{
		DEBUG_MSG("Copying Data Class")
	}
	
	// assignment operator
	DataC & DataC::operator=(const DataC & rhs)
	{
		DEBUG_MSG("Assign  Data Class")
		if (this != &rhs)
		{
		    // which version do we need?
		    // option 1: is this deep or shallow copy?
			// delete this->_data;
			// this->_data = new std::string(*rhs._data);
			
			// option 2
			// this->_data = rhs._data;
		}
		return *this;
	}
	
	// <--- non-member functions --->

	std::ostream & operator<<(???)
	{
		return ???;
	}
	
	DataC operator+(??? lhs, ??? rhs)
	{
	    // feel free to implement a different add functionality
		DEBUG_MSG("Adding  Data Classes")
		return DataC(*lhs._data + " " + *rhs._data);
	}
}

