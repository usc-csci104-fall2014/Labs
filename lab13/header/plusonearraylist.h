#ifndef PLUSONEARRAYLIST_H
#define PLUSONEARRAYLIST_H

#include "arraylist.h"

template <class T>
class PlusOneArrayList: public ArrayList<T>
{
	public:
		PlusOneArrayList();
		~PlusOneArrayList();

	protected:
		void resize();
};

#include "plusonearraylistImpl.h"

#endif
