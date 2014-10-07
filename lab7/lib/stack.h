#ifndef STACK_H
#define	STACK_H

#include "doublingarraylist.h"

template <class T>
class stack : private DoublingArrayList<T>
{
	public:
		stack()          { }
		virtual ~stack() { }

		void push (const T & val) { this->insert(this->size(), val);     }
		void pop ()               { this->remove(this->size() -  1);     }
		T const & top() const     { return this->get(this->size() - 1);  }
		bool isEmpty()  const     { return this->size() == 0; }
};

#endif //STACK_H
