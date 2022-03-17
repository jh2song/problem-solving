/*
reference
https://seokjin2.tistory.com/9
*/
#define MOD 1000
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Mat;

int n;
ll p;

Mat operator * (const Mat& a, const Mat& b)
{
	Mat ret(n, vector<ll>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= MOD;
		}
	}

	return ret;
}

Mat Mat_Power(Mat a, ll p)
{
	Mat ret(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++) // Identity Matrix
		ret[i][i] = 1;

	while (p > 0)
	{
		if (p % 2 == 1)
			ret = ret * a;
		
		p /= 2;
		a = a * a;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p;
	Mat base(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> base[i][j];

	Mat ans = Mat_Power(base, p);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}