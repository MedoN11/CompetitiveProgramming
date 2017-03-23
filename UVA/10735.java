import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class EulerCircuit 

{

	// this problem can be transformed into trying to orient undirected edges such that
	// indeg(u) == outdeg(u) for all vertices
	// This can be modelled as a flow problem
	// instead since graph is bipartite we can use easier to code matching
	static ArrayList<Integer> finalGraph[];
	static ArrayList<Integer> G[];
	static boolean seen[];
	static boolean directed[];
	static int edgeLeft[],edgeRight[];
	static int t;
	static int left[],right[];
	static int deg[],need[];
	static int n,m;
	static ArrayList<Integer> path;


	static void euler(int u)
	{
		while(finalGraph[u].size() >= 1)
		{
			int v = finalGraph[u].get(finalGraph[u].size() - 1);
			finalGraph[u].remove(finalGraph[u].size() - 1);
			euler(v);

		}
		path.add(u);
	}
	static boolean match(int u)
	{
		if(seen[u])
			return false;
		seen[u] = true;
		for(Integer v : G[u])
		{
			if(right[v] == -1 || match(right[v]))
			{
				left[u] = v;
				right[v] = u;
				return true;
			}
		}
		return false;
	}
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		t = sc.nextInt();
		boolean in = false;
		while(t-- >0)
		{
			if(in)
				out.println("");
			in = true;
			n = sc.nextInt(); m = sc.nextInt();

			directed = new boolean[m];
			seen = new boolean[n];
			finalGraph = new ArrayList[n];
			G = new ArrayList[n];
			path = new ArrayList();
			for(int i = 0 ; i  < n ; ++i)
			{
				finalGraph[i] = new ArrayList();
				G[i] = new ArrayList();
			}
			left = new int[n]; right = new int[m];
			Arrays.fill(left, -1);
			Arrays.fill(right, -1);
			edgeLeft = new int[m];
			edgeRight = new int[m];
			deg = new int[n];
			need = new int[n];
			int u,v;
			String dir;
			DSU dsu = new DSU(n);
			for(int j = 0 ; j < m ; ++j)
			{
				u = sc.nextInt() - 1; v = sc.nextInt() - 1;
				dir = sc.next();
				directed[j] = dir.equalsIgnoreCase("D");
				edgeLeft[j] = u; edgeRight[j] = v;
				deg[u]++; deg[v]++;
				dsu.union(u,v);
			}
			boolean bad = dsu.numDisjointSets() != 1;
			
			
			for(int i = 0 ; i < n && !bad ; ++i)
			{
				if((deg[i] & 1) == 1)
				{
					bad = true;
				}
			}
			

			for(int i = 0 ; i < n ; ++i)
				need[i] = deg[i] >> 1;
			for(int i = 0 ; i < m && !bad ; ++i)
			{
				if(directed[i])
				{
					--need[edgeLeft[i]];
					if(need[edgeLeft[i]] < 0)
						bad = false;
					right[i] = edgeLeft[i];
					
				}
				else
				{
					G[edgeLeft[i]].add(i);
					G[edgeRight[i]].add(i);
				}
			}
			for(int i = 0 ; i < n && !bad ; ++i)
			{
				while(need[i]-- > 0 && !bad)
				{
					Arrays.fill(seen, false);
					if(!match(i))
					{
						bad = true;
					}
				}
			}
			if(bad)
			{
				out.print("No euler circuit exist\n");

			}
			else
			{

				for(int i = 0 ; i < m ; ++i)
				{
					if(directed[i] || right[i] == edgeLeft[i])
					{

						finalGraph[edgeLeft[i]].add(edgeRight[i]);
					}
					else 
					{

						finalGraph[edgeRight[i]].add(edgeLeft[i]);
					}
				}
				euler(0);
				Collections.reverse(path);
				
				for(int i = 0 ; i < path.size(); ++i)
				{
					if(i != 0)
						out.print(" ");
					out.print(1+path.get(i));
				}
				out.println("");
			}
			
		}
		out.flush();
		out.close();


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
