#include "heavyproduct.h"
#include <iostream>
using namespace std;
heavyproduct::heavyproduct()
{
	weight = 0;
}

heavyproduct::heavyproduct(int w, int id, int p, string cat, string bnd):product(id,p,cat,bnd)
{
	weight = w;
}

void heavyproduct::take_productinfo()
{
	product::take_productinfo();
	int w;
	cout << "enter weight " << endl;
	cin >> w;
	setweight(w);
}
