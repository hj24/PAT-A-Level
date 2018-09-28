#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

// int V[MAX];
vector<int> V;
int d[MAX] = {-1};

int solve(int S){
	int &ans = d[S];
	if (ans != -1){
		return ans;
	}
	for (int i = 0; i < V.size(); ++i){
		return ans = max()
	}

}

int main(int argc, char const *argv[]){
	int N, M;
	scanf("%d%d", &N, &M);
	V.resize(N);
	for (int i = 0; i < N; ++i){
		scanf("%d", &V[i]);
	}

	
	return 0;
}