
public class EllysXor {

	static String a,b;
	static long DP[][][] = new long[70][2][2];
	static int bit = 0;

	public static void main(String[]args)throws Throwable
	{

	}

	public static long solve(int idx,int bl,int lr)
	{
		if(idx == b.length()) return 1;
		if(DP[idx][bl][lr] != -1) return DP[idx][bl][lr];
		long ret = 0;
		for(int j = 0 ; j < 2 ; j++)
		{
			if(idx == bit && j == 0) continue;

			if( (j < (a.charAt(idx)-'0')) && (bl != 1)) continue;

			if( (j > (b.charAt(idx) -'0') ) && (lr != 1)) continue;

			boolean nbl = (j > (a.charAt(idx)) -'0') || (bl == 1);

			boolean nlr = (j < (b.charAt(idx)-'0') ) ||(lr == 1);
			ret += solve(idx+1,nbl?1:0,nlr?1:0);
		}
		return DP[idx][bl][lr] = ret;
	}


	public static long get(int idx)
	{
		// nums with idx bit set to 1
		for(int i = 0 ; i < 70 ; i++)
		{
			for(int j = 0 ; j < 2 ; j++)
			{
				for(int k = 0 ; k < 2 ; k++) DP[i][j][k] = -1;
			}
		}
		bit = idx;
		return solve(0,0,0);
	}

	public static long getXor(long l, long r)
	{
		a = Long.toBinaryString(l);
		b = Long.toBinaryString(r);



		int len = a.length();

		len = a.length();
		while(len++ < b.length())
		{
			a = "0" + a;
		}


		StringBuilder sb = new StringBuilder();
		for(int k = 0 ; k < b.length() ; k++)
		{
			sb.append((get(k)%2));
		}
		return Long.parseLong(sb.toString(),2);


	}

}
