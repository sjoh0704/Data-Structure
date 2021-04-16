// practice04 recursive combination
#include<iostream>
using namespace std;
int cnt = 0;
int choose(int n, int k);

int main() {
	int n, k;
	cout << "nCk 계산하기\nn : ";
	cin >> n;
	cout << "k : ";
	cin >> k;
	int answer = choose(n, k);
	cout << n << "C" << k << " = " << answer << endl;
	cout << "호출 횟수: " << cnt << endl;
	
	return 0;
}

int choose(int n, int k) {
	//precondition: 자연수 n, k를 입력으로 받으며 n >= k 이여야 한다.  
	
	cout << n << ", " << k << endl;
	cnt += 1;
	if (k == 1) return n;
	else if (k == 0 || n == k) 	return 1;

	//postcondition: 매개변수가 n-1, k-1인 경우, n-1, k인 경우를 더한 값을 리턴한다.
	//choose함수가 호출될때마다 cnt값이 1씩 증가한다. 
	
	return choose(n - 1, k - 1) + choose(n - 1, k);
	//return: n combination k 값을 리턴한다. 
}