package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

// This is NOT my explanation. It's copied from a blog on CF, but my code uses same idea
//  "Boring partition:
// Sort the array in non-increasing order. Array size is n, numbering starts from 1. If we kept all the integers in the same subsequence, the answer would be (a[1] + a[2]) — (a[n-1] + a[n]), which is the difference between the maximal and minimal possible sums, respectively. To make the difference smaller, we need to either : decrease the maximal sum or increase the minimal sum. Since h >= 0, moving a number to another subsequence can only increase the sums. Hence it's impossible to decrease the current maximal sum, so we should try to increase the minimal sum. To do that, we should move the smallest element, a[n], to the other subsequence. Now, a few different scenarios can happen:
// 1) Maximal sum remains a[1] + a[2], minimal sum becomes a[n-1] + a[n] + h, the difference becomes smaller (or equal, if h = 0).
// 2) Maximal sum remains a[1] + a[2], minimal sum becomes a[n-2] + a[n-1], the difference becomes smaller (or equal, if a[n-2] = a[n]).
// 3) Maximal sum becomes a[1] + a[n] + h, minimal sum becomes a[n-2] + a[n-1]. The difference can be larger, equal or smaller.
// Moving more numbers to the other subsequence can't decrease the difference in any scenario. In conclusion, the answer is always either:
// 1) Keep everything in the same subsequence.
// 2) Keep everything in the same subsequence, except the smallest element." 
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
