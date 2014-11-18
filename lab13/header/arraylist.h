#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "ilist.h"
#include <stdexcept>

template <class T>
class ArrayList: public IList<T>
{
	public:
		ArrayList();
		~ArrayList ();
		int size () const;
		void insert (int position, const T & val);
		void remove (int position);
		void set (int position, const T & val);
		T& get (int position);
		T const & get (int position) const;

	protected:
		virtual void resize() = 0;
		T* array;
		int capacity;

	private:
		int _size;
};

#include "arraylistImpl.h"
#endif
