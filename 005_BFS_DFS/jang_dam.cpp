#include<iostream>
#include<queue>

using namespace std;

struct Point
{
	int x, y, water;

	Point(int _x, int _y,int _water) : x(_x), y(_y),water(_water)
	{
	}
};

int** mat;
int T;
queue<Point> q;

int checkAndPush(int x, int y,int water) //push되면 1 반환, 안되면 0반환
{
	if (x >= 0 && x < T && y >= 0 && y < T)
	{
		if (mat[y][x] == 0)	//방문한 곳이 아니고 길 이면 push
		{
			q.push(Point(x, y,water));
			mat[y][x] = water;
			return 1;
		}
	}
	return 0;
}
int dam(int x, int y, int k)
{
	q.push(Point(x-1,y-1,0));

	int sum = 0;

	while (!q.empty())
	{
		Point p = q.front();
		q.pop();
		if (p.water > k-1)
			break;

		mat[p.y][p.x] = 3;	//방문한 곳을 check

		int cnt = 0;

		cnt += checkAndPush(p.x - 1, p.y, p.water + 1);
		cnt += checkAndPush(p.x + 1, p.y, p.water + 1);
		cnt += checkAndPush(p.x, p.y - 1, p.water + 1);
		cnt += checkAndPush(p.x, p.y + 1, p.water + 1);

		if (p.water == k-1)
			sum += cnt;
	}
	if (sum == 0)
	{
		cout << "OH, MY GOD" << endl;
		exit(0);
	}
	return sum;
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
	{
		for (int j = 0; j < T; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < T; i++)
		delete[] mat[i];

	delete[] mat;

	return 0;
}