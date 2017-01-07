#include <Sales_data.h>
#include <iostream>

int main() {
    Sales_data total;    // variable to hold the running sum
    if (read(std::cin, total)) {    // read the first transaction
        Sales_data trans;    // variable to hold data for the next transaction
        while(read(std::cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);    // update total
            else {
                print(std::cout, total) << std::endl;    // print result
                total = trans;    // update the running total
            }
        }
        print(std::cout, total) << std::endl;    // print last transaction
    }
    else
        std::cerr << "No data!" << std::endl;
    return 0;
}