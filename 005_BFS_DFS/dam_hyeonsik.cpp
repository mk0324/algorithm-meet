#include <cstdio>
#include <queue>
using namespace std;
int t,a[101][101],k,flood[101][101]={0,},x,y;
typedef struct{
    int x,y,count;  
}Point;
queue<Point> q;
int relPos[4][2]= {{1,0},{-1,0},{0,1,},{0,-1}};
int bfs(){
    int ret=0;
    Point p = {x,y,0}; flood[y][x] = 1;
    q.push(p);  
    // bfs 시작 
    while(!q.empty()){
        p = q.front(); q.pop();
        for(int i=0; i<4;i++){
            int px = p.x + relPos[i][0];
            int py = p.y + relPos[i][1];
            if(px>0&&py>0 && px<t+1&&py<t+1 && flood[py][px]==0 && a[py][px]==0){
                flood[py][px] = 1;
                Point np = {px,py,p.count+1};
                if(p.count+1==k) ret++;
                q.push(np);
            }
        }
    }   
    return ret;
}
int main(){
    scanf("%d",&t);
    // 맵 초기화 
    for(int i =1; i<=t;i++){
        for(int j=1;j<=t;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&x,&y);
    scanf("%d",&k);
    int ret = bfs();
    printf(ret==0?"OH, MY GOD":"%d",ret);
}
