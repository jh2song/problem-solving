#include <bits/stdc++.h>
using namespace std;

int tc;
int n, m, w;
int s, e, t;

struct edge {
	int s;
	int e;
	int t;
};

bool IsTimeLoop(vector<edge> edges)
{
	vector<int> dist(n + 1, 999999);
	
	dist[1] = 0;
	int s, e, t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;

			if (dist[e] > dist[s] + t)
				dist[e] = dist[s] + t;
		}
	}

	for (int i = 0; i < edges.size(); i++)
	{
		s = edges[i].s;
		e = edges[i].e;
		t = edges[i].t;

		if (dist[e] > dist[s] + t)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> w;

		vector<edge> edges;

		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}

		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		if (IsTimeLoop(edges))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}