import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class ELR {


	// Graphs - Top sort
	
	// Create a directed graph from the given strings
	// Edge between s[i] and s[j] if s[i][n-1] == s[j][0]
	// compress strings to get middle elements not equal to borders
	// Handle impossible case alone by taking any top sort and checking it's valid string. ( If one are valid, it can be seen any will be valid).
	// Handle many case by checking there is only one valid top sort

	
	static boolean cycle;
	static int vis[];
	static boolean same(String s,char c) {
		for (int i = 0 ; i < s.length() ; ++i) {
			if (s.charAt(i) != c) {
				return false;
			}
		}
		return true;
	}
	static String compress(String s) {
		int l = 1, r = s.length() - 2;
		while (l < s.length() && s.charAt(l) == s.charAt(l - 1)) {
			++l;
		}
		while (r >= 0 && s.charAt(r) == s.charAt(r + 1)) {
			--r;
		}
		String tmp = "";
		for (int i = l ; i <= r ; ++i) {
			tmp += s.charAt(i);
		}
		System.out.println(tmp);
		return tmp;
	}
	public static void dfs(int u,ArrayList<Integer> g[]) {
		vis[u] = 1;
		for (Integer v : g[u]) {
			if (vis[v] == 1) {
				cycle = true;
			}
			if (vis[v] == 0) {
				dfs(v,g);
			}
		}
		vis[u] = 2;
	}
	static String con = "";
	public static void dfs2(int u,ArrayList<Integer> g[],ArrayList<String> cand) {
		vis[u] = 1;
		con += cand.get(u);
		for (Integer v : g[u]) {

			if (vis[v] == 0) {
				dfs2(v,g,cand);
			}
		}
		vis[u] = 2;
	}

	static boolean ok(String s) {
		int n = s.length();

		for (int i = 0 ; i < n ; ++i) {
			boolean cross = false;
			for (int j = i + 1; j < n ; ++j) {
				if (s.charAt(j) != s.charAt(i)) {
					cross = true;
				} else {
					if (cross) {
						return false;
					}
				}
			}
		}
		return true;
	}
	static String restore(String[] parts) {
		ArrayList<String> cand = new ArrayList();
		ArrayList<String> compressedCand = new ArrayList();
		boolean done[] = new boolean[parts.length];
		boolean initBad = false;
		for (int i = 0 ; i < parts.length ; ++i) {
			if (!ok(parts[i])) {
				return "IMPOSSIBLE";
			}
			if (done[i]) {
				continue;
			}
			String res = parts[i];
			for (int j = i + 1 ; j < parts.length ; ++j) {
				if (done[j]) {
					continue;
				}
				if (same(parts[j],parts[i].charAt(parts[i].length() - 1))) {
					res += parts[j];
					done[j] = true;
					continue;
				}
				if (same(parts[j],parts[i].charAt(0))) {
					res = parts[j] + res;
					done[j] = true;
				}
			}
			cand.add(res);
			compressedCand.add(compress(res));
		}
		System.out.println(cand.size());
		for (int i = 0 ; i < cand.size() ; ++i) {
			for (int j = 0 ; j < cand.size() ; ++j) {
				if (i == j) {
					continue;
				}
				for (int k = 0 ; k < compressedCand.get(i).length() ; ++k) {
					if (cand.get(j).indexOf(compressedCand.get(i).charAt(k)) != -1) {
						return "IMPOSSIBLE";
					}
				}
			}
		}
		int n = cand.size();
		ArrayList<Integer> g[] = new ArrayList[cand.size()];
		for (int i = 0 ; i < n ; ++i) {
			g[i] = new ArrayList();
		}
		int deg[] = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				if (i == j) {
					continue;
				}
				if (cand.get(i).charAt(cand.get(i).length() - 1) == (cand.get(j).charAt(0))) {
					g[i].add(j);
					System.out.println(i+" "+j);
					++deg[j];
				}
			}
		}


		Queue<Integer> q = new LinkedList();
		vis = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			if (vis[i] == 0) {
				dfs(i,g);
			}
			if (deg[i] == 0) {
				//dfs2(i,g,cand);
				q.add(i);
			}
		}
		Arrays.fill(vis, 0);
		for (int i = 0 ; i < n ; ++i) {
			if (deg[i] == 0) {
				dfs2(i,g,cand);

			}
		}
		System.out.println(con);
		System.out.println(cycle);
		if (cycle || !ok(con)) {
			return "IMPOSSIBLE";
		}

		String ans = "";
		while (!q.isEmpty()) {
			if (q.size() > 1) {
				return "MANY";
			}
			Integer cur = q.poll();
			ans += cand.get(cur);
			for (Integer v : g[cur]) {
				if (deg[v] == 0) {
					continue;
				}
				--deg[v];
				if (deg[v] == 0) {
					q.add(v);
				}
			}
		}
		System.out.println(initBad);
		return initBad? "MANY": ans;

	}
	public static void main(String[]args) throws Throwable {
		String res[] =  {"aaa","a","aa"};
			//{"ddde", "ddddd", "cccccc", "ccccoo", "oooodd", "cccccc", "ooooooo", "oo", "eeeeeeeee", "ee", "ddddddd"};
		System.out.println(restore(res));
	}



}