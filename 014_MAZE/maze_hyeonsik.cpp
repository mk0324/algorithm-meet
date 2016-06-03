#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
int t, n, m;
char maze[11][11];
typedef pair<int, int> coordi;
const char nextAc[4] = { 'L','R','U','D' }, reAc[4] = { 'R','L','D','U' };
const int relPos[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
coordi exitPos;
class Info {
public:
	set<coordi > pos;
	string ret;
	Info() { ret = ""; }
	Info(set<coordi > nSet, string nRet) {
		pos = nSet;
		ret = nRet;
	}
};
Info* Maze(Info in) {
	queue<Info> q;
	q.push(in);
	//BFS
	while (!q.empty()) {
		Info cur = q.front(); q.pop();
		char curAc = ' ';
		if (cur.ret.length() != 0) curAc = cur.ret[cur.ret.length() - 1];
		for (int i = 0; i<4; i++) {
			set<coordi> nextSet;
			//가지치기. 
			if (nextAc[i] != curAc && curAc != reAc[i]) {
				for (set<coordi>::iterator it = cur.pos.begin(); it != cur.pos.end(); it++) {
					int px = (*it).first, py = (*it).second;
					bool flag = true;
					//다음 이동이 벽이기 전까지 이동. 혹은 현재 위치가 출구일때 까지
					while (maze[py + relPos[i][1]][px + relPos[i][0]] != '#') {
						px += relPos[i][0];
						py += relPos[i][1];
						if(maze[py][px] == 'O') flag = false;
					}
					if(flag) nextSet.insert(make_pair(px, py));
				}
				//다음 값이 현재 값과 일치하면 continue
				if (nextSet == cur.pos) continue;
				//set의 사이즈가 0이면 모두 탈출 -> 결과 객체 반환 
				if(nextSet.size() == 0){
					return new Info(nextSet, cur.ret + nextAc[i]);
				}
				//현재 액션의 길이가 10이 넘어서면 NULL 반환 
				else if ((cur.ret + nextAc[i]).length() > 10) return NULL;
				q.push(Info(nextSet, cur.ret + nextAc[i])); 
			
			}
		}	
	}
	return NULL;
}
int main() {
	cin >> t;
	while (t--) {
		Info in;
		cin >> n >> m;
		for (int y = 0; y<n; y++) {
			for (int x = 0; x<m; x++) {
				cin >> maze[y][x];
				if (maze[y][x] == '.') in.pos.insert(make_pair(x, y));
				else if (maze[y][x] == 'O') {
					exitPos = make_pair(x, y);
				}
			}
		}
		Info* retInfo = Maze(in);
		if (retInfo == NULL) cout << "XHAE" << endl;
		else cout << retInfo->ret << endl;
	}
}
