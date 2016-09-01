
public class DropCoins {


	static int DP[][] = new DP[51][51];
	public static void main(String[]args)throws Throwable
	{

	}

	public int getMinimum(String[]boards,int K)
	{
		for(int i = 0 ; i < boards.length ; i++)
		{
			for(int j = 0 ; j < boards[0].length() ; j++)
			{
				int x = boards[i].charAt(j) == 'o' ? 1 : 0;
				DP[i][j] += x;
				if(i > 0) DP[i][j] += DP[i - 1][j];
				if(j > 0) DP[i][j] += DP[i][j - 1];
				if(i > 0 && j > 0) DP[i][j] -= DP[i - 1][j - 1];
			}
		}
		int n = boards.length;
		int m = boards[0].length();

		int A[][][][] = new int[51][51][51][51];
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				for(int k = i ; k < n ; k++)
				{
					for(int l = j ; l < m ; l++)
					{
						int subRect = DP[k][l]; 
						if (i > 0) subRect -= DP[i - 1][l];
						if (j > 0) subRect -= DP[k][j - 1];
						if (i > 0 && j > 0) subRect += DP[i - 1][j - 1];
						A[i][k][j][l] = subRect;
					}
				}
			}
		}
		int min_moves = 1 << 28;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				for(int k = i ; k <= n ; k++)
				{
					for(int l = j ; l <= m ; l++)
					{
						int subRect = 0;
						for(int x = i ; x < k ; x++)
						{
							for(int y = j ; y < l ; y++)
							{
								subRect += boards[x].charAt(y) == 'o' ? 1 : 0;
							}
						}
						if(subRect == K)
						{
							int move_up = i - 0;
							int move_down = n - k;
							int move_left = j - 0;
							int move_right = m - l;
							min_moves = Math.min(min_moves,move_up + move_down + Math.min(move_up, move_down) + move_left + move_right + Math.min(move_left, move_right));
						}

					}
				}
			}
		}
		return min_moves == 1 << 28 ? - 1 : min_moves;
	}
}
