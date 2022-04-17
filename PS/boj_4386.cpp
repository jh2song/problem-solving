#include <bits/stdc++.h>
using namespace std;

typedef pair<double, pair<int, int>> dii;

int n;
double arr[101][2];
vector<dii> graph;
int parent[101];

double answer = 0.0;

int Find(int u)
{
	if (parent[u] == u)
		return u;
	else
		return parent[u] = Find(parent[u]);
}

void Union(int u, int v, double w)
{
	int ur = Find(u);
	int vr = Find(v);

	if (ur == vr)
	{
		return;
	}

	parent[ur] = vr;
	answer += w;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double w = sqrt(pow((arr[i][0] - arr[j][0]), 2) + pow((arr[i][1] - arr[j][1]), 2));
			graph.push_back({ w, {i, j} });
		}
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++)
	{
		int u = graph[i].second.first;
		int v = graph[i].second.second;
		double w = graph[i].first;

		Union(u, v, w);
	}

	cout << answer;
	return 0;
}