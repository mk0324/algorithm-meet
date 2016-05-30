#include <cstdio>
#include <utility>
#include <vector>
#define createCamp(x,y,r) make_pair(make_pair(x,y),r);
using namespace std;
int t, n, x, y, r;
typedef pair<pair<int, int>, int> Camp;
vector<int> adj[3001];
Camp c[3001];

//인접 여부 
bool groupOk(Camp a, Camp b) {
	int distance = (a.first.first - b.first.first)*(a.first.first - b.first.first)
		+ (a.first.second - b.first.second)*(a.first.second - b.first.second);
	return distance <= (a.second + b.second)*(a.second + b.second);
}
int countCirclegroup() {
	int ret = 0;
	bool visited[3001] = { false, };
	//인접리스트 초기화 
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (groupOk(c[i], c[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	//탐색 
	vector<int> v;
	for (int i = 0; i<n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		v.push_back(i);
		while (!v.empty()) {
			int cur = v.back(); v.pop_back();
			for (int j = 0; j<adj[cur].size(); j++) {
				int tmp = adj[cur][j];
				if (!visited[tmp]) {
					visited[tmp] = true;
					v.push_back(tmp);
				}
			}
		}
		ret++;
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) {
			adj[i].clear();
			scanf("%d %d %d", &x, &y, &r);
			c[i] = createCamp(x, y, r);
		}
		printf("%d\n", countCirclegroup());
	}
}
