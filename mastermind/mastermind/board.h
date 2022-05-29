#ifndef BOARD
#define BOARD
#define SPEEDBOARD 25
#include "base.h"
#include <iostream>
#include <windows.h>


class board:public base {
protected:
    int computer_colors[4];
    int board_guesses_colors[10][4];
    int last_guesses[4];
    int board_save_colors[10][4];
    int result;
    int colors_pick_by_the_player[4];
public:
    //board() {
    //    this->computer_colors[] = {0};
    //    this->board_guesses_colors [10] [4] = { 0 };
    //    this->last_guesses[4] = { 0 };
    //    this->board_save_colors[10][4] = { 0 };
    //    this->result = 0;
    //    this->colors_pick_by_the_player[4] = { 1 };
    //}
    //board(int computer_colors[4], int board_guesses_colors[10][4], int last_guesses[4], int board_save_colors[10][4], int result, int colors_pick_by_the_player[4]) {
    //    this->computer_colors[4] = computer_colors[4];
    //    this->board_guesses_colors[10][4] = board_guesses_colors[10][4];
    //    this->last_guesses[4] = last_guesses[4];
    //    this->board_save_colors[10][4] = board_save_colors[10][4];
    //    this->result = result;
    //    this->colors_pick_by_the_player[4] = colors_pick_by_the_player[4];
    //}
    void read_colors();
    void validation_control(int tmp[4]);
    void print_colors_from_board(int k);
    void drawing_and_save_colours();
    void colors_verification();
    int print_board_final_version(int lenght, int width);
    void print_colors_from_board_guesses(int i);
    int check_if_right();
    void print_white_player();
    void print_colors_player();
    void colors_by_player();
    void print_last_guesses();
    void pick_and_save_colours();
    void print_colors_chose_by_player();
};

#endif
