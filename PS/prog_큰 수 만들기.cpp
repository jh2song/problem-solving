/*
reference
https://mtoc.tistory.com/80
*/

#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int numSize = number.size() - k;
    int start = 0;

    for (int i = 0; i < numSize; i++) {
        char maxNum = number[start];
        int maxIdx = start;
        for (int j = start; j <= k + i; j++) {
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }

        answer += maxNum;
        start = maxIdx + 1;
    }

    return answer;
}