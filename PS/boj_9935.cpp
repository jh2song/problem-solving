/* 
reference
https://cocoon1787.tistory.com/720
*/
#include <bits/stdc++.h>
using namespace std;

string a;
string p;
int a_len;
int b_len;
vector<char> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a;
	cin >> p;
	a_len = a.length();
	b_len = p.length();

	for (int i = 0; i < a_len; i++)
	{
		v.push_back(a[i]);

		if (v.size() >= b_len)
		{
			int v_len = v.size();

			bool flag = true;
			for (int j = 0; j < b_len; j++)
			{
				if (v[v_len - 1 - j] != p[b_len - 1 - j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				for (int j = 0; j < b_len; j++)
					v.pop_back();
			}
		}
	}

	if (v.empty())
		cout << "FRULA";
	else
	{
		for (auto& e : v)
		{
			cout << e;
		}
	}
	return 0;
}