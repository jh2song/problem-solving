#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int m;
ll answer = 0;

ll Npow(ll n, ll p)
{
	if (p == 0) 
		return 1;
	
	if (p % 2 == 0)
		return Npow(n * n % MOD, p / 2) % MOD;
	else
		return n * Npow(n * n % MOD, (p - 1) / 2) % MOD;
}

// return <- n^(mod-2)
ll GetInverse(ll n)
{
	return Npow(n, MOD - 2) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll a;
		ll b;

		cin >> a >> b;
		// b1/a1 + b2/a2 + ...
		answer = ((answer % MOD) + (b * GetInverse(a) % MOD)) % MOD;
		
	}

	cout << answer;
	return 0;
}