#include <stdio.h>
#include <vector>

using namespace std;

// 并查集
int* par;
int* rank;
void init(int size){
	par = new int[size];
	rank = new int[size]();
	for(int i = 0;i < size;i++){
		par[i] = i;
	}
}
void free(){
	delete[] par;
	delete[] rank;
}

int findRoot(int x){
	if(par[x] == x){
		return x;
	}
	else{
		return par[x] = findRoot(par[x]);
	}
}
void unite(int x,int y){
	x = findRoot(x);
	y = findRoot(y);
	if(x == y){
		return;
	}
	if(rank[x] < rank[y]){
		par[x] = y;
	}
	else if(rank[x] > rank[y]){
		par[y] = x;
	}
	else{
		par[x] = y;
		rank[y] ++;
	}
}

bool same(int x,int y){
	return findRoot(x) ==  findRoot(y);
}


int main()
{
	int n,k;
	scanf("%d %d", &n,&k);

	init(n * 3);
	
	int result = 0;
	for(int i = 0;i < k;i++){
		int d,x,y;
		scanf("%d %d %d", &d,&x,&y);
		x--;
		y--;
		if(x >= n || x < 0 || y >= n || y < 0){
			result ++;
		}
		else{
			// 同类
			if(d == 1){
				if(same(x,y + n) || same(x,y + 2 * n)){
					result ++;
				}
				else{
					unite(x,y);
					unite(x + n,y + n);
					unite(x + n * 2,y + n * 2);
				}
			}
			else{
				if(same(x,y) || same(x,y + n * 2)){
					result ++;
				}
				else{
					unite(x,y + n);
					unite(x + n, y + 2 * n);
					unite(x + 2 * n, y);
				}
			}
		}
	}

	printf("%d",result);
	free();
	return 0;

}