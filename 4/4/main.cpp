#include <iostream>
#include <time.h>
#include <conio.h>

#include "Game.h"
#include "Deck.h"
#include "IFormattable.h"
#include "Adapter.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Game* game = new Game();
	game->play();
	delete game;

	IFormattable* adapter = new Adapter();
	Deck deck;
	adapter->prettyPrint(deck);

	delete adapter;

	_getch;
	return 0;
}