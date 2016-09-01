import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;


public class Egalitarianism {

	static ArrayList<Integer> Graph[] = new ArrayList[60];
	static int diff = 0;
	static int comps = 0;
	static boolean[] seen = new boolean[60];
	static int cost[] = new int[60];


	public static void main(String[]args)throws Throwable
	{
		String s[] = {"NYNYYYN",
				"YNNYYYN",
				"NNNNYNN",
				"YYNNYYN",
				"YYYYNNN",
				"YYNYNNY",
		"NNNNNYN"};
		System.out.println(maxDifference(s,5));
	}
	static class Node
	{
		int idx;
		int curr_val;

		public Node(int idx,int curr_val)
		{
			this.idx = idx;
			this.curr_val = curr_val;
		}
	}
	public static void bfs(int idx)
	{
		Queue<Node> Q = new LinkedList();
		Q.add(new Node(idx,0));
		while(!Q.isEmpty())
		{
			Node v = Q.poll();
			if(seen[v.idx]) continue;
			seen[v.idx] = true;
			cost[v.idx] = v.curr_val;
			for(Integer k : Graph[v.idx])
			{
				if(seen[k]) continue;
				Q.add(new Node(k,v.curr_val+diff));
			}
		}
	}
	public static int maxDifference(String[]str,int d)
	{
		diff = d;
		Arrays.fill(seen,false);
		for(int i = 0 ; i < str.length ; i ++) Graph[i] = new ArrayList();
		for(int i = 0 ; i < str.length ; i++)
		{

			for(int j = 0 ; j < str[i].length() ; j++)
			{
				if(str[i].charAt(j) == 'Y')
				{
					Graph[i].add(j);
					Graph[j].add(i);
				}
			}
		}
		for(int i = 0 ; i < str.length ; i++)
		{
			if(!seen[i]) {
				System.err.println(i);
				bfs(i);
				++comps;
			}
		}

		if(comps >= 2) return -1;

		int ans = 0;
		for(int k = 0 ; k < str.length ; k++)
		{
			Arrays.fill(seen,false);
			Arrays.fill(cost,0);

			bfs(k);

			for(int i = 0 ; i < str.length ; i++)
			{
				for(int j = 0 ; j < str.length ; j++)
				{
					ans = Math.max(ans,Math.abs(cost[i]-cost[j]));
				}
			}
		}
		return ans;

	}
}
