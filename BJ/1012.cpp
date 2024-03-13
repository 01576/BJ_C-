// 1012 유기농 배추

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int M, N, K;
int arr[50][50] = { 0 };
int visited[50][50] = { 0 };

void DFS(int x, int y) {
	// 상하좌우
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//인덱스 안넘게
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		// 배추가 있는데 방문하지 않았을때
		if (arr[nx][ny] && !visited[nx][ny]) {
			visited[nx][ny]++;
			DFS(nx, ny);
		}
	}
}



int main() {
	int T, X, Y;
	cin >> T;
	for (int tr = 0; tr < T; tr++) {
		cin >> M >> N >> K;

		memset(arr, 0, sizeof(arr));				//초기화
		memset(visited, 0, sizeof(visited));		//초기화

		int worm = 0;

		// 배추가 존재하면 1
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		// 모든 배열 탐색
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				//연결되지 않은(no 방문) 배추 -> 지렁이 추가
				//연결된 배추 -> 제외
				if (arr[i][j] && !visited[i][j]) {
					worm++;
					visited[i][j]++;
					DFS(i, j);
				}
			}
		}
		cout << worm << '\n';
	}
}
