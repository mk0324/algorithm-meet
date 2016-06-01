#include<iostream>
#include<math.h>

using namespace std;

struct circle
{
	int x, y, R;
};

int N;
circle input[3001];
bool graph[3001][3001];
bool cnt[3001];

//두 원이 연결되어 있으면 true반환
bool connectCheck(circle& a, circle& b)
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;

	float d = dx*dx + dy*dy;
	
	if (d <= (a.R + b.R)*(a.R + b.R))
		return true;
	
	return false;
}
void dfs(int n)
{
	cnt[n] = true;
	for (int j = n + 1; j < N; j++)
	{
		if (!cnt[j] && graph[n][j])
			dfs(j);
	}
}
int main()
{
	int T;

	cin >> T;
	
	while (T--)
	{	
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> input[i].x >> input[i].y >> input[i].R;

		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
				graph[i][j] = connectCheck(input[i], input[j]);
		}
		int re = 0;
		
		for (int i = 0; i < N; i++)
		{
			if (!cnt[i])
			{
				dfs(i);
				re++;
			}
		}
		cout << re << endl;
	}
	return 0;
}