#include <iostream>

using namespace std;

//二分求幂（一般）
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
* 1.全面考察指数的正负、底数是否为零等情况。
* 2.写出指数的二进制表达，例如13表达为二进制1101。
* 3.举例:10^1101 = 10^0001*10^0100*10^1000。
* 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
*/
double Power(double base, int exponent) {
	//简单快速幂
	long long p = abs((long long)exponent);
	double r = 1.0;
	while (p)
	{
		if (p & 1)
			r *= base;
		base *= base;// 翻倍
		p >>= 1;// 右移一位
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
			throw new runtime_error("分母不能为0");
		exponent = -n;
	}
	else{// n==0
		return 1;// 0的0次方
	}
	while (exponent != 0){
		if ((exponent & 1) == 1)
			res *= curr;
		curr *= curr;// 翻倍
		exponent >>= 1;// 右移一位
	}
	return n >= 0 ? res : (1 / res);
}

//数值的整数次方:给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00
void main()
{
	cout << "power2="<<pow22(10.5,3) << endl;
	cout << "power=" << pow22(8.5, 13) << endl;
	cout << "power=" << Power_std(8.5, 13) << endl;
	cout << "Power=" << Power(8.5, 13) << endl;
	system("pause");
}