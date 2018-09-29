#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001
using namespace std;

vector<int> V, ans;
int record[MAX][101], dp[MAX];

int cmp(int a, int b){
	return a > b;
}

int main(int argc, char const *argv[]){
	int N, M;
	scanf("%d%d", &N, &M);
	V.resize(N);
	for (int i = 0; i < N; ++i){
		scanf("%d", &V[i]);
	}
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < V.size(); ++i){
		for (int j = M; j >= V[i] ; --j){
			if (dp[j] <= dp[j-V[i]] + V[i]){
				record[i][j] = 1;
				dp[j] = dp[j-V[i]] + V[i];
			}
		}
	}
	if (dp[M] != M){
		cout<<"No Solution"<<endl;
	}else {
		int index = N-1, v = M;
		while(v > 0){
			if (record[index][v]){
				ans.push_back(V[index]);
				v -= V[index];
			}
			index--;
		}
		for (int i = 0; i < ans.size(); ++i){
			i == 0 ? printf("%d", ans[i]):printf(" %d", ans[i]);
		}
	}	
	return 0;
}

/*
Sample Input  1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3

*/







