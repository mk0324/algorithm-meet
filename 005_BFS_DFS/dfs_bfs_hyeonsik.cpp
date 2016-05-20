#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,v;
//방문 정보 
bool visited1[1001],visited2[1001];
//인접리스트 
vector<int> adj[1001];

//스택(재귀)를 이용한 DFS 
void dfs(int x){
	visited1[x-1] = true;
	printf("%d ",x);
	sort(adj[x-1].begin(),adj[x-1].end());
	for(int i = 0; i<adj[x-1].size(); i++){
		if(visited1[adj[x-1][i]-1]==false) dfs(adj[x-1][i]);
	}
}

//큐를 이용한 BFS 
queue<int> q;
void bfs(int x){
	int tmp;
	q.push(x); visited2[x-1] = true;
	while(!q.empty()){
		tmp = q.front(); q.pop();
		printf("%d ",tmp);
		sort(adj[tmp-1].begin(),adj[tmp-1].end());
		for(int i = 0; i< adj[tmp-1].size(); i++){
			if(visited2[adj[tmp-1][i]-1]==false){
				visited2[adj[tmp-1][i]-1] = true;
				q.push(adj[tmp-1][i]);
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&v);
	for(int i = 0; i<m; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y); adj[y-1].push_back(x);
	}
	dfs(v);
	printf("\n");
	bfs(v);
}
