template <class T>
ArrayList<T>::ArrayList()
{
	_size = 0;
	capacity = 10;
	//let's set initial size as 10
	array = new T[capacity];
}

template <class T>
ArrayList<T>::~ArrayList ()
{
	//check if array exists
	if (array != NULL) delete [] array;
}

template <class T>
int ArrayList<T>::size () const
{
	return _size;
}

template <class T>
void ArrayList<T>::insert (int position, const T & val)
{
	//first check for out of range
	if (position > _size || position < 0)
		throw std::out_of_range("Invalid position, unable to insert");

	//now check for resize
	if (_size == capacity) resize();

	//valid position. We need to shift all the elements after the position to the right
	for (int i = _size; i > position; --i) array[i] = array[i - 1];

	//insert the item
	array[position] = val;
	++_size;
}

template <class T>
void ArrayList<T>::remove (int position)
{
	//the same process as insert, except no resize and shift left instead of right
	if (position >= _size || position < 0)
		throw std::out_of_range("Invalid position, unable to remove");

	//shifting to left overwrites the position we want to remove
	for (int i = position; i < _size; ++i)
	{
		array[i] = array[i+1];
	}

	--_size;
}

template <class T>
void ArrayList<T>::set (int position, const T & val)
{
	//very simple, directly access position
	if (position > _size || position < 0)
		throw std::out_of_range("Invalid position, unable to remove");

	array[position] = val;	
}

template <class T>
T & ArrayList<T>::get (int position)
{
	//directly access position
	if (position >= _size || position < 0)
		throw std::out_of_range("Invalid position, unable to remove");

	return array[position];

}

template <class T>
T const & ArrayList<T>::get (int position) const
{
	//same as above
	if (position >= _size || position < 0)
		throw std::out_of_range("Invalid position, unable to remove");

	return array[position];	
}
