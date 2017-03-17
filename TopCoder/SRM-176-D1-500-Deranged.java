import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Deranged {


	static long DP[][] = new long[15][1 << 15];
	static int n;
	static int arr[];
	public static long solve(int ind,int msk)
	{
		if(ind == n)
			return 1;
		if(DP[ind][msk] != -1)
			return DP[ind][msk];
		long ret = 0;
		TreeSet<Integer> put = new TreeSet();
		for(int i = 0 ; i < n ; ++i)
		{
			if( (msk & ( 1 << i)) > 0)
				continue;
			if(arr[i] == arr[ind] || put.contains(arr[i]))
				continue;
			put.add(arr[i]);
			ret += solve(ind + 1, msk | (1 << i));
		}
		return DP[ind][msk] = ret;
		
	}
	public static void main(String[]args)throws Throwable
	{
		int a[] = {0,0,0,1,1,1};
		System.out.println(numDerangements(a));
	}
	
	public static long numDerangements(int[] nums)
	{
		arr = nums; n = arr.length;
		for(int i = 0 ; i < nums.length ; ++i)
			--arr[i];
		for(int i = 0 ; i < 15 ; ++i)
			Arrays.fill(DP[i], -1);
		return solve(0,0);
	}

	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;

		Scanner(InputStream s) { br = new BufferedReader(new InputStreamReader(s)); }

		String next() throws IOException
		{
			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }

		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }
	}
}
