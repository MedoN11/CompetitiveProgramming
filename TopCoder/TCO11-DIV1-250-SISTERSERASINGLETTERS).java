import java.util.Arrays;

public class SisterErasingLetters 
{


	// DP + min/max theorm
	// DP function is an implementation of statement
	// optimise to n^2 by maintaing if we are in first call, or in skip phase
	static String main;
	static int n;

	public static void main(String[]args) throws Throwable
	{
		System.out.println(whoWins("abc"));
	}
	static int dp[][][][][];

	public static int solve(int ind,int org,int run,int turn,int st)
	{
		if(ind == n)
		{
			if(run == 1)
			{
				return turn;
			}
			return  st == 2 ? 1 : 0;
		}
		if(dp[turn][st][ind][org][run] != -1)
			return dp[turn][st][ind][org][run];
		if(turn == 0)
		{
			// erase
			int ret = 0;
			ret = Math.max(ret, solve(ind + 1,org,0,turn ^ 1,st));

			// leave
			int nst = st;
			if(st == 1 && main.charAt(ind) != main.charAt(org)) 
			{
				if(main.charAt(org) < main.charAt(ind)) nst = 2;
				else nst = 0;
			}
			ret = Math.max(ret, solve(ind + 1,org + 1,1,turn,nst));
			return dp[turn][st][ind][org][run] = ret;
		}
		else
		{
			// erase
			int ret = 1;
			ret = Math.min(ret, solve(ind + 1,org,0,turn ^ 1,st));

			// leave
			int nst = st;
			if(st == 1 && main.charAt(ind) != main.charAt(org)) 
			{
				if(main.charAt(org) < main.charAt(ind)) nst = 2;
				else nst = 0;
			}

			ret = Math.min(ret, solve(ind + 1,org + 1,1,turn,nst));
			return dp[turn][st][ind][org][run] = ret;
		}



	}
	public static String whoWins(String s)
	{
		n = s.length();
		dp = new int[2][3][n][n][2];
		main = s;
		for(int j = 0 ; j < 2 ; ++j)
			for(int k = 0 ; k < 3 ; ++k)
				for(int f = 0 ; f < n ; ++f)
					for(int a = 0 ; a < n ; ++ a)
						Arrays.fill(dp[j][k][f][a], -1);
		return solve(0,0,0,0,1) == 1 ? "Camomile" : "Romashka";
	}
}
