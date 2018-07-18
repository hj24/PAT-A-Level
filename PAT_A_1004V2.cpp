#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[100];
queue<int> q;
/*book 保存i层所含叶字节点的数量, level记录当前节点所在层数*/
/*maxdepth 记录总层数*/
int book[100], level[100], maxdepth = -1;

void bfs(){
	q.push(1);	/*根节点01*/
	level[1] = 0;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		maxdepth = max(level[front], maxdepth);
		if (v[front].size() == 0){
			book[level[front]]++;	/*该层非叶子节点数+1*/
		}
		for (int i = 0; i < v[front].size(); ++i){
			q.push(v[front][i]);
			level[v[front][i]] = level[front] + 1;
		}

	}

}

int main(int argc, char const *argv[]){
	int n, m, node, k;	/*node是非叶子节点，k是node节点的子节点*/
	cin>>n>>m;
	/*vector存储树结构*/
	for (int i = 0; i < m; ++i){
		cin>>node>>k;
		for (int j = 0; j < k; ++j){
			int child;
			cin>>child;
			v[node].push_back(child);
		}
	}
	bfs();
	cout<<book[0];
	for (int i = 1; i <= maxdepth; ++i){
		cout<<" "<<book[i];
	}
	cout<<endl;
	return 0;
}