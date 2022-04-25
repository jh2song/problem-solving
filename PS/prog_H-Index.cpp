#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    for (answer = citations[0]; answer >= 0; answer--)
    {
        int h = 0;
        for (auto& e : citations)
        {
            if (e >= answer)
                h++;
        }
        if (h >= answer)
            break;
    }

    return answer;
}