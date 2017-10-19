// #include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <regex>
#include <locale>

#include "./divide_and_conquer.h"
#include "./dynamic_programming.h"

using namespace std;

char RandomDNA() {
	int temp = rand()%4;
	switch(temp) {
		case 0:
			return 'A';
		case 1:
			return 'C';
		case 2:
			return 'G';

		/* Covers errors and case 4 */
		default:
			return 'T';
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		string worker = "\n\tUsage: \
						\n\t\t-n <#> \t\tMakes first random DNA sequence of length #, while second sequence is randomly shorter \
						\n\t\t-divcon \tDivide and Conquer via Algorith 3.12 \
						\n\t\t-dynpro \tDynamic Programming";
		cout << worker << endl << endl;
		return 0;
	}


	int DNA_string_length = 10;
	string str1, str2;

	string arg_str= "";
	for (int i = 1; i < argc; i++) arg_str.append(string(argv[i]).append(" "));

	smatch regMatch;
	if (regex_search(arg_str, regMatch, regex(".*\\-n (\\d+).*"))) {
		DNA_string_length = stoi(regMatch[1]);
	}

	/* Generate DNA sequences */
	str1.resize(DNA_string_length, 'x');
	str2.resize((DNA_string_length/2 + rand()%DNA_string_length/2), 'o');
	generate(str1.begin(), str1.end(), RandomDNA);
	generate(str2.begin(), str2.end(), RandomDNA);

	// str1 = "AACAGTTACC";	// To compare against the book
	// str2 = "TAAGGTCA";

	cout << endl;
	cout << "DNA Sequence 1: " << str1 << endl;
	cout << "DNA Sequence 2: " << str2 << endl << endl;
	cout.imbue(locale(""));

	if (regex_search(arg_str, regMatch, regex(".*\\-table.*"))) {
		cout << "Divide and Conquer:" << endl;
		for (int i = 1; i <= DNA_string_length; i++) {
			str1.resize(i, 'x');
			// str2.resize((i/2 + rand()%i/2), 'o');
			str2.resize(i, 'o');
			generate(str1.begin(), str1.end(), RandomDNA);
			generate(str2.begin(), str2.end(), RandomDNA);

			DivCon divcon(str1, str2);
			divcon.run();
			cout << "\tSeq Length: \t" << str1.size() << "\t\tBasic Ops: \t" << divcon.basic_ops << endl;
		}

		cout << "\nDynamic Programming:" << endl;
		for (int i = 1; i <= DNA_string_length; i++) {
			str1.resize(i, 'x');
			// str2.resize((i/2 + rand()%i/2), 'o');
			str2.resize(i, 'o');
			generate(str1.begin(), str1.end(), RandomDNA);
			generate(str2.begin(), str2.end(), RandomDNA);

			DynPro dynpro(str1, str2);
			dynpro.run();
			cout << "\tSeq Length: \t" << str1.size() << "\t\tBasic Ops: \t" << dynpro.basic_ops << endl;
		}


	}
	else {
		/* Determine which methods to run */
		if (regex_search(arg_str, regMatch, regex(".*\\-divcon.*"))) {
			DivCon divcon(str1, str2);
			divcon.run();

			cout << "Divide and Conquer Basic Operations: " << divcon.basic_ops << endl;
			cout << "Divide and Conquer Optimal Path Cost: " << divcon.opt_cost << endl << endl;

		}
		if (regex_search(arg_str, regMatch, regex(".*\\-dynpro.*"))) {
			DynPro dynpro(str1, str2);
			dynpro.run();

			cout << "Dynamic Programming Basic Operations: " << dynpro.basic_ops << endl;		
			cout << "Dynamic Programming Optimal Path Cost: " << dynpro.opt_cost << endl << endl;
		}
	}

	cout << endl;
	return 0;
}

















