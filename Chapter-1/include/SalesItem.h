#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <string>

using namespace std;

class Sales_item {
private:
	string 	ISBN;
	int 	copies_sold;
	float 	average_price;
public:
	/* Constructor */
	Sales_item();
	Sales_item(string isbn, int copy, float price);
	Sales_item(Sales_item &item);
	/* Destructor */
	~Sales_item();
	/* Setter */
	void setISBN(string isbn);
	void setCopy(int copy);
	void setPrice(float price);
	/* Getter */
	string getISBN();
	int getCopy();
	float getPrice();
	/* Operator overload */
	Sales_item & operator=  	(const Sales_item &item);				// =
	Sales_item & operator+= 	(const Sales_item &item);				// +=
	Sales_item operator+ 		(const Sales_item &item);				// +
	bool operator==				(const Sales_item &item);				// ==
	bool operator!=				(const Sales_item &item);				// !=
	friend ostream & operator<< (ostream &os, const Sales_item &item);	// <<
	friend istream & operator>> (istream &is, Sales_item &item);		// >>	
};

#endif