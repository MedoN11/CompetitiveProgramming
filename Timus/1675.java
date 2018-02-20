import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DyckwordUniformer
{
	// First let's count all n x m binary matrices with a one in each row.
	// The answer is simply (2^(m-1) - 1)^n
	// now we are sure every row is filled, but coloumns might be empty
	// let's erase those with 1 col ,2 col and 3 col
	// but if we do so, we can see we are over removing
	// inclusion inclusion comes in
	// the formula for inclusion is sum(i,0,m) ( (-1)^k * nCk(m,i) * (2^(m-i))^n)
	// once that is calculated we subtracted it from the intial answer
	

	static int maxn = 100005;
	static long fac[] = new long[maxn];
	static long mod = 1000*1000*1000 + 7;

	static long put(long x, long y) {
		long p = 1;
		for(int i= 1 ; i <= y; i<<=1 )
		{
			if((y & i) != 0) p= (1L*p*x) %mod;
			x = (1L*x*x) %mod;
		}
		return p;
	}

	static long nCk(long n,long m) {
		if(n < 0 || m < 0 || m > n)
			return 0;

		return (1L * fac[(int)n] * put( (1L * fac[(int)m] * fac[(int)(n-m)] ) % mod, mod - 2 ))%mod;
	}
	static int n,m,k,l;
	static long modPow(long n,long p) {
		if(p == 0)
			return 1;
		if(p == 1)
			return n;
		long mid = modPow(n, p >> 1);
		mid *= mid;
		mid %= mod;
		if((p & 1) > 0) mid *= n;
		mid %= mod;
		return mid;
	}
	public static long count(int n,int m) {


		long ways = modPow(modPow(2,m) - 1,n);
		ways %= mod;
		for (int i = 1 ; i <= m ; ++i) {

			if(i % 2 == 0) {

				ways += (nCk(m,i)*modPow(modPow(2,m - i) - 1,n))%mod;
				ways %= mod;
			}
			else  {
				ways -= (nCk(m,i)*modPow(modPow(2,m - i) - 1,n))%mod;
				if(ways < 0) ways += mod;
				ways %= mod;
			}
		}
		return ways;
	}
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		fac[0] = 1;
		for (int i = 1 ; i < maxn ; ++i) {
			fac[i] = i * fac[i - 1];
			fac[i] %= mod;
		}
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		l = sc.nextInt();
		long p = 1L*nCk(n,k)%mod * nCk(m,l)%mod;
		p %= mod;
		p *= count(n - k,m - l);
		p %= mod;
		System.out.println(p);


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