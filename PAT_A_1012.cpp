#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	string id;
	char subj;
	int best, score[4], rank[4];
}student;

char subject[4] = {'A', 'C', 'M', 'E'};
int flag;

bool cmp(student a, student b){
	return a.score[flag] > b.score[flag];
}

void get_best(student &ob){
	int max = 5, index = 0;
	for (int i = 0; i < 4; ++i){
		if (ob.rank[i] < max){
			max = ob.rank[i];
			index = i;
		}
	}
	ob.best = max;
	ob.subj = subject[index];
}


int main(int argc, char const *argv[]){
	int n, m;
	cin>>n>>m;
	student stu[n];
	for (int i = 0; i < n; ++i){
		cin>>stu[i].id>>stu[i].score[1]>>stu[i].score[2]>>stu[i].score[3];
		int sum = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
		stu[i].score[0] = sum / 3.0 + 0.5;
	} 
	for (flag = 0; flag < 4; ++flag){
		sort(stu, stu + n, cmp);
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; ++i){
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag]){
				stu[i].rank[flag] = stu[i - 1].rank[flag];
			}
		}
	}
	for (int i = 0; i < n; ++i){
		get_best(stu[i]);
	}
	string id[m];
	for (int i = 0; i < m; ++i){
		cin>>id[i];
	}
	for (int i = 0; i < m; ++i){
		int flag = 0;
		for (int j = 0; j < n; ++j){
			if (id[i] == stu[j].id){
				flag = 1;
				cout<<stu[j].best<<" "<<stu[j].subj<<endl;
			}
		}
		if (!flag){
			cout<<"N/A"<<endl;
		}
	}
	
	return 0;
}