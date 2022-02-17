#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int, less<int>> ms;
    for (auto op : operations)
    {
        if (op == "D 1") // max erase
        {
            if (ms.empty())
                continue;

            ms.erase(ms.find(*(--ms.end())));
        }
        else if (op == "D -1") // min erase
        {
            if (ms.empty())
                continue;

            ms.erase(ms.find(*(ms.begin())));
        }
        else
        {
            int num = stoi(op.substr(2));
            ms.insert(num);
        }
    }

    if (ms.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(--ms.end()));
        answer.push_back(*(ms.begin()));
    }

    return answer;
}