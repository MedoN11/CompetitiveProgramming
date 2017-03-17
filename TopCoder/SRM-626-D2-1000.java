package CodeForces;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class NegativeGraphDiv2 {



	public static void main(String[]args)throws Throwable
	{
		int n = 3;
		int a[] = {1,1,2,2,3,3};
		int b[] = {2,3,1,3,1,2};
		int c[] = {1,5,1,10,1,1};
		System.out.println(findMin(n,a,b,c,1));
	}

	static class Edge
	{
		int to;
		int cost;
		int from;

		public Edge(int from,int to,int cost)
		{
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
	}

	static ArrayList<Edge> edges;
	static long INF = 1L << 61;

	public static long findMin(int N,int[] s,int t[],int w[],int chrg)
	{
		edges = new ArrayList();
		for(int i = 0 ; i < s.length ; ++i)
		{
			edges.add(new Edge(s[i] - 1,t[i] - 1,w[i]));
		}
		long DP[][] = new long[chrg + 1][N];
		for(int i = 0 ; i <= chrg ; ++i)
			for(int j = 0 ; j < N ; ++j)
				DP[i][j] = INF;
		DP[0][0] = 0;

		for(int i = 0 ; i <= chrg ; ++i)
		{
			if(i > 0)
			{
				for(int j = 0 ; j < N ; ++j)
					DP[i][j] = DP[i - 1][j];
			}
			for(int j = 0 ; j <= N ; ++j)
			{
				for(Edge e : edges)
				{
					// do not apply charge
					DP[i][e.to] = Math.min(DP[i][e.to],DP[i][e.from] + e.cost);
					// apply
					if(i > 0)
					{
						DP[i][e.to] = Math.min(DP[i][e.to],DP[i - 1][e.from] + -1L*e.cost);
					}
				}
			}
		}


		return DP[chrg][N - 1];
	}
}
