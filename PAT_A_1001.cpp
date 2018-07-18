#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
	int A,B;
	cin>>A>>B;
	string sum = to_string(A+B);
	int len = sum.length();
	for (int i = 0; i < len; i++){
		cout<<sum[i];
		if (sum[i] == '-'){
			continue;
		}
		if (((i+1)%3 == len%3) && (i!=len-1)){
			cout<<",";
		}
	}
	cout<<endl;
	return 0;
}