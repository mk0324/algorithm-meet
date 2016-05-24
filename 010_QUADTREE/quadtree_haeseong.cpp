#include <iostream>
using namespace std;

int n;
int** p;

bool isAllZero(int a, int b, int k) {
	for (int i = a; i < a + k; i++) {
		for (int j = b; j < b + k; j++) {
			if (p[i][j] != 0)
				return false;
		}
	}
	return true;
}

bool isAllOne(int a, int b, int k) {
	for (int i = a; i < a + k; i++) {
		for (int j = b; j < b + k; j++) {
			if (p[i][j] != 1)
				return false;
		}
	}
	return true;
}

void quadTree(int a, int b, int k) {

	if (k == 1) {
		cout << p[a][b];
		return;
	}
	else if (isAllZero(a, b, k)) {
		cout << "0";
		return;
	}
	else if (isAllOne(a, b, k)) {
		cout << "1";
		return;
	}

	int m = k / 2;

	cout << "(";

	quadTree(a, b, m);
	quadTree(a, b + m, m);
	quadTree(a + m, b, m);
	quadTree(a + m, b + m, m);

	cout << ")";
}
int main()
{
	//freopen("input.txt", "r", stdin);

	// input N
	cin >> n;

	// make NxN array
	p = new int*[n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[n];
	}

	char c;
	// input array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == '0')
				p[i][j] = 0;
			else if (c == '1')
				p[i][j] = 1;
		}
	}

	quadTree(0, 0, n);
	cout << endl;

	return 0;
}