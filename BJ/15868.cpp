// 15868 치킨 배달
// 조합 사용 위해 일부 코드 참고

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



// input = 입력받는 도시 정보
// N = 도시 크기, M = 최대 치킨집
// dist = 도시의 치킨 거리
int input, N, M, dist = 10000;
int house[100][2];						// 집의 위치를 저장
int chicken[13][2];						// 치킨집 위치 저장
vector<int> num, temp;					// M개의 치킨집을 고를 때 사용



// 최소 치킨거리를 구하는 함수
// h_index = 집 개수
// c_index = 치킨집 개수
void shortest(int h_index, int c_index) {

	// 치킨집 수에 대한 벡터
	for (int i = 0; i < c_index; i++) {
		num.push_back(i);
		if (i < M) { temp.push_back(0); }		// 조합을 위해  
		else { temp.push_back(1); }				// ( nCk --> k만큼 0추가 --> 후에 if문으로  값이 0일 때만 특정동작 실행 ) 
	}											// https://twpower.github.io/90-combination-by-using-next_permutation


	int d;	// 치킨거리 계산을 위한 변수


	// 모든 조합에 대해
	do {
		cout << "=====================================" << endl;

		// 각 조합에 대한 치킨거리 더할 변수 
		int sum = 0;

		// 각 집에 대해
		for (int h = 0; h < h_index; h++) {
			int result = 10000;
			for (int i = 0; i < temp.size(); i++) {

				// 고른 치킨집들과의 거리 계산
				if (temp[i] == 0) {

					// 예) num = {0, 1, 2, 3} / temp = {0, 1, 1, 0} 일 때,
					// temp[i] == 0일 때의 num[i] = 0 or 3
					// 즉 0번째 치킨집과 3번째 치킨집을 뜻함

					int n = num[i];
					d = abs(house[h][0] - chicken[n][0]) + abs(house[h][1] - chicken[n][1]);
					result = min(result, d);				// 가장 가까운 치킨집과의 거리
				}
			}
			cout << h << "번집의 최소 치킨 거리 : " << result << endl;
			sum += result;
		}

		// 현재 치킨집 조합에 대한 거리와 
		// 역대 최소 치킨거리 비교
		dist = min(dist, sum);
		cout << "현재 최소 치킨 거리 : " << dist << endl;

	} while (next_permutation(temp.begin(), temp.end()));

	return;
}


// 메인
int main() {
	int h_index = 0, c_index = 0;
	cin >> N >> M;

	// 각 줄에 대해
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;

			// 집에 대한 정보일 때
			if (input == 1) {
				house[h_index][0] = i;				// 좌표 저장
				house[h_index][1] = j;
				h_index++;
			}

			// 치킨집에 대한 정보일 때
			else if (input == 2) {
				chicken[c_index][0] = i;			// 좌표 저장
				chicken[c_index][1] = j;
				c_index++;
			}
		}
	}
	cout << "집 개수 : " << h_index << endl;
	cout << "치킨집 개수 : " << c_index << endl;
	shortest(h_index, c_index);

	// 최소 치킨 거리 출력
	cout << dist;
}