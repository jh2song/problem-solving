#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001][4];
int dp_max[4];
int dp_min[4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// Input
	cin >> n;
	int t1, t2, t3;
	for (int i = 1; i <= n; i++)
	{
		cin >> t1 >> t2 >> t3;
		arr[i][1] = t1;
		arr[i][2] = t2;
		arr[i][3] = t3;
	}
	// Dynamic Programming
	dp_max[1] = dp_min[1] = arr[1][1];
	dp_max[2] = dp_min[2] = arr[1][2];
	dp_max[3] = dp_min[3] = arr[1][3];
	for (int i = 2; i <= n; i++)
	{
		int tdp1, tdp2, tdp3;
		// max
		tdp1 = arr[i][1] + max(dp_max[1], dp_max[2]);
		tdp2 = arr[i][2] + max(max(dp_max[1], dp_max[2]), dp_max[3]);
		tdp3 = arr[i][3] + max(dp_max[2], dp_max[3]);
		dp_max[1] = tdp1;
		dp_max[2] = tdp2;
		dp_max[3] = tdp3;
		// min
		tdp1 = arr[i][1] + min(dp_min[1], dp_min[2]);
		tdp2 = arr[i][2] + min(min(dp_min[1], dp_min[2]), dp_min[3]);
		tdp3 = arr[i][3] + min(dp_min[2], dp_min[3]);
		dp_min[1] = tdp1;
		dp_min[2] = tdp2;
		dp_min[3] = tdp3;
	}
	// Print Answer
	cout << max(max(dp_max[1], dp_max[2]), dp_max[3]) << " " << min(min(dp_min[1], dp_min[2]), dp_min[3]);
}