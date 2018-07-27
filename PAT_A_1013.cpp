#include <cstdio>
#include <algorithm>
using namespace std;

int v[1000][1000];
bool visited[1000];
int n, m, k;

void creat_map(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0; i < m; ++i){
		int c_1, c_2;
		scanf("%d%d",&c_1,&c_2);
		v[c_1][c_2] = v[c_2][c_1]= 1;
	}
}
void dfs(int node){
	visited[node] = true;
	for (int i = 1; i <= n; ++i){
		if (visited[i] == false && v[node][i] == 1){
			dfs(i);
		}
	}
}
void solve(){
	for (int i = 0; i < k; ++i){
		int count = 0;
		fill(visited, visited + 1000, false);
		int c;
		scanf("%d",&c);
		visited[c] = true;
		for (int j = 1; j <= n ; ++j){
			if (visited[j] == false){
				dfs(j);
				count++;
			}
		}
		printf("%d\n", count - 1);
	}
}
int main(int argc, char const *argv[]){
	creat_map();
	solve();
	return 0;
}
