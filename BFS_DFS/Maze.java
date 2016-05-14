package algo_meet;

import java.util.Scanner;

public class Maze2 {

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
		
		int cur_node = 1;
		Integer pre_node[] = new Integer[node]; 
		while(true)
		{			
			for (int j=0; j<node; j++ )
			{
				visited[cur_node-1]=1; //mark room visited
				if ( matrix[cur_node-1][j] != 1 || visited[j]==1) continue; //no edge or visited
				else if ( j == node-1 ) {
					System.out.print(cur_node+" ");
					cur_node = pre_node[cur_node-1];
					break;
				}
				else {		
					System.out.print(cur_node+" ");
					int tmp = cur_node;					
					cur_node = j+1;
					if(pre_node[cur_node-1]==null){
						pre_node[cur_node-1] = tmp;							
					}
									
					break;
				}
			}
			// if every node visited, end
		}
	}
}
