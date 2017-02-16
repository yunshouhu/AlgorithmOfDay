#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <functional>
using namespace std;

class Solution {
public:
	int Add3(int num1, int num2)
	{
		int res = 0;
		char* a = reinterpret_cast<char*>(num1);
		res=reinterpret_cast<long>(&(a[num2]));
		return res;
	}
	int Add2(int num1, int num2)
	{
		_asm{
			mov eax, num1;
			mov ecx, num2;
			add eax, ecx;
		}
	}
	/**
	����λ���㣬��������
��һ��������λ�� n1
�ڶ����������λ n2
��������n1 �� n2��ͣ��ظ���һ����ֱ����λΪ0����n2=0)
�ڵ�һ���У��������
�ڶ����У����ð�λ�룬����һλ
*/
	int Add(int num1, int num2) {
		while (num2 != 0) {
			int temp = num1^num2;
			num2 = (num1&num2) << 1;
			num1 = temp;
		}
		return num1;
	}
	//�ݹ�汾
	int Add4(int num1, int num2)
	{
		if (num2 == 0)
			return num1;
		return Add4(num1^num2, (num1&num2) << 1);
	}
};
/**
���üӼ��˳����ӷ���
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3
*/
void main()
{

	Solution s;

	cout << s.Add(12,32) << endl;
	cout << s.Add2(12, 32) << endl;
	cout << s.Add3(12, 32) << endl;
	cout << s.Add4(12, 32) << endl;

	system("pause");


}