#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]){
	string a;
	string digit[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int sum = 0; 
	stack<int> s;
	cin>>a;
	for (unsigned int i = 0; i < a.length(); ++i){
		sum += (a[i] - '0');
	}
	s.push(sum % 10);
	sum = sum / 10;
	while((sum / 10) != 0){
		s.push(sum % 10);
		sum = sum / 10;
	}
	if (sum != 0){		/*保证相加和为个位数的情况下，第一位不输出 zero*/
		s.push(sum);
	}
	
	cout<<digit[s.top()];
	s.pop();
	while(!s.empty()){
		cout<<" "<<digit[s.top()];
		s.pop();
	}
	cout<<endl;
	return 0;
}