#include<stdio.h>

int map[500][500];
int cache[500][500];
int delta[4][2] = {
	{ 0,1 },
	{ 0,-1 },
	{ 1,0 },
	{ -1,0 }
};
int M, N;

int route(const int x, const int y)
{
	if (x == N - 1 && y == M - 1)
		return 1;

	if (cache[y][x] != -1)
		return cache[y][x];

	cache[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int dx = x + delta[i][0];
		int dy = y + delta[i][1];

		if (dx < 0 || dx >= N || dy < 0 || dy >= M) //boundary exception
			continue;

		if (map[y][x] > map[dy][dx]) //인접 값이 더 작으면
			cache[y][x] += route(dx, dy);
	}
	return cache[y][x];
}
int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			cache[i][j] = -1;
		}
	}
	printf("%d\n", route(0, 0));
}