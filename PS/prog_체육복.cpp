#include <bits/stdc++.h>
using namespace std;

int total[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    for (int i = 1; i <= n; i++)
        total[i]++;
    for (auto& e : lost)
        total[e]--;
    for (auto& e : reserve)
        total[e]++;

    for (int i = 1; i <= n; i++) {
        if (total[i] == 2) {
            if (i - 1 >= 1 && total[i - 1] == 0)
                total[i - 1]++;
            else if (i + 1 <= n && total[i + 1] == 0)
                total[i + 1]++;
        }
    }

    int answer = 0;
    for (auto& e : total) {
        if (e >= 1)
            answer++;
    }

    return answer;
}