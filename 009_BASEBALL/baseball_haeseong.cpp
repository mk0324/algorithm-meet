#include <iostream>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;
	int y_score;
	int k_score;

	cin >> n;

	for (int i = 0; i < n; i++) {
		y_score = 0;
		k_score = 0;

		for (int j = 0; j < 9; j++) {
			int temp;
			cin >> temp;
			y_score += temp;
			cin >> temp;
			k_score += temp;
		}

		if (y_score > k_score)
			cout << "Yonsei" << endl;
		else if (y_score < k_score)
			cout << "Korea" << endl;
		else
			cout << "Draw" << endl;
	}

	return 0;
}