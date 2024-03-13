// 1931 ȸ�ǽ� ����

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
		// ���� ȸ�ǰ� �������ڸ��� ������..
		if (dur_u == 0) {
			use.push_back(meeting[i]);
			j++;
		}
		// ���� ȸ�ǰ� �������ڸ��� ������
		else if (dur_m == 0 && use[j].second <= meeting[i].first) {
			use.push_back(meeting[i]);
			j++;
		}
		// ���۽ð��� ������ ȸ�� �ð��� �� ª����
		else if (use[j].first == meeting[i].first && dur_u > dur_m) {
			use.pop_back();
			use.push_back(meeting[i]);
		}
		// ���۽ð��� �����ε� �����½ð��� �� �����϶�
		else if (use[j].first <= meeting[i].first && use[j].second >= meeting[i].second) {
			use.pop_back();
			use.push_back(meeting[i]);
		}
		// ������� ȸ���� ������ �ð����� ���۽ð��� �����̸�
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
