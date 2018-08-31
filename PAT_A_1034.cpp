#include <iostream>
#include <string>
#include <map>
#define INF 999999
#define MAX 2001
using namespace std;

int G[MAX][MAX], weight[MAX];
bool visited[MAX]={false};
map<string, int>gang;
map<int, string>get_gang;
map<string, int>record;
int cnt, max_weight=0;

void dfs(int current, int &num, int &max, int &threthold){
	visited[current] = true;
	if (weight[current] > max_weight){
		max_weight = weight[current];
		max = current;
	}
	for (int i = 1; i <= gang.size(); ++i){
		if (G[current][i] > 0){
			threthold += G[current][i];
			G[current][i] = G[i][current] = 0;
			if (!visited[i]){
				num++;
				dfs(i, num, max, threthold);
			}
		}
	}
}

void dfs_travel(int G[][MAX], int k){
	for (int i = 1; i <= gang.size(); ++i){
		int _num = 1, _max = 0, threthold = 0;
		if (!visited[i]){
			dfs(i, _num, _max, threthold);
			max_weight = 0;
			if (_num > 2 && threthold > k){
				cnt++;
				record[get_gang[_max]] = _num;
			}	
		}
	}
}

void init(int row, int col){
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			G[i][j] = 0;
		}
	}
}

int string_to_int(string s, int &id){
	if (gang[s] == 0){
		gang[s] = ++id;
		get_gang[id] = s;
	}else{
		return gang[s];
	}
	return gang[s];
}

int main(int argc, char const *argv[]){
	init(MAX, MAX);
	int N, K, id=0;
	cin>>N>>K;
	for (int i = 0; i < N; ++i){
		string from, to;
		int time;
		cin>>from>>to>>time;
		gang[from] = string_to_int(from, id);
		gang[to] = string_to_int(to, id);
		G[gang[from]][gang[to]] += time;
		G[gang[to]][gang[from]] += time;
		weight[gang[from]] += time;
		weight[gang[to]] += time;
	}
	dfs_travel(G, K);
	cout<<cnt<<endl;
	map<string, int>::iterator iter;
	for (iter = record.begin(); iter != record.end(); iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}