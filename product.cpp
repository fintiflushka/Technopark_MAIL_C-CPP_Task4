#include "product.h"
#include <new>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;


Product::Product() {
	name = NULL;
	producer = NULL;
	this->set_all("\0", "\0", 0, 0, 0);
}


Product::Product(const char* name, const char* producer, double cost, unsigned life, unsigned count) {
	try {
		this->name = new char[strlen(name)];
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
		return;
	}

	try {
		this->producer = new char[strlen(producer)];
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
		return;
	}

	this->set_all(name, producer, cost, life, count);
}


Product::Product(const Product& p) {
	this->set_all(p.name, p.producer, p.cost, p.life, p.count);
}


Product::~Product() {
	delete [] name;
	delete [] producer;
}


void* Product::set_all(const char* name, const char* producer, double cost, unsigned life, unsigned count) {
	set_name(name);
	set_producer(producer);
	this->cost = cost;
	this->life = life;
	this->count = count;
}


void* Product::set_name(const char* name) {

	if (name) delete [] this->name;

	try {
		this->name = new char[strlen(name)];
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
		return NULL;
	}

	strcpy(this->name, name);
}


void* Product::set_producer(const char* producer) {

	if (name) delete [] this->producer;

	try {
		this->producer = new char[strlen(producer)];
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
		return NULL;
	}

	strcpy(this->producer, producer);
}


void* Product::set_cost(unsigned cost) {
	this->cost = cost;
}


void* Product::set_life(unsigned life) {
	this->life = life;
}


void* Product::set_count(unsigned count) {
	this->count = count;
}


const char* Product::get_name() {
	return name;
}


const char* Product::get_producer() {
	return producer;
}


unsigned Product::get_cost() {
	return cost;
}


unsigned Product::get_life() {
	return life;
}


unsigned Product::get_count() {
	return count;
}


void Product::show() {	
	if (name) {
		cout << "name:		" << name << endl;
	}
	else {
		cout << "name:		" << "None" << endl;
	}

	if (producer){
		cout << "producer:	" << producer << endl;
	}
	else {
		cout << "producer:	" << "None" << endl;
	}

	cout << "cost:		" << cost << endl;
	cout << "life:		" << life << endl;
	cout << "count:		" << count << endl;
	cout << endl;
}

