#pragma once

using namespace std;

/* Dynamic Programming */
class DynPro {
private:
	
	int str1_len;	// m
	int str2_len;	// n
	// int str1_index; // i
	// int str2_index; // j
	vector<vector<int>> opt_matrix;

	void build_matrix();

public:
	string str1;	// x
	string str2;	// y
	unsigned long long int basic_ops = 0;
	int opt_cost = 0;

	DynPro() {}
	DynPro(string _str1, string _str2) 
		: str1(_str1), str2(_str2), str1_len(_str1.length()), str2_len(_str2.length()) {
			opt_matrix.resize(str1_len + 1, vector<int>(str2_len + 1, 0));
			for (auto row : opt_matrix)
				row.resize(str2_len + 1, 0);
		}
	~DynPro() {}

	void run() {
		build_matrix();
		opt_cost = opt_matrix[0][0];

		/* Uncomment to print matrix */
		// for (int i = 0; i < opt_matrix.size(); i++) {
		// 	for (int j = 0; j < opt_matrix[0].size(); j++)
		// 		cout << '\t' << opt_matrix[i][j];
		// 	cout << endl;
		// }
	}
};

void DynPro::build_matrix() {

	/* Populate bottom row */
	for (int i = opt_matrix[0].size() - 2; i >= 0; i--) {
		basic_ops++;
		opt_matrix[opt_matrix.size() - 1][i] = 2 * (opt_matrix[0].size() - 1 - i);
	}

	/* Populate right column */
	for (int j = opt_matrix.size() - 2; j >= 0; j--) {
		basic_ops++;
		opt_matrix[j][opt_matrix[0].size() - 1] = 2 * (opt_matrix.size() - 1 - j);
	}

	/* Fill the rest */
	for (int i = opt_matrix.size() - 2; i >= 0; i--) {
		for (int j = opt_matrix[0].size() - 2; j >= 0; j--) {
			int penalty = 0;
			if (str1[i] != str2[j])
				penalty = 1;

			basic_ops++;
			opt_matrix[i][j] = min({opt_matrix[i + 1][j + 1] + penalty,
									opt_matrix[i + 1][j] + 2,
									opt_matrix[i][j + 1] + 2});
		}
	}	
}











