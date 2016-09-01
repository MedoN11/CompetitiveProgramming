import java.util.Arrays;
import java.util.TreeMap;


public class YetAnotherIncredibleMachine {

	static long cnt[] = new long[51];
	static TreeMap<Long,Long> space = new TreeMap();
	
	public static void main(String[]args)throws Throwable
	
	{
		int fst[] = {7};
		int snd[] ={10};
		int trd[] ={3,4};
		System.out.println(countWays(fst,snd,trd));
		
	}
	public static int countWays(int x[], int move[],int balls[])
	{
		Arrays.sort(balls);
		long sum = 0;
		for(Integer b : balls)
		{
			space.put((long)(b),1L);
		}
		for(long i = -20010 ; i <= 20010 ; i++)
		{
			sum += space.get(i) == null ? 0L : space.get(i);
			space.put((long)(i),sum);
		}
		for(int i = 0 ; i < x.length ; i++)
		{
			long R = x[i] + move[i];
			long L = x[i] - move[i];
			for(long k = L ; k <= R ; k++)
			{
				long newL = k;
				long newR = k + move[i];
				if(newR <= R)
				{
					long bs = space.get(newR) - space.get(newL - 1);
					if(bs == 0) cnt[i]++;
				}
			}
		}
		long MOD = 1000*1000*1000 + 9;
		long ans = 1;
		for(int i = 0 ; i < x.length ; i++)
		{
			cnt[i] %= MOD;
			ans *= cnt[i];
			ans%=MOD;
		}
		ans %= MOD;
		return (int)(ans);

	}
}
