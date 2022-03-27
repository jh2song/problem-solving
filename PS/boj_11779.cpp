#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v[1001];
int dist[1001];
int parent[1001];

int n;
int m;
int s, e;

void Dijkstra(int start)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;

	dist[start] = 0;
	parent[start] = -1;
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_weight = pq.top().first;
		pq.pop();

		if (cur_weight > dist[cur_node])
			continue;

		for (auto& e : v[cur_node])
		{
			int next_node = e.first;
			int next_weight = cur_weight + e.second;

			if (next_weight < dist[next_node])
			{
				parent[next_node] = cur_node;
				pq.push({ next_weight, next_node });
				dist[next_node] = next_weight;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	cin >> s >> e;

	Dijkstra(s);
	
	cout << dist[e] << "\n";
	
	stack<int> sta;
	
	int index = e;
	sta.push(index);

	do
	{
		index = parent[index];
		sta.push(index);
	} while (parent[index] != -1);

	cout << sta.size() << "\n";

	while (!sta.empty())
	{
		cout << sta.top() << " ";
		sta.pop();
	}
	return 0;
}