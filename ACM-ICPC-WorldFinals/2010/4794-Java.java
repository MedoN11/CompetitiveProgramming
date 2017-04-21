package WF2010;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SharingChocolate
{


	static int n;
	static int cut[];
	static boolean DP[][];
	static boolean vis[][];
	static short bits[];
	static short a[];
	static short firstBit[];


	static boolean solve(int x,int y,int msk)
	{
		if(vis[msk][x])
			return DP[msk][x];
		vis[msk][x] = true;
		if(x == 0 && y == 0)
			return msk == 0;
		if(msk == 0)
		{
			return x == 0 && y == 0;
		}
		if(bits[msk] == 1)
		{

			int ind = firstBit[msk];
			if(cut[ind] != x * y)
				return DP[msk][x] = false;
			return DP[msk][x] = true;
		}

		boolean ret = false;
		for(int subMsk = msk ; subMsk > 0 && !ret; subMsk = (subMsk - 1) & msk)
		{


			int otherMsk = msk & ~(subMsk);
			int sumOther = a[otherMsk];
			int sumSub = a[subMsk];
			
			if(msk == otherMsk || msk == subMsk)
				continue;
			if(a[subMsk] + a[otherMsk] != a[msk])
				continue;
			if(sumSub % x != 0 && sumSub % y != 0)
				continue;
			if(sumOther % x != 0 && sumOther % y != 0)
				continue;
			for(int l = 0 ; l <= x && !ret ; ++l)
			{
				if(l * y == sumSub && sumOther == (x - l) * y)
					ret |= solve(l,y,subMsk) && solve(x - l,y,otherMsk);

				for(int w = 0 ; w <= y && !ret ; ++w)
				{

					if(x * w == sumSub && x * (y - w) == sumOther)
						ret |= solve(x,w,subMsk) && solve(x,y - w,otherMsk);



				}
			}
		}
		return DP[msk][x] = ret;

	}
	public static void main(String[]args) throws Throwable
	{
		int tc = 1;

		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		bits = new short[1 << 15]; firstBit = new short[1 << 15];
		for(int i = 0 ; i < (1 << 15) ; ++i)
		{
			int ones = 0, ind = -1;
			for(int j = 0 ; j < 15 ; ++j)
			{
				if( ((1 << j) & i) > 0)
				{
					++ones; ind = j;
				}
			}
			bits[i] = (short)(ones);
			firstBit[i] = (short)ind;
		}
		while(true)
		{
			n = sc.nextInt();
			if(n == 0)
				break;
			a = new short[1 << 15];

			int x = sc.nextInt();int y = sc.nextInt();
			DP = new boolean[1 << n][x + 1];
			vis = new boolean[1 << n][x + 1];
			int area = x * y;
			int sum = 0;
			cut = new int[n];
			for(int i = 0 ; i < n ; ++i)
			{
				cut[i] = sc.nextInt();
				sum += cut[i];
			}
			out.printf("Case %d: ",tc++);
			if(sum != area)
				out.print("No");
			else
			{
				for(int i = 0 ; i < (1 << n) ; ++i)
				{
					int s = 0;
					for(int j = 0 ; j < n ; ++j)
						if( ((1 << j) & i) > 0)
							s += cut[j];
					a[i] = (short)(s);
				}
				if(x > y)
				{
					int tmp = x;
					x = y;
					y = tmp;
				}
				boolean can = solve(x,y,(1 << n) - 1);
				if(can)
					out.print("Yes");
				else out.print("No");
			}
			out.println("");

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
