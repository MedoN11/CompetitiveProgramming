package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class HedgeMazes
{
	static class Edge
	{
		int from;
		int to;
		int id;
		
		public Edge(int from,int to,int id)
		{
			this.from = from;
			this.id = id;
			this.to = to;
			
		}
	}

	static ArrayList<Edge> graph[];
	static int myComp[];
	static int dfs_low[];
	static int dfs_num[];
	static int time = 0;
	static DSU dsu;


	public static void dfs(int u,int p)
	{
		dfs_num[u] = dfs_low[u] = time++;

		for(Edge e : graph[u])
		{

			if(dfs_num[e.to] == -1)
			{
				dfs(e.to,u);
				dfs_low[u] = Math.min(dfs_low[u],dfs_low[e.to]);
				if(dfs_low[e.to]  > dfs_num[u])
				{
					dsu.union(e.to, u);
				}

			}
			else if(e. to != p) dfs_low[u] = Math.min(dfs_low[u], dfs_num[e.to]);
		}
	}

	static int n,e,q;
	
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		while(true)
		{
			n = sc.nextInt(); e = sc.nextInt(); q = sc.nextInt();
			if(n + e + q == 0)
				break;
			graph = new ArrayList[n];
			dfs_num = new int[n];
			dfs_low = new int[n];
			
			myComp = new int[n];

			
			dsu = new DSU(n);
			
			time = 0;
			
			for(int i = 0 ; i < n ; ++i)
			{
				graph[i] = new ArrayList();
				dfs_num[i] = -1;
			}
			for(int i = 0 ; i < e ; ++i)
			{
				int u = sc.nextInt() - 1;
				int v = sc.nextInt() - 1;
				graph[v].add(new Edge(v,u,i));
				graph[u].add(new Edge(u,v,i));
			}
			
			for(int i = 0 ; i < n ; ++i)
			{
				if(dfs_num[i] == -1)
					dfs(i,-1);
			}
			
			for(int j = 0 ; j < q ; ++j)
			{
				int u = sc.nextInt() - 1; int v = sc.nextInt() - 1;
				if(dsu.isSameSet(u, v) )
					out.println("Y");
				else out.println("N");
			}
			out.println("-");
		}
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
	
	static class DSU 
	{
		int rank[];
		int parent[];
		int N;
		int sets;
		int setsize[];

		public DSU(int N){
			this.N = N;
			sets = N;
			parent = new int[N];
			rank = new int[N];
			setsize = new int[N];
			for(int i=0;i<N;i++){ parent[i] = i; setsize[i] = 1; }

		}
		

		public void union(int x,int y)
		{
			if(isSameSet(x,y)) return;
			sets--;
			int xp = getParent(x);
			int yp = getParent(y);
			if(rank[xp]>rank[yp]){ parent[yp] = xp; setsize[xp]+=setsize[yp];}
			else{
				if(rank[xp]==rank[yp]){
					rank[yp]++;
					parent[xp] = yp;
					setsize[yp]+=setsize[xp];
				}
				else
				{ parent[xp] =yp; setsize[yp] += setsize[xp]; }
			}

		}

		public int getParent(int x){
			if(x==parent[x]) return x;
			return parent[x] = getParent(parent[x]);
		}

		public boolean isSameSet(int x,int y){
			return getParent(x)==getParent(y);
		}

		public int numDisjointSets(){
			return sets;
		}
		public int getSetSize(int x){
			return setsize[getParent(x)];
		}



	}

	
}
