// #include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <regex>

#include "./divide_and_conquer.h"

using namespace std;

char RandomDNA() {
	int temp = rand()%5;
	switch(temp) {
		case 0:
			return 'A';
		case 1:
			return 'C';
		case 2:
			return 'G';
		case 3:
			return 'T';

		/* Covers errors and case 4 */
		default:
			return ' ';
	}
}

int main(int argc, char* argv[]) {
	int DNA_string_length = 3;
	string str1(DNA_string_length, 'x'), str2(DNA_string_length, 'o');

	string arg_str= "";
	for (int i = 1; i < argc; i++) arg_str.append(string(argv[i]).append(" "));

	smatch regMatch;
	if (regex_search(arg_str, regMatch, regex(".*\\-n (\\d+).*"))) {
		DNA_string_length = stoi(regMatch[1]);
		str1.resize(DNA_string_length, 'x');
		str2.resize(DNA_string_length, 'o');
	}

	// cout << str1 << endl << str2 << endl;

	generate(str1.begin(), str1.end(), RandomDNA);
	generate(str2.begin(), str2.end(), RandomDNA);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << "DNA length: " << DNA_string_length << endl;

	if (regex_search(arg_str, regMatch, regex(".*\\-divcon.*"))) {
		DivCon divcon(str1, str2);
		// cout << "Divide and Conquer Optimal Path Cost: " << divcon.run() << endl;
		int temp = divcon.run();
		cout << "Divide and Conquer Optimal Path Cost: " << temp << endl;

	}
	// if (regex_search(arg_str, regMatch, regex(".*\\-n (\\d+).*"))) {
	// 	DNA_string_length = stoi(regMatch[1]);
	// }

	return 0;
}

















