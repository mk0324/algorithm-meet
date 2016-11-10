#include <cstdio>

int N;			// 1 <= N <= 2000
int M;          // 1 <= M <= 100000
int p[2001];
char isPalindrome[2001][2001] = {'0',};
int S, E;

int main()
{
    //freopen("input_10942.txt", "r", stdin);
    // input N.
    scanf("%d", &N);
    // input sequence of numbers.
    for(int i=1; i<=N; i++) {
        scanf("%d", &p[i]);
    }
    
    // determine whether [i,j] is palindrome or not.
    int i, j, k;
    for(k=0; k<=N-1; k++) {
        for(i=1, j=i+k; i<=N-k && j<=N; i++, j++) {
            
            if(k==0) {
                // len == 1
                isPalindrome[i][j] = '1';
            }
            else if(k==1) {
                // len == 2
                if(p[i] == p[j])
                    isPalindrome[i][j] = '1';
                else
                    isPalindrome[i][j] = '0';
            }
            else {
                // 3 <= len
                if(isPalindrome[i+1][j-1] == '1'
                   && p[i] == p[j]) {
                    isPalindrome[i][j] = '1';
                }
                else {
                    isPalindrome[i][j] = '0';
                }
            }
        }
    }
    
    // input M.
    scanf("%d", &M);
    // print whether [S,E] is palindrome.
    while(M-->0) {
        scanf("%d", &S);
        scanf("%d", &E);
        printf("%c\n", isPalindrome[S][E]);
    }
    
    return 0;
}

