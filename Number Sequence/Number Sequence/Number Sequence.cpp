#include <iostream>
#include<cmath>
using namespace std;

int num[50000] = { 0 };
int MAX = 0;
void cal_num()//计算S1...Sk有多少个数字
{
	num[1] = 1;
	for (int i = 2; ; i++)
	{
		int n = 0;//n表示Sk有多少个数
		if (i >= 10000)
		{
			n = 9 + 90 * 2 + 900 * 3 + 9000 * 4 + (i - 9999) * 5;
		}
		if (i < 10000 && i >= 1000)
		{
			n = 9 + 90 * 2 + 900 * 3 + (i - 999) * 4;
		}
		if (i < 1000 && i >= 100)
		{
			n = 9 + 90 * 2 + (i - 99) * 3;
		}
		if (i < 100 && i >= 10)
		{
			n = 9 + (i - 9) * 2;
		}
		if (i < 10)
		{
			n = i;
		}
		if (2147483647 - num[i - 1] < n)
		{
			MAX = i;
			break;
		}
		num[i] = num[i - 1] + n;

	}
}
int cal_k(int i)//判断数位于哪个k
{
	for (int j = 1;; j++)
	{
		if (j < MAX && i <= num[j])
			return j;
		if (j == MAX)
			return j;

	}

}

int ans(int i)
{
	int k = cal_k(i);
	int j = i - num[k - 1];//j代表在Sk中的顺序

	if (j > num[9999] - num[9998])
	{
		int temp = j - (num[9999] - num[9998]) - 1;
		int number = 10000 + temp / 5;
		int count = temp % 5;//0到4；
		for (int m = 0; m < count; m++)
		{

			number = number - (number / (int)pow(10, 4 - m)) * (int)pow(10, 4 - m);
		}
		return number / ((int)pow(10, 4 - count));
	}
	else if (j > num[999] - num[998])
	{
		int temp = j - (num[999] - num[998]) - 1;
		int number = 1000 + temp / 4;
		int count = temp % 4;
		for (int m = 0; m < count; m++)
		{

			number = number - (number / (int)pow(10, 3 - m)) * (int)pow(10, 3 - m);
		}
		return number / ((int)pow(10, 3 - count));
	}
	else if (j > num[99] - num[98])
	{
		int temp = j - (num[99] - num[98]) - 1;
		int number = 100 + temp / 3;
		int count = temp % 3;
		for (int m = 0; m < count; m++)
		{

			number = number - (number / (int)pow(10, 2 - m)) * (int)pow(10, 2 - m);
		}
		return number / ((int)pow(10, 2 - count));
	}
	else if (j > num[9] - num[8])
	{
		int temp = j - (num[9] - num[8]) - 1;
		int number = 10 + temp / 2;
		int count = temp % 2;
		for (int m = 0; m < count; m++)
		{
			number = number - (number / (int)pow(10, 1 - m)) * (int)pow(10, 1 - m);
		}
		return number / ((int)pow(10, 1 - count));
	}
	else
	{
		return j;
	}

}

int main()
{
	cal_num();

	int t;
	cin >> t;


	for (int i = 1; i <= t; i++)
	{
		int m;
		cin >> m;
		cout << ans(m) << endl;
	}












}