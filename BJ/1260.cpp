// 1260 DFS와 BFS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool d_visited[1001], b_visited[1001];
vector<int> graph[1001];

// 너비우선
void DFS(int x) {
	d_visited[x] = true;
	cout << x << ' ';
	sort(graph[x].begin(), graph[x].end());

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!d_visited[y]) { DFS(y); }
	}
}

// 깊이우선
void BFS(int start) {
	b_visited[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!b_visited[y]) {
				q.push(y);
				b_visited[y] = true;
			}
		}
	}
}


int main() {
	int N, M, V, f, s;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> f >> s;
		graph[f].push_back(s);
		graph[s].push_back(f);
	}

	DFS(V);
	cout << '\n';
	BFS(V);
	cout << '\n';
}
