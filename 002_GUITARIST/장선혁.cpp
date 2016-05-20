#include <iostream>

using namespace std;

int **mem;

int findMaxVolume(int curVal, int maxVol, int depth, int* dt_arr, int i)
{
	if (curVal < 0 || curVal > maxVol)
		return -1;

	if (depth <= 0)
		return curVal;

	if (mem[i][curVal] != -2)
		return mem[i][curVal];

	int left = findMaxVolume(curVal - dt_arr[i], maxVol, depth - 1, dt_arr, i + 1);
	int right = findMaxVolume(curVal + dt_arr[i], maxVol, depth - 1, dt_arr, i + 1);

	mem[i][curVal] = (left > right) ? left : right;

	return mem[i][curVal];
}

int main()
{
	int N, S, M;

	cin >> N >> S >> M;

	mem = new int*[N];

	int* V = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> V[i];
		mem[i] = new int[M+1];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M+1; j++)
			mem[i][j] = -2;
	}
	cout << findMaxVolume(S, M, N, V, 0) << endl;

	return 0;
}
