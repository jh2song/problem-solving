/*
reference
https://www.acmicpc.net/board/view/72638
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll diff = 999999999999;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	ll a1, a2, a3;
	for (int i = 0; i <= n - 3; i++)
	{
		int j = i + 1;
		int k = n - 1;
		while (j < k)
		{
			if (v[i] + v[j] + v[k] == 0)
			{
				cout << v[i] << " " << v[j] << " " << v[k];
				return 0;
			}

			if (abs(v[i] + v[j] + v[k]) < diff)
			{
				diff = abs(v[i] + v[j] + v[k]);
				a1 = v[i];
				a2 = v[j];
				a3 = v[k];
			}

			if (v[i] + v[j] + v[k] > 0)
				k--;
			else
				j++;
		}
	}

	cout << a1 << " " << a2 << " " << a3;
	return 0;
}