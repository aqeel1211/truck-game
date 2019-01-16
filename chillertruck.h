#pragma once
#include "truck.h"
#include "coldproduct.h"
class chiller :public truck {
	int chillertemperature;
	coldproduct *cparray;
	int size;
public:
	chiller();
	chiller(int ct,int s, int mdl, int maxcap, int pwr, string pnumber);
	void copy_products(coldproduct obj[]);
	void load_products(coldproduct obj[]);
	void setsize(int s) {
		size = s;
	}
	int getsize() {
		return size;
	}
	void setchillertemperature(int temp) {
		chillertemperature = temp;
	}
	int getchillertemperature() {
		return chillertemperature;
	}
	coldproduct* getcparray() {
		return cparray;
	}
	void writetofile();
	void readfromfile();
	bool operator <(chiller &obj);
	bool operator ==(chiller&obj);
	void operator [](coldproduct &obj);
	void operator ()(coldproduct &obj);	
	void remove_products(coldproduct del);
	virtual void spawn_truck(board &obj);
//	virtual void move_truck(board &obj);
	~chiller() {
		delete[] cparray;
	}
};