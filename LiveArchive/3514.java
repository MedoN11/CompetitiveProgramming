import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.Stack;
import java.util.TreeSet;

public class Cactus_NEERC05
{

	// I do not read multiple cases
	// Code is AC on codeforces though.
	// BCC Tree problem


	static int low[],num[];
	static Stack<Integer> s;
	static int n,m;
	static int l[],r[];
	static int ch = 0;
	static boolean bad = false;
	static int explored = 0;
	static ArrayList<Edge> G[];

	static class Edge
	{
		int v;
		int id;

		public Edge(int v,int id)
		{
			this.v = v;
			this.id = id;
		}
	}

	static BigInteger ans = BigInteger.ONE;
	static int tim = 0;
	static String nodes[] = new String[1000];
	static boolean used[];
	static void dfs(int u,int pind)
	{
		num[u] = low[u] = tim++;
		++explored;
		if(bad)
			return;

		for(Edge e : G[u])
		{

			int v = e.v, ind = e.id;
			if(pind == ind)
				continue;
			if(!used[ind])
			{
				s.push(ind);
				used[ind] = true;
			}
			if(num[u] == 0)
				++ch;

			if(num[v] == -1)
			{
				dfs(v,ind);

				low[u] = Math.min(low[u], low[v]);
				int cnt = 0;
				if(num[u] == 0 && ch > 1 || (num[u] <= low[v] && num[u] != 0))
				{
					TreeSet<Integer> has = new TreeSet();
					while(!s.empty())
					{

						int curr = s.pop();
						has.add(l[curr]);
						has.add(r[curr]);
						++cnt;
						if(curr == ind)
							break;
					}
					if(cnt != 1)
					{

						if(has.size() != cnt)
							bad = true;
						if(cnt != 1)
							cnt++;

						ans = ans.multiply(BigInteger.valueOf(cnt));
					}
				}

			}
			else low[u] = Math.min(low[u],num[v]);

		}

	}


	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt(); m = sc.nextInt();
		G = new ArrayList[n];
		for(int i = 0 ; i < n ; ++i)
			G[i] = new ArrayList();
		low = new int[n];
		num = new int[n];
		for(int i = 0 ; i < n ; ++i)
			low[i] = num[i] = -1;
		int prev = -1;
		int curr = 0;
		int edgeID = 0;
		l = new int[1001*1001];
		r = new int[1001*1001];
		for(int i = 0 ; i < m ; ++i)
		{
			int k = sc.nextInt();
			curr = -1; prev = -1;
			while(k-- > 0)
			{
				curr = sc.nextInt() - 1;
				if(prev != -1)
				{
					G[curr].add(new Edge(prev,edgeID)); G[prev].add(new Edge(curr,edgeID));
					nodes[edgeID] = (curr+1)+" "+(prev+1);
					l[edgeID] = curr;
					r[edgeID] = prev;
					++edgeID;
				}
				prev =  curr;
			}

		}

		used = new boolean[edgeID];
		s = new Stack();
		dfs(0,-1);

		if(s.size() != 1)
		{
			TreeSet<Integer> has = new TreeSet();
			int cnt = 0;
			while(!s.empty())
			{

				curr = s.pop();
				has.add(l[curr]);
				has.add(r[curr]);
				++cnt;

			}
			if(has.size() != cnt)
				bad = true;
			if(cnt != 1)
				cnt++;

			ans = ans.multiply(BigInteger.valueOf(cnt));
		}


		if(explored != n || bad)
			ans = BigInteger.ZERO;
		out.println(ans);
		out.flush();
		out.close();


	}

	static class Scanner
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public Scanner(InputStream stream)
		{
			this.stream = stream;
		}

		int read()
		{
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars){
				curChar = 0;
				try{
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c)
		{
			return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
		}

		boolean isEndline(int c)
		{
			return c=='\n'||c=='\r'||c==-1;
		}

		int nextInt()
		{
			return Integer.parseInt(next());
		}

		long nextLong()
		{
			return Long.parseLong(next());
		}

		double nextDouble()
		{
			return Double.parseDouble(next());
		}

		String next(){
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do{
				res.appendCodePoint(c);
				c = read();
			}while(!isSpaceChar(c));
			return res.toString();
		}

		String nextLine(){
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do{
				res.appendCodePoint(c);
				c = read();
			}while(!isEndline(c));
			return res.toString();
		}

	}
}
