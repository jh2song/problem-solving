#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int s, e, w;
int answer_s, answer_e;
int dist[1001];

typedef pair<int, int> pii;
vector<pair<int, int>> v[1001]; // index: start // first: end // second: weight

void Dijkstra(int start)
{
	dist[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		int c = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (w > dist[c])
			continue;
		
		for (auto e : v[c])
		{
			int next_c = e.first;
			int next_w = w + e.second;

			if (next_w < dist[next_c])
			{
				dist[next_c] = next_w;
				pq.push({ next_w, next_c });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 1000; i++)
		dist[i] = INT_MAX;

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> w;
		v[s].push_back({ e, w });
	}
	cin >> answer_s >> answer_e;

	Dijkstra(answer_s);

	cout << dist[answer_e];
	return 0;
}