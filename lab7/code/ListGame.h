#ifndef LISTGAME_H_
#define LISTGAME_H_

bool isAnimal(char animal);
bool animalMoveMatch(char food, char move);

class ListGame
{
private:
	char * _sequence;

public:
	ListGame(char * sequence);
	int Run();
};

#endif /* LISTGAME_H_ */
