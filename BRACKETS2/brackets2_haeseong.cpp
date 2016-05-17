#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool bracket(string str)
{
	stack<char> S;

	for(string::iterator it=str.begin(); it!=str.end(); ++it) {
		switch(*it) {
		case '(':
		case '{':
		case '[':
			S.push(*it);
			break;
		case ')':
		case '}':
		case ']': {
				if(S.empty())
					return false;
				else if(S.top()+1 == *it || S.top()+2 == *it) {
					S.pop();
					break;
				}
				else
					return false;
			}
		default:
			break;
		}
	}

	if(S.empty())
		return true;
	else
		return false;
}
int main()
{
	//freopen("input_bracket.txt", "r", stdin);
	int C;
	string str;

	cin >> C;
	cin.clear();
	cin.ignore();

	for(int i=0; i<C; i++) {
		getline(cin, str);

		if(bracket(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
