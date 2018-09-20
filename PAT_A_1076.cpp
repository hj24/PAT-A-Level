#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

struct node{
    int id, layer;
};
vector<vector<int> > v;

int bfs(node n, int L){
    int cnt = 0;
    queue<node> q;
    bool visited[MAX] = {false};
    
    visited[n.id] = true;
    q.push(n);
    while (!q.empty()){
        node start = q.front();
        q.pop();
        for (int i = 0; i < v[start.id].size(); ++i){
            if (!visited[v[start.id][i]] && start.layer <= L){
                visited[v[start.id][i]] = true;
                cnt++;
                node t = {v[start.id][i], start.layer + 1};
                q.push(t);
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]){
    int N, L, K;
    cin>>N>>L;
    v.resize(N+1);
    for (int i = 1; i <= N; ++i){
        int num;
        cin>>num;
        for (int j = 0; j < num; ++j){
            int temp;
            cin>>temp;
            v[temp].push_back(i);
        }
    }
    cin>>K;
    for (int i = 0; i < K; ++i){
        int t_id;
        cin>>t_id;
        node n = {t_id, 1};
        cout<<bfs(n, L)<<endl;
    }
    return 0;
}
