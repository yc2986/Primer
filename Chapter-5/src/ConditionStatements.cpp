#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

static void ifStatement();
static void switchStatement();

int main() {
	cout << "[conditional statements]" << endl;
	ifStatement();
	cout << endl;

	cout << "[switch statements]" << endl;
	switchStatement();
	return 0;
}

void ifStatement() {
	/**
	 * grading system
	 * F: under 60
	 * D: 60 - 69
	 * C: 70 - 79
	 * B: 80 - 89
	 * A: 90 - 99
	 * A++: 100
	 * for ending with 0, 1, 2 get a "-"
	 * for ending with 8, 9 get a "+"
	 */
	vector<string> grade = {"F", "D", "C", "B", "A", "A++"};
	cout << "please type in the student's score, press CTRL-D to terminate" << endl;
	int score;
	string letterGrade;
	while (cin >> score) {
		if (score < 60)
			letterGrade = grade[0];
		else {
			letterGrade = grade[(score - 50) / 10];
			if (score != 100) {
				if (score % 10 > 7)
					letterGrade += "+";
				else if (score % 10 < 3)	// elsif match to nearest else
					letterGrade += "-";
			}
		}
		cout << "letter grade = " << letterGrade << endl;
	}
}

void switchStatement() {
	string sentence = "Here is the vowel counter program. It will go through this sentence and count the vowel appeared.";
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	for (auto &ch : sentence) {
		switch(ch) {
			case 'a': ++aCnt; break;
			case 'e': ++eCnt; break;
			case 'i': ++iCnt; break;
			case 'o': ++oCnt; break;
			case 'u': ++uCnt; break;
			default :       ; break;	// do nothing for default
		}
	}
	cout << "number of 'a': " << aCnt << endl
		 << "number of 'e': " << eCnt << endl
		 << "number of 'i': " << iCnt << endl
		 << "number of 'o': " << oCnt << endl
		 << "number of 'u': " << uCnt << endl;
}