#pragma once
#include"product.h"

class coldproduct :public product {
	int temperature,weight;
public:
	coldproduct();
	coldproduct(int temp, int w, int id, int p, string cat, string bnd);
	void settemperature(int temp) {
		temperature = temp;
	}
	int gettemperature() {
		return temperature;
	}
	void setweight(int w) {
		weight = w;
	}
	int getweight() {
		return weight;
	}
	void take_productinfo();
	~ coldproduct(){}
};