import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class BelandF {

	static ArrayList<Integer> tree[] = new ArrayList[401];
	static int N,K;
	static int DP[][][] = new int [401][401][2];
	static int parent[] = new int[401];
	static int childs[] = new int[401];
	static StringBuilder out = new StringBuilder();
	static TreeMap<Pair,Integer> T = new TreeMap();

	static class Pair implements Comparable<Pair>
	{
		int u;
		int v;
		public Pair(int u,int v)
		{
			this.u = u;
			this.v = v;
		}
		public int compareTo(Pair o) 
		{
			if(this.u == o.u) return this.v  - o.v;
			return this.u - o.u;
		}
	}

	public static void trace(int idx,int rem,int root)
	{
		int ret = 0;


		//System.err.println(idx +" " +rem +" "+root);
		if(root == 1 && childs[idx] == 0)
		{

			if(idx != 0)out.append(T.get(new Pair(idx,parent[idx])));
			return;
		}

		int sol = DP[idx][rem][root];

		if(rem < 0) return;
		if(rem == 0)
		{



			for(int i = tree[parent[idx]].indexOf(idx) ; i < tree[parent[idx]].size() ; i++ )
			{

				out.append(T.get(new Pair(parent[idx],tree[parent[idx]].get(i))) +" ");
			}
			return;
			//return DP[idx][rem][root] = tree[parent[idx]].size() - (tree[parent[idx]].indexOf(idx) );
		}
		if(root == 1)
		{
			int fstCh = tree[idx].get(0);

			if(idx != 0) out.append(T.get(new Pair(idx,parent[idx]))+" ");
			trace(fstCh,rem - 1,0);
			return;
		}

		int myPos = tree[parent[idx]].indexOf(idx);
		boolean must = tree[parent[idx]].size() == myPos + 1 ? true : false;
		int nextBrother = must ? - 1 : tree[parent[idx]].get(myPos + 1);

		if(childs[idx] == 0)
		{
			if(must)
			{

				if(rem == 1) return;
				else ret =  1 << 25;
			}
			else
			{
				if(sol  == solve(nextBrother,rem - 1,0) ) trace(nextBrother,rem - 1, 0);
				else
				{
					out.append(T.get(new Pair(nextBrother,parent[idx])) +" ");
					trace(nextBrother,rem,0);
				}
			}
			return;
		}
		int fstCh = tree[idx].get(0);
		ret = 1 << 25;
		// part of the component



		if(must)
		{
			ret = DP[idx][rem][root] = solve(fstCh,rem - 1,0);
			trace(fstCh,rem - 1,0);
			return;
		}

		for(int k = 1 ; k < rem - 1 ; k++)
		{
			ret = Math.min(ret,solve(fstCh,k,0) + solve(nextBrother,rem - 1 - k,0));
			if(sol == ret)
			{
				trace(fstCh,k,0);
				trace(nextBrother,rem - 1 - k,0);
				return;
			}
		}



		// not part of the component
		ret = Math.min(ret,(1 + solve(nextBrother,rem,0)));
		if(sol == ret)
		{
			out.append(T.get(new Pair(parent[idx],idx))+" ");
			trace(nextBrother,rem,0);
			return;
		}

		return;
	}

	public static int solve(int idx,int rem,int root)
	{
		int ret = 0;

		//System.err.println(idx +" " +rem +" "+root);
		if(root == 1 && childs[idx] == 0)
		{
			if(rem == 1) {

				if(idx != 0)  ++ret;
				return ret;
			}
			else return 1 << 25;
		}

		if(DP[idx][rem][root] != -1) return DP[idx][rem][root];

		if(rem < 0) return 1 << 25;
		if(rem == 0)
		{

			return DP[idx][rem][root] = tree[parent[idx]].size() - (tree[parent[idx]].indexOf(idx) );
		}
		if(root == 1)
		{
			int fstCh = tree[idx].get(0);

			ret = 0;
			if(idx != 0) ++ret;
			return DP[idx][rem][root] = ret + solve(fstCh,rem - 1,0);
		}

		int myPos = tree[parent[idx]].indexOf(idx);
		boolean must = tree[parent[idx]].size() == myPos + 1 ? true : false;
		int nextBrother = must ? - 1 : tree[parent[idx]].get(myPos + 1);

		if(childs[idx] == 0)
		{
			if(must)
			{

				if(rem == 1) return 0;
				else return DP[idx][rem][root] =  1 << 25;
			}
			else
			{
				return DP[idx][rem][root] = Math.min(solve(nextBrother,rem - 1,0),1+solve(nextBrother,rem,0));
			}
		}
		int fstCh = tree[idx].get(0);
		ret = 1 << 25;
		// part of the component



		if(must)
		{
			return DP[idx][rem][root] = solve(fstCh,rem - 1,0);
		}

		for(int k = 1 ; k < rem - 1 ; k++)
		{
			ret = Math.min(ret,solve(fstCh,k,0) + solve(nextBrother,rem - 1 - k,0));
		}



		// not part of the component
		ret = Math.min(ret,(1 + solve(nextBrother,rem,0)));

		return DP[idx][rem][root] = ret;

	}

	public static void dfs(int idx)
	{
		int ch = 0;
		for(Integer k : tree[idx])
		{
			if(k != parent[idx])
			{
				parent[k] = idx;
				dfs(k);
				++ch;
			}
		}
		childs[idx] = (ch);
	}

	public static void construct()
	{
		dfs(0);
		for(int i = 1 ; i < N ; ++i)
		{
			tree[i].remove(tree[i].indexOf(parent[i]));

		}


	}
	public static void main(String[]args)throws Throwable
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < 401 ; ++i) tree[i] = new ArrayList();
		N = new Integer(st.nextToken());
		K = new Integer(st.nextToken());

		Arrays.fill(parent,-1);
		for(int i = 0 ; i < N - 1 ; i++)
		{
			st = new StringTokenizer(br.readLine());
			int u = new Integer(st.nextToken()) - 1;
			int v = new Integer(st.nextToken()) - 1;
			tree[u].add(v);
			tree[v].add(u);

			T.put(new Pair(u,v),i + 1);
			T.put(new Pair(v,u),i+1);
		}
		for(int i = 0 ; i < 401 ; ++i)
		{
			for(int j = 0 ; j < 401 ; ++j)

				for(int k = 0 ; k < 2; k++)
				{
					DP[i][j][k] = -1;
				}
		}


		int sol = 1 << 30;
		construct();


		for(int i = 0 ; i < N ; ++i)
		{
			sol = Math.min(sol,solve(i,K,1));
		}
		for(int i = 0 ; i < N ; ++i)
		{
			if(solve(i,K,1) == sol) 
			{
				trace(i,K,1);
				break;
			}
		}

		//System.out.println(solve(1,K,1));
		System.out.println(sol);
		System.out.println(out);
		//System.out.println(solve(0,K,1));

	}
}