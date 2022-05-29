#ifndef BASE
#define BASE

#include<iostream>
#include <string>
#include<cstdlib>
#include <windows.h>
#include<stdio.h>
#include <conio.h>
#include<time.h>
#include<memory> //for sleep()

class base {
public:
	void text(const std::string& text);
	void scrollbar_remover();
	void setFontSize(int FontSize);
	void intro();
	void typing_animation(const std::string& s, int speed);
	void pause_system();
	void available_colors();
};


#endif
#pragma once
