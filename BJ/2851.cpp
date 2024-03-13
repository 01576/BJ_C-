// 2851 ½´ÆÛ ¸¶¸®¿À

#include <iostream>
using namespace std;

int main() {
    int mushroom[10];
    for (int i = 0; i < 10; i++) {
        cin >> mushroom[i];
    }

    int cha, nextcha, score = 0;
    int n = 0;

    while (true) {
        score += mushroom[n];
        cha = abs(100 - score);
        nextcha = abs(100 - (score + mushroom[n + 1]));
        if (cha <= nextcha || score >= 100) {
            break;
        }
        n++;
    }

    if (nextcha == cha) {
        cout << score + mushroom[n + 1];
    }
    else { cout << score; }
}