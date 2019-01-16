#pragma once
#include"product.h"

class heavyproduct :public product {
	int weight;
public:
	heavyproduct();
	heavyproduct(int w, int id, int p, string cat, string bnd);
	void setweight(int w) {
		weight = w;
	}
	int getweight() {
		return weight;
	}
	void take_productinfo();
	~ heavyproduct(){}
};