template <class T>
PlusTenArrayList<T>::PlusTenArrayList():ArrayList<T>()
{
	//calls parent constructor
	// ArrayList<T>::ArrayList();
}
template <class T>
PlusTenArrayList<T>::~PlusTenArrayList()
{
	//calls parent constructor by default
}
template <class T>
void PlusTenArrayList<T>::resize()
{
	//create new Array of new size;
	T* newArray = new T[this->capacity+10];
	//copy over all the elements
	for (int i = 0; i < this->capacity; ++i)
	{
		newArray[i] = this->array[i];
	}

	//now that it's copied over, delete the old one
	delete [] this->array;

	//set the new array
	this->array = newArray;

	//update size
	this->capacity += 10;

}
