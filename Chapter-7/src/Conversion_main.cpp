#include <Sales_data.h>
#include <Constructor.h>
#include <iostream>
#include <string>

void implicit_conversion() {
    std::cout << "[implicit conversion]" << std::endl;
    std::string null_book = "9-999-99999-9";
    Sales_data item("0-112-10234-3", 2, 10);
    item.combine(null_book);    // valid since Sales_data has a string value constructor
    item.combine(std::cin);     // valid
    //item.combine("9-999-99999-9");    // invalid since double conversion is illegal
}

void explicit_conversion() {
    std::cout << "[explicit conversion]" << std::endl;
    std::string null_book = "9-999-99999-9";
    Constructor item("0-112-10234-3", 2, 10);
    //item.combine(null_book);    // illegal because constructor is declared explict. No implicit conversion
    item.combine(Constructor(null_book));
    item.combine(static_cast<Constructor>(std::cin));
}

int main() {
    implicit_conversion();
    explicit_conversion();
    return 0;
}