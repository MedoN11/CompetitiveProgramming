package WF2016;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BranchAssignment 
{



	static class Edge
	{
		int v,w;
		public Edge(int v,int w)
		{
			this.v = v;
			this.w = w;
		}
	}

	static class Entry implements Comparable<Entry>
	{
		long dis;
		int u;
		public Entry(int u,long dis)
		{
			this.u = u;
			this.dis = dis;
		}
		@Override
		public int compareTo(Entry o) {

			return Long.compare(this.dis, o.dis);
		}
	}

	static int n,b,s,e;
	static ArrayList<Edge> G[],rev[];

	public static void diji(int src,ArrayList<Edge> G[])
	{
		long dis[] = new long[n];
		Arrays.fill(dis, 1L << 59);
		PriorityQueue<Entry> pq = new PriorityQueue();
		pq.add(new Entry(src,0));
		dis[src] = 0;
		while(!pq.isEmpty())
		{
			Entry e = pq.poll();
			if(dis[e.u] < e.dis)
				continue;
			dis[e.u] = e.dis;
			for(Edge ed : G[e.u])
			{
				if(ed.w + dis[e.u] < dis[ed.v])
				{
					dis[ed.v] = ed.w + dis[e.u];
					pq.add(new Entry(ed.v,dis[ed.v]));
				}
			}
		}

		for(int i = 0 ; i < b ; ++i)
			arr[i] += dis[i];


	}
	static long DP[][];

	static long cost(int i,int j,long pre[])
	{

		if(i > j)
			return 1L << 59;
		return (pre[j] - (i == 0 ? 0 : pre[i - 1]))* (j - i);
		
	}

	static int A[][];


	static void fill(int G,int L,int R,int kL,int kR,long pre[])
	{

		if(L > R) return;

		int mid = (L + R) >> 1;

		DP[G][mid] = 1L << 59;

		for(int k = kL ; k <= kR ; ++k)
		{
			long newCost = DP[G - 1][k] + cost(k + 1,mid,pre);

			if(newCost < DP[G][mid])
			{
				DP[G][mid] = newCost;
				A[G][mid] = k;
			}
		}

		fill(G,L,mid - 1,kL,A[G][mid],pre);

		fill(G,mid + 1,R,A[G][mid],kR,pre);
	}
	static long arr[];
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); b = sc.nextInt(); s = sc.nextInt(); e = sc.nextInt();
		G = new ArrayList[n + 1];
		rev = new ArrayList[n + 1];
		for(int i = 0 ; i < n + 1 ; ++i)
		{
			G[i] = new ArrayList();
			rev[i] = new ArrayList();
		}
		for(int i = 0 ; i < e ; ++i)
		{
			int u = sc.nextInt() - 1; int v = sc.nextInt() - 1; int l = sc.nextInt();
			G[u].add(new Edge(v,l));
			rev[v].add(new Edge(u,l));
		}
		arr = new long[b];
		diji(b,G);
		diji(b,rev);
		for(int i = 0 ; i < b ; ++i )
			arr[i] = -arr[i];
		long pre[] = new long[b];
		Arrays.sort(arr);
		for(int i = 0 ; i < b ; ++i)
		{

			arr[i] = -arr[i];
			pre[i] = arr[i];
			if(i > 0)
				pre[i] += pre[i - 1];
		}
		DP = new long[s + 1][n];

		A = new int[s + 1][n];

		for(int i = 0 ; i < b ; ++i)
		{
			DP[1][i] = cost(0,i,pre);
			
		}

		
	
		for(int g = 2 ; g <= s ; ++g)
		{
			
			fill(g,0,b - 1,0,b - 1,pre);
			
		}
		System.out.println(DP[s][b - 1]);


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
