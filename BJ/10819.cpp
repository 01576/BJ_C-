// 10819 차이를 최대로

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

    // 배열 정렬
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

    // N이 짝수일 때, 홀수일 때 나눠서
    // 합이 최대가 되는 경우
    // 1, 2, 3, 4, 5 ,6 의 경우
    // 3 6 2 5 1 4 => 내림차순으로 반으로 나눠서 
    // 작은쪽 - 큰쪽 - 작은쪽... 으로 계산시 최대값

    if (N % 2 == 0) {
        // 짝수일 때
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
        // 홀수일 때
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

        // (작 큰 작 큰 큰) 순서
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0 && i <= N / 2) {
                fin1[i] = lit[i / 2];
            }
            else {
                fin1[i] = man[i / 2];
            }
        }

        // (큰 작 큰 작 큰) 순서
        fin2[0] = man[N / 2];
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                fin2[i + 1] = lit[i / 2];
            }
            else {
                fin2[i + 1] = man[i / 2];
            }
        }

        // 더 합이 큰 순서 이용
        int hap1 = 0;
        int hap2 = 0;
        for (int i = 0; i < N - 1; i++) {
            hap1 += abs(fin1[i] - fin1[i + 1]);
            hap2 += abs(fin2[i] - fin2[i + 1]);
        }
        for (int i = 0; i < N; i++) {
            if (hap1 > hap2) {
                fin[i] = fin1[i];
                cout << endl << "작큰작큰큰" << endl;
            }
            else {
                fin[i] = fin2[i];
                cout << endl << "큰작큰작큰" << endl;
            }
        }
    }


    // 출력
    int hap = 0;
    for (int i = 0; i < N - 1; i++) {
        hap += abs(fin[i] - fin[i + 1]);
    }
    cout << endl << hap;
}