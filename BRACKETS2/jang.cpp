#include<iostream>
#include<stack>
#include<string>

using namespace std;


bool matchCheck(char left, char right) //left와 right가 (),{},[]쌍을 이루는지 검사
{
	char charSet[3][2] = {
		{ '(',')' },
		{ '{','}' },
		{ '[',']' }
	};

	bool c = false;

	for (int i = 0; i < 3; i++)
	{
		if (left == charSet[i][0])
		{
			if (right == charSet[i][1])
				c = true;
		}
	}
	return c;
}
int main()
{
	int C;

	cin >> C;

	while (C--)
	{
		stack<char> stk;

		string s;
		
		cin >> s;
		
		int i;
		bool t = true;

		for (i = 0; i < s.length(); i++)
		{
			if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
				stk.push(s.at(i));
			else
			{
				if (!stk.empty())
				{
					t = matchCheck(stk.top(), s.at(i));
					if (t)
						stk.pop();
				}
				else
					t = false;
			}

			if (!t) //틀린 구문인 것이 판단되면 바로 for문을 나와도 된다.
				break;
		}

		if (!t || !stk.empty())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}