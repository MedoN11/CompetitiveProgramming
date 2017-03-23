import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BearAndJumps
{


	static ArrayList<Integer> tree[];
	static int n,K;
	static long down[];
	static long cnt[][];
	static long allCnt[][];
	static long ans[];

	public static void dfs(int u,int p)
	{

		for(Integer v : tree[u])
		{
			if(v == p)
				continue;
			dfs(v,u);
			down[u] += down[v] + cnt[v][0] + 1;
			cnt[u][1 % K]++;
			for(int k = 0 ; k < K ; ++k)
			{
				cnt[u][(k + 1) % K] += cnt[v][k];
			}
			
		}

	}


	public static void dfs2(int u,int p,long prCnt[])
	{
		allCnt[u] = cnt[u];
		ans[u] += down[u];
		if(p != -1)
		{	
			
			ans[u]++;
			allCnt[u][1 % K]++;
			for(int k = 0 ; k < K ; ++k)
				allCnt[u][(k + 1) % K] += prCnt[k];
			ans[u] += prCnt[0];
		}
		for(Integer v : tree[u])
		{
			if(v == p)
				continue;
			long tmp[] = new long[10];
			ans[v] += ans[u] - down[v] - 1 - cnt[v][0];
			for(int k = 0 ; k < K ; ++k)
			{

				tmp[k] = allCnt[u][k];
			}
			
			for(int k = 0 ; k < K ; ++k)
				tmp[(k + 1) % K] -= cnt[v][k];

			tmp[1 % K]--;

			dfs2(v,u,tmp);
		}
	}
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); K = sc.nextInt();
		down = new long[n];
		ans = new long[n];
		cnt = new long[n][K];
		tree = new ArrayList[n];
		for(int i = 0 ; i < n ; ++i)
			tree[i] = new ArrayList();
		int u,v;
		ans = new long[n];
		for(int i = 0 ; i < n - 1 ; ++i)
		{
			u = sc.nextInt(); v = sc.nextInt();
			--u; --v;
			tree[u].add(v);
			tree[v].add(u);
		}
		allCnt = new long[n][K];
		dfs(0,-1);


		dfs2(0,-1,new long[K]);
		long res = 0;
		for(int i = 0 ; i < n ; ++i)
			res += ans[i];
	
		if(res % 2 == 1)
			throw new Exception();
		System.out.println(res >> 1);

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
