#include "Game.h"


Game::Game() {

	for (int i = 0; i < 4; i++)
	{
		deck[i] = new Deck();
		deck[i]->shuffle();
	}
	player = new Player();
	dealer = new Dealer();
}

Game::~Game() {

	for (int i = 0; i < 4; i++) delete deck[i];
	delete player;
	delete dealer;
}

void Game::play() {

	int size = 0;
	cout << "9 вариант\n --> Тип: базовый\n --> Доп.правило: сплит\n";
	cout << "\nВаш баланс: " << player->getBalance();
	cout << "\x1b[33m$\n\x1b[0m" << "\x1b[31mВаша ставка?\x1b[0m" << endl;
	cin >> bet;

	dealer->addCard(deck[rand() % 4]->pop());
	player->addCard(deck[rand() % 4]->pop());
	player->addCard(deck[rand() % 4]->pop());
	while (match) partGame();
}

void Game::printGame() {

	cout << "\x1b[33m\nКолоды:\t\x1b[0m";
	for (int i = 0; i < 4; i++) {
		cout << "[" << deck[i]->getSize() << "]\t";
	}
	cout << "\x1b[32m\nДилер:\t\x1b[0m";
	for (int i = 0; i < dealer->getHand()->getCards().size(); i++) {
		cout << *dealer->getHand()->getCards().at(i) << "\t";
	}
	cout << "\x1b[31m\nВы:\t\x1b[0m";
	for (int i = 0; i < player->getHand()->getCards().size(); i++) {
		cout << *player->getHand()->getCards().at(i) << "\t";
	}
}

void Game::partGame() {
	playerScore = player->getHand()->getScore();
	if (playerScore == 21 && player->getHand()->getCards().size() == 2) {
		blackJack();
	}
	else {
		printGame();
		if (player->getHand()->getCards().size() == 2 && isSplit == true) menuSurrender();
		else menu();
	}
}

void Game::menu()
{
	cout << "\n1. Хватит\n2. Еще\n";
	cin >> item;
	dealerScore = dealer->getHand()->getScore();
	playerScore = player->getHand()->getScore();
	if (item == 1) stop();
	else if (item == 2) more();
	else cout << "Попробуйте еще раз!\n";
}

void Game::menuSurrender()
{
	cout << "\n1. Хватит\n2. Еще\n3. Сплит?\n";
	cin >> item;
	dealerScore = dealer->getHand()->getScore();
	playerScore = player->getHand()->getScore();
	if (item == 1) stop();
	else if (item == 2) more();
	else if (item == 3) split();
	else std::cout << "Попробуйте еще раз!\n";
}

void Game::conditionMaxCard()
{
	if (player->getHand()->getCards().size() == 5 && player->getHand()->getScore() < 21) {
		bet *= 1.5;
		win();
	}
	else if (player->getHand()->getCards().size() == 6 && player->getHand()->getScore() < 21) {
		bet *= 2;
		win();
	}
	else if (player->getHand()->getCards().size() == 7 && player->getHand()->getScore() < 21) {
		bet *= 3;
		win();
	}
}

void Game::more() {

	try {
		player->addCard(deck[rand() % 4]->pop());
		playerScore = player->getHand()->getScore();
		conditionMaxCard();
		if (playerScore > 21) throw true;
	}
	catch (...) {
		printGame();

		cout << "\nПеребор! Вы проиграли! Ваш проигрыш: " << bet << ". Ваш баланс: " << player->getBalance() - bet << endl;

		player->clearHand();
		dealer->clearHand();

		match = false;
	}
}

void Game::stop() {

	dealer->addCard(deck[rand() % 4]->pop());
	dealerScore = dealer->getHand()->getScore();

	if (dealerScore >= 21) win();
	if (dealerScore < playerScore) win();
	if (dealerScore < 21 && dealerScore >= playerScore) losing();
}

void Game::split() {
	try {
		player->addCard(deck[rand() % 4]->pop());
		playerScore = player->getHand()->getScore();
		conditionMaxCard();
		if (playerScore > 21) throw true;
	}
	catch (...) {
		printGame();

		cout << "\nПеребор! Вы проиграли! Ваш проигрыш: " << bet << ". Ваш баланс: " << player->getBalance() - bet << endl;

		player->clearHand();
		dealer->clearHand();

		match = false;
	}
	try {
		player->addCard(deck[rand() % 4]->pop());
		playerScore = player->getHand()->getScore();
		conditionMaxCard();
		if (playerScore > 21) throw true;
	}
	catch (...) {
		printGame();

		cout << "\nПеребор! Вы проиграли! Ваш проигрыш: " << bet << ". Ваш баланс: " << player->getBalance() - bet << endl;

		player->clearHand();
		dealer->clearHand();

		match = false;
	}

	isSplit = false;
}

void Game::losing() {
	printGame();

	player->clearHand();
	dealer->clearHand();

	cout << "\nПеребор! Вы проиграли: " << bet << ". Ваш баланс: " << player->getBalance() - bet << endl;
	match = false;
}

void Game::win() {

	printGame();

	player->addMoney(bet);
	player->clearHand();
	dealer->clearHand();

	cout << "\nПоздравляю! Вы выиграли: " << bet << ". Ваш баланс: " << player->getBalance() << endl;
	match = false;
}

void Game::blackJack() {
	printGame();

	player->addMoney(1.5 * bet);
	player->clearHand();
	dealer->clearHand();

	cout << "\nПоздравляю! У вас блэкджек! Вы выиграли: " << bet * 1.5 << ".  Ваш баланс: " << player->getBalance() << endl;
	match = false;
}