#include <iostream>
//#include "Data.h"

//header
#include <exception>
#include <stdexcept>
#include <cstddef>    // to import size_t. We use this instead of int to avoid warnings.
// #include "Data.h"  // do we need this here? No

namespace lab4
{
	//! A class that acts like a list with a maximum size
	/*! @tparam T The type to store
	 @tparam Capacity The maximum size of the list (=capacity) */
	template<class T, size_t Capacity>
	class BoundedList
	{
	public:
		//! Construct an empty list
		BoundedList();

		//! Construct a list with some number of elements taking on the same value
		/*! @param size The size of the list, which can be at most Capacity
		 @param value The value to give every entry in the list */
		BoundedList(size_t size, T const & value = T());

		////! Destructor
		~BoundedList();

		//! Appends an item to the end of the list if there is room
		void push_back(T const & data);

		/*! @return the size always >= 0 and < Capacity */
		//! returns the number of items added to the list.
		size_t size() const;

		//! Get a reference to the item by index (const version)
		T const & getItem(int index) const;

		//! Get a reference to the first item in my list (mutable)
		T & front();

		//! Get a reference to the first item in my list (const)
		T const & front() const;

		//! Get a reference to the last item in my list (mutable)
		T & back();

		//! Get a reference to the last item in my list (const)
		T const & back() const;

	private:
		size_t _size; //!< The current index of my last item

		// Data storage. If you want to use the dynamic array version,
		// then you have to modify the constructor and destructor.
		T _data[Capacity];  //!< Data stored as stack based array
		// T * _data;       //!< Data stored as a dynamically allocated array.
	};  // class BoundedList
} // namespace lab4

//template class implementation
template<class T, size_t Capacity>
lab4::BoundedList<T, Capacity>::BoundedList()
		: _size(0) // , _data( new T[Capacity] )
{
}

template<class T, size_t Capacity>
lab4::BoundedList<T, Capacity>::BoundedList(size_t size, T const & value)
		: _size(size) // , _data( new T[Capacity] )
{
	if (_size > Capacity) throw std::out_of_range("Capacity is full");
	for (size_t i = 0; i < size; ++i)
		_data[i] = value;
}

template<class T, size_t Capacity>
void lab4::BoundedList<T, Capacity>::push_back(T const & data)
{
	if (_size >= Capacity) throw std::out_of_range("Capacity is full");
	_data[_size++] = data;
}

template<class T, size_t Capacity>
lab4::BoundedList<T, Capacity>::~BoundedList()
{
	// delete [] _data;
}

template<class T, size_t Capacity>
size_t lab4::BoundedList<T, Capacity>::size() const
{
	return _size;
}

template<class T, size_t Capacity>
T const & lab4::BoundedList<T, Capacity>::getItem(int index) const
{
	// what should we do if index was out of bound?
	if (index >= _size) throw std::out_of_range("index is larger than size");
	return _data[index];
}

template<class T, size_t Capacity>
T & lab4::BoundedList<T, Capacity>::front()
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[0];
}

template<class T, size_t Capacity>
T const & lab4::BoundedList<T, Capacity>::front() const
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[0];
}

template<class T, size_t Capacity>
T & lab4::BoundedList<T, Capacity>::back()
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[_size - 1];
}

template<class T, size_t Capacity>
T const & lab4::BoundedList<T, Capacity>::back() const
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[_size - 1];
}

//custom data class
class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area () {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

template<class Rectangle, size_t Capacity>
void printList(lab4::BoundedList<Rectangle, Capacity> const & b)
{
	for (size_t i = 0; i < b.size(); ++i)
	{
		Rectangle item = b.getItem(i);
		std::cout << item.area() << std::endl;
	}
}

//main class
int main()
{
	lab4::BoundedList<Rectangle, 3> * l = nullptr;
	try
	{
		l = new lab4::BoundedList<Rectangle, 3>();
		Rectangle r1, r2;  // make a new data
		r1.set_values(2, 3);
		r2.set_values(4, 5);
		//lab4::DataC d2(d1);        // copy the data
		//d1.setString("hi");        // changing d1 value but not d2
		//auto d3 = d1 + d2;         // add two data
		l->push_back(r1);
		l->push_back(r2);

		std::cout << "Print the list:" << std::endl;
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
