// 1541 문서 검색

#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, word;
	getline(cin, a);
	getline(cin, word);
	int index = 0, search = 0;

	while (index < a.length()) {
		if (a.find(word, index) == index) {
			search += 1;
			index += word.length();
		}
		else { index++; }
	}
	cout << search;
}