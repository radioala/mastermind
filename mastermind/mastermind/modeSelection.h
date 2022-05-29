#ifndef MODESELECTION
#define MODESELECTION
#define _CRT_SECURE_NO_WARNINGS
#define SPEED 30

#include "board.h"
#include "base.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <windows.h>


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class players: public board{
protected:
	char player1[50];
	int pointsPlayer1;
	char player2[50];
	int pointsPlayer2;
	int choice;
public:
	//constuorts
	players() {
		strcpy(this->player1, "GRACZ 1");
		strcpy(this->player2, "GRACZ 2");
		this->choice = 1;
		this->pointsPlayer1 = 0;
		this->pointsPlayer2 = 0;
	}
	//players(char player1[], char player2[], int choice, int ) {
	//	strcpy(this->player1, player1);
	//	strcpy(this->player2, player2);
	//	this->choice = choice;
	//}
	//players(players &p) {
	//	strcpy(this->player1, p.player1);
	//	strcpy(this->player2, p.player2);
	//	this->choice = p.choice;
	//}
	//functions
	void mode_selection();
	void communication_with_user();
	//geters
	char* get_player1();
	char* get_player2();
	int get_choice();
	int get_pointsPlayer1();
	int get_pointsPlayer2();
	//seters
	void set_pointsPlayer1(int points);
	void set_pointsPlayer2(int points);
};
#endif

