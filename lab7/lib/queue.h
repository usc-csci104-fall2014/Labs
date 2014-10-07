#ifndef QUEUE_H
#define	QUEUE_H

#include "doublingarraylist.h"

template <class T>
class queue : private DoublingArrayList<T>
{
	public:
		queue()          { }
		virtual ~queue() { }

		void enqueue (const T & val) { this->insert(this->size(), val);     }
		void dequeue ()               { this->remove(0);     }
		T const & peek() const     { return this->get(0);  }
		bool isEmpty()  const     { return this->size() == 0; }
};

#endif //QUEUE_H
