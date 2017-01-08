#include <Scope.h>
#include <iostream>

int main() {
    Scope::Type num = 2.0;
    Type context = " executed";
    Scope foo;
    std::cout << "Global scope: " << foo.setVal(context) << std::endl;
    std::cout << "Class scope:  " << foo.setVal(num) << std::endl;
    return 0;
}