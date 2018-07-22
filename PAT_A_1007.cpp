#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]){
	vector<int> v;
	int k;
	cin>>k;
	int left = 0, right = k - 1, temp_sum = 0, max = -1, index = 0;
	for (int i = 0; i < k; ++i){
		int val;
		cin>>val;
		v.push_back(val);
		temp_sum += val;
		if (temp_sum < 0){
			temp_sum = 0;
			index = i + 1;
		}else if(temp_sum > max){
			max = temp_sum;
			left = index;
			right = i;
		}
	}
	if (max < 0){
		max = 0;
	}
	cout<<max<<" "<<v[left]<<" "<<v[right]<<endl;
	return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]){
	int K, val, left, right, dp[10000] = {0}, sum, max = -99999999;
	bool flag = true;
	vector<int> v;
	cin>>K;
	for (int i = 0; i < K; ++i){
		cin>>val;
		v.push_back(val);
		if (val > 0){
			flag = false;
		}
	}
	dp[0] = v[0];
	for (int i = 1; i < v.size(); ++i){
		dp[i] = dp[i-1] + v[i];
	}
	for (int i = -1; i < K; ++i){
		for (int j = i; j < K; ++j){

			if (i == j && i != -1){
				sum = v[i];
			}else if(i == -1){
				sum = dp[j + 1];
			}else
				sum = dp[j] - dp[i];
			
			if (sum > max){
				max = sum;
				if (i == j){
					left = i;
					right = j;
				}else{
					left = i + 1;
					right = j;
				}
			}
//			cout<<max<<endl;
		}
	}
	if (flag){
		cout<<0<<" "<<v[0]<<" "<<v[K - 1]<<endl;
	}else
		cout<<max<<" "<<v[left]<<" "<<v[right]<<endl;
	return 0;
}
*/