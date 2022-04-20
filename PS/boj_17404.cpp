/*
reference
https://kyu9341.github.io/algorithm/2020/02/19/algorithm17404/
*/
#include <bits/stdc++.h>
#define MAX 99999999
using namespace std;

int n;
int arr[1001][3];
int dp[1001][3];
int ans = MAX;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (int k = 0; k <= 2; k++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (i == k)
				dp[0][i] = arr[0][i];
			else
				dp[0][i] = MAX;
		}

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		for (int i = 0; i <= 2; i++)
		{
			if (i == k)
				continue;
			else
				ans = min(ans, dp[n - 1][i]);
		}
	}

	cout << ans;
	return 0;
}