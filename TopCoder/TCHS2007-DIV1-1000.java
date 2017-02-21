package CodeForces;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class Work
{


	public static void main(String[]args)throws Throwable
	{
		int x[] = {1,1};
		int c = 1;
		System.out.println(numberOfWays(x,c));
	}


	public static int binarySearch(ArrayList<Integer> set, int max)
	{
		int lo = 0;
		int hi = set.size() - 1;
		int ans = -1;

		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if(set.get(mid) <= max)
			{
				lo = mid + 1;
				ans = mid;
			}
			else hi = mid - 1;
		}

		return ans + 1;
	}

	public static int numberOfWays(int[] x,int C)
	{

		int n = x.length;
		int half = n >> 1;

			int ans = 0;
			ArrayList<Integer> firstSet = new ArrayList();
			for(int msk = 1 ; msk < (1 << half) ; ++msk)
			{
				int cost = 0;
				for(int i = 0 ; i< half ; ++i)
				{
					if( (msk & (1 << i)) > 0)
					{
						cost += x[i];
					}
				}
				if(cost > C)
					continue;
				ans++;
				firstSet.add(cost);
			}
			Collections.sort(firstSet);
			int rem = n - half;
			System.out.println(n +" "+half+" "+rem);
			for(int msk = 1; msk < (1 << rem ) ; ++msk)
			{
				int cost = 0;
				for(int i = 0 ; i < rem ; ++i)
				{
					int ind = i + half;
					if( (msk & (1 << i) ) > 0)
					{
						cost += x[ind];
					}
				}
				if(cost > C)
					continue;
				++ans;
				ans += binarySearch(firstSet,C - cost);
			}
			ans++;
			return ans;
	}
}
