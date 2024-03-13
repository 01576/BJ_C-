// 10819 ���̸� �ִ��

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[8];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // �迭 ����
    for (int i = 0; i < N - 1; i++) {
        int tmp;
        for (int j = i + 1; j < N; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    int lit[4], man[4], fin[8];
    int j = 0;

    // N�� ¦���� ��, Ȧ���� �� ������
    // ���� �ִ밡 �Ǵ� ���
    // 1, 2, 3, 4, 5 ,6 �� ���
    // 3 6 2 5 1 4 => ������������ ������ ������ 
    // ������ - ū�� - ������... ���� ���� �ִ밪

    if (N % 2 == 0) {
        // ¦���� ��
        for (int i = 0; i < N; i++) {
            if (i < N / 2) {
                man[i] = arr[i];
                cout << "man : " << arr[i];
            }
            else {
                lit[j] = arr[i];
                cout << "lit : " << arr[i];
                j += 1;
            }
        }
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                fin[i] = lit[i / 2];
            }
            else {
                fin[i] = man[i / 2];
            }
        }
    }
    else {
        // Ȧ���� ��
        for (int i = 0; i < N; i++) {
            if (i < (N + 1) / 2) {
                man[i] = arr[i];
                cout << "man : " << arr[i];
            }
            else {
                lit[j] = arr[i];
                cout << "lit : " << arr[i];
                j += 1;
            }
        }

        int fin1[8], fin2[8];

        // (�� ū �� ū ū) ����
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0 && i <= N / 2) {
                fin1[i] = lit[i / 2];
            }
            else {
                fin1[i] = man[i / 2];
            }
        }

        // (ū �� ū �� ū) ����
        fin2[0] = man[N / 2];
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                fin2[i + 1] = lit[i / 2];
            }
            else {
                fin2[i + 1] = man[i / 2];
            }
        }

        // �� ���� ū ���� �̿�
        int hap1 = 0;
        int hap2 = 0;
        for (int i = 0; i < N - 1; i++) {
            hap1 += abs(fin1[i] - fin1[i + 1]);
            hap2 += abs(fin2[i] - fin2[i + 1]);
        }
        for (int i = 0; i < N; i++) {
            if (hap1 > hap2) {
                fin[i] = fin1[i];
                cout << endl << "��ū��ūū" << endl;
            }
            else {
                fin[i] = fin2[i];
                cout << endl << "ū��ū��ū" << endl;
            }
        }
    }


    // ���
    int hap = 0;
    for (int i = 0; i < N - 1; i++) {
        hap += abs(fin[i] - fin[i + 1]);
    }
    cout << endl << hap;
}