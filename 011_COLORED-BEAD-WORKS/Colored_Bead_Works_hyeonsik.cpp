#include <iostream>
#include <cstdio>
#include <utility>
#include <map>
#include <vector>
//반복문 매크로 
#define FOR(k,a,b) for(int k = a; k < b; k++)
#define M_FOR(k,a,b) for(int k = a; k >= b; k--)
#define D_FOR(a,b,c,d) for(int i = a; i<b; i++) for(int j = c; j<d; j++)
//구슬 비트 
#define W_BIT(a,b) (8*a+2*b)
using namespace std;
map<unsigned int, double> cache[17];
typedef pair<unsigned int, double> dishStat;
int T, actCount;
unsigned int dish;
char act[17];

//bitmask -> vector 
vector<vector<char> > getStatVector(unsigned int dish) {
	vector< vector<char> > ret;
	ret.resize(4);
	D_FOR(0, 4, 0, 4) {
		if (dish&(1 << W_BIT(i, j))) ret[i].push_back('W');
		else if (dish&(1 << (W_BIT(i, j)))) ret[i].push_back('G');
		else ret[i].push_back('E');
	}
	return ret;
}

double getProb(int curAct, unsigned int curDish) {
	//기저사례 1 : 모든 액션 실행. 
	if (curAct == actCount) return curDish == dish ? 1 : 0;
	//기저사례 2 : DP 
	if (cache[curAct].find(curDish) != cache[curAct].end())
		return cache[curAct][curDish];
	vector<vector<char> > ret = getStatVector(curDish);
	//구슬일 경우 
	if (act[curAct] == 'W' || act[curAct] == 'G') {
		int centNum = 0, curBead = act[curAct] == 'W' ? 0 : 1;
		D_FOR(1, 3, 1, 3) if (ret[i][j] == 'E')  centNum++;
		//중앙 공간이 3개 비었을 경우, 대각선 100% 
		if (centNum == 3) {
			if (ret[1][1] != 'E') cache[curAct][curDish] += getProb(curAct + 1, curDish | (1 << (20 + curBead)));
			else if (ret[1][2] != 'E') cache[curAct][curDish] += getProb(curAct + 1, curDish | (1 << (18 + curBead)));
			else if (ret[2][1] != 'E') cache[curAct][curDish] += getProb(curAct + 1, curDish | (1 << (12 + curBead)));
			else if (ret[2][2] != 'E') cache[curAct][curDish] += getProb(curAct + 1, curDish | (1 << (10 + curBead)));
		}
		//중앙 공간이 1,2,4개 남았을경우, 1/centNum 
		else if (centNum <= 4 && centNum > 0) {
			D_FOR(1, 3, 1, 3) {
				if (ret[i][j] == 'E')
					cache[curAct][curDish] += getProb(curAct + 1, curDish | (1 << (W_BIT(i, j) + curBead))) / centNum;
			}
		}
		//중앙이 꽉찼을 경우, 1/나머지공간 
		else {
			D_FOR(0, 4, 0, 4) if (ret[i][j] == 'E') centNum++;
			D_FOR(0, 4, 0, 4) {
				if (ret[i][j] == 'E')
					cache[curAct][curDish] += getProb(curAct + 1, curDish | (1 << (W_BIT(i, j) + curBead))) / centNum;
			}
		}
	}
	else {
		unsigned int nextDish = curDish;
		if (act[curAct] == 'L') {
			FOR(k, 0, 4) D_FOR(0, 4, 1, 4) {
				//직전 -1~-2비트가 00이면 오른쪽으로 2bit shift 
				if (!(nextDish &(3 << (W_BIT(i, j) - 2)))) 
					nextDish = ((nextDish & (3 << (W_BIT(i, j)))) >> 2) | (nextDish&~(3 << (W_BIT(i, j))));		
			}
			cache[curAct][curDish] += getProb(curAct + 1, nextDish);
		}
		else if (act[curAct] == 'T') {
			FOR(k, 0, 4) D_FOR(1, 4, 0, 4) {
				//이전 -7~-8비트가 00이면 왼쪽으로 8bit shift 
				if (!(nextDish &(3 << (W_BIT(i, j) - 8)))) 
					nextDish = ((nextDish & (3 << (W_BIT(i, j)))) >> 8) | (nextDish&~(3 << (W_BIT(i, j))));		
			}
			cache[curAct][curDish] += getProb(curAct + 1, nextDish);
		}

		else if (act[curAct] == 'R') {
			FOR(k, 0, 4) FOR(i, 0, 4) M_FOR(j, 2, 0) {
				//이후 1~2비트가 00이면 왼쪽으로 2bit shift  
				if (!(nextDish &(3 << (W_BIT(i, j) + 2)))) 
					nextDish = ((nextDish & (3 << (W_BIT(i, j)))) << 2) | (nextDish&~(3 << (W_BIT(i, j))));	
			}
			cache[curAct][curDish] += getProb(curAct + 1, nextDish);
		}

		else if (act[curAct] == 'B') {
			FOR(k, 0, 4) M_FOR(i, 2, 0) FOR(j, 0, 4) {
				//이전 -7~-8비트가 00이면 왼쪽으로 8bit shift 
				if (!(nextDish &(3 << (W_BIT(i, j) + 8)))) 
					nextDish = ((nextDish & (3 << (W_BIT(i, j)))) << 8) | (nextDish&~(3 << (W_BIT(i, j))));	
			}
			cache[curAct][curDish] += getProb(curAct + 1, nextDish);
		}
	}

	return cache[curAct][curDish];
}

int main() {
	cin >> T;
	while (T--) {
		FOR(k, 0, 17)cache[k].clear();
		dish = 0;
		cin >> actCount;
		FOR(k, 0, actCount) cin >> act[k];
		D_FOR(0, 4, 0, 4) {
			char tmp;
			cin >> tmp;
			if (tmp == 'W') dish |= 1 << W_BIT(i, j);
			if (tmp == 'G') dish |= 1 << (W_BIT(i, j) + 1);
		}
		cache[actCount][dish] = 1.0;
		printf("%.9lf\n", getProb(0, 0));	
	}
}
