#pragma once
#include"cargotruck.h"
#include "heavyproduct.h"
class electriccargo :public cargo {
	int electricplates;
public:
	electriccargo();
	electriccargo(int ep, int mdl, int maxcap, int pwr, string pnumber, int s,string t);
	void setelectricplates(int ep) {
		electricplates = ep;
	}
	int getelectricplates() {
		return electricplates;
	}
	void load_products(heavyproduct obj[]);
	bool operator <(electriccargo &obj);
	bool operator ==(electriccargo &obj);
	void operator [](heavyproduct &obj);
	void operator ()(heavyproduct &obj);
	void remove_products(heavyproduct del);
	void writetofile();
	void readfromfile();
	~electriccargo() {

	}
	virtual void spawn_truck(board &obj);
	//virtual void move_truck(board &obj);
};