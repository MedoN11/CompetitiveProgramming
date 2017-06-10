import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Anniversary 
{

	static int n,m;
	static ArrayList<Integer> tree[];
	static int[] tin,tout;

	static class SegmentTree 
	{

		int[] lo,hi;
		long[] delta,color;

		SegmentTree(int n)
		{
			lo = new int[4 * n + 1];
			hi = new int[4 * n + 1]; 
			delta = new long[4 * n + 1]; 
			color = new long[4 * n + 1];

			init(1,0,n - 1);
		}

		void init(int i,int a,int b)
		{
			lo[i] = a; hi[i] = b;
			if(a == b)
			{
				return;
			}
			int mid = (a + b) / 2;
			init(i << 1,a,mid);
			init((i << 1) + 1,mid + 1,b);
			
		}

		void update(int i)
		{
			color[i] = get(i << 1) | get((i << 1) + 1);

		}
		void prop(int i)
		{
			if(delta[i] == 0)
				return;
			delta[i << 1] = delta[i];
			delta[(i << 1) + 1] = delta[i];
			delta[i] = 0;

		}



		long get(int i)
		{
			return delta[i] == 0 ? color[i] : delta[i];
		}
		long query(int i,int a,int b)
		{

			//System.out.println(i+" "+lo[i] + " "+hi[i] +" "+a+" "+b);
			// out of cover

			if(b < lo[i] || hi[i] < a)
				return 0;
			// fully covered
			if(a <= lo[i] && hi[i] <= b)
			{

				return get(i);
			}

			prop(i);

			long ansLeft = query(i << 1,a,b);
			long ansRight = query((i << 1) + 1,a,b);

			update(i);

			return ansRight | ansLeft;
		}
		void color(int i,int a,int b,long val)
		{
			// out of cover
			
			if(b < lo[i] || a > hi[i])
				return;
			// fully covered
			if(a <= lo[i] && hi[i] <= b)
			{

				delta[i] = val;
				return;
			}

			prop(i);


			color(i << 1,a,b,val);
			color((i << 1) + 1,a,b,val);


			update(i);

		}
	}

	static int time = 0;
	static void dfs(int u,int p)
	{
		tin[u] = time++;

		for(Integer v : tree[u])
		{
			if(v == p)
				continue;
			dfs(v,u);
		}


		tout[u] = time - 1;
	}

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); m = sc.nextInt();

		tree = new ArrayList[n];
		for(int i = 0 ; i < n ; ++i) tree[i] = new ArrayList();
		int color[] = new int[n];
		tin = new int[n]; tout = new int[n];
		for(int i = 0 ; i < n ; ++i) color[i] = sc.nextInt();
		for(int j = 0 ; j < n - 1 ; ++j)
		{
			int u = sc.nextInt(), v = sc.nextInt(); 
			--u; --v;
			tree[u].add(v); tree[v].add(u);
		}
		dfs(0,-1);
		SegmentTree st = new SegmentTree(time);
		for(int i = 0 ; i < n ; ++i)
		{
			st.color(1, tin[i], tin[i], 1L << color[i]);
		}
		PrintWriter out = new PrintWriter(System.out);
		for(int j = 0 ; j < m ; ++j)
		{
			int t = sc.nextInt();
			if(t == 1)
			{
				int v = sc.nextInt(), c = sc.nextInt();
				--v;
				st.color(1, tin[v], tout[v], 1L << c);
			}
			else
			{
				int v = sc.nextInt(); --v;
				long msk = st.query(1, tin[v], tout[v]);
				//System.err.println(msk);
				out.println(Long.bitCount(msk));

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
		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}


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