import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class JackPot 

{
	
	
	
	static int cntA[] = new int[26];
	static int cntB[] = new int[26];
	static int cntC[] = new int[26];

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		while(tc-- > 0)
		{
			String a,b,c;
			int x,y,z;
			x = sc.nextInt(); y = sc.nextInt(); z = sc.nextInt();
			a = sc.next().toLowerCase(); b = sc.next().toLowerCase(); c = sc.next().toLowerCase();
			Arrays.fill(cntA, 0);
			Arrays.fill(cntB, 0);
			Arrays.fill(cntC, 0);
			for(int i = 0 ; i < a.length() ; ++i)
				cntA[a.charAt(i) -'a']++;
			for(int i = 0 ; i < b.length() ; ++i)
				cntB[b.charAt(i) -'a']++;
			for(int i = 0 ; i < c.length() ; ++i)
				cntC[c.charAt(i) -'a']++;
			double ret = 0;
			for(int i = 0 ; i < 26 ; ++i)
			{
				double p =  1.0*((double)cntA[i] / x) * ((double)cntB[i] / (y)) * ((double)cntC[i] / z);
				ret += p * 2.0 * 5;
				ret += p * 2.0 * 7;
				ret += p * 10.0;
			}
			out.printf("%.4f\n", ret);

			
		}
		out.flush();
		out.close();
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
