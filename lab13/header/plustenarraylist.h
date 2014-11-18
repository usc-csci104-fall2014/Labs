#ifndef PLUSTENARRAYLIST_H
#define PLUSTENARRAYLIST_H

#include "arraylist.h"

template <class T>
class PlusTenArrayList: public ArrayList<T>
{
	public:
		PlusTenArrayList();
		~PlusTenArrayList();

	protected:
		void resize();
};

#include "plustenarraylistImpl.h"

#endif
