#include <Special.h>
#include <iostream>

void Aggregate_class() {
    Aggregate anna = { 0, "Anna" };
    Aggregate bob  = { 1, "Bob"};
    std::cout << "No: " << anna.number << ", Name: " << anna.name << std::endl;
    std::cout << "No: " << bob.number << ", Name: " << bob.name << std::endl;
}

void Literal_class() {
    constexpr Debug io_sub(false, true, false);    // debug IO
    if (io_sub.any())
        std::cerr << "IO error occur" << std::endl;
    constexpr Debug prod(false);
    if (prod.any())
        std::cerr << "cannot be reached here!" << std::endl;
}

int main() {
    std::cout << "[aggregate]" << std::endl;
    Aggregate_class();
    std::cout << std::endl;

    std::cout << "[literal]" << std::endl;
    Literal_class();
    std::cout << std::endl;

    return 0;
}