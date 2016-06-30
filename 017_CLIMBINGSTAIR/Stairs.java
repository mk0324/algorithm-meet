package depromeet.algo;
//윤환 

import java.util.Scanner;

public class Stairs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int st[] = new int[N];
		int dp[] = new int[N];
		for(int i=0; i<N; i++)
		{
			st[i] = sc.nextInt();
		}
		dp[0]=st[0];
		dp[1]=st[0]+st[1];
		dp[2]=Math.max(st[0], st[1])+st[2];
		for(int i=3; i<N; i++)
		{
			dp[i]=Math.max(dp[i-2], dp[i-3]+st[i-1])+st[i];
		}
		
		System.out.println(dp[N-1]);
	}
	

}
