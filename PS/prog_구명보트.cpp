/*
reference
https://m.blog.naver.com/tkddn0928/221790401154
*/

/*
최대한 limit에 맞춰야 한다.
*/


#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int head = 0;
    int tail = people.size() - 1;

    // 오름차순
    sort(people.begin(), people.end());

    while (head <= tail) {
        if (people[head] + people[tail] <= limit) {
            head++;
            tail--;
            answer++;
        }
        else {
            tail--;
            answer++;
        }
    }

    return answer;
}