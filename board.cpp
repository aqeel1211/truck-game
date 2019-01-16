#include "board.h"
#include "truck.h"
#include "cargotruck.h"
#include <iostream>
#include "chillertruck.h"
#include "electriccargotruck.h"
#include "fuelcargotruck.h"
using namespace std;
board::board()
{
	row = 36;
	col = 51;
	currentrow = 0;
	currentcol = 0;
	arr = new char*[row];
	for (int i = 0; i < col; i++) {
		arr[i] = new char[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(arr + i) + j) = ' ';
		}
	}

}

board::board(int r, int c)
{
	row = r;
	col = c;
	arr = new char*[row];
	for (int i = 0; i < col; i++) {
		arr[i] = new char[col];
	}

}

void board::place_truck(int row, int col, int sign)
{
	*(*(arr + row) + col) = sign;
}

void board::create_board()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i % 6 == 0 && j % 10 == 0) {
				*(*(arr + i) + j) = 219;
			}
			else {
				*(*(arr + i) + j) = ' ';
			}
		}
	}
}

void board::spawn_alltrucks(board & obj)
{
	create_board();
	truck *c, *ch, *ec, *fc;
	c = new cargo;
	ch = new chiller;
	ec = new electriccargo;
	fc = new fuelcargo;
	c->spawn_truck(obj);
	move_cargo(obj, 43);
	ch->spawn_truck(obj);
	move_chiller(obj, 35);
	ec->spawn_truck(obj);

	fc->spawn_truck(obj);
}

void board::display_board(/*board &obj*/)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << *(*(arr + i) + j);
		}
		cout << endl;
	}
}

void board::move_cargo(board &obj, int sign)
{
	//truck *t;
	Sleep(1000);
	arr[obj.getcurrentrow()][obj.getcurrentcol()] = ' ';
	/*if (GetAsyncKeyState(VK_DOWN)) {*/
	int checkcol = 0;
	int check = 1;
	int check1 = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (check != 0) {
				Sleep(200);
				system("cls");
				setcurrentrow(obj.getcurrentrow() - 1);
				place_truck(obj.getcurrentrow(), obj.getcurrentcol(), sign);
				display_board();
				checkcol = 0;
				if (getcurrentrow() == 0) {
					checkcol++;
					check = 0;
					setcurrentcol(getcurrentcol() + 1);
				}
			}

			else if (checkcol == 1) {
				Sleep(200);
				system("cls");
				setcurrentrow(getcurrentrow() + 1);
				//	checkcol = getcurrentcol();
				place_truck(getcurrentrow(), getcurrentcol(), sign);
				display_board();
				check = 0;
			}
		}
	}
}

void board::move_chiller(board & obj, int sign)
{
	Sleep(1000);
	arr[obj.getcurrentrow()][obj.getcurrentcol()] = ' ';
	/*if (GetAsyncKeyState(VK_DOWN)) {*/
	int checkcol = 0;
	int check = 1;
	int check1 = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (check != 0) {
				Sleep(200);
				system("cls");
				setcurrentcol(obj.getcurrentcol() +1);
				place_truck(obj.getcurrentrow(), obj.getcurrentcol(), sign);
				display_board();
				checkcol = 0;
				if (getcurrentrow() == 0) {
					checkcol++;
					check = 0;
					setcurrentcol(getcurrentcol() + 1);
				}
			}

			else if (checkcol == 1) {
				Sleep(200);
				system("cls");
				setcurrentcol(obj.getcurrentcol() - 1);

				//	checkcol = getcurrentcol();
				place_truck(getcurrentrow(), getcurrentcol(), sign);
				display_board();
				check = 0;
			}
		}
	}
}
