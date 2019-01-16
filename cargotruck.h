#pragma once
#include"truck.h"
#include"heavyproduct.h"
#include"board.h"
class cargo:public truck {
	heavyproduct *hparray;
	int size;
	string type;
public:
	cargo();
	cargo(int mdl, int maxcap, int pwr, string pnumber, int s,string type);
	void copy_products(heavyproduct obj[]);
	void load_products(heavyproduct obj[]);
	void setsize(int s) {
		size = s;
	}
	int getsize() {
		return size;
	}
	void settype(string s) {
		type = s;
	}
	string gettype() {
		return type;
	}
	heavyproduct* gethparray() {
		return hparray;
	}
	void writetofile();
	void readfromfile();
	void display();
	bool operator <(cargo &obj);
	bool operator ==(cargo &obj);
	void operator [](heavyproduct &obj);
	void operator ()(heavyproduct &obj);
	void remove_products(heavyproduct del);
	virtual void spawn_truck(board &obj);
	//virtual void move_truck(board &obj);
	~cargo() {
		delete[] hparray;
	}
};