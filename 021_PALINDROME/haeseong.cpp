#include <cstdio>
using namespace std;
 
int N;          // 1 <= N <= 2000
int M;          // 1 <= M <= 1000000
 
int p[2001];    // original number sequence
int q[2001];    // reversed number sequence
 
int S, E;
 
bool isEqual(int S, int E) 
{
    // p(s, e)
    // q(n+1-e, n+1-s)
    int i, j;
    for(i=S, j=N+1-E; i<=E; i++, j++) {
        if(p[i] != q[j])
            return false;
        else
            continue;
    }
    return true;
}
 
int main()
{
    //freopen("input_10942.txt", "r", stdin);
 
    scanf("%d", &N);
     
    for(int i=1; i<=N; i++) {
        scanf("%d", &p[i]);
        q[N+1-i] = p[i];
    }
 
    scanf("%d", &M);
    while(M-->0) {
        scanf("%d %d", &S, &E);
 
        if(isEqual(S, E))
            printf("1\n");
        else
            printf("0\n");
    }
 
    return 0;
}