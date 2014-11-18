#ifndef DOUBLINGARRAYLIST_H
#define DOUBLINGARRAYLIST_H

#include "arraylist.h"

template <class T>
class DoublingArrayList: public ArrayList<T>
{
	public:
		DoublingArrayList();
		~DoublingArrayList();

	protected:
		void resize();
};

#include "doublingarraylistImpl.h"

#endif
