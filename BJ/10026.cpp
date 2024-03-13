// 10026 적록색약

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Red : 빨간 구역의 수		| Green : 초록 구역의 수
// Blue : 파란 구역의 수	| RandG: 빨+초 합쳐진 구역의 수
int N, Red = 0, Green = 0, Blue = 0, RandG = 0;
vector<string> area;
int Rvisited[101][101], Gvisited[101][101],
Bvisited[101][101], RGvisited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isRorG(int i, int j) {
	return (area[i][j] == 'R' || area[i][j] == 'G');
}

bool isR(int i, int j) {
	return area[i][j] == 'R';
}

bool isG(int i, int j) {
	return area[i][j] == 'G';
}

bool isB(int i, int j) {
	return area[i][j] == 'B';
}

// 적록색약일 때
void DFS_RG(int x, int y) {
	RGvisited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < N && ny < N && nx >= 0 && ny >= 0 && isRorG(nx, ny) && RGvisited[nx][ny] != 1) {
			DFS_RG(nx, ny);
		}
	}
}

// 빨간 구역
void DFS_R(int x, int y) {
	Rvisited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < N && ny < N && nx >= 0 && ny >= 0 && isR(nx, ny) && Rvisited[nx][ny] != 1) {
			DFS_R(nx, ny);
		}
	}
}

// 초록 구역
void DFS_G(int x, int y) {
	Gvisited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < N && ny < N && nx >= 0 && ny >= 0 && isG(nx, ny) && Gvisited[nx][ny] != 1) {
			DFS_G(nx, ny);
		}
	}
}

// 파란 구역
void DFS_B(int x, int y) {
	Bvisited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < N && ny < N && nx >= 0 && ny >= 0 && isB(nx, ny) && Bvisited[nx][ny] != 1) {
			DFS_B(nx, ny);
		}
	}
}

int main() {
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		area.push_back(s);
	}

	// 초기화
	memset(RGvisited, 0, sizeof(RGvisited));
	memset(Rvisited, 0, sizeof(Rvisited));
	memset(Gvisited, 0, sizeof(Gvisited));
	memset(Bvisited, 0, sizeof(Bvisited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isRorG(i, j) && RGvisited[i][j] != 1) {
				DFS_RG(i, j);
				RandG++;
			}
			if (isR(i, j) && Rvisited[i][j] != 1) {
				DFS_R(i, j);
				Red++;
			}
			if (isG(i, j) && Gvisited[i][j] != 1) {
				DFS_G(i, j);
				Green++;
			}
			if (isB(i, j) && Bvisited[i][j] != 1) {
				DFS_B(i, j);
				Blue++;
			}
		}
	}
	cout << Red + Green + Blue << ' ' << RandG + Blue << '\n';
}