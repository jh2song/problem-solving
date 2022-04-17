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
vector<char> graph;

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
		graph.push_back(a[i]);

		if (graph.size() >= b_len)
		{
			int v_len = graph.size();

			bool flag = true;
			for (int j = 0; j < b_len; j++)
			{
				if (graph[v_len - 1 - j] != p[b_len - 1 - j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				for (int j = 0; j < b_len; j++)
					graph.pop_back();
			}
		}
	}

	if (graph.empty())
		cout << "FRULA";
	else
	{
		for (auto& e : graph)
		{
			cout << e;
		}
	}
	return 0;
}