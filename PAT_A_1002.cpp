#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]){
	float poly[1001] = {0};
	int exp,m,n,count=0;
	float cof;
	cin>>m;
	for (int i = 0; i < m; ++i){
		cin>>exp>>cof;
		poly[exp]+=cof;
	}
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>exp>>cof;
		poly[exp]+=cof;
	}
	for (int i = 0; i < 1001; ++i){
		if (poly[i] != 0){
			count++;
		}
	}
	cout<<count;
	for (int i = 1000; i >= 0; i--){
		if (poly[i] != 0){
			printf(" %d %.1f", i, poly[i]);
		}
	}
	cout<<endl;
	return 0;
}