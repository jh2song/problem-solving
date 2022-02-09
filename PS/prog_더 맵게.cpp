#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq_sco;

    // pq_sco에 스코빌 지수 push // encoding check
    for (auto e : scoville)
    {
        pq_sco.push((ll)e);
    }

    while (1)
    {
        // upper k check
        if (pq_sco.top() >= K)
            break;
        // fail check
        if (pq_sco.size() < 2)
            return -1;


        ll small = pq_sco.top();
        pq_sco.pop();
        ll big = pq_sco.top();
        pq_sco.pop();
        pq_sco.push(small + big * 2);

        answer++;
    }

    return answer;
}