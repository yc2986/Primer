#include <string>

/** 
 * an aggregate class requires: 
 *       all class member to be public
 *       no defined constructor
 *       no in-class initializer
 *       no virtual method                
 */
struct Aggregate {
    int number;
    std::string name;
};

/**
 * a literal class can be:
 *       1. an aggregate class with all member as constexpr
 *       2. a non-aggregate class meet these conditions:
 *            ~ data members are all constexpr
 *            ~ must have at least one constexpr constructor
 *            ~ constexpr initializer for member's in class initiliztion
 *            ~ must use default destructor
 */
class Debug {
public:
    /**
     * constexpr constructor should be:
     *     1. no return statement
     *     2. can only have one return statement
     *     3. 1+2 means empty function body
     *     4. must initialize all data member
     */    
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() const { return this->hw || this->io || this->other; }
    void set_hw(bool b) { this->hw = b; }
    void set_io(bool b) { this->io = b; }
    void set_other(bool b) { this->other = b; }
private:
    bool hw;    //!< hardware error
    bool io;    //!< io error
    bool other; //!< other error
};