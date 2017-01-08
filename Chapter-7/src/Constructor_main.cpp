#include <Constructor.h>

int main() {
    std::cout << "[default constructor]" << std::endl;
    Constructor foo0;
    std::cout << std::endl;

    std::cout << "[input constructor]" << std::endl;
    Constructor foo1(std::cin);
    std::cout << std::endl;

    std::cout << "[parameter constructor]" << std::endl;
    Constructor foo2("xx-xxx-xxxx", 5, 10);
    std::cout << std::endl;

    return 0;
}