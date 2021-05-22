//practice12 
// 20160518 오승주
// 앞의 예제에서 “stack.h” 대신 #include <stack> 을 사용해보자 
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