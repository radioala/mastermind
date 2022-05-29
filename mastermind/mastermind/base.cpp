#include "base.h"


void base::text(const std::string& text) {

	std::string string_blueprint = "";
	for (int i = 0; i < text.length(); i++) {
		string_blueprint += text[i];
		std::cout << string_blueprint;
		system("cls");
		Sleep(10);
	}
	std::cout << string_blueprint;
}

void base::scrollbar_remover() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD get_size = {
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, get_size);
}

void base::setFontSize(int FontSize) {
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize;
	//info.FontWeight = FW_BOLD;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}


void base::typing_animation(const std::string& s,int speed) {
	int x = 0;
	while (s[x] != '\0')
	{
		std::cout << s[x];
		Sleep(speed);
		x++;
	};
}

void base::pause_system() {
	std::cout << "Press Enter to continue...";
	while (std::cin.get() != '\n');
}

/*Wypisuje mozliwe kolory do wyboru
*/
void base::available_colors() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	this->typing_animation("Mozliwe kolory do wyboru: \n", 25);
	printf("0");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("%c ", 254);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	printf("1");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("%c ", 254);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	printf("2");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("%c ", 254);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	printf("3");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("%c ", 254);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	printf("4");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("%c ", 254);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	printf("5");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("%c ", 254);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

}
void base::intro() {
	int speed_slow = 75;
	int speed = 25;
	this->setFontSize(60);
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	this->scrollbar_remover();
	printf("\n\n\n\n\n\n\n                 ");
	this->typing_animation("Witaj w grze ",80);
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	this->typing_animation("M",speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	this->typing_animation("A", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	this->typing_animation("S", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	this->typing_animation("T", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	this->typing_animation("E", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	this->typing_animation("R", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	this->typing_animation("M", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	this->typing_animation("I", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	this->typing_animation("N", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	this->typing_animation("D", speed_slow);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	std::cin.clear();
	printf("\n\n\n\n\n\n\n\n\n\n                              ");
	this->pause_system();
	system("cls");
	printf("\n\n\n\n\n\n       ");
	this->typing_animation("Jesli chcesz pominac instrukcje wcisnij 1.\n",speed);
	printf("       ");
	this->typing_animation("Jesli nie, wcisnij jakikolwiek inny klawisz\n", speed);
	printf("\n       ");
	this->typing_animation("Wybor: ",speed);
	char a;
	std::cin >> a;
	system("cls");
	if (a != '1') {
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::string rules;
		printf("                     ");
		this->typing_animation("Jak grac?\n\n\n\n", speed);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		this->typing_animation("Gra gra polega na odgadnieciu przez gracza ciagu kolorow wybranego przez przeciwnika lub losowo przez komputer.\n\n",speed);
		this->available_colors();
		this->typing_animation("\nKolory wybiera sie za pomoca cyfr od 0 do 5.\n\n",speed);
		this->typing_animation("Plansza kolorow bedzie wypelniala sie automatycznie.\nObok pojawi sie plansza z oznaczeniami\n",speed);
		printf("\n\n\n\n                              ");
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		this->pause_system();
		system("cls");
		printf("\n\n\n                     ");
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		this->typing_animation("Oznaczenia:\n\n", speed);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("%c", 2);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		rules = "-ten znak oznacza, ze podales poprawany kolor i stoi on na wlasciwym miesjcu\n\n", 2;
		typing_animation(rules, speed);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("%c", 2);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		rules = "-ten znak oznacza, ze kolor, ktory podales wystepuje w\nszukanym ciagu, ale nie na wlasciwym miejscu\n";
		typing_animation(rules, speed);
		printf("\n\n\n\n\n\n\n                              ");
		this->pause_system();
	}
}
