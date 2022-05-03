#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> solution(int brown, int yellow) {
    vector<pii> yellow_size;

    for (int width = yellow; width >= 1; width--) {
        if (yellow % width != 0)
            continue;

        int height = yellow / width;
        if (height > width)
            break;

        yellow_size.push_back({ width, height });
    }

    for (auto& e : yellow_size) {
        int width = e.first;
        int height = e.second;

        if (brown == (width + 2) * (height + 2) - width * height) {
            return { width + 2, height + 2 };
        }
    }

    return { -1, -1 };
}