#include <string>
#include <vector>
using namespace std;

bool isCompleted[101];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i = 1; i <= 101; i++) // 일 수 별로 슬라이딩
    {
        for (int j = 0; j < progresses.size(); j++) // 진도 업데이트
        {
            if (progresses[j] >= 100)
                continue;
            progresses[j] += speeds[j];
        }

        int ansElement = 0;
        for (int j = 0; j < progresses.size(); j++)
        {
            if (progresses[j] < 100)
                break;

            if (isCompleted[j])
                continue;

            isCompleted[j] = true;
            ansElement++;
        }

        if (ansElement > 0)
            answer.push_back(ansElement);
    }

    return answer;
}