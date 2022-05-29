#include"base.h"
#include "board.h"
#include "modeSelection.h"


int main(void) {
	HANDLE hOut;                              //need for 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //colors
	players p;
	int tmp = 1;
	int tmp2 = 0;
	int tmp_player = 1; 
	int counter = 1; //count rounds
	p.intro();
	system("cls");
	p.mode_selection();
	system("cls");
	p.communication_with_user();
	putchar('\n');
	do {
		if (p.get_choice() == 1) {
			system("cls");
			SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE);
			p.setFontSize(65);
			printf("\n\n\n\n\n\n\n");
			std::string tmps ="                      RUNDA ";
			tmps += std::to_string(counter);
			tmps += "                         ";
			p.typing_animation(tmps, 40);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			printf("\n\n\n\n\n\n\n\n                          ");
			Sleep(1500);
			std::cin.clear();
			p.pause_system();
			system("cls");
			p.setFontSize(30);
			p.drawing_and_save_colours();
			int tmp = p.print_board_final_version(10,4);
			counter++;
		}
		else {
			if (tmp_player == 1) {
				system("cls");
				SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE);
				p.setFontSize(65);
				printf("\n\n\n\n\n\n\n");
				std::string tmps = "                      RUNDA ";
				tmps += std::to_string(counter);
				tmps += "                         ";
				p.typing_animation(tmps, 40);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				printf("\n\n\n\n\n\n\n\n                          ");
				Sleep(1500);
				std::cin.clear();
				p.pause_system();
				system("cls");
				p.setFontSize(30);
				p.typing_animation("Rozgrywke rozpoczyna Gracz1.\n", SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
				p.typing_animation(p.get_player1(), SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				p.typing_animation(" wybiera ulozenie kolorow. Wybrane kolory pojawia sie na kosoli i znikna po 3 sekundach\n", SPEED);		
				p.available_colors();
				putchar('\n');
				p.colors_by_player();
				system("CLS");
				p.typing_animation("Twoje kolory to: ",SPEED);
				p.print_colors_chose_by_player();
				fflush(stdout); /* force a write(2) to output the string to the terminal */
				sleep_for(nanoseconds(3));
				sleep_until(system_clock::now() + seconds(4));
				printf("\r\033[K");
				p.typing_animation("Czas zaczac rozgrywke! ",SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
				p.typing_animation(p.get_player2(), SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				p.typing_animation(" powodzenia!\n", SPEED);
				int result = p.print_board_final_version(10, 4);
				tmp_player = 2;
				p.set_pointsPlayer1(result);
				std::cout << "Punkty: " << p.get_player1() << ": " << p.get_pointsPlayer1() << ", " << p.get_player2() << ": " << p.get_pointsPlayer2() << std::endl;
				counter++;
			}
			else {
				system("cls");
				system("cls");
				p.setFontSize(30);
				p.typing_animation("Rozgrywke rozpoczyna Gracz2.\n",SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
				p.typing_animation(p.get_player2(), SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				p.typing_animation(" wybiera ulozenie kolorow. Wybrane kolory pojawia sie na kosoli i znikna po 4 sekundach\n",SPEED);				
				p.available_colors();
				putchar('\n');
				p.colors_by_player();
				system("CLS");
				p.typing_animation("Twoje kolory to: ", SPEED);
				p.print_colors_chose_by_player();
				fflush(stdout); /* force a write(2) to output the string to the terminal */
				sleep_for(nanoseconds(3));
				sleep_until(system_clock::now() + seconds(4));
				printf("\r\033[K");
				p.typing_animation("Czas zaczac rozgrywke! ", SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
				p.typing_animation(p.get_player1(), SPEED);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				p.typing_animation(" powodzenia!\n", SPEED);
				int result = p.print_board_final_version(10, 4);
				tmp_player = 1;
				p.set_pointsPlayer2(result);
				std::cout << "Punkty: " << p.get_player1() << ": " << p.get_pointsPlayer1() << ", " << p.get_player2() << ": " << p.get_pointsPlayer2() << std::endl;
				counter++;
			}
		}
		printf("Jesli chcesz kontynuwoac wcisnij 1: ");
		std::cin >> tmp;
	} while (tmp == 1);
}