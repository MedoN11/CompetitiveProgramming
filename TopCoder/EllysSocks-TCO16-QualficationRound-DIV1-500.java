import java.util.Arrays;


public class EllysSocks {

	static int arr[];
	static int pairs;
	static boolean taken[] = new boolean[1005];
	public static void main(String[]args) throws Throwable
	{
		int p[] = {42, 37, 84, 36, 41, 42};
		int cnt = 2;
		
		System.out.println(getDifference(p,cnt));
	}
	
	public static boolean can(long d)
	{
		Arrays.fill(taken, false);
		int k = pairs;
		for(int i = 0 ; i < arr.length ;i++)
		{
			if(taken[i]) continue;
			for(int j = i + 1 ; j < arr.length ; j++)
			{
				if(taken[j]) continue;
				if( Math.abs(arr[i] - arr[j]) <= d)
				{
					taken[i] = true;
					taken[j] = true;
					--k;
					break;
				}
			}
		}
		return k <= 0;
		
	}
	public static int getDifference(int[]s,int P)
	{
		arr = s;
		pairs = P;
		Arrays.sort(s);
		
		for(int i = 0 ; i < s.length ;i++)
		{
			System.out.println(arr[i]);
		}
		long lo = 0;
		long hi = 100000000000L;
		long ans = 0;
		while(lo <= hi)
		{
			long mid = lo + (hi-lo)/2;
			
			if(can(mid))
			{
				
				hi = mid - 1;
				ans = mid;
			}
			else lo = mid + 1;
		}
		return (int)(ans);
	}
}
