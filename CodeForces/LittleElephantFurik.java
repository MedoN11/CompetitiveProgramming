package Sheet1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class LittleElephantFurik
{


	static int n;
	static char[] a,b;
	static long cnt[][];
	public static void main(String[]args)throws Throwable
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = new Integer(br.readLine());
		a = br.readLine().toLowerCase().toCharArray();
		b = br.readLine().toLowerCase().toCharArray();
		cnt = new long[n][26];
		for(int i = n - 1 ; i >= 0 ; --i)
		{
			cnt[i][b[i] - 'a'] += (long)((n - i));
			if(i + 1 < n)
			{
				for(int j = 0 ; j < 26 ; ++j)
				{
					cnt[i][j] += (long)(cnt[i + 1][j]);
				}
			}
		}
		double prob = 0;
		long tot = 0;
		for(long i = 1;  i <= n ; ++i)
		{
			tot += (long)((long)(1L*n - i + 1) * (long)(1L*n - i + 1));
		}
		double subProb = 1.0/tot;
		for(int i = 0 ; i < n ; ++i)
		{
			prob += subProb * (long)(cnt[i][a[i] - 'a'] * (1L*i + 1));
		}
		for(int i = 0 ; i < n ; ++i)
		{
			Arrays.fill(cnt[i], 0);
		}

		for(int i = n - 1 ; i >= 0 ; --i)
		{
			cnt[i][a[i] - 'a'] = (n - i);
			if(i + 1 < n)
			{
				for(int j = 0 ; j < 26 ; ++j)
				{
					cnt[i][j] += (long)(cnt[i + 1][j]);
				}
			}
		}
		for(int i = 0 ; i < n ; ++i)
		{
			if(i + 1 < n)
			prob += subProb * (long)(cnt[i + 1][b[i] - 'a'] * (1L*i + 1));
		}
		System.out.println(prob);

	}

}
