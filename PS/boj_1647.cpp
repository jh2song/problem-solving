#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[100001];
int level[100001];
vector<pair<int, pair<int, int>>> v;
int answer = 0;
bool flag = false;

int Find(int u)
{
	if (parent[u] == u) 
		return u;

	return parent[u] = Find(parent[u]);
}

void Union(int u, int v, int w)
{
	int ur = Find(u);
	int vr = Find(v);

	if (ur == vr)
		return;

	if (level[ur] < level[vr])
	{
		parent[ur] = vr;
		level[vr] += level[ur];
	}
	else
	{
		parent[vr] = ur;
		level[ur] += level[vr];
	}

	if (level[ur] == n || level[vr] == n)
	{
		flag = true;
		return;
	}

	answer += w;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}

	v.resize(m);

	for (int i = 0; i < m; i++)
	{
		cin >> v[i].second.first >> v[i].second.second >> v[i].first;
	}

	sort(v.begin(), v.end());

	for (auto& e : v)
	{
		Union(e.second.first, e.second.second, e.first);
		if (flag)
			break;
	}

	cout << answer;
	return 0;
}