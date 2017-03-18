import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {



	public static void bad()
	{
		System.out.println("Impossible");
		System.exit(0);
	}
	public static long get(long x)
	{
		long lo = 0; long hi = x;
		long ans = -1;
		while(lo <= hi)
		{
			long mid = lo + (hi - lo) / 2L;

			if(mid * (mid + 1) / 2 >= x)
			{
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		if(ans * (ans + 1) / 2 != x)
			bad();
		return ans;

	}
	
	static void shot(long zeros,long ones,long a10,long a01)
	{
		if(zeros * ones != (a10 + a01))
			return;
		PrintWriter out = new PrintWriter(System.out);
		if(ones + zeros == 0)
			out.println(1);
			
		while(ones + zeros > 0)
		{
			if(a01 >= ones)
			{
				out.print(0);
				a01 -= ones;
				--zeros;
			}
			else
			{
				out.print(1);
				a10 -= zeros;
				--ones;
			}
		}
	
		out.flush();
		out.close();
		System.exit(0);
	}
	public static void main(String[] args) throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		long a00,a01,a10,a11;
		a00 = sc.nextLong(); a01 = sc.nextLong(); a10 = sc.nextLong(); a11 = sc.nextLong();
		
		
		long zeros = get(a00);
		long ones = get(a11);
	
		if(zeros != 0)
			++zeros;
		if(ones != 0)
			++ones;
		shot(zeros,ones,a10,a01);
		if(zeros == 0)
		{
			if(ones == 0)
			{
				shot(1,1,a10,a01);
				shot(1,0,a10,a01);
				shot(0,1,a10,a01);
				shot(0,0,a10,a01);
			}
			shot(0,ones,a10,a01);
			shot(1,ones,a10,a01);
		}
		if(ones == 0)
		{
			shot(zeros,0,a10,a01);
			shot(zeros,1,a10,a01);
		}
		
		bad();
		

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

		int nextLong() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	}
}