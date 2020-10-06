//描述
//我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。
//
//如多项式2x20 - x17 + 5x9 - 7x7 + 16x5 + 10x4 + 22x2 - 15
//
//对应的表达式为：2 20 - 1 17 5 9 - 7 7 16 5 10 4 22 2 - 15 0。
//
//为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。
//
//同时输入表达式的幂数大小顺序是随机的。
//
//我们需要做的就是把所给的两个多项式加起来。
//
//输入
//输入包括多行。
//第一行整数n, 表示有多少组的多项式需要求和。(1 < n < 100)
//	下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。
//	每行长度小于300。
//	输出
//	输出包括n行，每行为1组多项式相加的结果。
//	在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。
//	系数为零的项不要输出。
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