#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "product.h"
using namespace std;


#define PRODUCT_COUNT 10


bool compare(const char* s_1, const char* s_2);
int c_strtoint(const char*);


int main (int argc, char* argv[]) {

	if (argc < 4) {
		cerr << "Недостаточно аргументов командной строки ";
		return 0;
	}

	Product prod = 5.4;
	prod.show();

	char str_1[] = "Продукт";
	char str_2[] = "Производитель";

	Product p[PRODUCT_COUNT];

	for(int i; i < PRODUCT_COUNT; i += 2) {
		p[i].set_all(str_1, str_2, rand() % 10000 + 1, rand() % 31 + 1, rand() % 100 + 1);
	} 


	cout << "POINT 1:" << endl; 
	for(int i; i < PRODUCT_COUNT; i ++) {
			if (compare(p[i].get_name(), argv[1])) {
				p[i].show();
			}
	}



	unsigned cost = c_strtoint(argv[2]);
	cout << "POINT 2:" << endl; 
	for(int i; i < PRODUCT_COUNT; i ++) {
		if (compare(p[i].get_name(), argv[1]) && p[i].get_cost() <= cost) {
			p[i].show();
		}
	}

	unsigned life = c_strtoint(argv[3]);
	cout << "POINT 3:" << endl; 
	for(int i; i < PRODUCT_COUNT; i ++) {
		if (p[i].get_life() > life) {
			p[i].show();
		}
	}

	return 0;
}


bool compare(const char* s_1, const char* s_2) {
	string ns_1;
	string ns_2;

	if (s_1 && s_2) {
		ns_1 = string(s_1);
		ns_2 = string(s_2);
		if (ns_1 == ns_2) {
			return true;
		}
	}

	return false;
}


int c_strtoint(const char* str) {
	int num;
	istringstream ist(str);
	ist >> num;

	return num;
}