#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll s;
ll arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int answer = INT_MAX;
	int li = 1;
	int ri = 1;
	ll sum = 0;
	
	while (ri <= n)
	{
		sum += arr[ri];
		if (sum >= s)
		{
			while (sum >= s)
			{
				sum -= arr[li];
				li++;
			}

			answer = min(answer, ri - li + 2);
		}
		
		ri++;
	}

	if (answer == INT_MAX)
		cout << 0;
	else
		cout << answer;

	return 0;
}