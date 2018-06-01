import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ELR {


	// Problem can be simplified to minimum vertex cover
	// The graph is bipartite, so we can use hopcropft algorithm in O(E*sqrt(V))
	// then print the solution
	static ArrayList<Integer>[] g;
	static int n,m;
	static int[] pair_U, pair_V, dist;
	static final int NIL = 0, INF = (int)1e9;
	static int hopcroftKarp()
	{
		pair_U = new int[n + 1];	
		pair_V = new int[m + 1];	
		dist = new int[n + 1];

		int matching = 0;
		while(bfs()) {
			for(int u = 1; u <= n; ++u) {
				if(pair_U[u] == NIL && dfs(u)) {
					++matching;
				}
			}
		}
		return matching;
	}	
	static boolean bfs()
	{
		Queue<Integer> q = new LinkedList<Integer>();
		for(int u = 1; u <= n; ++u) {
			if(pair_U[u] == NIL) {
				dist[u] = 0;
				q.add(u);
			}
			else {
				dist[u] = INF;
			}
		}
		dist[NIL] = INF;
		while(!q.isEmpty())
		{
			int u = q.remove();
			if(dist[u] < dist[NIL])
				for(int v : g[u])
					if(dist[pair_V[v]] == INF) {
						dist[pair_V[v]] = dist[u] + 1;
						q.add(pair_V[v]);
					}
		}
		return dist[NIL] != INF;
	}

	static boolean dfs(int u)
	{
		if(u == NIL)
			return true;

		for(int v : g[u]) {
			if(dist[pair_V[v]] == dist[u] + 1 && dfs(pair_V[v])) {
				pair_U[u] = v;
				pair_V[v] = u;
				return true;
			}
		}
		dist[u] = INF;
		return false;


	}
	static boolean vis[];
	static boolean conn[][];
	static ArrayList<Integer> g2[];
	static void dfsMV(int u) {
		System.err.println("here "+u);
		vis[u] = true;
		for (Integer v : g2[u]) {
			if (!vis[v]) {
				dfsMV(v);
			}
		}
	}
	static ArrayList<Integer> getMinVertexCover() {
		g2 = new ArrayList[n + m + 4];
		vis = new boolean[n + m + 4];
		ArrayList<Integer> nodes = new ArrayList();
		for (int i = 0 ; i < n + m + 4 ; ++i) {
			g2[i] = new ArrayList();
		}
		boolean skip[] = new boolean[n + 1];
		ArrayList<Integer> next = new ArrayList();
		for (int i = 1 ; i <= n ; ++i) {
			for (int j = 1 ; j <= m ; ++j) {
				if (conn[i][j + n]) {
					if (pair_U[i] == j) {
						skip[i] = true;
						g2[j + n].add(i);
						next.add(j);
					} else {

						g2[i].add(j + n);
						next.add(j);
					}
				}
			}
		}
		//		for (Integer v : next) {
		//			for (int i = 1 ; i <= n ; ++i) {
		//				if (conn[i][v + n])
		//				skip[i] = true;
		//			}
		//		}
		for (int i = 1 ; i <= n ; ++i) {
			if (!vis[i] && !skip[i]) {
				dfsMV(i);
			}
		}
		for (int i = 1 ; i <= n ; ++i) {
			if (!vis[i] && pair_U[i] > NIL && pair_U[i] < INF) {
				nodes.add(i);
			}
		}
		for (int i = 1 ; i <= m ; ++i) {
			System.err.println(vis[i + n]+" "+pair_V[i]);
			if (vis[i + n] && pair_V[i] > NIL && pair_V[i] < INF) {
				nodes.add(i + n);
			}
		}

		return nodes;
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		while (true) {
			n = sc.nextInt();
			m = sc.nextInt();
			int k = sc.nextInt();
			if (n + m + k == 0) {
				break;
			}
			int f = Math.max(n, m);
			conn = new boolean[n + m  + 2][n + m + 2];
			g = new ArrayList[n + 1];
			for (int i = 0 ; i <= n ; ++i) {
				g[i] = new ArrayList();
			}
			//			pair_U = new int[n + 1];
			//			pair_V = new int[m + 1];
			//			dist = new int[n + 1];
			for (int i = 0 ; i < k ; ++i) {

				int x = sc.nextInt(),y = sc.nextInt();
				g[x].add(y);
				conn[x][y + n] = true;
				conn[y + n][x] = true;

			}
			int res = hopcroftKarp();
			out.print(res);
			ArrayList<Integer> sol = getMinVertexCover();
			for (Integer r : sol) {
				if (r <= n) {
					out.print(" r"+r);
				} else {
					r -= n;
					out.print(" c"+r);
				}
			}
			out.println();

		}

		out.flush();
		out.close();
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}

}