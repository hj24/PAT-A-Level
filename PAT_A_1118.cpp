#include <cstdio>
#include <algorithm>
using namespace std;
static const int MAX = 10001;

struct UF{
	int father[MAX], num[MAX];
	void init(){
		for (int i = 0; i < MAX; ++i){
			father[i] = i;
			num[i] = 1;
		}
	}
	int find_root(int u){
		if (father[u] != u){
			father[u] = find_root(father[u]);
		}
		return father[u];
	}
	void Union(int x, int y){
		int fx = find_root(x);
		int fy = find_root(y);
		if (fx < fy){
			father[fy] = fx;
			num[fx] += num[fy];
		}else if (fx > fy){
			father[fx] = fy;
			num[fy] += num[fx];
		}
	}
}uf;

int main(int argc, char const *argv[]){
	int N, K, Q, count_pic=0, count_bird=0, id, birds[MAX];
	bool visited[MAX] = {false};
	uf.init();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		scanf("%d", &K);
		for (int j = 0; j < K; ++j){
			scanf("%d", &birds[j]);
			visited[birds[j]] = true;
			if (j>0){
				uf.Union(birds[j], birds[j-1]);
			}
		}
	}
	for (int i = 1; i <= MAX; ++i){
		if (visited[i]){
			count_bird++;
		}
	}
	fill(visited, visited+10001, false);
	for (int i = 1; i <= count_bird; ++i){
		int id = uf.find_root(i);
		visited[id] = true;
	}
	for (int i = 1; i <= MAX; ++i){
		if (visited[i]){
			count_pic++;
		}
	}
	scanf("%d", &Q);
	int q[MAX][2];
	for (int i = 0; i < Q; ++i){
		for (int j = 0; j < 2; ++j){
			scanf("%d", &q[i][j]);
		}
	}
	printf("%d %d\n", count_pic, count_bird);
	for (int i = 0; i < Q; ++i){
		printf("%s\n", (uf.find_root(q[i][0])) == (uf.find_root(q[i][1]))?"Yes":"No");
	}
	return 0;
}