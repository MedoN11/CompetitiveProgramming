package Sheet1;

import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeSet;

public class KSubstring 
{

	
	public static void main(String[]args)throws Throwable
	{
		int arr[] = maxSubstring(8,19,17,2093,12);
		System.out.println(arr[0] +" "+arr[1]);
	}
	static long arr[],prefix[];
	static class Pair
	{
		int idx;
		long val;
		public Pair(int idx,long val) 
		{
			this.idx = idx;
			this.val = val;
		}
	}
	public static int[] maxSubstring(int a0,int x,int y,int m,int n)
	{
		arr = new long[n]; prefix = new long[n];
		arr[0] = a0;
		prefix[0] = a0;
		for(int i = 1 ; i < n ; ++i)
		{
			arr[i] = (1L*arr[i - 1]%m * x%m + y%m) %m ;
			prefix[i] = arr[i];
			prefix[i] += prefix[i - 1];
		}
		
		long ans = 1L << 62;
		int res = -1;
		for(int k = n ; k >= 1 ; --k)
		{
			TreeSet<Long> set = new TreeSet();
			Queue<Pair> q = new LinkedList();
			for(int i = 0 ; i < n ; ++i)
			{
				if(i + k - 1 >= n)
					continue;
				long sum = prefix[i + k - 1] - (i == 0 ? 0 : prefix[i - 1]);
				q.add(new Pair(i + k,sum));
				while(!q.isEmpty() && q.peek().idx <= i)
				{
					set.add(q.poll().val);
				}
				Long upper = set.ceiling(sum);
				Long lower = set.floor(sum);
				if(upper != null && Math.abs(upper - sum)  < ans)
				{
					ans = Math.abs(upper - sum);
					res = k;
				}
				if(lower != null && Math.abs(lower - sum)  < ans)
				{
					ans = Math.abs(lower - sum);
					res = k;
				}
				
			}
		}
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = i + 1 ; j < n ; ++j)
			{
				if(Math.abs(arr[j] - arr[i]) < ans)
				{
					ans = Math.abs(arr[j] - arr[i]);
					res = 0;
				}
			}
		}
	int a[] = {res,(int)ans};
	return a;
	
	}
}
