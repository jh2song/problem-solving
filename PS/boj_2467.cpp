/*
reference
https://m.blog.naver.com/iambigman97/221860065921
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	// first element positive
	if (v[0] > 0)
	{
		cout << v[0] << " " << v[1];
		return 0;
	}
	// last element negative
	if (v[n - 1] < 0)
	{
		cout << v[n - 2] << " " << v[n - 1];
		return 0;
	}

	// now this sequence has neg/pos alternative
	int li = 0;
	int ri = n - 1;
	vector<pair<ll, pair<int, int>>> answer;
	while (li < ri)
	{
		answer.push_back({ abs(v[li] + v[ri]), {li, ri} });
		if (v[li] + v[ri] < 0)
			li++;
		else
			ri--;
	}

	sort(answer.begin(), answer.end());
	cout << v[answer[0].second.first] << " " << v[answer[0].second.second];
	return 0;
}