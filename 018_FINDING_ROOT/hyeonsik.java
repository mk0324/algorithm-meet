package algorithm;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static final int MAX = 987654321;
	public static int n, arr[][];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] == 0)
					arr[i][j] = MAX;
			}
		}

		int[][] ret = calc2(arr);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ret[i][j] < MAX)
					System.out.print("1 ");
				else
					System.out.print("0 ");
			}
			System.out.println();
		}
	}

	// 1. 플로이드 와샬
	public static int[][] calc(int[][] input) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					int tmp = input[j][i] + input[i][k];
					if (input[j][k] >= tmp) {
						input[j][k] = tmp;
					}
				}
			}
		}
		return input;
	}

	// 2. BFS
	public static int[][] calc2(int[][] input) {
		boolean[][] visited = new boolean[n][n];
		//방문여부 초기화
		for(int i = 0; i<n; i++)
			Arrays.fill(visited[i], false);
		
		Queue<Integer> q = new LinkedList<Integer>();
		for (int i = 0; i < n; i++) {
			q.offer(i);
			while (!q.isEmpty()) {
				int top = q.poll();
				// 현재에서 다른 노드 접근이 가능하면 큐에 삽입한다.
				for (int j = 0; j < n; j++) {
					if (j!= top && visited[i][j] == false && input[top][j] == 1) {
						input[i][j] = 1;
						visited[i][j] = true;
						q.offer(j);
					}
				}
			}
		}
		return input;
	}
}
