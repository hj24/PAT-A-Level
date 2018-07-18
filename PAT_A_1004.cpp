#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> T[100];
int book[100], maxDepth = -1;

void dfs(int index, int depth){
	if (T[index].size() == 0){	/*如果该节点没有子节点，则该层叶节点数字+1*/
		book[depth]++;
		maxDepth = max(maxDepth, depth);
		return;
	}
	for (int i = 0; i < T[index].size(); ++i){
		dfs(T[index][i], depth + 1);
	}
	
}

int main(int argc, char const *argv[]){
	int n, m, node, k, child;	/*n是总结点数，m是非叶子节点数，k是node节点的孩子节点数量*/
	cin>>n>>m;
	for (int i = 0; i < m; ++i){
		cin>>node>>k;
		for (int j = 0; j < k; ++j){
			cin>>child;
			T[node].push_back(child);
		}
	}
	dfs(1, 0);
	cout<<book[0];
	for (int i = 1; i < maxDepth + 1; ++i){
		cout<<" "<<book[i];
	}
	cout<<endl;
	return 0;
}