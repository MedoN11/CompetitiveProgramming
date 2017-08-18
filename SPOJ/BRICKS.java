import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class PWORDS 
{

	// Observation + BIT
	// Problem can be phrased as follows
	// Given String a and requests of the form move a non previously moved character c to position i such that for each request i = i + 1
	// and first request has i = 1
	// String B is how the requests arrive
	// In this case it's optimal to get the first non matched character because in all cases
	// it will lead to a lower bound on maximum number of swaps needed
	
	// So solution is at each step the current request will contribute curr - i + (how many characters after curr moved back as they will chage curr position)
	// it's standard variation of BIT to update ranges, and query a point.
	static int bit[] = new int[1 << 19];
	static int lim;

	static int query(int ind)
	{
		ind++;
		int s = 0;
		while(ind > 0)
		{
			s += bit[ind];
			ind -= ind & - ind;
		}
		return s;
	}
	static void upd(int r)
	{
		add(0,1);
		add(r + 1,-1);
	}
	
	static void add(int ind,int delta)
	{
		ind++;
		while(ind < lim)
		{
			bit[ind] += delta;
			ind += ind & - ind;
		}
	}

	public static void main(String[]args)throws Throwable
	{

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		int tc = 1;
		Queue<Integer> q[] = new LinkedList[26];
		for(int i = 0 ; i < 26 ; ++i) q[i] = new LinkedList();
		String a,b;
		boolean g[][];
		while(t-- > 0)
		{
			for(int i = 0 ; i < 26 ; ++i) q[i].clear();
			g = new boolean[26][26];
			a = sc.next();
			b = sc.next();
			int k = sc.nextInt();
			while(k-- > 0)
			{
				String x = sc.next();
				g[x.charAt(0) - 'a'][x.charAt(1) - 'a'] = g[x.charAt(1) - 'a'][x.charAt(0) - 'a'] = true;
			}
			if(a.length() != b.length())
			{
				out.println("-1");
				continue;
			}
			long mod = 1L << 32;
			int n = a.length();
			// solve
			for(int i = 0 ; i < n ; ++i) 
			{
				q[a.charAt(i) - 'a'].add(i);
				bit[i] = 0;
			}
			bit[n + 1] =   bit[n] = 0;
			long steps = 0;
			lim = n + 1;
			for(int i = 0 ; i < n ; ++i)
			{

				char nxt = b.charAt(i);
				if(q[nxt -'a'].isEmpty())
				{
					steps = -1;
					break;
				}
				int curr = q[nxt - 'a'].poll();
				for(int j = 0 ; j < 26 ; ++j)
				{
					if(steps == -1)
						break;
					char here = (char)(j + 'a');
					if(!q[j].isEmpty())
					{
						if(q[j].peek() <= curr && !g[nxt - 'a'][here - 'a'])
							steps = -1;
					}
				}
				if(steps == -1)
					break;
				steps += curr - i + query(curr);
				while(steps >= mod) steps -= mod;
				upd(curr);


			}
			
		
			out.println(steps);

		}
		out.flush();
		out.close();

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