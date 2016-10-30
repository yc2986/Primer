#include <iostream>
#include <string>
#include <cassert>

#ifndef NDEBUG
#	define DEBUG_STDOUT(x) (std::cout << (x) << std::endl)
#else
#	define DEBUG_STDOUT(x)
#endif

static std::string screen(const unsigned height = 5, const unsigned width = 5, const char background = '*');	// default arguments

inline const std::string &shorterString(const std::string &s1, const std::string &s2) {	// inline function
	return (s1 < s2) ? s1 : s2;
}

constexpr unsigned fixed_size() { return 3; }	// can only return constexpr for constexpr declared function
constexpr unsigned scale(const unsigned s) { return fixed_size() * s; }	// s can only be constexpr variable, otherwise compile time error

static void assertShorter(const std::string &s1, const std::string &s2);	// assert if s1.size() >= s2.size()

int main() {
	std::cout << screen() << std::endl;
	std::cout << screen(3) << std::endl;
	std::cout << screen(5, 10, 'o') << std::endl;
	std::cout << shorterString(screen(5, 5), screen(5, 4)) << std::endl;
	std::cout << shorterString(screen(fixed_size(), scale(2)), screen(fixed_size(), scale(3))) << std::endl;
	assertShorter(screen(3), screen());	// will not run if compile with -DNDEBUG flag
	assertShorter(screen(), screen(3));	// will not run if compile with -DNDEBUG flag
	return 0;
}

std::string screen(const unsigned height, const unsigned width, const char background) {
	std::string Row = std::string(width, background) + "\n";
	std::string Window;
	for (unsigned row = 0; row < height; row++)
		Window += Row;
	return Window;
}

void assertShorter(const std::string &s1, const std::string &s2) {
	assert(s1.size() < s2.size());	// assert if condition evaluated to be false
	DEBUG_STDOUT("No Assertion!");
}