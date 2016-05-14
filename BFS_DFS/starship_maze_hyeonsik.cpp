#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int> > graph;
vector<int> visited;
void dfs(int cur){
	printf("%d ",cur);
	sort(graph[cur-1].begin(),graph[cur-1].end());
	for(int i =0; i<graph[cur-1].size();i++){
		if(visited[graph[cur-1][i]-1]==0){
			visited[graph[cur-1][i]-1] = 1;
			dfs(graph[cur-1][i]);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	graph.resize(n);
	visited.resize(n);
	for(int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a-1].push_back(b);
		graph[b-1].push_back(a);
	}
	visited[0] = 1;
	dfs(1);	
}
