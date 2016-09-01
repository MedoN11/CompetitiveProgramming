import java.util.ArrayList;


public class ColorfulChocolates {

	static int DP[][][][] = new int[51][51][51][51];
	static int n;
	static char arr[];

	// Dynamic Programming
	// Problem can also be solved using Greedy in N^3..however DP is more natural and easier to prove in this case.
	// This DP runs in 26*N^4 and since N is 50. This fits within the limits.

	public static void main(String[]args)throws Throwable
	{
		System.out.println(maximumSpread("CBABBACBABABCCCCCAABBAACBBBBCBCAAA",8));
	}

	public static int solve(int idx,int front,int len,int ansFront, int c)
	{
		if(len == 0) return 0;
		if(idx == n)
		{
			return (1 << 25);
		}
		if(DP[idx][front][len][ansFront] != -1){
			return DP[idx][front][len][ansFront];

		}
		int ret = 0;
		int goal = arr[idx]-'a';
		if(goal == c)
		{
			return DP[idx][front][len][ansFront] = ret = front+solve(idx+1,front,len-1,ansFront+1,c);
		}
		else
		{
			// put at back
			ret = front+ansFront+solve(idx+1,front,len,ansFront,c);
			//put front
			ret = Math.min(ret,solve(idx+1,front+1,len,ansFront,c));
			return DP[idx][front][len][ansFront] = ret;
		}
	}
	public static int maximumSpread(String str,int maxSwaps)
	{


		n = str.length();

		str = str.toLowerCase();
		arr = str.toCharArray();
		int max = 0;
		for(int x = 0 ; x < 51; x++)
		{
			for(int y = 0 ; y < 51 ; y++)
			{
				for(int z = 0 ; z < 51 ; z++)
				{

					for(int f = 0 ; f < 51 ; f++)

						DP[x][y][z][f] = -1;
				}
			}
		}
		ArrayList<Integer> arrs[]= new ArrayList[26];
		for(int i = 0 ; i < 26 ; i++)
		{
			arrs[i] = new ArrayList<Integer>();
		}
		for(int i = 0 ; i < str.length() ; i++)
		{

			arrs[arr[i]-'a'].add(i);
		}



		for(int i = 0 ; i < 26 ; i++)
		{
			for(int x = 0 ; x < 51; x++)
			{
				for(int y = 0 ; y < 51 ; y++)
				{
					for(int z = 0 ; z < 51 ; z++)
					{

						for(int f = 0 ; f < 51 ; f++)

							DP[x][y][z][f] = -1;
					}
				}
			}

			for(Integer z : arrs[i])
			{
				int res = 0;
				for(int a = 0 ; a < 51 ; a++)
				{
					int gg = solve(z,0,a,0,str.charAt(z)-'a');
					if(gg <= maxSwaps) res = a;
				}
				max = Math.max(res, max);
			}


		}

		return max;

	}
}
