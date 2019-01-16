#pragma once
#include <string>
#include "board.h"
using namespace std;
class truck{
	int model, power;
	const int maximumcapacity;
	string platenumber;
public:
	truck();
	truck(int mdl, int maxcap, int pwr, string pnumber);
	void setmodel(int mdl) {
		model = mdl;
	}
	void setpower(int pwr) {
		power = pwr;
	}
	void setplatenumber(string pnumber) {
		platenumber = pnumber;
	}
	int getmodel() {
		return model;
	}
	int getmaximumcapacity() {
		return maximumcapacity;
	}
	string getplatenumber() {
		return platenumber;
	}
	int getpower() {
		return power;
	}
	void writetofile();
	void readfromfile();
	virtual void spawn_truck(board &obj)=0;
	//virtual void move_truck(board &obj) = 0;
	//virtual void move_truck1(board &obj) = 0;
};