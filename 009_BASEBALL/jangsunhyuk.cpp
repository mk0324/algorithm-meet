#include<stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int sY, sK;
		
		sY = sK = 0;

		int n = 9;
		while (n--)
		{
			int Y, K;

			scanf("%d %d", &Y, &K);
			sY += Y;
			sK += K;
		}

		if (sY > sK)
			printf("Yonsei\n");
		else if (sY < sK)
			printf("Korea\n");
		else
			printf("Draw\n");
	}
	return 0;
}