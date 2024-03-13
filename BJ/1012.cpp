// 1012 ����� ����

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
	// �����¿�
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//�ε��� �ȳѰ�
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		// ���߰� �ִµ� �湮���� �ʾ�����
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

		memset(arr, 0, sizeof(arr));				//�ʱ�ȭ
		memset(visited, 0, sizeof(visited));		//�ʱ�ȭ

		int worm = 0;

		// ���߰� �����ϸ� 1
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		// ��� �迭 Ž��
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				//������� ����(no �湮) ���� -> ������ �߰�
				//����� ���� -> ����
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
