#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[21][21];
bool visited[21][21];
bool alpha[26];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int DFS(int y, int x, int level)
{
	int ret = level;

	if (visited[y][x])
		return 0;
	
	int ch = arr[y][x] - 'A';
	if (alpha[ch])
		return 0;


	visited[y][x] = true;
	alpha[ch] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 1 || ny > r)
			continue;
		if (nx < 1 || nx > c)
			continue;

		ret = max(ret, DFS(ny, nx, level + 1));
	}

	alpha[ch] = false;
	visited[y][x] = false;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> arr[i][j];

	cout << DFS(1, 1, 1);

	return 0;
}