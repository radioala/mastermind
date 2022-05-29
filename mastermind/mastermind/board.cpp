#include "board.h"
/*Funckja wczytuje kolory(liczby calkowite od 0 do 5) od uzytkownika. Przeprowadza kontrole poprawnosci wproawdzanych danych
*/
void board::read_colors() {
	this->typing_animation("Wbierz kolor: cyfry od 0 do 5\n", SPEEDBOARD);
	int tmp[4];
std::cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
	validation_control(tmp);
	for (int i = 0; i < 4; i++) {
		this->colors_pick_by_the_player[i] = tmp[i];
	}
}

/*kontorla poprawnosci kolorow
*/
void board::validation_control(int tmp[4]) {
	for (int i = 0; i < 4; i++) {
		while (tmp[i] != 0 && tmp[i] != 1 && tmp[i] != 2 && tmp[i] != 3 && tmp[i] != 4 && tmp[i] != 5) {
			this->typing_animation("Podales zle dane! Popraw je.\n", SPEEDBOARD);
			this->available_colors();
			putchar('\n');
			this->typing_animation("Wbierz kolor: cyfry od 0 do 5\n", SPEEDBOARD);
			std::cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
			i = 0;
		}
	}

}

/*Losuje kolory z 6, kolory moga sie powtarzac.
*/
void board::drawing_and_save_colours() {
	for (int i = 0; i < 4; ++i) {
		this->computer_colors[i] = rand() % 6;
	}
}

void board::colors_by_player() {
	int tmp[4];
	std::cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
	validation_control(tmp);
	for (int i = 0; i < 4; i++) {
		this->computer_colors[i] = tmp[i];
	}
}

void board::print_colors_chose_by_player() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {//filoletowy
		if (this->computer_colors[i] == 0) {
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->computer_colors[i] == 1) {//zielony
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->computer_colors[i] == 2) {//niebieski
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->computer_colors[i] == 3) { //zloty
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->computer_colors[i] == 4) { //czerwony
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->computer_colors[i] == 5) { //seledynowy
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (i != 3) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			putchar('|');
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}

void board::pick_and_save_colours() {
	this->typing_animation("Wbierz kolor: cyfry od 0 do 5\n", SPEEDBOARD);
	int tmp[4];
	std::cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
	validation_control(tmp);
	for (int i = 0; i < 4; i++) {
		this->colors_pick_by_the_player[i] = tmp[i];
	}
}

/*Funckaj sprawdza czy kolory podane przez uzytkownika zgadzaja sie z poprawna wersja.
 -jesli kolor jest wlasciwy i na wlasciwym miesjuc do tablicy intow (last_guesses) w klasie board wpsiuje 0
 -jesli kolor jest wlasciwy, ale nie na wlasciwym miesjuc do tablicy intow (last_guesses) w klasie board wpsiuje 1
 -jesli kolor jest nie wlasciwy do tablicy intow (last_guesses) w klasie board wpsiuje 2
 */
void board::colors_verification() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {
		if (this->colors_pick_by_the_player[0] == this->computer_colors[i] || this->colors_pick_by_the_player[1] == this->computer_colors[i] || this->colors_pick_by_the_player[2] == this->computer_colors[i] || this->colors_pick_by_the_player[3] == this->computer_colors[i]) {
			if (this->colors_pick_by_the_player[i] == this->computer_colors[i]) {
				this->last_guesses[i] = 0; //dobre miejsce dobyr kolor
			}
			else this->last_guesses[i] = 1; //dobry kolor zle miejsce
		}
		else this->last_guesses[i] = 2;
	}
}
/*Funckja sprawdza czy uzytkownik zgad³ poprawna wersje, jesli tak konczy petle
*/
int board::check_if_right() {
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		if (this->last_guesses[i] == 0)
			tmp++;
		else break;
	}
	return tmp;
}
/*Funkcja wypisuje na konsoli znaki ostatniego zgadywania przez uzytkownika
bialy- jesli wlasciwy kolor jest na wlasicywm miejscu
seledynowy- jesli wlasciwy kolor nie jest na wlasciwym miesjcu
*/
void board::print_last_guesses() {
	int tmp = 0;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {
		if (this->last_guesses[i] == 1) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("%c", 2);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			tmp++;
		}
		else if (this->last_guesses[i] == 0) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // srebrny
			printf("%c", 2);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			tmp++;
		}
	}
	for (int i = 0; i < 7 - tmp; i++) {
		printf(" ");
	}
}
/*Funckja wypisuje na konsoli kolory wybrane przez uzytkownika
*/
void board::print_colors_player() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {//filoletowy
		if (this->colors_pick_by_the_player[i] == 0) {
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->colors_pick_by_the_player[i] == 1) {//zielony
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->colors_pick_by_the_player[i] == 2) {//niebieski
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->colors_pick_by_the_player[i] == 3) { //zloty
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->colors_pick_by_the_player[i] == 4) { //czerwony
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->colors_pick_by_the_player[i] == 5) { //seledynowy
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (i != 3) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			putchar('|');
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}
/*Funkcja wypisuje na konsoli 4 biale kwadraty
*/
void board::print_white_player() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {
		putchar(254);
		putchar('|');
	}

}
/*Funkcja wypisuje na konsoli znaki wszystkich oprocz ostatniego zgadywania przez uzytkownika
bialy- jesli wlasciwy kolor jest na wlasicywm miejscu
seledynowy- jesli wlasciwy kolor nie jest na wlasciwym miesjcu
*/
void board::print_colors_from_board_guesses(int i) {
	int tmp = 0;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 0; j < 4; j++) {
		if (this->board_guesses_colors[i][j] == 0) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("%c", 2);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			tmp++;
		}

		else if (this->board_guesses_colors[i][j] == 1) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("%c", 2);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			tmp++;
		}
	}
	for (int i = 0; i < 7 - tmp; i++) {
		printf(" ");
	}
}
/*Funkcja wypisuje na konsoli poprzednie ruchy uzytkownika
*/
void board::print_colors_from_board(int i) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 0; j < 4; j++) {
		if (this->board_save_colors[i][j] == 0) {
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->board_save_colors[i][j] == 1) {//zielony
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->board_save_colors[i][j] == 2) {//niebieski
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->board_save_colors[i][j] == 3) { //zloty
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->board_save_colors[i][j] == 4) { //czerwony
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (this->board_save_colors[i][j] == 5) { //seledynowy
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			putchar(254);
		}
		if (j != 3) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			putchar('|');
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}

/*Funckja wypisuje na konsoli ostateczna wersje planszy. Wypisuje kolory (ostatnio wprowadzone przez uzytkownika jak i poprzednie)
 oraz przeprowadze sprawdzanie zgodnosci kolorow z wersja poprawna. Wypisuje znaki swiadczace o poprawnosci zgadywanych kolorow (zarowno ostatnio wprowadzone przez uzytkownika jak i poprzednie)
@param lenght- dlugosc planszy
@param width- szerokosc planszy
*/
int board::print_board_final_version(int lenght, int width) {
	int result =0;
	for (int k = 0; k < lenght; k++) {
		this->available_colors();
		putchar('\n');
		this->read_colors();
		this->colors_verification();
		putchar('\n');
		printf("|");
		for (int i = 0; i < lenght; ++i) {
			if (i % lenght == 0) {
				for (int j = 0; j < width * 4 - 1; j++) {
					if (j == 7) {
						printf("|");
					}
					else printf("-");
				}
				printf("|\n|");
			}
			for (int j = 0; j < 2 * width - 3; ++j) {
				if (j == 0 && i <= k) {
					if (i == k) {
						this->print_colors_player();
						putchar('|');
						this->print_last_guesses();
					}
					else {
						this->print_colors_from_board(i);
						putchar('|');
						this->print_colors_from_board_guesses(i);
					}
				}
				else if (j == 0) {
					this->print_white_player();
					printf("       ");
				}

			}
			printf("|\n|");

		}
		for (int j = 0; j < width * 4 - 1; j++) {
			if (j == 7) {
				printf("|");
			}
			else printf("-");
		}
		int tmp = this->check_if_right();
		if (tmp == 4) {
			printf("\nZGADLES!!");
			result = 1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			this->board_save_colors[k][i] = this->colors_pick_by_the_player[i];
		}
		for (int i = 0; i < 4; i++) {
			this->board_guesses_colors[k][i] = this->last_guesses[i];
		}
		printf("|\n\n");
	}
	return result;
}