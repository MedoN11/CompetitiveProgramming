package CodeForces;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class P8XMatrixRecovery
{

	static StringBuilder[] res;



	static int main;
	public static void main(String[]args)throws Throwable
	{
		String a[] = {"??0"
				,"11?"
				,"?01"
				,"1?1"};
		String b[] = {"1???"
				,"?111"
				,"0?1?"};
		String[] ans = solve(a,b);
		for(int i = 0 ; i < ans.length; ++i)
			System.out.println(ans[i]);
	}

	public static int maxMatching(List<Integer>[] graph,int n1, int n2) {
		int[] matching = new int[n2];
		Arrays.fill(matching, -1);
		int matches = 0;
		for (int u = 0; u < n1; u++) {
			if (findPath(graph, u, matching, new boolean[n1]))
				++matches;
		}
		return matches;
	}

	static boolean findPath(List<Integer>[] graph, int u1, int[] matching, boolean[] vis) {
		vis[u1] = true;
		for (int v : graph[u1]) {
			int u2 = matching[v];
			if (u2 == -1 || !vis[u2] && findPath(graph, u2, matching, vis)) {
				matching[v] = u1;
				return true;
			}
		}
		return false;
	}
	static ArrayList<Integer> rowMatches[] = new ArrayList[1001];
	static String rows[], cols[];
	static int R,C;
	static boolean takenL[] = new boolean[1001];
	static boolean takenR[] = new boolean[1001];


	static boolean matches(String str,int ind)
	{
		for(int i = 0 ; i < str.length() ; ++i)
		{
			if(res[i].charAt(ind) == '?' || str.charAt(i) == '?')
				continue;
			if(res[i].charAt(ind) != str.charAt(i))
				return false;
		}
		return true;
	}

	static boolean canMatch()
	{
		for(int i = 0 ; i < 1000; ++i)
			G[i].clear();
		for(int i = 0 ; i < C  ; ++i)
		{

			for(int j = 0 ; j < C ; ++j)
			{

				if(matches(cols[j],i))
				{

					G[i].add(j);
				}
			}
		}
		//	System.out.println(maxMatching(G,idL,idR));
		return maxMatching(G,C,C) == C;
	}


	static ArrayList<Integer> G[] = new ArrayList[1001];
	public static String[] solve(String[]r, String[] c)
	{
		for(int i = 0 ; i < 1001; ++i)
		{
			G[i] = new ArrayList();
			rowMatches[i] = new ArrayList();
		}
		rows = r; cols = c;
		R = rows.length; C = cols.length;
		res = new StringBuilder[R];
		for(int i = 0 ; i < R ; ++i)
		{
			res[i] = new StringBuilder();
			res[i].append(rows[i]);
		}

		for(int i = 0 ; i < R ; ++i)
		{
			for(int j = 0 ; j < res[i].length() ; ++j)
			{
				if(res[i].charAt(j) == '?')
				{
					res[i].setCharAt(j, '0');
					if(!canMatch())
						res[i].setCharAt(j, '1');
				}
				
			}
		}

		String ans[] = new String[R];
		for(int i = 0 ; i < R ; ++i)
		{
			ans[i] = res[i].toString();
		}

		return ans;




	}


}