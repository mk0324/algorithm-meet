#include <stdio.h>
int main(){
    int p[1000000];
    int cases;
    int N;
    int i;
    int curVal;
    long long int profit;
    scanf("%d", &cases); 
    while (cases--){
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d", &p[i]);
        profit = 0;
        curVal = p[N-1];
        for (i = N-2; i >= 0; i--){
            if (p[i] > curVal)
                curVal = p[i];
            else
                profit += curVal - p[i];
        }
        printf("%lld\n", profit);
    }
    return 0;
}
