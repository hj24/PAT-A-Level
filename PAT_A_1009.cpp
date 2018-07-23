#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(int argc, char const *argv[]){
	map<int, double> poly_a, poly_b, poly_p;
	map<int, double>::iterator it_a, it_b, it_p;
	int k_1, k_2;
	cin>>k_1;
	for (int i = 0; i < k_1; ++i){
		int exp;
		double cof;
		cin>>exp>>cof;
		poly_a[exp] = cof;
	}
	cin>>k_2;
	for (int i = 0; i < k_2; ++i){
		int exp;
		double cof;
		cin>>exp>>cof;
		poly_b[exp] = cof;
	}
	for (it_a = poly_a.begin(); it_a != poly_a.end(); ++it_a){
		for (it_b = poly_b.begin(); it_b != poly_b.end(); ++it_b){
			// 指数相加，系数相乘
			int key = it_a->first + it_b->first;
			double value = it_a->second * it_b->second;
			map<int, double>::iterator it;
			it = poly_p.find(key);
			if (it == poly_p.end()){
				poly_p[key] = value;
			}else{
				it->second += value;
			}

		}
	}
	for (it_p = poly_p.begin(); it_p != poly_p.end(); ++it_p){
		if (it_p->second == 0.0){
			poly_p.erase(it_p);
		}
	}
	cout<<poly_p.size();
	map<int, double>::reverse_iterator r_it;
	for (r_it = poly_p.rbegin(); r_it != poly_p.rend(); ++r_it){
		printf(" %d %.1f", r_it->first, r_it->second);
	}
	cout<<endl;
	return 0;
}