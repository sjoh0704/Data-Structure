#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> a[8];
bool visited[8] = { false };
void dfs(int start) {
	
	if (visited[start])
		return;
	cout << start << endl;
	visited[start] = true;
	for (int i = 0; i < a[start].size(); i++)
		dfs(a[start][i]);

}

void dfs2(int start) {
	
	stack<int> s;
	s.push(start);
	visited[start] = true;
	while (!s.empty()) {
		int cs = s.top();
		s.pop();
		cout << cs << endl;
		for (int i = 0; i < a[cs].size(); i++) {
			if (!visited[a[cs][i]]) {
				s.push(a[cs][i]);
				visited[a[cs][i]] = true;
			}

		}

	}


}

int main() {

	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);


	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	dfs(1);


	return 0;
}