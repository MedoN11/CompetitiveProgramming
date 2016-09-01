
public class LamsGrid {

	static char[][]arr;
	static int K;
	static int N;

	public static int choose(int col)
	{
		int cnt = 0;
		int M = arr.length;

		for(int j = 0 ; j < M ; j++)
		{
			boolean all_one = true;

			for(int i = 0 ; i < N ; i++){ if(i == col) all_one &= arr[j][i] == '0';
			else all_one &=arr[j][i] == '1';

			if(i == col) if(arr[j][i] == '1') arr[j][i] = '0';
			else arr[j][i] = '1';
			}

			if(all_one)++cnt;
		}

		return cnt;

	}
	
	public static void main(String[]args)
	{
		String a[] = {"01",
				 "10",
		 "10"};
		System.out.println(mostLit(a,1));
	}
	public static int mostLit(String a[],int k)
	{
		K = k;
		arr = new char[a.length][a[0].length()];
		for(int i = 0 ; i < a.length ; i++)
			for(int j = 0 ; j < a[i].length(); j ++) arr[i][j] = a[i].charAt(j);

		N =  a[0].length();
		int curr_max = 0;
		while( K-- > 0)

		{
			int choice = 0;
			int maxlit = 0;
			for(int j = 0 ; j < N ; j++)
			{
				int other = choose(j);
				if(other > maxlit)
				{
					maxlit = other;
					choice = j;
				}
			}
			curr_max = maxlit;
		}
		return curr_max;
	}
}
