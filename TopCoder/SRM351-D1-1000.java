
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ELR {

	// For each cell initially has a range [-inf,inf]
	// then it gets bounded each by the cells to it's left and right
	// after processing each cell has a range [x,y] it can occupy
	// imagine a graph between each cell, and the respective range
	// we need maximum matching between cells, and all these nodes.
	// We also need lexographically minimum matching for it to satisify printing constraints
	// so each time try to match a cell by bruteforce, then check if rest form a perfect matching
	public static void main(String[]args) throws Throwable {
		String[] a = {"?? ?? 20 ?? ??", 
				"?? ?? ?? ?? ??", 
				"?? ?? ?? 05 ??", 
				"?? ?? ?? ?? ??", 
		"?? ?? ?? ?? ??"};
		String t[] = completeTheSquare(a);
		for (int i = 0 ; i < t.length ; ++i) {

			System.out.println(t[i]);


		}
	}
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
				//System.out.println(u);
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
			if(dist[u] < dist[NIL]) {
				
				for(int v : g[u]) {
					
					if(dist[pair_V[v]] == INF) {
						dist[pair_V[v]] = dist[u] + 1;
						
						q.add(pair_V[v]);
					}
				}
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


	public static String[] completeTheSquare(String[] res) {
		n = 5;
		m = 5;
		int l[][] = new int[n][m];
		int r[][] = new int[n][m];
		int mat[][] = new int[n][m];
		for (int i = 0 ; i < n ; ++i) {
			StringTokenizer st = new StringTokenizer(res[i]);
			for (int j = 0 ; j < n ; ++j) {
				String cur = st.nextToken();
				if (!cur.equals("??")) {
					l[i][j] = new Integer(cur) - 1;
					r[i][j] = new Integer(cur) - 1;
					mat[i][j] = new Integer(cur) - 1;
				} else {
					mat[i][j] = -1;
				}
			}
		}
		for (int i = 0 ; i < n ; ++i) {
			int low = -1, high = 25;
			for (int j = 0 ; j < n ; ++j) {
				if (mat[i][j] != -1) {
					low = mat[i][j];
				} else {
					l[i][j] = low + 1;
				}
			}
			for (int j = n - 1 ; j >= 0 ; --j) {
				if (mat[i][j] != -1) {
					high = mat[i][j];
				} else {
					r[i][j] = high - 1;
				}
			}
		}
		g = new ArrayList[26];
		for (int i = 0 ; i < 26 ; ++i) {
			g[i] = new ArrayList();
		}
		for (int i = 0 ; i < n ; ++i) {

			for (int j = 0 ; j < m ; ++j) {

				for (int k = 0 ; k < 25 ; ++k) {

					if (k >= l[i][j] && k <= r[i][j]) {

						g[i * m + j + 1].add(k + 1);

					} 
				}

			}

		}
		n = 25;
		m = 25;
		int x = hopcroftKarp();
		System.out.println(x);
		if (x != 25) return new String[] {};
		boolean doneLeft[] = new boolean[25], doneRight[] = new boolean[25];
		int ans[] = new int[25];
		int done = 24;
		for (int i = 0 ; i < 5; ++i) {
			for (int j = 0 ; j < 5 ; ++j) {
				for (int k = l[i][j] ; k <= r[i][j] ; ++k) {
					if (doneRight[k]) {
						continue;
					}
					g = new ArrayList[26];
					for (int ii = 0 ; ii < 26 ; ++ii) {
						g[ii] = new ArrayList();
					}
					for (int ii = 0 ; ii < 5 ; ++ii) {

						for (int jj = 0 ; jj < 5 ; ++jj) {

							for (int kk = l[ii][jj] ; kk <= r[ii][jj] ; ++kk) {
								if (doneLeft[ii * 5 + jj] || doneRight[kk])
									continue;
								if (k == kk || (ii == i && j == jj)) {
									continue;
								}
								if (kk >= l[ii][jj] && kk <= r[ii][jj]) {

									g[ii * 5 + jj + 1].add(kk + 1);

								} 
							}

						}

					}
					int tmp = hopcroftKarp();
					
					if (tmp == done) {
						System.out.println(k);
						--done;
						ans[i * 5 + j] = k;
						doneLeft[i * 5 + j] = true;
						doneRight[k] = true;
						break;
					}
				}
			}
		}
		String ret[] = new String[5];
		//System.out.println(solveAssignmentProblem(a));
		for (int i = 0 ; i < 5 ; ++i) {
			String cur = "";
			for (int j = 0 ; j < 5 ; ++j) {
				String tmp = ""+(ans[i * 5 + j] + 1);

				if(tmp.length() < 2) {
					tmp = '0' + tmp;

				}

				if (j != 0)  {
					cur += " " + tmp;
				}
				else {
					cur += tmp;
				}
			}

			ret[i] = cur;
		}
		return ret;
	}

}