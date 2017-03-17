package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BoringPartition
{
	static Integer n,h;
	static Pair arr[];

	static class Pair implements Comparable<Pair>
	{
		int first,second;

		public Pair(int first,int second)
		{
			this.first = first;
			this.second = second;
		}
		public int compareTo(Pair o) {
			
			return this.first - o.first;
		}
		
		
	}
	public static void main(String[]args)throws Throwable
	{

		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		h = sc.nextInt();
		short ans[] = new short[n];
		Arrays.fill(ans, (short)2);
	
		arr = new Pair[n];
		for(int i = 0 ; i < n ; ++i)
		{
			arr[i] = new Pair(sc.nextInt(),i);
		}	
		Arrays.sort(arr);
		long max = arr[n - 1].first + arr[n - 2].first;
		long min = arr[0].first + arr[1].first;
		long abs = max - min;

	
		//flip
		long max2 = Math.max(arr[n - 1].first + arr[0].first +h, max);
		long cap =  arr[0].first + arr[1].first + h;
		for(int i = 1 ; i < n - 1 ; ++i)
		{
			if(arr[i].first + arr[i + 1].first < cap)
			{
				cap = arr[i].first + arr[i + 1].first;
				break;
			}
		}
		long abs2 = max2 - cap;
		if(abs2 < abs)
		{
			ans[arr[0].second] = 1;
			abs = abs2;
		}
		
		out.println(abs);
		for(int i = 0 ; i < n ; ++i)
			out.print(ans[i]+" ");
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
