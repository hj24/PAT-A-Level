#include <iostream>
#include <cstdio>
#define INF 999999
using namespace std;

typedef struct {
	int hour;
	int minute;
	int second;
}record;
typedef struct {
	string number;
	record r1, r2;
}stu;

int main(int argc, char const *argv[]){
	string unlocked, locked;
    stu s;
	int numOfRecord;
	int min = INF, max = 0;
	cin>>numOfRecord;
	for (int i = 0; i < numOfRecord; ++i){
		cin>>s.number;
		scanf("%d:%d:%d", &s.r1.hour, &s.r1.minute, &s.r1.second);
		scanf("%d:%d:%d", &s.r2.hour, &s.r2.minute, &s.r2.second);
		int sum1 = s.r1.hour * 3600 + s.r1.minute * 60 + s.r1.second;
		int sum2 = s.r2.hour * 3600 + s.r2.minute * 60 + s.r2.second;
		if (sum1 < min){
			min = sum1;
			unlocked = s.number;
		}
		if (sum2 > max){
			max = sum2;
			locked = s.number;
		}
	}
	cout<<unlocked<<" "<<locked<<endl;
	return 0;
}