#ifndef STACKGAME_H_
#define STACKGAME_H_

bool isShape(char shape);
bool shapeMoveMatch(char shape, char move);

class StackGame
{
private:
	char * _sequence;

public:
	StackGame(char * sequence);
	int Run();
};

#endif /* STACKGAME_H_ */
