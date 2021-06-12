// practice04 recursive combination
#include<iostream>
using namespace std;
int cnt = 0;
int choose(int n, int k);

int main() {
	int n, k;
	cout << "nCk ����ϱ�\nn : ";
	cin >> n;
	cout << "k : ";
	cin >> k;
	int answer = choose(n, k);
	cout << n << "C" << k << " = " << answer << endl;
	cout << "ȣ�� Ƚ��: " << cnt << endl;
	
	return 0;
}

int choose(int n, int k) {
	//precondition: �ڿ��� n, k�� �Է����� ������ n >= k �̿��� �Ѵ�.  
	
	cout << n << ", " << k << endl;
	cnt += 1;
	if (k == 1) return n;
	else if (k == 0 || n == k) 	return 1;

	//postcondition: �Ű������� n-1, k-1�� ���, n-1, k�� ��츦 ���� ���� �����Ѵ�.
	//choose�Լ��� ȣ��ɶ����� cnt���� 1�� �����Ѵ�. 
	
	return choose(n - 1, k - 1) + choose(n - 1, k);
	//return: n combination k ���� �����Ѵ�. 
}