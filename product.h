#pragma once
#include <string>
using namespace std;
class product {
	int id, price;
	string category, brand;
	
public:
	product();
	product(int id, int p, string cat, string bnd);
	void setid(int id) {
		this->id = id;
	}
	void setprice(int p) {
		price = p;
	}
	void setcategory(string cat) {
		category = cat;
	}
	void setbrand(string bnd) {
		brand = bnd;
	}
	
	int getid() {
		return id;
	}
	int getprice() {
		return price;
	}
	string getcategory() {
		return category;
	}
	string getbrand() {
		return brand;
	}
	void take_productinfo();
	~ product(){
	}
};