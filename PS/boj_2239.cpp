#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
bool can[9][9][10];
vector<pair<int, int>> zero;

void Update(bool paramCan[9][9][10], int y, int x, int target)
{
	for (int i = 0; i < 9; i++)
	{
		paramCan[y][i][target] = false;
		paramCan[i][x][target] = false;
	}

	for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++)
	{
		for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++)
		{
			paramCan[i][j][target] = false;
		}
	}
}

bool BT(unsigned int idx)
{
	if (idx >= zero.size())
		return true;

	int y = zero[idx].first;
	int x = zero[idx].second;

	for (int i = 1; i <= 9; i++)
	{
		if (can[y][x][i])
		{
			arr[y][x] = i;
			bool tcan[9][9][10];
			memcpy(tcan, can, sizeof(can));
			Update(can, y, x, i);
			if (BT(idx + 1))
				return true;
			memcpy(can, tcan, sizeof(can));
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 10; k++)
				can[i][j][k] = true;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char ch;
			cin >> ch;
			arr[i][j] = ch - '0';
			
			if (arr[i][j] == 0)
			{
				zero.push_back({ i, j });
			}
			else
			{
				Update(can, i, j, arr[i][j]);
			}
		}
	}

	BT(0);

	// answer printing
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}