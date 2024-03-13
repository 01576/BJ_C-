// 1931 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, start_t, end_t, dur_u, dur_m;
vector<pair<int, int>> meeting;
vector<pair<int, int>> use;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start_t >> end_t;
		meeting.push_back(pair<int, int>(start_t, end_t));
	}
	sort(meeting.begin(), meeting.end());
	use.push_back(meeting[0]);

	int j = 0;
	for (int i = 1; i < N; i++) {
		dur_u = use[j].second - use[j].first;
		dur_m = meeting[i].second - meeting[i].first;
		// 이전 회의가 시작하자마자 끝나면..
		if (dur_u == 0) {
			use.push_back(meeting[i]);
			j++;
		}
		// 다음 회의가 시작하자마자 끝나면
		else if (dur_m == 0 && use[j].second <= meeting[i].first) {
			use.push_back(meeting[i]);
			j++;
		}
		// 시작시간이 같은데 회의 시간이 더 짧으면
		else if (use[j].first == meeting[i].first && dur_u > dur_m) {
			use.pop_back();
			use.push_back(meeting[i]);
		}
		// 시작시간은 이후인데 끝나는시간이 더 이전일때
		else if (use[j].first <= meeting[i].first && use[j].second >= meeting[i].second) {
			use.pop_back();
			use.push_back(meeting[i]);
		}
		// 사용중인 회의의 끝나는 시간보다 시작시간이 이후이면
		else if (use[j].second <= meeting[i].first) {
			use.push_back(meeting[i]);
			j++;
		}

	}

	for (int i = 0; i < use.size(); i++) {
		cout << use[i].first << " - " << use[i].second << '\n';
	}
	cout << use.size() << '\n';
}
