// 15868 ġŲ ���
// ���� ��� ���� �Ϻ� �ڵ� ����

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



// input = �Է¹޴� ���� ����
// N = ���� ũ��, M = �ִ� ġŲ��
// dist = ������ ġŲ �Ÿ�
int input, N, M, dist = 10000;
int house[100][2];						// ���� ��ġ�� ����
int chicken[13][2];						// ġŲ�� ��ġ ����
vector<int> num, temp;					// M���� ġŲ���� �� �� ���



// �ּ� ġŲ�Ÿ��� ���ϴ� �Լ�
// h_index = �� ����
// c_index = ġŲ�� ����
void shortest(int h_index, int c_index) {

	// ġŲ�� ���� ���� ����
	for (int i = 0; i < c_index; i++) {
		num.push_back(i);
		if (i < M) { temp.push_back(0); }		// ������ ����  
		else { temp.push_back(1); }				// ( nCk --> k��ŭ 0�߰� --> �Ŀ� if������  ���� 0�� ���� Ư������ ���� ) 
	}											// https://twpower.github.io/90-combination-by-using-next_permutation


	int d;	// ġŲ�Ÿ� ����� ���� ����


	// ��� ���տ� ����
	do {
		cout << "=====================================" << endl;

		// �� ���տ� ���� ġŲ�Ÿ� ���� ���� 
		int sum = 0;

		// �� ���� ����
		for (int h = 0; h < h_index; h++) {
			int result = 10000;
			for (int i = 0; i < temp.size(); i++) {

				// �� ġŲ������� �Ÿ� ���
				if (temp[i] == 0) {

					// ��) num = {0, 1, 2, 3} / temp = {0, 1, 1, 0} �� ��,
					// temp[i] == 0�� ���� num[i] = 0 or 3
					// �� 0��° ġŲ���� 3��° ġŲ���� ����

					int n = num[i];
					d = abs(house[h][0] - chicken[n][0]) + abs(house[h][1] - chicken[n][1]);
					result = min(result, d);				// ���� ����� ġŲ������ �Ÿ�
				}
			}
			cout << h << "������ �ּ� ġŲ �Ÿ� : " << result << endl;
			sum += result;
		}

		// ���� ġŲ�� ���տ� ���� �Ÿ��� 
		// ���� �ּ� ġŲ�Ÿ� ��
		dist = min(dist, sum);
		cout << "���� �ּ� ġŲ �Ÿ� : " << dist << endl;

	} while (next_permutation(temp.begin(), temp.end()));

	return;
}


// ����
int main() {
	int h_index = 0, c_index = 0;
	cin >> N >> M;

	// �� �ٿ� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;

			// ���� ���� ������ ��
			if (input == 1) {
				house[h_index][0] = i;				// ��ǥ ����
				house[h_index][1] = j;
				h_index++;
			}

			// ġŲ���� ���� ������ ��
			else if (input == 2) {
				chicken[c_index][0] = i;			// ��ǥ ����
				chicken[c_index][1] = j;
				c_index++;
			}
		}
	}
	cout << "�� ���� : " << h_index << endl;
	cout << "ġŲ�� ���� : " << c_index << endl;
	shortest(h_index, c_index);

	// �ּ� ġŲ �Ÿ� ���
	cout << dist;
}