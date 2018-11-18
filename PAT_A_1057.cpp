#include <iostream>
#include <string>
using namespace std;

const int maxn = 100010;

int n, bit[maxn], stack[maxn], top;

int lowbit(int u){
	return u & -u;
} 

long long sum(int u){
	long long res = 0;
	while (u > 0){
		res += bit[u];
		u -= lowbit(u);
	}
	return res;
}

void add(int u, int d){
	while (u <= maxn){
		bit[u] += d;
		u += lowbit(u);
	}
}

void PeekMedian(){
	int l, r, mid, k;
	l = 1, r = maxn;
	k = (top + 2) / 2;
	while (l < r){
		mid = (l + r) >> 1;
		if (sum(mid) >= k){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout<<l<<endl;
}

int main(int argc, char const *argv[]){
	//freopen("/Users/macbook/Downloads/testdata (1).in", "r", stdin);
	string command;
	int cnt = 0;
	top = -1;
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>command;
		if (command == "Pop"){
			if (top == -1){
				cout<<"Invalid"<<endl;
				continue;
			}
			cout<<stack[top]<<endl;
			add(stack[top--], -1);
		}
		if (command == "Push"){
			int key;
			cin>>key;
			stack[++top] = key;
			add(key, 1);
		}
		if (command == "PeekMedian"){
			if (top == -1){
				cout<<"Invalid"<<endl;
				continue;
			}
			PeekMedian();
		}
	}
	return 0;
}