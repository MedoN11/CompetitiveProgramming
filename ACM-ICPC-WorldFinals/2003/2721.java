package WF2003;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BuildingBridges
{


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


	static boolean seen[][];
	static char grid[][];
	static int n,m;
	static int comps[][];
	static int dx[] = {0,0,1,-1,1,-1,1,-1};
	static int dy[] = {1,-1,0,0,1,-1,-1,1};
	static class Edge implements Comparable<Edge>
	{
		int u;
		int v,cost;
		public Edge(int u,int v,int cost)
		{
			this.u = u;
			this.v = v;
			this.cost = cost;
		}
		@Override
		public int compareTo(Edge o) {
			return this.cost - o.cost;
		}
	}

	static boolean valid(int i,int j)
	{
		return i >= 0 && j >= 0 && i < n && j < m;
	}
	public static void dfs(int i,int j,int ind)
	{
		if(seen[i][j])
			return;
		comps[i][j] = ind;
		seen[i][j] = true;
		for(int k = 0 ; k < 8 ; ++k)
		{
			int xc = i + dx[k];
			int yc = j + dy[k];
			if(valid(xc,yc) && grid[xc][yc] == '#')
				dfs(xc,yc,ind);
		}

	}

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int city = 1;
		boolean start = true;
		while(true)
		{
			
			n = sc.nextInt(); m = sc.nextInt();
			if(n + m == 0)
				break;
			seen = new boolean[n][m];
			grid = new char[n][m];
			comps = new int[n][m];
			if(!start)
				out.print("\n");
			start = false;
			

			for(int i = 0 ; i < n ; ++i)
			{
				String str = sc.next();
				for(int j = 0 ; j < m ; ++j)
				{
					grid[i][j] = str.charAt(j);
				}

			}
			int ind = 0;
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < m ; ++j)
				{
					if(seen[i][j] || grid[i][j] != '#')
						continue;
					dfs(i,j,ind++);
				}
			}

			ArrayList<Edge> edges = new ArrayList();
			int offset[] = {0,1,-1};
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < m ; ++j)
				{
					for(int k = 0 ; k < m ; ++k)
					{
						for(int f = 0 ; f < 3 ; ++f)
						{
							int xi = offset[f] + i;
							if(valid(xi,k) && grid[i][j] == grid[xi][k] && grid[i][j] == '#')
							{
								if(comps[i][j] != comps[xi][k])
								{
									edges.add(new Edge(comps[i][j],comps[xi][k],Math.max(0,Math.abs(j - k) - 1)));
								}
							}
						}
					}
				}
			}

			for(int f = 0 ; f < m ; ++f)
			{
				for(int i = 0 ; i < n ; ++i)
				{
					for(int j = 0 ; j < n ; ++j)
					{
						for(int k = 0 ; k < 3 ; ++k)
						{
							int xf = f + offset[k];
							if(valid(j,xf) && grid[i][f] == grid[j][xf] && grid[i][f] == '#')
							{
								if(comps[i][f] != comps[j][xf])
								{
									edges.add(new Edge(comps[i][f],comps[j][xf],Math.max(0, Math.abs(i - j) - 1)));
								}
							}
						}
					}
				}
			}

			int cost = 0;
			int bridges = 0;
			Collections.sort(edges);
			DSU dsu = new DSU(ind);
			for(Edge e :edges)
			{
				if(dsu.isSameSet(e.u, e.v))
					continue;
				dsu.union(e.u, e.v);
				cost += e.cost;
				++bridges;
			}
			//cost >>= 1;
			out.printf("City %d\n",city++);
			if(ind <= 1)
			{
				out.println("No bridges are needed.");
			}
			else
			{
				if(edges.size() == 0)
					out.printf("No bridges are possible.\n");
				else if(bridges == 1)
					out.printf("1 bridge of total length %d\n",cost);
				else out.printf("%d bridges of total length %d\n", bridges,cost);
				if(dsu.numDisjointSets() > 1)
					out.printf("%d disconnected groups\n",dsu.numDisjointSets());

			}
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

		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }


	}
}
