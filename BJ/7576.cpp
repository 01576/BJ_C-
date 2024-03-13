// 7576 토마토
// 코드 참고

#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000];
int M, N, result = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

bool IsInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < N&& ny < M);
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (IsInside(ny, nx) == 1 && tomato[nx][ny] == 0) {
				tomato[nx][ny] = tomato[x][y] + 1;
				q.push(pair<int, int>(nx, ny));
			}
		}
	}
}

int main() {
	int T;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> T;
			tomato[i][j] = T;
			if (T == 1) {
				q.push(pair<int, int>(i, j));
			}
		}
	}

	BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				cout << "-1" << '\n';
				return 0;
			}
			if (result < tomato[i][j]) { result = tomato[i][j] - 1; }
		}
	}
	cout << result << '\n';
}
