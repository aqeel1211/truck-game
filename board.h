#pragma once
#include <Windows.h>
#include <conio.h>
class board {
	int row;
	int col,currentrow,currentcol;
	char **arr;
public:
	board();
	board(int r, int c);
	void setrow(int r) {
		row = r;
	}
	void setcol(int c) {
		col = c;
	}
	void setcurrentcol(int c) {
		currentcol = c;
	}
	void setcurrentrow(int r) {
		currentrow = r;
	}
	int getcurrentrow() {
		return currentrow;
	}
	int getcurrentcol() {
		return currentcol;
	}
	int getrow() {
		return row;
	}
	int getcol() {
		return col;
	}
	void setboard(char **r) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				(*(*(arr + i) + j)) = (*(*(r + i) + j));
			}
		}
	}
	char **getboard() {
		return arr;
	}
	void place_truck(int row, int col, int sign);
	void create_board();
	void spawn_alltrucks(board &obj);
	void display_board(/*board &obj*/);
	void move_cargo(board &obj,int sign);
	void move_chiller(board &obj, int sign);
};