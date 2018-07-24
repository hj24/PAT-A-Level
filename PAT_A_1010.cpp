#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long long convert(string n, long long radix){
	long long sum = 0, temp_digit = 0;
	for (unsigned int i = 0; i < n.length(); ++i){
		if (n[i] >= '0' && n[i] <= '9'){
			temp_digit = n[i] - '0';
		}else {
			temp_digit = n[i] - 'a' + 10;
		}
		sum += temp_digit * pow(radix, n.length() - 1 - i);
	}
	return sum;
}

long long binary_search(string n, long long compare_num){
	/*
	max_element(str.begin(), str.end()) 方法得到字符串中ascii码最大的字符
	isdigit(char) 判断字符是对应的数字还是字母
	*/
	char t = *max_element(n.begin(), n.end());	
	long long low = (isdigit(t) ? t - '0' : t - 'a' + 10) + 1;
	long long high = max(compare_num, low);
	while (low <= high){
		long long mid = (low + high) / 2;
		long long num = convert(n, mid);
		/*这里if语句顺序要注意一下，由于上面num可能会溢出，
		所以一定要放在最前面检验，否则某些测试样例可能会和 num < compare_num产生冲突*/
		if (num > compare_num || num < 0){
			high = mid - 1;
		}else if (num < compare_num){
			low = mid + 1;
		}else {
        	return mid;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]){
	string n1, n2; 
	long long radix = 0, result = 0, tag = 0;
	cin>>n1>>n2>>tag>>radix;
	if (tag == 1){
		result = binary_search(n2, convert(n1, radix));
	}
	if (tag == 2){
		result = binary_search(n1, convert(n2, radix));
	}
	if (result != -1){
		cout<<result<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}