import java.util.*;
import java.lang.*;
import java.io.*;
	
public class Main {

 public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);    
		
		//testCase
		int test = sc.nextInt();
		for(int i=0; i<test; i++)
		{
			
			//numOfDays
			int n = sc.nextInt();
			int stock[] = new int[n];
			for(int j=0; j<n; j++)
			{
				stock[j] = sc.nextInt();
			}
			
			//Profit
			int profit = 0;
			int cur = 0;
			for(int j=0; j<n; j++)
			{
				if(cur>stock[n-1-j])
					profit += cur-stock[n-1-j];
				else { cur = stock[n-1-j]; }
			}
			System.out.println(profit);
		}
	}
} //
	
		
