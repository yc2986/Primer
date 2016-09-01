#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data data1, data2;
	double price = 0;
	cout << "Enter the first book's ISBN, copies sold, price per book" << endl;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	cout << "Enter the second book's ISBN, copies sold, price per book" << endl;
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	/*
	 * print out sum of two sales data object
	 */
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		cout << data1.bookNo << " " << totalCnt
			 << " " << totalRevenue << " ";
		if (totalCnt != 0)
			cout << totalRevenue / totalCnt << endl;
		else
			cout << "(no sales)" << endl;
		return 0;
	}
	else {
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;
	}
}