#ifndef BOUNDEDLIST_H_
#define BOUNDEDLIST_H_

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

#include "BoundedListImpl.h"

#endif // BOUNDEDLIST_H_
