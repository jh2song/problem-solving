/*
reference
https://beginthread.tistory.com/142
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string a, b;
int alen, blen;
string answer = "";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	alen = a.length();
	blen = b.length();
	
	for (int i = 1; i <= alen; i++)
	{
		for (int j = 1; j <= blen; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[alen][blen] << "\n";

	if (dp[alen][blen] != 0)
	{
		int i = alen;
		int j = blen;
		while (dp[i][j]!=0)
		{
			if (a[i - 1] == b[j - 1])
			{
				answer = a[i - 1] + answer;
				i--;
				j--;
			}
			else if (dp[i][j - 1] > dp[i - 1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}

	cout << answer;
	return 0;
}