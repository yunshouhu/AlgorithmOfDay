#include <iostream>
using namespace std;//���������ռ�

int g(int m)//ԭ���Ķ��˷ֺ�
{
	int s = 1;
	while (m > 0) {

		if (m % 2 == 1)
		{
			//�����׳�
			s *= m;
		}	
		m--;
	}
	return s;
}int f(int n)
{
	int sum = 0;//ԭ���ľ�Ȼʹ�þ�̬����
	while (n > 0)
	{
		sum = sum + g(n);
		n--;//ԭ���Ľ�����ѭ����

	}
	return sum;
}

//http://acm.nyist.net/JudgeOnline/problem.php?pid=65
int main()
{
	int a;
	cin >> a;
	while (a--) {
		int n;
		cin >> n;
		cout << f(n) << endl;
	}
	return 0;
}