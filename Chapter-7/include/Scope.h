#ifndef SCOPE_H
#define SCOPE_H

#include <string>

using Type = std::string;
Type initval();

class Scope {
public:
    using Type = double;
public:
    Type setVal(Type);
    ::Type setVal(::Type&);
    Type initVal();
private:
    int val;
};

#endif