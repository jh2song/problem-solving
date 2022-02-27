#include <bits/stdc++.h>
using namespace std;

int n;
int board[17][17];
int dp[17][17][17][17];

int DFS(int dy, int dx, int ey, int ex)
{
	int y1, x1; // 시작점
	int y2 = ey + dy, x2 = ex + dx; // 중점
	int y3 = ey, x3 = ex; // 끝점

	if (y2 < 1 || x2 < 1)
		return 0;

	int& ret = dp[y2][x2][y3][x3];
	if (ret != -1)
		return ret;
	ret = 0;

	if (dy == 0 && dx == -1) // 가로
	{
		if (board[y2][x2] == 1 || board[y3][x3] == 1)
			return ret = 0;

		// case 1
		y1 = y2;
		x1 = x2 - 1;
		if (y1 >= 1 && x1 >= 1 
			&& board[y1][x1] == 0)
		{
			ret += DFS(0, -1, y2, x2);
		}
		// case 5
		y1 = y2 - 1;
		x1 = x2 - 1;
		if (y1 >= 1 && x1 >= 1
			&& board[y1][x1] == 0 && board[y1][x1 + 1] == 0 && board[y1 + 1][x1] == 0)
		{
			ret += DFS(-1, -1, y2, x2);
		}
	}
	else if (dy == -1 && dx == 0) // 세로
	{
		if (board[y2][x2] == 1 || board[y3][x3] == 1)
			return ret = 0;

		// case 3
		y1 = y2 - 1;
		x1 = x2;
		if (y1 >= 1 && x1 >= 1
			&& board[y1][x1] == 0)
		{
			ret += DFS(-1, 0, y2, x2);
		}
		// case 6
		y1 = y2 - 1;
		x1 = x2 - 1;
		if (y1 >= 1 && x1 >= 1
			&& board[y1][x1] == 0 && board[y1][x1 + 1] == 0 && board[y1 + 1][x1] == 0)
		{
			ret += DFS(-1, -1, y2, x2);
		}
	}
	else if (dy == -1 && dx == -1) // 대각선
	{
		if (board[y2][x2] == 1 || board[y2][x2 + 1] == 1 || board[y2 + 1][x2] == 1 || board[y3][x3] == 1)
			return ret = 0;

		// case 2
		y1 = y2;
		x1 = x2 - 1;
		if (y1 >= 1 && x1 >= 1
			&& board[y1][x1] == 0)
		{
			ret += DFS(0, -1, y2, x2);
		}
		// case 4
		y1 = y2 - 1;
		x1 = x2;
		if (y1 >= 1 && x1 >= 1
			&& board[y1][x1] == 0)
		{
			ret += DFS(-1, 0, y2, x2);
		}
		// case 7
		y1 = y2 - 1;
		x1 = x2 - 1;
		if (y1 >= 1 && x1 >= 1
			&& board[y1][x1] == 0 && board[y1][x1 + 1] == 0 && board[y1 + 1][x1] == 0)
		{
			ret += DFS(-1, -1, y2, x2);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	memset(dp, -1, sizeof(dp));
	dp[1][1][1][2] = 1;
	cout << DFS(0, -1, n, n) + DFS(-1, 0, n, n) + DFS(-1, -1, n, n);
	
	return 0;
}