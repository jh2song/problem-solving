#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.length();

    // i: splitting unit (count)
    for (int i = 1; i < s.length(); i++)
    {
        string tmp_s = "";
        int cnt = 1;
        string pat = s.substr(0, i); // first pattern
        for (int j = i; j < s.length(); j += i)
        {
            if (pat == s.substr(j, i))
            {
                cnt++;
            }
            else
            {
                string num = "";
                if (cnt != 1)
                    num += to_string(cnt);
                tmp_s += num + pat;
                pat = s.substr(j, i);
                cnt = 1;
            }
        }
        string num = "";
        if (cnt != 1)
            num += to_string(cnt);
        tmp_s += num + pat;

        if (answer > tmp_s.length())
            answer = tmp_s.length();
    }

    return answer;
}