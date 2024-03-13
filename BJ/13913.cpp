// 13913 숨바꼭질4

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// 현재 위치, 이동할 위치 -> 벡터 저장
// ===> 거쳐온 경로를 알 수 있게


int nx, N, K, s;
int dx[3] = { 2,-1,1 };
int visited[100001] = { 0 };
vector<pair<int, int>> v;

bool isInside(int nx) {
	return (nx >= 0 && nx <= 100000 && visited[nx] != 1);
}

void BFS(int start) {

	// (초, 현재 위치)
	queue<pair<int, int>> q;
	q.push(pair<int, int>(0, start));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		visited[start] = 1;

		// 수빈이 위치 = 동생 위치라면
		if (x == K) {
			s = y;
			return;
		}

		// 3가지 연산에 대해
		for (int i = 0; i < 3; i++) {
			// 곱하기일 때
			if (dx[i] == 2) {
				nx = x * dx[i];
				if (isInside(nx)) {
					q.push(pair<int, int>(y + 1, nx));	// 1초 뒤 수빈위치 = nx
					visited[nx] = 1;

					// 경로 저장
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
					q.push(pair<int, int>(y + 1, nx));	// 1초 뒤 수빈위치 = nx
					visited[nx] = 1;

					// 경로 저장
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

	// 예외 처리
	// 1) 수빈이가 뒤에 있을 때 -> 뺴기 연산만 진행하므로 
	if (N > K) {
		cout << N - K << '\n';
		for (int i = 0; i <= N - K; i++) {
			cout << N - i << ' ';
		}
	}
	// 2) 수빈이 0, 동생 1일 때 
	else if (N == 0 && K == 1) {
		cout << 1 << '\n' << 0 << ' ' << 1;
	}
	// 위 두가지 경우가 아니면 BFS 진행
	else {
		BFS(N);
		int m = K;
		int i = v.size() - 1;
		cout << s << '\n';

		// 스택에 최단경로 저장
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
