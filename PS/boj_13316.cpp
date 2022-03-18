#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
	srand(time(NULL));

	vector<pii> G;
	while (true)
	{
		for (int n = 2; n <= 10; n++)
		{
			for (int k = 0; k < 1000; k++)
			{
				for (int j = 0; j < n; j++)
				{
					G.push_back({ rand() % 1001, rand() % 1001 });
				}
				sort(G.begin(), G.end(), [](const pii& l, const pii& r) { return l.first * r.second < l.second* r.first; });

				bool ch = false;
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						ch |= G[i].first * G[j].second > G[i].second * G[j].first;
					}
				}

				if (ch)
				{
					cout << n << "\n";
					for (auto& e : G)
						cout << e.first << " " << e.second << "\n";

					return 0;
				}

				G.clear();
			}
		}
	}
	cout << "Program End!";
	return 0;
}