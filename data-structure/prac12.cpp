//practice12 
// 20160518 ������
// ���� �������� ��stack.h�� ��� #include <stack> �� ����غ��� 
#include<iostream>
#include<stack>
using namespace std;
int main() {

	stack<int> s;
	
	int tmp;
	cin >> tmp;
	while (tmp) {
		s.push(tmp);
		cin >> tmp;
	}

	while (!s.empty()) {
		
		
		cout << s.top()<< endl;
		s.pop();

	}
	return 0;
}