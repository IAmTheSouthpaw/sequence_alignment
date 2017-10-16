#pragma once

using namespace std;

/* Divide and Conquer */
class DivCon {
private:
	string str1;	// x
	string str2;	// y
	int str1_len;	// m
	int str2_len;	// n
	// int str1_index; // i
	// int str2_index; // j
	//time_t
	int opt(int str1_index, int str2_index);

public:
	int basic_ops;
	int opt_cost;

	DivCon(string _str1, string _str2) 
		: str1(_str1), str2(_str2), str1_len(_str1.length()), str2_len(_str2.length()), basic_ops(0) {}
	~DivCon() {}

	int run() {
		opt_cost = opt(0, 0);
		cout << endl;
		return opt_cost;
	}
};

int DivCon::opt(int str1_index, int str2_index) {
	cout << '\t' << ((str1_index != 0) ? str1.substr(0, str1_index) : "") << '[' << str1[str1_index] << ']' << ((str1_index != str1_len) ? str1.substr(str1_index + 1) : "") << '\t' << str1_index << endl;
	cout << '\t' << ((str2_index != 0) ? str2.substr(0, str2_index) : "") << '[' << str2[str2_index] << ']' << ((str2_index != str2_len) ? str2.substr(str2_index + 1) : "") << '\t' << str2_index << endl;

	int cost = 0;

	if (str1_index == str1_len)
		cost = 2 * (str2_len - str2_index);
		// return 2 * (str2_len - str2_index);
	else if (str2_index == str2_len)
		cost = 2 * (str1_len - str1_index);
		// return 2 * (str1_len - str1_index);

	else {
		int penalty = 0;
		if (str1[str1_index] != str2[str2_index])
			penalty = 1;

		// return min({opt(str1_index + 1, str2_index + 1) + penalty,
		cost = min({opt(str1_index + 1, str2_index + 1) + penalty,
					opt(str1_index + 1, str2_index) + 2,
					opt(str1_index, str2_index + 1) + 2});
	}

	cout << "\t\t\tCost:" << cost << endl;
	return cost;
}











