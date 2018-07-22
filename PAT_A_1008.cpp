#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]){
	int k, time = 0;
	vector<int> list;
	cin>>k;
	for (int i = 0; i < k; ++i){
		int val;
		cin>>val;
		list.push_back(val);
	}
	for (int i = 0; i < k; ++i){
		if (i == 0){
			time += list[0] * 6 + 5;
		}else{
			if (list[i] < list[i-1]){
				time += (list[i-1] - list[i]) * 4 + 5;
			}else if(list[i] > list[i-1]){
				time += (list[i] - list[i-1]) * 6 + 5;
			}else {
				time += 5;
			}
		}
	}
	cout<<time<<endl;
	return 0;
}