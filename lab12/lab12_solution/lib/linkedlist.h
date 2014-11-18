#ifndef SET_H
#define	SET_H

#include <stdexcept>
#include "ilist.h"

#ifndef ITEM
#define ITEM

	template <class T>
	struct Item
	{
	  T value;
	  Item<T> *prev, *next;
	};

#endif //ITEM

template <class T>
class LinkedList: public IList<T>
{
	public:

		LinkedList();
		~LinkedList();

		int size () const;
		void insert (int position, const T & val);
		void remove (int position);
		void set (int position, const T & val);
		T& get (int position);
		T const & get (int position) const;

	private:
		void removePtr (Item<T>* p);
		Item<T> *head;
		Item<T> *tail;
		int listSize;
};

#include "linkedlistImpl.h"

#endif //SET_H

