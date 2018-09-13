#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#define MAX 10001
using namespace std;

vector<vector<int> > v;
vector<int> temp;
set<int> node;
int cnt=0, N, max_height=0, max_index, visited[MAX] = {0};

void dfs(int current, int height){
	visited[current] = 1;
	if (height > max_height){
		temp.clear();
		max_height = height;
		temp.push_back(current);
		max_index = current;
	}else if (height == max_height){
		temp.push_back(current);
	}
	for (int i = 0; i < v[current].size(); ++i){
		if (visited[v[current][i]] == 0){
			dfs(v[current][i], height + 1);
		}
	}
}
void dfs_travel(){
	for (int i = 1; i <= N; ++i){
		if (!visited[i]){
			dfs(i, 1);
			cnt++;
		}
	}
}

int main(int argc, char const *argv[]){
	cin>>N;
	v.resize(N+1);
	for (int i = 0; i < N-1; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs_travel();
	for (int i = 0; i < temp.size(); ++i){
		node.insert(temp[i]);
	}

	
	if (cnt >= 2){
		cout<<"Error: "<<cnt<<" components"<<endl;
	}else{
		fill(visited, visited+10001, 0);
		dfs(max_index, 1);
		for (int i = 0; i < temp.size(); ++i){
			node.insert(temp[i]);
		}
		set<int>::iterator iter;
		for (iter = node.begin(); iter != node.end() ; ++iter){
			cout<<*iter<<endl;
		}
	}
	return 0;
}