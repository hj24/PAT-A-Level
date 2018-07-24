#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]){
	char WTL[3] = {'W', 'T', 'L'};
	double rate[3][3], result[3], mul = 1.0; 
	int book[3];
	for (int i = 0; i < 3; ++i){
		double max = 0.0;
		int index;
		for (int j = 0; j < 3; ++j){
			cin>>rate[i][j];
			if (rate[i][j] > max){
				max = rate[i][j];
				index = j;
			}
		}
		result[i] = max;
		book[i] = index;
	}
	cout<<WTL[book[0]];
	for (int i = 1; i < 3; ++i){
		cout<<" "<<WTL[book[i]];
	}
	for (int i = 0; i < 3; ++i){
		mul *= result[i];
	}
	printf(" %.2lf\n", (mul * 0.65 - 1) * 2);
	return 0;
}