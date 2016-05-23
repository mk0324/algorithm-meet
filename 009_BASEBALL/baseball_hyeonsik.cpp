#include <cstdio>
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int score[2] = {0,0}, tmp1, tmp2;
		for(int i = 0; i<9; i++){
			scanf("%d %d",&tmp1,&tmp2);
			score[0]+=tmp1; score[1]+=tmp2;
		}
		printf(score[0]>score[1]?"Yonsei\n":(score[0]<score[1]?"Korea\n":"Draw\n"));
	}
}
