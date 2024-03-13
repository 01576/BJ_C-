// 1697 ���ٲ���

#include <iostream>
#include <queue>
using namespace std;

int nx, N, K, s;
int dx[3] = { 1,-1,2 };
int visited[100000] = { 0 };

void BFS(int start) {

	// (��, ���� ��ġ)
	queue<pair<int, int>> q;
	q.push(pair<int, int>(0, start));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		visited[start] = 1;

		// ������ ��ġ = ���� ��ġ���
		if (x == K) {
			s = y;
			return;
		}

		// 3���� ���꿡 ����
		for (int i = 0; i < 3; i++) {
			// ���ϱ��� ��
			if (dx[i] == 2) {
				nx = x * dx[i];
				if (nx <= 100000 && nx >= 0 && visited[nx] != 1) {
					q.push(pair<int, int>(y + 1, nx));	// 1�� �� ������ġ = nx
					visited[nx] = 1;
				}
			}
			else {
				nx = x + dx[i];
				if (nx <= 100000 && nx >= 0 && visited[nx] != 1) {
					q.push(pair<int, int>(y + 1, nx));	// 1�� �� ������ġ = nx
					visited[nx] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;
	BFS(N);
	cout << s << '\n';
}