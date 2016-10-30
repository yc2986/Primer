#include <iostream>
#include <string>
#include <vector>

struct Account {
	std::string id;
	Account(const std::string &i) : id(i) {}
};

struct Phone {
	std::string phone;
	Phone(const std::string &p) : phone(p) {}
};

struct Name {
	std::string name;
	Name(const std::string &n) : name(n) {}
};

struct Record {
	Account account;
	Phone phone;
	Name name;
	Record(const std::string &a, const std::string &p, const std::string &n)
	:	account(Account(a))
	,	phone(Phone(p))
	,	name(Name(n)) {}
};

Record lookup(const Account&, const std::vector<Record>&);
Record lookup(const Phone&, const std::vector<Record>&);
Record lookup(const Name&, const std::vector<Record>&);

const std::string &shorterString(const std::string &s1, const std::string &s2);
std::string &shorterString(std::string &s1, std::string &s2);	// overload because reference and reference of const object are two different types

int main() {
	std::vector<Record> records = {
		Record("001", "111-111-1111", "Bulbasaur"),
		Record("002", "111-111-1112", "Ivysaur"),
		Record("003", "111-111-1113", "Venusaur"),
		Record("004", "111-111-1114", "Charmander"),
		Record("005", "111-111-1115", "Charmeleon"),
		Record("006", "111-111-1116", "Charizard"),
		Record("007", "111-111-1117", "Squirtle"),
		Record("008", "111-111-1118", "Wartortle"),
		Record("009", "111-111-1119", "Blastoise")
	};
	auto Bulb = lookup(Account("001"), records);
	auto Char = lookup(Phone("111-111-1115"), records);
	auto Blas = lookup(Name("Blastoise"), records);

	std::cout << "lookup by account: id = " << Bulb.account.id << ", phone = " <<  Bulb.phone.phone << ", name = " << Bulb.name.name << std::endl;
	std::cout << "lookup by account: id = " << Char.account.id << ", phone = " <<  Char.phone.phone << ", name = " << Char.name.name << std::endl;
	std::cout << "lookup by account: id = " << Blas.account.id << ", phone = " <<  Blas.phone.phone << ", name = " << Blas.name.name << std::endl;
	const std::string const_long = "I am long string", const_short = "short string";
	std::string longer = "I am long string", shorter = "short string";
	auto const_shorter = shorterString(const_long, const_short);
	auto non_const_shorter = shorterString(longer, shorter);
	std::cout << "shorter const string: " << const_shorter << std::endl;
	std::cout << "shorter string: " << non_const_shorter << std::endl;
	return 0;
}

Record lookup(const Account &account, const std::vector<Record> &records) {
	for (auto &rec : records)
		if (account.id == rec.account.id)
			return rec;
}

Record lookup(const Phone &phone, const std::vector<Record> &records) {
	for (auto &rec : records)
		if (phone.phone == rec.phone.phone)
			return rec;
}

Record lookup(const Name &name, const std::vector<Record> &records) {
	for (auto &rec : records)
		if (name.name == rec.name.name)
			return rec;
}

const std::string &shorterString(const std::string &s1, const std::string &s2) {
	return (s1.size() <= s2.size()) ? s1 : s2;
}

std::string &shorterString(std::string &s1, std::string &s2) {
	auto &r = shorterString(const_cast<const std::string&>(s1), const_cast<const std::string&>(s2));
	return const_cast<std::string&>(r);
}