#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 99999999;
int city[501][501], team[501], dist[501], num[510], gather[510];
int cn, rn, c1, c2;
bool visited[510] = {false};

void inputGraph(){
	cin>>cn>>rn>>c1>>c2;
	fill(city[0], city[0] + 501*501, INF);
	for (int i = 0; i < cn; ++i){	/*赋点权*/
		cin>>team[i];
	}
	for (int i = 0; i < rn; ++i){	/*赋边权*/
		int begain, end, distance;
		cin>>begain>>end>>distance;
		city[end][begain] = city[begain][end] = distance;
	}
}

void initDist(){
	fill(dist, dist + 501, INF);
	dist[c1] = 0;
}

void dijkstraSolve(){
	num[c1] = 1;
	gather[c1] = team[c1];
	for (int i = 0; i < cn; ++i){
		int min = INF, u = -1;
		for (int j = 0; j < cn; ++j){
			if (visited[j] == false && dist[j] < min){
				min = dist[j];
				u = j;
			}
		}
		if (u == -1){
			break;
		}
		visited[u] = true;
		for (int j = 0; j < cn; ++j){
			if (visited[j] == false && city[u][j] != INF){  /*如果未被访问过且两城市相通*/
				if (dist[j] > city[u][j] + dist[u]){
					dist[j] = city[u][j] + dist[u];
					gather[j] = team[j] + gather[u]; 
					num[j] = num[u];
				}else if(dist[j] == city[u][j] + dist[u]){
					num[j] = num[u] + num[j];
					if (gather[u] + team[j] > gather[j]){
						gather[j] = gather[u] + team[j];
					}
				}
			}
		}

	}
	cout<<num[c2]<<" "<<gather[c2]<<endl;
}

int main(int argc, char const *argv[]){
	inputGraph();
	initDist();
	dijkstraSolve();
	return 0;
}