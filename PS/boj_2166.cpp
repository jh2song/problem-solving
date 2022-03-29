#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;

int n;

int main()
{
	scanf(" %d", &n);
	vector<pdd> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		scanf(" %lf %lf", &v[i].first, &v[i].second);
	}

	// Shoelace formula
	double sum = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		sum += v[i].first * v[i + 1].second;
	}
	sum += v[n].first * v[1].second;
	for (int i = 2; i <= n; i++)
	{
		sum -= v[i].first * v[i - 1].second;
	}
	sum -= v[1].first * v[n].second;
	
	sum = abs(sum);
	sum /= 2;
	printf("%.1lf", sum);

	return 0;
}