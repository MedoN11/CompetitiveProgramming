import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class AntonAndPermutation 
{


	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		int n;
		int tc = 1;
		int to[];
		PrintWriter out = new PrintWriter(System.out);
		while(true)
		{
			n = sc.nextInt();
			if(n == 0)
				break;
			int p[] = new int[n + 1];
			to = new int[n + 1];
			TreeMap<Integer,Integer> map = new TreeMap();
			int min = 1 << 30;
			for(int i = 1 ; i <= n ; ++i)
			{
				p[i] = sc.nextInt();
				min = Math.min(min, p[i]);
				map.put(p[i], i);
			}
			int ind = 0;
			for(Entry<Integer,Integer> e : map.entrySet())
			{
				to[e.getValue()] = ++ind;
				//System.err.println( +" "+ind);
			}
			
			int ans = 0;
			boolean vis[] = new boolean[n + 1];
			for(int i = 1 ; i <= n ; ++i)
			{
				if(vis[i])
					continue;
				ArrayList<Integer> cycle = new ArrayList();
				int curr = i;
				int minLocal = 1 << 30;
				do
				{
					minLocal = Math.min(minLocal, p[curr]);
					vis[curr] = true;
					cycle.add(curr);
					curr = to[curr];
				}
				while(!vis[curr]);
				
				int sum1 = 0;
				int sum2 = 0;
				for(Integer x : cycle)
				{
					sum1 += p[x];
					sum2 += p[x];
				}
				sum1 -= minLocal;
				sum1 += minLocal*(cycle.size() - 1);
				sum2 -= minLocal;
				sum2 += min * (cycle.size() - 1);
				sum2 += (min + minLocal) << 1;
				ans += Math.min(sum1, sum2);
				

			}
			
			out.printf("Case %d: %d\n\n",tc++,ans);

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
