import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Anniversary 
{

	static String a,b;
	static int L[],R[];
	static int n,m;
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);

		a = sc.next(); b = sc.next();
		n = a.length(); m = b.length();
		L = new int[n]; R = new int[n];
		int pos[] = new int[26]; Arrays.fill(pos, -1);
		for(int i = 0, j = 0 ; i < n ;  ++i)
		{
			if(j < m && a.charAt(i) == b.charAt(j))
			{
				L[i] = j;
				pos[a.charAt(i) - 'a'] = j++;
				
			}
			else L[i] = pos[a.charAt(i) - 'a'];
		}
		Arrays.fill(pos, 1 << 30);
		for(int i = n - 1 , j = m - 1 ; i >= 0 ; --i)
		{
			if(j >= 0 && a.charAt(i) == b.charAt(j))
			{
				R[i] = j;
				pos[a.charAt(i) - 'a'] = j--;
			}
			else R[i] = pos[a.charAt(i) - 'a'];
		}
		for(int i = 0 ; i < n ; ++i)
		{
			//System.out.println(R[i] + " " + L[i] );
			if(R[i] > L[i])
			{
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");




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