#include <bits/stdc++.h>
using namespace std;

bool visited[501];

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
        });

    int point = 0;
    vector<int> fsfe; // from start to end
    while (true)
    {
        // break condition
        if (fsfe.size() == jobs.size())
            break;

        bool exit_flag = false;
        for (int i = 0; i < jobs.size(); i++)
        {
            if (visited[i] == false && jobs[i][0] <= point)
            {
                visited[i] = true;
                fsfe.push_back(jobs[i][1] + (jobs[i][0] - point));
                point += jobs[i][1] + (jobs[i][0] - point);
                exit_flag = true;
                break;
            }
        }

        if (exit_flag)
            continue;

        // idle time process
        int min = 999999;
        int min_idx = -1;
        for (int i = 0; i < jobs.size(); i++)
        {
            if (visited[i] == false && jobs[i][0] <= min)
            {
                min = jobs[i][0];
                min_idx = i;
            }
        }

        visited[min_idx] = true;
        fsfe.push_back(jobs[min_idx][1]);
        point += jobs[min_idx][1] + (jobs[min_idx][0] - point);
    }

    for (auto e : fsfe)
    {
        answer += e;
    }

    answer = answer / (int)jobs.size();
    return answer;
}