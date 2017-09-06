import java.util.Arrays;

public class BoxTower {


	static int dp[][][];
	static int n;
	static int x[],y[],z[];


	static int solve(int conf,int lst,int msk)
	{
		if(dp[conf][lst][msk] != -1)
			return dp[conf][lst][msk];
		int ret = 0;
		int a = 0 , b = 0;
		if(lst != n)
		{
			if(conf == 0) {a = x[lst]; b = y[lst];}
			if(conf == 1) {a = x[lst]; b = z[lst];}
			if(conf == 2) {a = z[lst]; b = y[lst];}
		}
		else 
		{
			a = 1 << 30;
			b = 1 << 30;
		}
		for(int i = 0 ; i < n ; ++i)
		{
			if((msk & (1 << i)) != 0)
				continue;

			for(int k = 0 ; k < 3 ; ++k)
			{
				long top = 0;
				int gain = 0;
				int u = 0, v = 0;
				if(k == 0) {u = x[i]; v = y[i]; gain = z[i];}
				if(k == 1) {u = x[i]; v = z[i]; gain = y[i];}
				if(k == 2) {u = z[i]; v = y[i]; gain = x[i];}
				if(u <= a && v <= b || u <= b &&  v <= a)
					ret = Math.max(ret,gain + solve(k,i,msk | 1 << i));
			}


		}
		return dp[conf][lst][msk] = ret;
	}
	public static int tallestTower(int x1[],int y1[],int z1[])
	{
		n = x1.length;
		x = x1; y = y1; z = z1;
		dp = new int[3][n + 1][1 << n];
		for(int i = 0 ; i < 3 ; ++i)
		{
			for(int j = 0 ; j < n + 1 ; ++j)
				Arrays.fill(dp[i][j], -1);
		}
		return solve(0,n,0);

	}

	public static void main(String[]args)throws Throwable
	{
		int x[] = {20,30};
		int y[] = {20,30};
		int z[] = {20,10};
		System.out.println(tallestTower(x,y,z));
	}


}