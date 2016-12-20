#include <Sales_data.h>

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &item) {
    this->units_sold    += item.units_sold;     // note: member function can access
    this->revenue       += item.revenue;        //       private member of any instance
    return *this;
}

double Sales_data::avg_price() const {
    if (this->units_sold)
        return this->revenue / this->units_sold;
    else
        return 0;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2) {
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}