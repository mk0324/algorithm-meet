#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n;
void brackets2(const string& input){
	const string openning = "[{(", clossing = "]})";
	stack<char> st;
	for(int i = 0; i<input.length(); i++){
		//현재 문자가 여는 괄호면 스택에 삽입 
		if(openning.find(input[i]) != string::npos)
			st.push(input[i]);
		else {
			if(!st.empty()&&openning.find(st.top()) == clossing.find(input[i]))
				st.pop();
			else{
				printf("NO\n");
				return;
			} 
		}
	}
	//문자를 다 검사했을 때 스택이 비었으면 YES, 아니면 NO 
	if(st.empty()) printf("YES\n");
	else printf("NO\n");
	
}
int main(){
	scanf("%d",&n);
	while(n--){
		string input;
		cin>>input;
		brackets2(input);
	}
}
