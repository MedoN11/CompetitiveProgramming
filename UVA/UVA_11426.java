import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class UVA_11426 {


	// we need to calculate gcd(i,j) for all i < j < n
	// we will bruteforce the j
	// gcd must divide j
	// so for every divisor of j we will fix it as the gcd
	// gcd(x,j) = i 
	// now we need to find all x that fullfill this equation
	// since i | j and i | x, then gcd(x,j) = i * gcd(x/i,j / i)
	// if gcd(x/i,j/i) is not equal to 1, then it contradicts our assumption that the gcd is i
	// so we need to count how many numbers j / i is coprime with
	// it can be done with phi function
	// it needed to implement using harmonic sum trick in nlogn to pass
	static int n;

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		int max = 4000001;
		boolean prime[] = new boolean[max];
		int phi[] = new int[max];
		for(int i = 2 ; i < max ; ++i) {
			prime[i] = true;
			phi[i] = 1;

		}
		for(int i = 2 ; i < max ; ++i) {
			if(prime[i]) {
				phi[i] = i - 1;
				for (int j = i * 2 ; j < max ; j += i) {
					prime[j] = false;
					int k = j;
					int res = 1;
					while(k % i == 0) {
						k /= i;
						res *= i;
					}
					phi[j] *= (res - res / i);
				}
			}
		}
		long F[] = new long[max];
		// gcd(x*i,p*i) = i
		// = i * gcd(i,p)
		for(int i = 1 ; i < max ; ++i) {

			for(int j = i * 2 ; j < max ; j += i) {
				F[j] += 1L*i * phi[j / i];
			}

		}
		for(int i = 1 ; i < max ; ++i) {
			F[i] += F[i - 1];
		}
		PrintWriter out = new PrintWriter(System.out);
		while(true) {
			n = sc.nextInt();
			if( n == 0)
				break;
			out.println(F[n]);

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
