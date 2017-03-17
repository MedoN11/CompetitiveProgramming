package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BoringPartition
{
	
	static ArrayList<Integer> tree[];
	static double E[];
	static int sum[];
	static int n;
	
	public static void dfs(int u,int p)
	{
		sum[u] = 1;
		for(Integer v : tree[u])
		{
			if(p != v)
				dfs(v,u);
			sum[u] += sum[v];
		}
	}
	
	public static void solve(int u,int p)
	{
		
		int tot = 0;
		for(Integer v : tree[u])
		{
			if(v != p)
				tot += sum[v];
			
		}
		for(Integer v : tree[u])
		{
			if(v != p)
			{
				E[v] = 1 + E[u] + (tot -  sum[v]) / 2.0;
				solve(v,u);
			}
		}
	}
	public static void main(String[]args)throws Throwable
	{

		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		E = new double[n + 1];
		sum = new int[n + 1];
		tree = new ArrayList[n];
		for(int i = 0 ; i < n ; ++i)
			tree[i] = new ArrayList();
		for(int i = 1 ; i < n ; ++i)
		{
			int p = sc.nextInt(); --p;
			tree[p].add(i);
		}
		dfs(0,-1);
		E[0] = 1;
		solve(0,-1);
		PrintWriter out = new PrintWriter(System.out);
		for(int i = 0 ; i < n ; ++i)
			out.print(E[i] +" ");
		out.flush();
		out.close();
		
	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }

		String next() throws IOException
		{
			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();

		}

		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	}
}
