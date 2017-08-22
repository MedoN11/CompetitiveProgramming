import java.util.Arrays;

public class OrderOfTheHats {

	static boolean adj[][];
	static int dp[];
	static int n;
	
	// Graphs on DP + Bitmask
	
	// Construct a topological sort of the graph using DP with minimum edge deletions
	// denote the topological sort as t1,t2,t3,t4...tn
	// at every step choose ti to be a non used node from the msk
	// the cost of adding the current edge is the number of nodes connected to it but not active in msk
	// because this is the cost of edges that must be removed so it's dependency can be resolved..also these edges will cause cycle in future
	// by construct cycles will never occur


	public static int solve(int msk)
	{
		if(msk == (1 << n)  - 1)
			return 0;
		if(dp[msk] != -1)
			return dp[msk];
		int ret = 1 << 30;
		for(int i = 0 ; i < n ; ++i)
		{
			if((msk & (1 << i)) != 0)
				continue;
			int pay = 0;
			for(int j = 0 ; j < n ; ++j)
			{
				if( ((msk) & (1 << j)) > 0)
				{
					//if(adj[i][j]) ++pay;
				}
				else if(adj[j][i]) ++pay;
			}
			ret = Math.min(ret,pay + solve(msk | 1 << i));
		}
		return dp[msk] = ret;
	}

	public static void main(String[]args)throws Throwable
	{
		String s[] = {"NYN",
				"NNY",
		"YNN"};
		System.out.println(minChanged(s));
	}
	public static int minChanged(String[] chart)
	{
		n = chart.length;
		adj = new boolean[n][n];
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				if(chart[i].charAt(j) == 'Y')
					adj[i][j] = true;
			}
		}
		dp = new int[1 << n];
		Arrays.fill(dp, -1);
		return solve(0);
	}
}
