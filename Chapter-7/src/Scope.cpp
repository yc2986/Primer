#include <Scope.h>

// Type = std::string, global scope
Type initVal() {
    return "initial commit";
}

// Type = double
Scope::Type Scope::setVal(Scope::Type param) {
    this->val = param + this->initVal();
    return this->val;
}

::Type Scope::setVal(::Type &param) {
    ::Type ret = ::initVal() + param;
    return ret;
}

Scope::Type Scope::initVal() {
    return 1;
}