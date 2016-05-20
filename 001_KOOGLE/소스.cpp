#include <string>
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int main()
{
	int c;

	cin >> c;

	string* topWords = new string[c];

	for (size_t i = 0; i < c; i++)
	{
		int n;

		cin >> n;

		string inputWord;
		long double max_strength = 0;

		for (size_t j = 0; j < n; j++)
		{
			cin >> inputWord; 
			
			int a, b;
			a = b = 0;

			for (size_t k = 0; k < inputWord.length(); k++)
			{
				if ('a' <= inputWord.at(k) && 'z' >= inputWord.at(k)) a++;
				else if ('0' <= inputWord.at(k) && '9' >= inputWord.at(k)) b++;
			}
			long double new_strength = a*log(26) + b;

			if (new_strength > max_strength )
			{
				max_strength = new_strength;
				topWords[i] = inputWord;
			}
			else if (new_strength == max_strength) // strength가 같으면 
			{
				if (inputWord < topWords[i]) {
					max_strength = new_strength;
					topWords[i] = inputWord;
				}
			}
		}
	}

	for (int i = 0; i < c; i++)
	{
		cout << topWords[i]<<endl;
	}

	_getch();
	return 0;
}