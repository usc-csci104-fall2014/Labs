#include <stdexcept>
#include <cstring>
#include "ListGame.h"
#include "queue.h"

ListGame::ListGame(char * sequence) : _sequence(sequence)
{
	if (!sequence || std::strlen(sequence) < 1) throw std::invalid_argument("sequence is empty");
}

int ListGame::Run()
{
	queue<char> state;
	int point = 0;

	// Enqueue everything into the Queue
    // The cstring is null-terminated which makes it easier than string in this case.
	for (char c = *_sequence; c != 0; c=*(++_sequence))
	{
		if (isAnimal(c)) state.enqueue(c);
		else if (!state.isEmpty())
		{
			if (animalMoveMatch(state.peek(), c))
			{
				++point;
				state.dequeue();
			}
			else --point;
		}
	}

	return point;
}

bool isAnimal(char animal)
{
	return animal == 'M' || animal == 'L';
}

bool animalMoveMatch(char animal, char food)
{
	return (animal == 'M' && food == 'B') || (food == 'S' && animal == 'L');
}
