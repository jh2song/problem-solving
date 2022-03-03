#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt, person;
int parent[51];
vector<int> v[51];
vector<int> knowing;
int before;

int Find(int u)
{
	if (u == parent[u])
		return u;
	else
		return parent[u] = Find(parent[u]);
}

void Union(int x, int y)
{
	int xr = Find(x);
	int yr = Find(y);

	parent[xr] = yr;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> person;
		knowing.push_back(person);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			if (j >= 1)
			{
				cin >> person;
				Union(before, person);
				v[i].push_back(person);
				before = person;
			}
			else
			{
				cin >> person;
				v[i].push_back(person);
				before = person;
			}
		}
	}

	int answer = m;
	for (int i = 1; i <= m; i++)
	{
		bool flag = false;
		for (auto& person : v[i])
		{
			if (flag)
				break;
			for (auto& known : knowing)
			{
				if (Find(person) == Find(known))
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			answer--;
	}

	cout << answer;
	return 0;
}