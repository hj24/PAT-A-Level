#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
static const int MAX = 1001;

struct UF{
    int fa[MAX];    // 第i个节点的父节点
    int num[MAX];    // 以i为父节点的元素个数
    /* 初始化*/
    void init(){
        for (int i = 0; i < MAX; ++i){
            fa[i] = i;
            num[i] = 1;
        }
    }
    /* 查找u节点的父节点，路径压缩算法*/
    int find_root(int u){
        if (fa[u] != u){
            fa[u] = find_root(fa[u]);
        }
        return fa[u];
    }
    /* 合并*/
    void Union(int x, int y){
        int fx = find_root(x);
        int fy = find_root(y);
        if (fx != fy){
            fa[fy] = fx;
            num[fx] += num[fy];
        }
    }
}uf;

bool cmp(int a, int b){
    return a>b;
}

int main(int argc, char const *argv[]){
    int m, k, hobbies[MAX] = {0}, count = 0, book[MAX] = {0};
    vector<int> results;
    uf.init();
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j){
            int temp;
            scanf("%d", &temp);
            if (hobbies[temp] == 0){
                hobbies[temp] = i;
            }
            uf.Union(i, uf.find_root(hobbies[temp]));
        }
    }
    for (int i = 1; i <= m; ++i){
         if (book[uf.find_root(i)] == 0){
             book[uf.find_root(i)] = 1;
             count++;
         }
    }
    printf("%d\n", count);
    for (int i = 1; i <= m; ++i){
        if (book[i] != 0) {
            results.push_back(uf.num[i]);
        }
    }
    sort(results.begin(), results.end(), cmp);
    printf("%d",results[0]);
    for (int i = 1; i<results.size(); ++i) {
        printf(" %d",results[i]);
    }
    printf("\n");
    return 0;
}

