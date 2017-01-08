#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <string>
#include <iostream>

class Constructor {
public:
    /**
     * typical constructor with list initialization
     */
    Constructor(std::string s, unsigned cnt, double price)
        : bookNo(s)
        , units_sold(cnt)
        , revenue(cnt * price) {
            std::cout << "[string, unsigned, price]" << std::endl;
        }
    /**
     * default constructor with default value, and use delegate
     */
    explicit Constructor(std::string s = "") : Constructor(s, 0, 0) {
        std::cout << "[string]" << std::endl;
    }
    explicit Constructor(std::istream &is) : Constructor() {
        std::cout << "[istream]" << std::endl;
        double price = 0;
        is >> this->bookNo >> this->units_sold >> price;
        this->revenue = this->units_sold * price;
    }
    void combine(const Constructor &item) {
        std::cout << "[combine]" << std::endl;
    }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

#endif