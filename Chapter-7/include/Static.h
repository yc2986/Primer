#include <string>

class Account {
public:
    inline void calculate() { this->amount += this->amount * this->interestRate; }
    inline static double rate() { return interestRate; }
    inline static void rate(const double newRate) { interestRate = newRate; }
private:
    std::string owner;
    double amount;
    static double interestRate;
    inline static double initRate() { return 0.1; }
    static Account account;    //!< static member can have incomplete type
    Account *account_ptr;    //!< pointer member can have incomplete type
    //Account acc;    //!< illegal...
};

// static member initialization
double Account::interestRate = initRate();