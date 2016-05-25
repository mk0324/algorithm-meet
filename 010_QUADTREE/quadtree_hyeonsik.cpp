#include <cstdio>
int N, input[64][64];
void quadTree(int x, int y, int size) {
	int cur = input[y][x];
	bool flag = true;
	for (int i = y; (i< y + size) && flag; i++) 
		for (int j = x; (j<x + size) && flag; j++) 
			if (cur != input[i][j]) flag = false;
	//전부 일치했으면 초기 문자 출력 
	if (flag) printf("%d", cur);
	//아니면 4개로 분할
	else {
		printf("(");
		quadTree(x, y, size / 2);
		quadTree(x + size / 2, y, size / 2);
		quadTree(x, y + size / 2, size / 2);
		quadTree(x + size / 2, y + size / 2, size / 2);
		printf(")");
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i< N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%1d", &input[i][j]);
	quadTree(0, 0, N);
}
