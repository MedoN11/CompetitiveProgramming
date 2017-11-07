import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class KOPC12B {


	// let's phrase the problem as picking i boys and n - i girls to form a group of size n
	// this can be seen as picking n people from 2n people
	// imagine first n is zeros, and second is 1's
	// picking n from these two concatenated togther would get all groups 
	// also known as vandermond's identity

	// now imagine that the i here stands for picking a leader from the boys
	// assume we picking n people from 2n
	// we can pick a leader in n ways
	// but we will over count because we will include girls too
	// notice that in half of the cases leader will be a boy so divide by 2
	static long mod = 1000*1000*1000 + 7;
	static long fact[] = new long[3000000 + 5];

	static long put(long x,long y)
	{
		long p = 1;
		for(int i= 1 ; i <= y; i<<=1 )
		{
			if((y & i) > 0) { p= (1L*p*x) %mod;

			}
			x = (1L*x*x) %mod;
		}
		return p;
	}

	static long nCk(int n,int m)
	{
		if(m == 0)
			return 1;
		return (1L * fact[n] * put( (1L * fact[m] * fact[n-m] ) % mod, mod - 2 ))%mod;
	}
	static long fast(int n,int r)
	{

		return ((nCk(n,r)%mod))%mod;
	}
	public static void main(String[]args)throws Throwable {

		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		fact[0] = 1;
		for(int i=1;i < 3000005;i++) fact[i] =( 1L * fact[i-1] *i )%mod;
		int t = sc.nextInt();
		while(t-- > 0) {
			long two = 500000004;
			int n = sc.nextInt();
			out.printf("%d\n",((n*nCk(2*n,n)%mod)*two)%mod);

		}

		out.flush();
		out.close();
	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }
		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}


		String next() throws IOException
		{

			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();

		}
		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }
		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }




	}
}
