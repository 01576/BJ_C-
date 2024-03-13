// 6603 ·Î¶Ç

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void lotto(int k, vector<int> v) {
	vector<int> select;
	for (int i = 0; i < k; i++) {
		if (i < 6) { select.push_back(0); }
		else { select.push_back(1); }
	}
	do {
		for (int i = 0; i < k; i++) {
			if (select[i] == 0) {
				cout << v[i] << " ";
			}
		}
		cout << '\n';
	} while (next_permutation(select.begin(), select.end()));
}

int main() {
	int k, S;
	cin >> k;
	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> S;
			v.push_back(S);
		}
		lotto(k, v);
		cout << '\n';
		for (int i = 0; i < k; i++) {
			v.pop_back();
		}
		cin >> k;
	}
}