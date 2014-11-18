#ifndef STACK_H
#define	STACK_H

template <class T>
class stack : private LinkedList<T>
{
	public:
		stack() { }
		virtual ~stack() { }

		void push (const T & val) { this->insert(0, val);     }
		void pop ()               { this->remove(0);          }
		T const & top() const     { return this->get(0);      }
		bool isEmpty()  const     { return this->size() == 0; }
};

#endif //STACK_H
