package algo_meet;

import java.util.Scanner;

public class Maze {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		// making matrix
		int node = sc.nextInt();
		int edge = sc.nextInt();
		
		int visited[] = new int[node];
		int matrix[][] = new int[node][node];
		
		for (int i=0; i<edge; i++ )
		{
			int a =sc.nextInt();
			int b =sc.nextInt();
			
			matrix[a-1][b-1] = 1;
			matrix[b-1][a-1] = 1;			
		}
		
		//searching
		int pre_node = 0;
		int cur_node = 1;
		while(true)
		{			
			for (int j=0; j<node; j++ )
			{
				visited[cur_node-1]=1; //mark room visited
				if ( matrix[cur_node-1][j] != 1 || visited[j]==1) continue; //no edge or visited
				else if ( j == node-1 ) {
					cur_node = pre_node;
					break;
				}
				else {
					System.out.print(cur_node+" ");
					pre_node = cur_node;
					cur_node = j+1;
					break;
				}
			}			
		}
	}
}
