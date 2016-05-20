#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
long long n, arr[100001];
long long histogram(){
    stack<long long> st;
    long long i,ret = 0;
    st.push(-1);
    for(i=0; i<n;i++){
        //스택이 비어있지 않고,  
        while(!st.empty()&&arr[i]<arr[st.top()]){
            int tmp = st.top(); st.pop();
            if(!st.empty())
                //left는 st.top
                //left-right-1 너비, 높이 arr[tmp]의 직사각형 넓이 
                ret = max(ret, arr[tmp]*(i-st.top()-1));
        }
        //너비를 다 구하고 다음 판자를 스택에 삽입.
        st.push(i); 
    }
    //히스토그램을 끝까지 스택에 넣었는데도 안끝났다면
    //스택에 남아있는 판자들에서의 최대값을 구한다. 
    while(!st.empty()) {
        int tmp = st.top(); st.pop();
        if(!st.empty())
            ret = max(ret, arr[tmp]*(i-st.top()-1));
    }
    return ret;
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    printf("%lld\n",histogram());
    
}   
