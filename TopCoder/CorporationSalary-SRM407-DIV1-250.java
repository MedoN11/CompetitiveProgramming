import java.util.ArrayList;
import java.util.Arrays;


public class CorporationSalary {

	static ArrayList<Integer> Graph[] = new ArrayList[60];
	static int diff = 0;
	static int comps = 0;
	static boolean[] seen = new boolean[60];
	static long DP[] = new long[60];


	static	long dfs(int idx)
	{

		if(DP[idx] != -1) return DP[idx];
		int childs = 0;
		DP[idx] = 0;
		for(Integer k : Graph[idx])
		{
			if(seen[k]) continue;
			DP[idx] += dfs(k);
			++childs;

		}
		if(childs == 0) DP[idx]++;

		return DP[idx];

	}
	public static long totalSalary(String[] str)
	{
		Arrays.fill(DP,-1);
		Arrays.fill(seen,false);
		for(int i = 0 ; i < str.length ; i ++) Graph[i] = new ArrayList();
		for(int i = 0 ; i < str.length ; i++)
		{

			for(int j = 0 ; j < str[i].length() ; j++)
			{
				if(str[i].charAt(j) == 'Y')
				{
					Graph[i].add(j);

				}
			}
		}

		long sum = 0;
		for(int i = 0 ; i < str.length ;i ++)
		{

			sum += dfs(i);
		}

		return sum;
	}
}
