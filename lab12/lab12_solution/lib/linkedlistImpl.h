template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	listSize = 0; 
}

template <class T>
LinkedList<T>::~LinkedList()
{
	//base case, if list is empty, then just delete
	if (head == NULL)
	{
		return;
	}

	//while not on the last element
	while (head->next != NULL)
	{
		//move and delete previous element
		Item<T>* toDelete = head;
		head = head->next;
		delete toDelete;
	}

	//delete last element
	delete head;
}

template <class T>
void LinkedList<T>::insert (int position, const T & val)
{

	//check for invalid position
	//extra case of NULL so that it can continue if the list is empty
	if (position < 0 || position > listSize)
	{
		throw std::out_of_range("Invalid position for insert");
	}

	Item<T>* toAdd = new Item<T>;
	toAdd->value = val;
	toAdd->next = NULL;
	toAdd->prev = NULL;

	//check if empty
	if (listSize == 0)
	{
		head = toAdd;
		tail = toAdd;
		++listSize;
		return;
	}

	//check if head
	if (position == 0)
	{
		//inserting is easy
		toAdd->next = head;
		head->prev = toAdd;
		head = toAdd;
		++listSize;
		return;
	}

	//check if at tail
	if (position == listSize)
	{
		toAdd->prev = tail;
		tail->next = toAdd;
		tail = toAdd;
		++listSize;
		return;
	}

	//if reached here, it means that it's inserting in the middle
	//get to the position first

	Item<T>* insertAt = head;

	for (int i = 0 ; i < position; ++i)
	{
		insertAt = insertAt->next;
	}

	Item<T>* newPrev = insertAt->prev;
	Item<T>* newNext = insertAt;

	//now at correct position, add it to the left of insertAt;
	toAdd->prev = newPrev;
	toAdd->next = newNext;

	newPrev->next = toAdd;
	newNext->prev = toAdd;

	++listSize;
}

template<class T>
void LinkedList<T>::removePtr (Item<T> *p)
{
	//If the pointer is the head pointer, set the head as the second element
	if (p == head)
	{
		head = p->next;
		if (head) head->prev = NULL;
	}
	else //not head element
	{
		//the previous' element's next pointer is p's next element
		p->prev->next = p->next;
	}

	//Same as above, but just the other way around
	if (p == tail)
	{
		tail = p->prev;
		if (tail) tail->next = NULL;
	}
	else
	{
		p->next->prev = p->prev;
	}

	delete p;
}

template <class T>
void LinkedList<T>::remove (int position)
{
	//test for empty
	if (head == NULL) throw std::out_of_range("List is empty!");

	//test for out of range
	if (position < 0 || position > listSize) throw std::out_of_range("Invalid position for remove");

	Item<T>* toRemove = head;

	for (int i = 0; i < position; ++i) toRemove = toRemove->next;

	removePtr(toRemove);
	--listSize;
}

template <class T>
void LinkedList<T>::set (int position, const T & val)
{
	//test for empty
	if (head == NULL) throw std::out_of_range("List is empty!");

	if (position < 0 || position > listSize) throw std::out_of_range("Invalid position to set");

	Item<T>* toReplace = head;

	for (int i = 0; i < position; ++i) toReplace = toReplace->next;

	toReplace->value = val;
}

template <class T>
T& LinkedList<T>::get (int position)
{
	//test for empty
	if (head == NULL) throw std::out_of_range("List is empty!");

	//same thing as set except return the value

	if (position < 0 || position > listSize) throw std::out_of_range("Invalid position to set");

	Item<T>* toGet = head;

	for (int i = 0; i < position; ++i) toGet = toGet->next;

	//switch it out
	return toGet->value;
}

template <class T>
int LinkedList<T>::size () const
{
	return listSize;
}

template <class T>
T const & LinkedList<T>::get (int position) const
{
	//test for empty
	if (head == NULL) throw std::out_of_range("List is empty!");

	//same thing as set except return the value

	if (position < 0 || position > listSize) throw std::out_of_range("Invalid position to set");

	Item<T>* toGet = head;

	for (int i = 0; i < position; ++i) toGet = toGet->next;

	//switch it out
	return toGet->value;
}
