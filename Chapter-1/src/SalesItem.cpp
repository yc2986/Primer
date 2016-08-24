#include <iostream>
#include "SalesItem.h"

using namespace std;

Sales_item::Sales_item() {
	this->ISBN 			= "X-XXX-XXXXX-X";
	this->copies_sold 	= 0;
	this->average_price = 0;
}

Sales_item::Sales_item(string isbn, int copy, float price) {
	this->ISBN 			= isbn;
	this->copies_sold	= copy;
	this->average_price = price;
}

Sales_item::Sales_item(Sales_item &item) {
	this->ISBN 			= item.ISBN;
	this->copies_sold	= item.copies_sold;
	this->average_price = item.average_price;
}

Sales_item::~Sales_item() {}

void Sales_item::setISBN(string isbn) {
	this->ISBN 			= isbn;
}

void Sales_item::setCopy(int copy) {
	copy = (copy >= 0) ? copy : 0;
	this->copies_sold 	= copy;
}

void Sales_item::setPrice(float price) {
	price = (price >= 0) ? price : 0;
	this->average_price = price;
}

string Sales_item::getISBN() {
	return this->ISBN;
}

int Sales_item::getCopy() {
	return this->copies_sold;
}

float Sales_item::getPrice() {
	return this->average_price;
}

Sales_item & Sales_item::operator=(const Sales_item &item) {
	this->ISBN 			= item.ISBN;
	this->copies_sold	= item.copies_sold;
	this->average_price = item.average_price;
	return *this;
}

Sales_item & Sales_item::operator+=(const Sales_item &item) {
	if (this->ISBN != item.ISBN) {
		cout << "Could not plus two different book!" << endl;
		return *this;
	}
	this->average_price = this->average_price * this->copies_sold \
						+ item.average_price  * item.copies_sold;
	this->copies_sold 	+= item.copies_sold;
	this->average_price /= this->copies_sold;
	return *this;
}

Sales_item Sales_item::operator+(const Sales_item &item) {
	Sales_item sum = *this;		// Make a copy of self
	sum += item;				// Use += operator
	return sum;
}

bool Sales_item::operator==(const Sales_item &item) {
	return (this->ISBN == item.ISBN);
}

bool Sales_item::operator!=(const Sales_item &item) {
	return (this->ISBN != item.ISBN);
}

ostream & operator<< (ostream &os, const Sales_item &item) {
	os << "ISBN:          " << item.ISBN << endl;
	os << "Copies Sold:   " << item.copies_sold << endl;
	os << "Average Price: " << item.average_price << endl;
	return os;
}

istream & operator>> (istream &is, Sales_item &item) {
	cout << "Enter ISBN: "; flush(cout);
	is >> item.ISBN;
	cout << "Entere copies sold: "; flush(cout);
	is >> item.copies_sold;
	cout << "Enter average price: "; flush(cout);
	is >> item.average_price;
	cout << endl;
	return is;
}