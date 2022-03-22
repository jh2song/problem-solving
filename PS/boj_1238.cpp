#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, x;
int a, b, c;
int dist[1001];
vector<pii> v[1001];


int Dijkstra(int start, int end)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;

	dist[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		int cn = pq.top().second;
		int cd = pq.top().first;
		pq.pop();

		if (cd > dist[cn])
			continue;

		for (auto& e : v[cn])
		{
			int nn = e.first;
			int nd = cd + e.second;

			if (nd < dist[nn])
			{
				dist[nn] = nd;
				pq.push({ nd, nn });
			}
		}
	}

	return dist[end];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, Dijkstra(i, x) + Dijkstra(x, i));
	}

	cout << ans;
	return 0;
}