#pragma once

using namespace std;

/* Divide and Conquer */
class DivCon {
private:
	int str1_len;	// m
	int str2_len;	// n
	// int str1_index; // i
	// int str2_index; // j

	int opt(int str1_index, int str2_index);

public:
	string str1;	// x
	string str2;	// y
	unsigned long long int basic_ops;
	int opt_cost;

	DivCon() {}
	DivCon(string _str1, string _str2) 
		: str1(_str1), str2(_str2), str1_len(_str1.length()), str2_len(_str2.length()), basic_ops(0) {}
	~DivCon() {}

	void run() {
		opt_cost = opt(0, 0);
	}
};

int DivCon::opt(int str1_index, int str2_index) {
	basic_ops++;

	if (str1_index == str1_len)
		return 2 * (str2_len - str2_index);
	else if (str2_index == str2_len)
		return 2 * (str1_len - str1_index);

	else {
		int penalty = 0;
		if (str1[str1_index] != str2[str2_index])
			penalty = 1;

		return min({opt(str1_index + 1, str2_index + 1) + penalty,
					opt(str1_index + 1, str2_index) + 2,
					opt(str1_index, str2_index + 1) + 2});
	}
}












