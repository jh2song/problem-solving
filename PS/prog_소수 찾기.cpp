#include <bits/stdc++.h>
using namespace std;

int prime[10000000];
bool visited[7];


bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void DFS(string numbers, int index, string token) {
    token += numbers[index];
    int num = stoi(token);
    if (isPrime(num))
        prime[num]++;

    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        DFS(numbers, i, token);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    for (int i = 0; i < numbers.size(); i++) {
        visited[i] = true;
        DFS(numbers, i, "");
        visited[i] = false;
    }

    for (int i = 0; i < 10000000; i++) {
        if (prime[i] > 0)
            answer++;
    }

    return answer;
}