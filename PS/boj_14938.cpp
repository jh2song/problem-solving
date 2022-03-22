#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int cost[101][101];
int item[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			cost[i][j] = INT_MAX;

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 1; i <= r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		cost[a][b] = min(cost[a][b], l);
		cost[b][a] = min(cost[b][a], l);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cost[i][k] == INT_MAX || cost[k][j] == INT_MAX)
					continue;

				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cost[i][i] = 0;
	}

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (cost[i][j] <= m)
				sum += item[j];
		}
		v.push_back(sum);
	}

	sort(v.begin(), v.end(), greater<int>());

	cout << v[0];

	return 0;
}