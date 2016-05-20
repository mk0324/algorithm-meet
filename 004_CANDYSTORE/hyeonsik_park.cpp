#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
int n, c, cache[10001];
double m, p;
typedef pair<int, int> Candy;
Candy cd[5001];
int candyStore(int money) {
	int& ret = cache[money];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <n; i++) {
		//남은 금액이 0 이상일 경우에만 비교. 
		if (money - cd[i].second >= 0) {
			int tmp = cd[i].first + candyStore(money - cd[i].second);
			ret = max(ret, tmp);
		}
	}
	return ret;
}
int main() {
	while (true) {
		memset(cache, -1, sizeof(cache));
		scanf("%d %lf", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d %lf", &c, &p);
			cd[i] = make_pair(c, (int)(p*100+0.5));
		}
		printf("%d\n", candyStore((int)(m*100+0.5)));
	}
}
