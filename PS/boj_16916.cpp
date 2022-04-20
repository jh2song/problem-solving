#include <bits/stdc++.h>
using namespace std;

string s, p;
int ps;
int border[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> p;
	ps = p.size();

	// Preprocessing
	int i = 0;
	int j = -1;
	border[0] = -1;
	while (i < ps)
	{
		while (j > -1 && p[i] != p[j])
			j = border[j];

		i++;
		j++;

		border[i] = j;
	}

	i = 0;
	j = 0;
	int position = -1;
	while (i < s.size())
	{
		while (j >= 0 && s[i] != p[j])
			j = border[j];

		i++;
		j++;

		if (j == ps)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}