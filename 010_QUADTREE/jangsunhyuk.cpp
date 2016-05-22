#include <iostream>
#include <string>

using namespace std;

string image[64];

void compressImage(int startPosX,int startPosY,int compressSize)
{
	char imageAt = image[startPosY].at(startPosX);

	int i, j;

	for (i = startPosY; i < startPosY + compressSize; i++)
	{
		for (j = startPosX; j < startPosX + compressSize; j++)
		{
			if (imageAt == image[i].at(j))
				imageAt = image[i].at(j);
			else
			{
				cout << "(";
				compressImage(startPosX, startPosY, compressSize / 2);
				compressImage(startPosX + compressSize / 2, startPosY, compressSize / 2);
				compressImage(startPosX, startPosY + compressSize / 2, compressSize / 2);
				compressImage(startPosX + compressSize / 2, startPosY + compressSize / 2, compressSize / 2);
				cout << ")";
				goto outFor;
			}
		}
	}

outFor:
	//for문을 다 돌았다면
	if (i == startPosY + compressSize && j == startPosX + compressSize) 
		cout << imageAt;
}
int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N;i++)
		cin >> image[i];
	
	compressImage(0,0,N);
	
	return 0;
}