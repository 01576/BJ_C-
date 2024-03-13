// 1920 ¼ö Ã£±â

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, a, x, mid;
int arr[1000000];

void findx(int x, int low, int high) {
	while (low <= high) {
		mid = (low + high) / 2;
		if (x == arr[mid]) { cout << 1 << '\n'; return; }
		else if (x < arr[mid]) {
			high = mid - 1;
		}
		else if (x > arr[mid]) {
			low = mid + 1;
		}
	}
	cout << 0 << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		int low = 0, high = N - 1;
		findx(x, low, high);
	}
}