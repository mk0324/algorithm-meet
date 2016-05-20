#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <stack>
using namespace std;
string input;
int matching[221], brkNum = 0; 
bool erasing[221]; 
set<string> retSet;
string ret;

//문자열을 만들어간다.
// 가능한 경우의 수
// 1. 현재 문자가 괄호일경우 : (1) 지운다, (2) 안지운다
// 2. 현재 문자가 괄호가 아닐 경우 : 문자열을 계속 만든다. 

//void eraseBrackets(int cur){
//	//기저사례 : 문자열을 완성
//	if(cur == input.length()){
//		retSet.insert(ret);
//		return;
//	} 
//
//	if(input[cur] == '('){	
//		//지우는 경우
//		erasing[matching[cur]] = true;
//		eraseBrackets(cur+1);	
//		erasing[matching[cur]] = false;
//	
//		//안지우는 경우
//		ret+=input[cur];
//		eraseBrackets(cur+1);
//		ret.erase(ret.begin()+cur-1);
//	
//	}
//	else if(input[cur] ==')'){
//		//짝괄호를 지운 경우 
//		if(erasing[cur]) eraseBrackets(cur+1);
//		//안지운 경우 
//		else {
//			ret+=input[cur];
//			eraseBrackets(cur+1);
//			ret.erase(ret.begin()+cur-1);
//		}
//	}
//	else{
//		ret+=input[cur];
//		eraseBrackets(cur+1);
//		ret.erase(ret.begin()+cur-1);
//	}
//}

void eraseBrackets(int cur){
	//기저사례 : 문자열을 완성
	if(cur == input.length()){
		retSet.insert(ret);
		return;
	} 
	if(input[cur] == '('){	
		//괄호를 지우는 경우
		erasing[matching[cur]] = true;
		eraseBrackets(cur+1);	
		erasing[matching[cur]] = false;
	}
	if(input[cur] ==')'&&erasing[cur]){
		//짝괄호를 지운 경우 
		eraseBrackets(cur+1);
	}
	//괄호,짝괄호를 안지우거나 일반 문자열일 경우. 
	else{
		ret+=input[cur];
		eraseBrackets(cur+1);
		ret.resize(ret.size()-1);
		//ret.erase(ret.begin()+cur-1);
	}
}


//괄호 매칭 설정 
void matchBrackets(string& input){
	stack<int> st;
	for(int i = 0; i<input.length();i++){
		if(input[i] == '(') st.push(i);
		else if(input[i] == ')'){
			//매칭이 되는 괄호를 저장한다. 
			matching[i] = st.top();
			matching[st.top()] = i;		
			st.pop();
			brkNum++;
		}
	}
}
int main(){
	cin>>input;
	matchBrackets(input);
	eraseBrackets(0);
	retSet.erase(input);
	set<string>::iterator it;
	for(it = retSet.begin(); it!=retSet.end(); it++)
		cout<<(*it)<<endl;
}
