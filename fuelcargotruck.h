#pragma once
#include"cargotruck.h"
#include "heavyproduct.h"
class fuelcargo :public cargo {
	int fuel;
public:
	fuelcargo();
	fuelcargo(int ep, int mdl, int maxcap, int pwr, string pnumber, int s,string t);
	void setfuel(int f) {
		fuel = f;
	}
	int getfuel() {
		return fuel;
	}
	void load_products(heavyproduct obj[]);
	bool operator <(fuelcargo &obj);
	bool operator ==(fuelcargo &obj);
	void operator [](heavyproduct &obj);
	void operator ()(heavyproduct &obj);
	void remove_products(heavyproduct del);
	void writetofile();
	void readfromfile();
	~fuelcargo() {
	
	}
	virtual void spawn_truck(board &obj);
};