import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class PWORDS 
{


	// First we bruteforce on how we parition the costs
	// then it changes into a DP problem for each string
	


	static long DP[][][][] = new long[2][10][605][1 << 10];
	static long DP2[][][][] = new long[2][10][605][1 << 10];

	static String a,b;
	static char fst[],snd[];


	static long solve1(int ind,int rem,int f,int msk,int took)
	{
		
		if(rem < 0)
			return 0;
		if(ind == a.length())
			return rem == 0 && f == 0 ? 1 : 0;
		if(DP[f][ind][rem][msk] != -1)
			return DP[f][ind][rem][msk];
		
		long ret = 0;
		TreeSet<Character> seen = new TreeSet();
		for(int i = 0 ; i < fst.length ; ++i)
		{
			if( (msk & (1 << i)) > 0 || seen.contains(fst[i]) )
				continue;
			seen.add(fst[i]);
			char c = fst[i];
			ret += solve1(ind + 1, rem - Math.abs(c - a.charAt(ind)),f,msk | (1 << i),took | 1 << (fst[i] -'a'));
			if(f > 0)
			{
				char nxt = (char)(c + 1);
				
				if((took & (1 << (nxt-'a'))) == 0)
				ret += solve1(ind + 1, rem - Math.abs(nxt - a.charAt(ind)),0,msk | (1 << i),took | 1 << (nxt -'a'));
				char prev = (char)(c - 1);
				if((took & (1 << (prev-'a'))) == 0)
				ret += solve1(ind + 1, rem - Math.abs(prev - a.charAt(ind)),0,msk | (1 << i),took | (1 << (prev - 'a')));
			}
			
		}
		return DP[f][ind][rem][msk] = ret;

	}

	static long solve2(int ind,int rem,int f,int msk,int took)
	{	
		if(rem < 0)
			return 0;
		if(ind == b.length())
			return rem == 0 && f == 0 ? 1 : 0;
		if(DP2[f][ind][rem][msk] != -1)
			return DP2[f][ind][rem][msk];
		long ret = 0;
		TreeSet<Character> seen = new TreeSet();
		for(int i = 0 ; i < snd.length ; ++i)
		{
			if( (msk & (1 << i)) > 0 || seen.contains(snd[i]) )
				continue;
			seen.add(snd[i]);
			char c = snd[i];
			
			ret += solve2(ind + 1, rem - Math.abs(c - b.charAt(ind)),f,msk | (1 << i),took | (1 << (snd[i] - 'a')));
			if(f > 0)
			{
				char nxt = (char)(c + 1);
				if((took & (1 << (nxt-'a'))) == 0)
				ret += solve2(ind + 1, rem - Math.abs(nxt - b.charAt(ind)),0,msk | (1 << i),took | 1 << (nxt -'a'));
				char prev = (char)(c - 1);
				if((took & (1 << (prev-'a'))) == 0)
				ret += solve2(ind + 1, rem - Math.abs(prev - b.charAt(ind)),0,msk | (1 << i),took | (1 << (prev - 'a')));
			}
			
		}
		return DP2[f][ind][rem][msk] = ret;

	}

	public static void main(String[]args)throws Throwable
	{

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		int tc = 1;
		while(t-- > 0)
		{
			for(int i = 0 ; i < 2 ; ++i)
			{
				for(int j = 0 ; j < 10 ; ++j)
				{
					for(int k = 0 ; k < 505 ; ++k)
					{
						Arrays.fill(DP[i][j][k], -1);
						Arrays.fill(DP2[i][j][k], -1);
					}
				}
			}
			a = sc.next(); b = sc.next(); int x = sc.nextInt();
			long ans = 0;
			fst = a.toCharArray();
			snd = b.toCharArray();
			
			if(x < 505)
			{
				for(int i = 0 ; i <= x ; ++i)
				{
					ans += 1L*solve1(0,i,0,0,0) * solve2(0,x - i,1,0,0);
					ans += 1L*solve1(0,i,1,0,0) * solve2(0,x - i,0,0,0);
				}
			}
			out.printf("Case %d: %d\n",tc++,ans);

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
