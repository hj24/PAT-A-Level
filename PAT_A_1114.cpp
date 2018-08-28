#include <cstdio>
#include <algorithm>
using namespace std;
static const int MAX = 10000;
static const int NUM_CHILD = 5;

struct Data{	/*存放输入数据的结构体*/
	int id, fa, mo, k, m, area;
	int child[NUM_CHILD]; 
}data[MAX];

struct node{
	int id, num;
	double house, area, aveHouse, aveArea; 
}node[MAX];

struct UF{
	int num[MAX], fa[MAX];
	void init(){
		for (int i = 0; i < MAX; ++i){
			fa[i] = i;
			num[i] = 1;
		}
	}
	int find_root(int u){
		if (fa[u] != u){
			fa[u] = find_root(fa[u]);
		}	
		return fa[u];
	}
	void Union(int x, int y){
		int fx = find_root(x);
		int fy = find_root(y);
		if (fx > fy){
			fa[fx] = fy;
			num[fy] += num[fx];
		}else if (fx < fy){
			fa[fy] = fx;
			num[fx] += num[fy];
		}
	}
}uf;
bool visited[MAX] = {false};

bool cmp(struct node a, struct node b){
	if (a.aveArea != b.aveArea){
		return a.aveArea > b.aveArea;
	}else{
		return a.id < b.id;
	}
}

int main(int argc, char const *argv[]){
	int n;
	uf.init();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d%d%d", &data[i].id, &data[i].fa, &data[i].mo, &data[i].k);
		if (data[i].fa != -1){
			uf.Union(data[i].fa, data[i].id);
		}
		if (data[i].mo != -1){
			uf.Union(data[i].mo, data[i].id);
		}
		for (int j = 0; j < data[i].k; ++j){
			scanf("%d", &data[i].child[j]);
			uf.Union(data[i].child[j], data[i].id);
		}
		scanf("%d%d", &data[i].m, &data[i].area);
	}
	int count = 0;
	for (int i = 0; i < n; ++i){
		int id = uf.find_root(data[i].id);
		if(!visited[id]){
			count++;
			visited[id] = true;
		}
		node[id].id = id;
		node[id].num = uf.num[id];
		node[id].house += data[i].m;
		node[id].area += data[i].area;
	}
	for (int i = 0; i < n; ++i){
		int id = uf.find_root(data[i].id);
		if (visited[id]){
			node[id].aveHouse = node[id].house / node[id].num;
			node[id].aveArea = node[id].area / node[id].num;
		}
	}
	printf("%d\n", count);
	sort(node, node+10000, cmp);
	for (int i = 0; i < count; ++i){
		printf("%04d %d %.3f %.3f\n", node[i].id, node[i].num, node[i].aveHouse, node[i].aveArea);
	}
	return 0;
}