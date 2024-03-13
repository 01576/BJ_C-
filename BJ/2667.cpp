// 2667 단지번호붙이기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string s;
int k = 0, N, apart[26][26], visited[26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void DFS(int x, int y) {
	k++;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && apart[nx][ny] == 1 && visited[nx][ny] == 0) {
			DFS(nx, ny);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			apart[i][j] = s[j] - '0';
			visited[i][j] = 0;
		}
	}
	vector<int> danji;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (apart[i][j] == 1 && visited[i][j] == 0) {
				DFS(i, j);
				danji.push_back(k);
				k = 0;
			}
		}
	}
	sort(danji.begin(), danji.end());
	cout << danji.size() << '\n';
	for (int i = 0; i < danji.size(); i++) {
		cout << danji[i] << '\n';
	}
}
