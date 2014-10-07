#include <stdexcept>
#include <cstring>
#include "StackGame.h"
#include "stack.h"

StackGame::StackGame(char * sequence) : _sequence(sequence)
{
	if (!sequence || std::strlen(sequence) < 1) throw std::invalid_argument("sequence is empty");
}

int StackGame::Run()
{
	stack<char> state;
	int point = 0;

	// Push everything into the stack.
    // The cstring is null-terminated which makes it easier than string in this case.
	for (char c = *_sequence; c != 0; c=*(++_sequence))
	{
		if (isShape(c)) state.push(c);
		else if (!state.isEmpty())
		{
			if (shapeMoveMatch(state.top(), c))
			{
				++point;
				state.pop();
			}
			else --point;
		}
	}

	return point;
}

bool isShape(char shape)
{
	return shape == 'C' || shape == 'S';
}

bool shapeMoveMatch(char shape, char move)
{
	return (shape == 'C' && move == 'R') || (shape == 'S' && move == 'L');
}
