#ifndef MAP_H
#define	MAP_H

#include <stdexcept>
#include "linkedlist.h"

template<class keyT, class valueT>
struct mapPair
{
	keyT key;
	valueT value;
};

template <class keyT, class valueT>
class map
{
	public:
		map ();  // constructor for a new empty map

		~map (); // destructor

		int size () const; // returns the number of key-value pairs

		void add (const keyT & key, const valueT & value); 
		  /* Adds a new association between the given key and the given value.
			 If the key already has an association, it should throw an exception.
		  */

		void remove (const keyT & key);
		 /* Removes the association for the given key.
			If the key has no association, it should throw an exception. */

		const valueT& get (const keyT & key) const;
		 /* Returns the value associated with the given key.
			If the key has no association, it should throw an exception. */

	private:
		LinkedList< mapPair<keyT, valueT> > internalStorage;
		int storageSize;

		int find(keyT findKey) const;
};

#include "mapImpl.h"

#endif //MAP_H
