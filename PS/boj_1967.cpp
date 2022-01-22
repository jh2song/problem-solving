#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> node[10001]; // first: child, second: weight
bool isVisited[10001];
int n;
int farDist = 0;
int dia1 = 1; // diameter first point

void DFS(int p, int len) // param 1: parent, param 2: length
{
	if (isVisited[p])
		return;

	isVisited[p] = true;

	if (len > farDist)
	{
		farDist = len;
		dia1 = p;
	}

	for (int i = 0; i < node[p].size(); i++)
	{
		DFS(node[p][i].first, len + node[p][i].second);
	}
}

int main()
{
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	DFS(1, 0);

	farDist = 0;
	memset(isVisited, false, sizeof(isVisited));

	DFS(dia1, 0);

	cout << farDist;
	return 0;
}