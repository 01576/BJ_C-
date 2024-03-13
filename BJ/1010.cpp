// 1010 다리놓기

#include <iostream>
using namespace std;

int T, N, M;
long long p, s;

long long f1(int N, int M) {
	p = M;
	if (N == 1) {
		return p;
	}
	else {
		return M * f1(N - 1, M - 1);

	}
}

long long f2(int N) {
	p = 1;
	if (N == 1) {
		return p;
	}
	else {
		return N * f2(N - 1);

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		if (N == M) { cout << 1 << '\n'; }
		else if (N > M - N) {
			cout << f1(M - N, M) / f2(M - N) << '\n';
		}
		else {
			cout << f1(N, M) / f2(N) << '\n';
		}
	}
}