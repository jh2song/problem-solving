#include <bits/stdc++.h>
using namespace std;

struct Element {
    int value;
    int location;
    int order;
};

int Max_value_element(deque<Element> dq)
{
    int ret = -999;
    for (Element& ele : dq)
    {
        if (ele.value > ret)
            ret = ele.value;
    }

    return ret;
}

int solution(vector<int> priorities, int location) {
    deque<Element> dq;
    deque<Element> ansDQ;
    for (int i = 0; i < priorities.size(); i++)
    {
        dq.push_back({ priorities[i], i, -1 });
    }

    int cnt = 1;

    while (true)
    {
        if (dq.empty())
            break;

        if (dq[0].value >= Max_value_element(dq))
        {
            dq[0].order = cnt;
            cnt++;
            ansDQ.push_back(dq.front());
            dq.pop_front();
            continue;
        }

        Element popped = dq.front();
        dq.pop_front();
        dq.push_back(popped);
    }

    for (Element ele : ansDQ)
    {
        if (ele.location == location)
            return ele.order;
    }
}