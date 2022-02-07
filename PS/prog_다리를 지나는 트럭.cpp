#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;

    deque<pair<int, int>> onRoad_element_pii; // first: truck이 얼마나 갔는지, second: weight
    int onRoad_sum = 0;
    int truck_weights_index = 0; // 입력은 vector인데 pop_front를 사용하고 싶어서 사용

    for (;; answer++)
    {
        // 트럭 left_shift
        for (auto& ele : onRoad_element_pii)
        {
            ele.first = ele.first + 1;
        }
        // 도로를 지나친 트럭은 pop
        if (!onRoad_element_pii.empty() && onRoad_element_pii[0].first >= bridge_length)
        {
            onRoad_sum -= onRoad_element_pii[0].second;
            onRoad_element_pii.pop_front();
        }
        // 분기 조건 시작
        if (truck_weights_index >= truck_weights.size() && onRoad_element_pii.empty())
            break;

        if (truck_weights_index >= truck_weights.size())
            continue;
        // 분기 조건 끝

        // 도로에 트럭을 넣는게 가능하면
        if (onRoad_sum + truck_weights[truck_weights_index] <= weight)
        {
            onRoad_sum += truck_weights[truck_weights_index];
            onRoad_element_pii.push_back({ 0, truck_weights[truck_weights_index] });
            truck_weights_index++;
        }

    }

    return answer;
}