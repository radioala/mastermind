#include "modeSelection.h"

void players::mode_selection() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	this->typing_animation("Wybierz tryb gry:", SPEED);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	this->typing_animation("\n1): gra z komputerem\n2): gra z przeciwnikiem\n", SPEED);
	int tmp;
	printf("\n\n");
	this->typing_animation("WYBOR: ",SPEED);
	std::cin >> tmp;
	while (tmp != 1 && tmp != 2) {
		system("cls");
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		printf("\n\n\n\n\n\n\n\n\n");
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		this->typing_animation("Wybierz tryb gry:", SPEED);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		this->typing_animation("\n1)Gra z komputerem\n2)Gra z przeciwnikiem\n", SPEED);
		printf("\n\n");
		this->typing_animation("WYBOR: ", SPEED);
		std::cin >> tmp;
	}
	this->choice = tmp;
}

void players::communication_with_user() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (choice == 1) {
		std::cin.clear();
		printf("\n\n\n\n\n\n\n            ");
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		this->typing_animation("Wybrales tryb gry z komputerem.\n\n", SPEED);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		printf("\n      ");
		this->typing_animation("Kolory zostana wybrane losowo. Powodzenia!\n", SPEED);
	}
	if (choice == 2) {
		std::cin.clear();
		printf("\n\n\n          ");
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		this->typing_animation("Wybrales tryb gry z przeciwnikiem.\n\n\n\n", SPEED);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		this->typing_animation("Podaj nick GRACZA 1:\n", SPEED);
		std::cin >> this->player1;
		putchar('\n');
		this->typing_animation("Podaj nick GRACZA 2:\n", SPEED);
		std::cin >> this->player2;
		putchar('\n');
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	printf("\n\n\n\n                               ");
	this->pause_system();
	this->choice = choice;;
}

//geters
char* players::get_player1() {
	return this->player1;
}
char* players::get_player2() {
	return this->player2;
}
int players::get_choice() {
	return this->choice;
}
int players::get_pointsPlayer1() {
	return this->pointsPlayer1;
}
int players::get_pointsPlayer2() {
	return this->pointsPlayer2;
}
//seters

void players::set_pointsPlayer1(int points) {
	this->pointsPlayer1 += points;
};
void players:: set_pointsPlayer2(int points) {
	this->pointsPlayer2 += points;
};