#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // sorting in asc
    // 1st: request_start
    // 2nd: taken_time
    sort(jobs.begin(), jobs.end());
    auto cmp = [](vector<int> a, vector<int> b) {return a[1] > b[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    int cur_time = 0;
    int i = 0;
    while (!(i >= jobs.size() && pq.empty()))
    {
        if (i < jobs.size() && cur_time >= jobs[i][0])
        {
            pq.push(jobs[i++]);
            continue;
        }

        if (pq.empty())
        {
            cur_time = jobs[i][0];
            continue;
        }

        if (!pq.empty())
        {
            cur_time += pq.top()[1];
            answer += cur_time - pq.top()[0];
            pq.pop();
        }
    }

    return answer / jobs.size();
}