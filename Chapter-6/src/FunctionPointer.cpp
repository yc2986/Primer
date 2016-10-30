#include <iostream>
#include <string>

const std::string &select(const std::string &s1, const std::string &s2, const std::string &(*f)(const std::string &, const std::string &));

const std::string &longer(const std::string &s1, const std::string &s2) {
	return (s1.size() > s2.size()) ? s1 : s2;
}

const std::string &shorter(const std::string &s1, const std::string &s2) {
	return (s1.size() < s2.size()) ? s1 : s2;
}

const std::string &bigger(const std::string &s1, const std::string &s2) {
	return (s1 > s2) ? s1 : s2;
}

const std::string &smaller(const std::string &s1, const std::string &s2) {
	return (s1 < s2) ? s1 : s2;
}

int main() {
	std::string s1 = "abcd", s2 = "bcd";
	std::cout << "Longer: " << select(s1, s2, longer) << std::endl;
	std::cout << "Shorter: " << select(s1, s2, shorter) << std::endl;
	std::cout << "Bigger: " << select(s1, s2, bigger) << std::endl;
	std::cout << "Smaller: " << select(s1, s2, smaller) << std::endl;
}

const std::string &select(const std::string &s1, const std::string &s2, const std::string &(*f)(const std::string &, const std::string &)) {
	return f(s1, s2);
}