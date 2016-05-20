#include<iostream>
#include<queue>

using namespace std;

bool* visit;
bool** graph; //N*N array
int N, M, V;

void dfs(int v)
{
	cout << v <<" ";
	visit[v - 1] = false;

	for (int i = 0; i < N; i++)
	{
		if (!graph[v - 1][i] && visit[i])
			dfs(i + 1);
	}
}
int main()
{

	cin >> N >> M >> V;
	
	graph = new bool*[N];
	for (int i = 0; i < N; i++)
		graph[i] = new bool[N];

	while (M--)
	{
		int i, j;
		cin >> i >> j;

		graph[i - 1][j - 1] = false;
		graph[j - 1][i - 1] = false;
	}	//make graph

	//dfs
	visit = new bool[N];	//방문했는지 여부
	dfs(V);

	//visit은 전부 false가 되어있음
	cout << endl;

	//bfs
	queue<int> q;

	q.push(V);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		visit[v - 1] = true;

		cout << v << " ";

		for (int i = 0; i < N; i++)
		{
			if( !graph[v - 1][i] && !visit[i])
			{
				q.push(i + 1);
				visit[i] = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
		delete[] graph[i];
	
	delete[] graph;
	delete[] visit;

	return 0;
}