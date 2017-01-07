/**
 * Sales Data class
 * 
 * Has the following features:
 *     An isbn member function to return the object's isbn
 *     A combine member function to add one Sales_data object into another
 *     A function named add to add two Sales_data objects
 *     A read function to read data from an istream into a Sales_data object
 *     A print function to print the value of a Sales_data on an ostream
 */
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);    //!< all friend methods should be declared out of class once more
friend std::ostream &print(std::ostream&, const Sales_data&);   //!< these are friend declaration rather than method declaration
friend std::istream &read(std::istream&, Sales_data&);
public:
    // constructor
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, 
               unsigned n, 
               double p)
               : bookNo (s)
               , units_sold(n)
               , revenue(n * p) { }
    Sales_data(std::istream &is);
    /**
     * const specifier here stands for this pointer points to a const object
     * this pointer is a const pointer to a const Sales_data object
     */
    std::string isbn() const { return this->bookNo; }
    /**
     * acting as backend for "+=" operator
     * \param item item used to add on
     * \return reference to Sales_data object after adding
     */
    Sales_data& combine(const Sales_data &item);
private:
    std::string bookNo;         //!< isbn book number
    unsigned    units_sold = 0; //!< book unit sold
    double      revenue = 0.0;  //!< sell revenue

    /**
     * average price calculator
     */
    double avg_price() const;
};

/**
 * add function for Sales_data
 * \param item1 first item
 * \param item2 second item
 * \return a copy of added Sales_data object
 */
Sales_data add(const Sales_data &item1, const Sales_data &item2);
/**
 * print function for Sales_data
 * \param os ostream operator
 * \param item Sales_data object
 * \return ostream operator
 */
std::ostream &print(std::ostream &os, const Sales_data &item);
/**
 * read function for Sales_data
 * \param is istream operator
 * \param item target object to hold the read in data
 * \return istream operator
 */
std::istream &read(std::istream &is, Sales_data &item);
#endif