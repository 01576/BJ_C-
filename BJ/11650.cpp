// 11650 좌표 정렬하기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, x, y;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
}