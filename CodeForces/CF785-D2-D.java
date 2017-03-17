import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{

	static char arr[];
	static long sufClose[];
	static long fac[];
	static long mod = 1000*1000*1000 + 7;
	
	static long put(long x, long y)
	{
		long p = 1;
		for(int i= 1 ; i <= y; i<<=1 )
		{
			if((y & i) != 0) p= (1L*p*x) %mod;
			x = (1L*x*x) %mod;
		}
		return p;
	}

	static long nCk(long n,long m)
	{
		return (1L * fac[(int)n] * put( (1L * fac[(int)m] * fac[(int)(n-m)] ) % mod, mod - 2 ))%mod;
	}
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);

		arr = sc.next().toCharArray();
		sufClose = new long[arr.length + 1];
		fac = new long[arr.length + 1];
		fac[0] = 1;
		for(int i = 1 ; i < arr.length + 1;  ++i)
		{
			fac[i] = fac[i - 1] * i; fac[i] %= mod;
		}
		for(int i = arr.length - 1 ; i >= 0 ; --i)
		{
			if(i + 1 < arr.length)
				sufClose[i] = sufClose[i + 1];
			sufClose[i] += arr[i] == ')' ? 1 : 0;
		}
		int before = 0;
		long tot = 0;
		for(int i = 0 ; i < arr.length ; ++i)
		{
			if(arr[i] == '(')
			{

				if(i + 1 < arr.length && sufClose[i + 1] > 0)
				{
					
					tot += nCk(before + sufClose[i + 1],sufClose[i + 1] - 1);
					
					
				}
				before++;
			}



		}

		System.out.println(tot);

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
