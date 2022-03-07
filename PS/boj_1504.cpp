#include <bits/stdc++.h>
using namespace std;

typedef struct edge {
	int end;
	int weight;
} Edge;

typedef pair<int, int> pii; // first: cost, second: node

int n, e;
int v1, v2;
int dist[801];
vector<Edge> node[801];

int Dijkstra(int start, int end)
{
	for (int i = 1; i <= 800; i++)
		dist[i] = INT_MAX;

	dist[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_weight_from1 = pq.top().first;
		pq.pop();
		
		if (cur_weight_from1 > dist[cur_node])
			continue;

		for (auto& e : node[cur_node])
		{
			int next_node = e.end;
			int next_weight_from1 = cur_weight_from1 + e.weight;

			if (next_weight_from1 < dist[next_node])
			{
				dist[next_node] = next_weight_from1;
				pq.push({ next_weight_from1, next_node });
			}
		}
	}

	if (dist[end] == INT_MAX)
		dist[end] = -1;

	return dist[end];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	
	/*
	Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, n);
	Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, n);
	*/
	int r1 = INT_MAX, r2 = INT_MAX;
	int t1, t2, t3;
	t1 = Dijkstra(1, v1);
	t2 = Dijkstra(v1, v2);
	t3 = Dijkstra(v2, n);
	if (t1 != -1 && t2 != -1 && t3 != -1)
		r1 = t1 + t2 + t3;
	t1 = Dijkstra(1, v2);
	t2 = Dijkstra(v2, v1);
	t3 = Dijkstra(v1, n);
	if (t1 != -1 && t2 != -1 && t3 != -1)
		r2 = t1 + t2 + t3;

	int answer = min(r1, r2);
	if (answer == INT_MAX)
		answer = -1;
	cout << answer;
}