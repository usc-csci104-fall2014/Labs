template <class keyT, class valueT>
map<keyT, valueT>::map ()
{
	storageSize = 0;
}

template <class keyT, class valueT>
map<keyT, valueT>::~map ()
{
	//no dynamically allocated memory, no need to delete
}

template <class keyT, class valueT>
int map<keyT, valueT>::size () const
{
	return storageSize;
}

template <class keyT, class valueT>
void map<keyT, valueT>::add (const keyT & key, const valueT & value)
{
	//if value does not already exist
	if (find(key) == -1)
	{
		mapPair<keyT, valueT> newPair;
		newPair.key 	= key;
		newPair.value 	= value;
		internalStorage.insert(0, newPair);
		++storageSize;
	}
	else
	{
		//already exists, throw exception
		throw std::invalid_argument("Key already exists in map!");
	}
} 

template <class keyT, class valueT>
void map<keyT, valueT>::remove (const keyT & key)
{
	int index = find(key);
	if (index == -1)
		throw std::invalid_argument("Key does not exist, cannot remove");
	internalStorage.remove(index);
	--storageSize;
}

template <class keyT, class valueT>
const valueT& map<keyT, valueT>::get (const keyT & key) const
{
	int index = find(key);
	if (index == -1)
		throw std::invalid_argument("Key does not exist, cannot get value");
	return internalStorage.get(index).value;
}

//if return -1, it means it doesn't exist
template <class keyT, class valueT>
int map<keyT, valueT>::find(keyT findKey) const
{
	if (storageSize == 0) return -1;

	for (int i = 0; i < storageSize; ++i)
	{
		if (internalStorage.get(i).key == findKey) return i;
	}

	return -1;
}
