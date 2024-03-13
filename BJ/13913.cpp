// 13913 ���ٲ���4

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// ���� ��ġ, �̵��� ��ġ -> ���� ����
// ===> ���Ŀ� ��θ� �� �� �ְ�


int nx, N, K, s;
int dx[3] = { 2,-1,1 };
int visited[100001] = { 0 };
vector<pair<int, int>> v;

bool isInside(int nx) {
	return (nx >= 0 && nx <= 100000 && visited[nx] != 1);
}

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
				if (isInside(nx)) {
					q.push(pair<int, int>(y + 1, nx));	// 1�� �� ������ġ = nx
					visited[nx] = 1;

					// ��� ����
					v.push_back(pair<int, int>(x, nx));
					if (x == nx) {
						s = y + 1;
						return;
					}
				}
			}
			else {
				nx = x + dx[i];
				if (isInside(nx)) {
					q.push(pair<int, int>(y + 1, nx));	// 1�� �� ������ġ = nx
					visited[nx] = 1;

					// ��� ����
					v.push_back(pair<int, int>(x, nx));
					if (x == nx) {
						s = y + 1;
						return;
					}
				}
			}
		}
	}
}

int main() {
	stack<int> st;
	cin >> N >> K;

	// ���� ó��
	// 1) �����̰� �ڿ� ���� �� -> ���� ���길 �����ϹǷ� 
	if (N > K) {
		cout << N - K << '\n';
		for (int i = 0; i <= N - K; i++) {
			cout << N - i << ' ';
		}
	}
	// 2) ������ 0, ���� 1�� �� 
	else if (N == 0 && K == 1) {
		cout << 1 << '\n' << 0 << ' ' << 1;
	}
	// �� �ΰ��� ��찡 �ƴϸ� BFS ����
	else {
		BFS(N);
		int m = K;
		int i = v.size() - 1;
		cout << s << '\n';

		// ���ÿ� �ִܰ�� ����
		while (m != N && i >= 0) {
			if (v[i - 1].second == m) {
				m = v[i - 1].first;
				st.push(v[i - 1].second);
				i = i - 1;
			}
			else { i -= 1; }
		}

		cout << N << ' ';
		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
	}
}
