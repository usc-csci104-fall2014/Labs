#ifndef BOUNDEDLIST_IMPL__H_
#define BOUNDEDLIST_IMPL__H_

// Some of these function need good exception to guard against bad index
// there is also one function missing. create a place holder to avoid the linker error

template<class T, size_t Capacity>
lab4::BoundedList<T, Capacity>::BoundedList()
		: _size(0) // , _data( new T[Capacity] )
{
}

template<class T, size_t Capacity>
lab4::BoundedList<T, Capacity>::BoundedList(size_t size, T const & value)
		: _size(size) // , _data( new T[Capacity] )
{
	if (_size > Capacity) throw std::out_of_range("Capacity is full");
	for (size_t i = 0; i < size; ++i)
		_data[i] = value;
}

template<class T, size_t Capacity>
void lab4::BoundedList<T, Capacity>::push_back(T const & data)
{
	if (_size >= Capacity) throw std::out_of_range("Capacity is full");
	_data[_size++] = data;
}

template<class T, size_t Capacity>
lab4::BoundedList<T, Capacity>::~BoundedList()
{
	// delete [] _data;
}

template<class T, size_t Capacity>
size_t lab4::BoundedList<T, Capacity>::size() const
{
	return _size;
}

template<class T, size_t Capacity>
T const & lab4::BoundedList<T, Capacity>::getItem(int index) const
{
	// what should we do if index was out of bound?
	if (index >= _size) throw std::out_of_range("index is larger than size");
	return _data[index];
}

template<class T, size_t Capacity>
T & lab4::BoundedList<T, Capacity>::front()
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[0];
}

template<class T, size_t Capacity>
T const & lab4::BoundedList<T, Capacity>::front() const
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[0];
}

template<class T, size_t Capacity>
T & lab4::BoundedList<T, Capacity>::back()
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[_size - 1];
}

template<class T, size_t Capacity>
T const & lab4::BoundedList<T, Capacity>::back() const
{
	if (_size < 1) throw std::out_of_range("list is empty");
	return _data[_size - 1];
}

#endif // BOUNDEDLIST_IMPL__H_
