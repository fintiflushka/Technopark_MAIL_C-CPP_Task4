#include <iostream>
using namespace std;


class Product {
	char* name;
	char* producer;
	double cost;
	unsigned life; 
	unsigned count;
public:
	Product();
	explicit Product(unsigned life): life(life) {};
	Product(const char* name, const char* producer, double cost, unsigned life, unsigned count);
	Product(const Product& p);
	~Product();
	void* set_all(const char* name, const char* producer, double cost, unsigned life, unsigned count);
	void* set_name(const char* name);
	void* set_producer(const char* producer);
	void* set_cost(unsigned cost);
	void* set_life(unsigned life);
	void* set_count(unsigned count);
	const char* get_name();
	const char* get_producer();
	unsigned get_cost();
	unsigned get_life();
	unsigned get_count();
	void show();
};