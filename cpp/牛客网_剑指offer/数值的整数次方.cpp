#include <iostream>

using namespace std;

//�������ݣ�һ�㣩
int pow2(int a, int b)
{
	int r = 1, base = a;
	while (b != 0)
	{
		if (b % 2)
			r *= base;
		base *= base;
		b /= 2;
	}
	return r;
}

double pow22(double a, int b)
{
	double r = 1, base = a;
	while (b != 0)
	{
		if (b % 2)
			r *= base;
		base *= base;
		b /= 2;
	}
	return r;
}

/**
* 1.ȫ�濼��ָ���������������Ƿ�Ϊ��������
* 2.д��ָ���Ķ����Ʊ�����13���Ϊ������1101��
* 3.����:10^1101 = 10^0001*10^0100*10^1000��
* 4.ͨ��&1��>>1����λ��ȡ1101��Ϊ1ʱ����λ����ĳ����۳˵����ս����
*/
double Power(double base, int exponent) {
	//�򵥿�����
	long long p = abs((long long)exponent);
	double r = 1.0;
	while (p)
	{
		if (p & 1)
			r *= base;
		base *= base;// ����
		p >>= 1;// ����һλ
	}
	return exponent<0 ? 1 / r : r;
}

double Power_std(double base, int n) {
	double res = 1, curr = base;
	int exponent;
	if (n>0){
		exponent = n;
	}
	else if (n<0){
		if (base == 0)
			throw new runtime_error("��ĸ����Ϊ0");
		exponent = -n;
	}
	else{// n==0
		return 1;// 0��0�η�
	}
	while (exponent != 0){
		if ((exponent & 1) == 1)
			res *= curr;
		curr *= curr;// ����
		exponent >>= 1;// ����һλ
	}
	return n >= 0 ? res : (1 / res);
}

//��ֵ�������η�:����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
//https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00
void main()
{
	cout << "power2="<<pow22(10.5,3) << endl;
	cout << "power=" << pow22(8.5, 13) << endl;
	cout << "power=" << Power_std(8.5, 13) << endl;
	cout << "Power=" << Power(8.5, 13) << endl;
	system("pause");
}