#include <iostream>
#include<set>
#include<map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	set<int> mi;//指数集合；
	map<int, int> ans;
	for (int i = 1; i <= n; i++)
	{

		mi.clear();
		int m = 0, p = 0;//m表示系数，p表示幂数；

		cin >> m >> p;

		int max = p;

		while (p >= 0)
		{
			if (mi.find(p) == mi.end())
			{
				mi.insert(p);
				ans[p] = m;
			}
			else
			{

				ans[p] += m;
			}
			cin >> m >> p;
			if (p > max)
			{
				max = p;
			}
		}

		cin >> m >> p;

		if (p > max)
		{
			max = p;
		}

		while (p >= 0)
		{
			if (mi.find(p) == mi.end())
			{
				mi.insert(p);
				ans[p] = m;
			}
			else
			{

				ans[p] += m;
			}
			cin >> m >> p;

			if (p > max)
			{
				max = p;
			}

		}


		for (set<int>::reverse_iterator j = mi.rbegin(); j != mi.rend(); j++)
		{
			if (ans[*j])
			{
				cout << "[ " << ans[*j] << " " << *j << " ] ";
			}

		}
		cout << endl;
	}








}