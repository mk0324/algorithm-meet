#include <cstdio>
#include <algorithm>
using namespace std;
int n, height[100000];


int histogram(int left, int right){
	//기저사례 : 한칸만 남았을 경우. 
	if(left == right) return height[left];
	int mid = (left+right)/2, ret;
	//mid를 제외한 좌,우의 histogram 최대값을 구한다. 
	ret =  max(histogram(left,mid),histogram(mid+1,right));
	//mid를 중간에 걸친 histogram을 구한다. 
	int rr = mid+1, ll = mid, curHeight=min(height[rr],height[ll]);
	ret = max(ret, curHeight*2);
	
	//height가 큰 쪽으로 하나씩 좌우를 확장해가며 비교한다. 
	while(ll>left || rr<right){ 
		if(rr<right && (ll == left ||height[rr+1]>height[ll-1])){
			rr++;	
			curHeight = min(curHeight,height[rr]);
		} else {
			ll--;
			curHeight = min(curHeight,height[ll]);
		}
		ret = max(ret, curHeight*(rr-ll+1));
	}
	return ret;	 
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&height[i]);
	printf("%d",histogram(0,n-1));
}
