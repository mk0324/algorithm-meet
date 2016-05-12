#include<iostream>
#include<queue>

using namespace std;

struct Point
{
	int x, y;

	Point(int _x, int _y) : x(_x), y(_y)
	{
	}
};

int** mat;
int T;
queue<Point> q;

int checkAndPush(int x, int y) //push되면 1 반환, 안되면 0반환
{
	if (x >= 0 && x < T && y >= 0 && y < T)
	{
		if (mat[y][x] != 1 && mat[y][x] != 3)	//방문이 안되었고 벽이 아니라면 push
		{
			q.push(Point(x, y));
			return 1;
		}
	}
	return 0;
}
int dam(int x, int y, int k)
{
	int water = 0;

	q.push(Point(x-1,y-1));

	while (!q.empty())
	{
		Point p = q.front();
		q.pop();
		mat[p.y][p.x] = 3;	//방문한 곳을 check

		int cnt = 0;

		cnt += checkAndPush(p.x - 1, p.y);
		cnt += checkAndPush(p.x + 1, p.y);
		cnt += checkAndPush(p.x, p.y - 1 );
		cnt += checkAndPush(p.x, p.y + 1 );

		if (cnt == 0)
		{
			cout << "OH, MY GOD" << endl;
			exit(0);
		}
		water++;
		if (water == k)
			return cnt;
	}
}
int main()
{
	cin >> T;

	mat = new int*[T];

	for (int i = 0; i < T; i++)
		mat[i] = new int[T];

	for (int i = 0; i < T; i++)
		for (int j = 0; j < T; j++)
			cin >> mat[i][j];
	
	int x, y;
	cin >> x >> y;

	int K;
	cin >> K;

	cout<<dam(x, y, K)<<endl;

	for (int i = 0; i < T; i++)
		delete[] mat[i];

	delete[] mat;

	return 0;
}