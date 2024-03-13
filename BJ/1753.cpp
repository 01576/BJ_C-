// 1753 최단경로
// 데이크스트라 공부

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int V, u, v, start, E, w;
vector<pair<int, int>> nodes[20001];
int d[20001];

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;

    pq.push({ 0, s });
    d[s] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist)
            continue;

        for (int i = 0; i < nodes[now].size(); i++)
        {
            int cost = dist + nodes[now][i].second;

            if (cost < d[nodes[now][i].first])
            {
                d[nodes[now][i].first] = cost;
                pq.push(make_pair(-cost, nodes[now][i].first));
            }
        }
    }
}

int main() {
    cin >> V >> E >> start;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        nodes[u].push_back({ v, w });
    }

    for (int i = 0; i <= V; i++) {
        d[i] = INF;
    }
    dijkstra(start);

    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << d[i] << '\n';
        }
    }

}