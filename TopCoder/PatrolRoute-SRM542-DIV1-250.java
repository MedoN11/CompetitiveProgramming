
public class PatrolRoute {

	static long preX[] = new long[20000+5];
	static long preY[] = new long[20000+5];
	static long MOD = 1000 * 1000 * 1000 + 7;

	public static void main(String[]args)throws Throwable
	{
		System.out.println(countRoute(4000,4000,4000,14000));
	}


	public static int countRoute(int x,int y, int minT,int maxT)
	{
		long ans = 0;

		for(long i = 1 ; i <= x ; i++)
		{
			preX[(int)(2*i)] = (x-i) * (i-1L);
			preX[(int)(2*i)] %=MOD;
		}
		for(long i = 1 ; i <= y ; i++)
		{
			preY[(int)(2*i)] = (long)((y-i) * (i-1));
			preY[(int)(2*i)] %= MOD;
		}

		for(long i = 1 ; i < preY.length; i++){
			preY[(int)(i)] += preY[(int)(i-1)];
			preY[(int)(i)] %=MOD;
		}

		for(long i = 2 ; i <= 2*x ; i++)
		{
			if(maxT - i >= 0 ){
				long t = preX[(int)i];
				long mid = preY[(int)(maxT-i)] - preY[(int)(Math.max(0,minT-i-1))];
				mid += MOD;
				mid %= MOD;
				t *= mid;
				t %= MOD;
				ans += t;
				ans %=MOD;
			}

		}




		ans*=6L;
		ans%=MOD;

		return (int)ans;


	}
}
