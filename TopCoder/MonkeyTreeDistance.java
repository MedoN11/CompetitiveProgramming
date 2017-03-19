
public class MonkeyTreeDistance 
{

	static int x[],y[];

	public static void main(String[]args)throws Throwable
	{
		int x[] = {1,4,1};
		int y[] = {4,1,1};
		System.out.println(minimalMaximumDistance(x,y));
	}

	public static long f(long ground)
	{
		int n = x.length;
		long max = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = i + 1 ; j < n ; ++j)
			{
				long d = 0;
				if(x[i] == x[j])
					d = Math.abs(y[i] - y[j]);
				else d = Math.abs(y[i] - ground) + Math.abs(y[j] - ground) + Math.abs(x[i] - x[j]);
				max = Math.max(max,d);
			}
		}
		return max;
	}
	public static String minimalMaximumDistance(int[] xx,int[] yy)
	{
		x = xx; y = yy;
		long left = -(1L << 35), right = 1L << 35; // set your range
		while (right-left > 3) { // We need 4 different positions
			long g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

			if (f(g) < f(h)) // use > if f increase then decrease
				right = h;
			else
				left = g;
		}

		long solIdx = left, answer = f(left++);
		for (long i = left; i <= right; ++i)	// iterate on the remaining
			if(answer > f(i))
			{
				answer = f(i);
				solIdx = i;
			}
		return answer +"";
	}
}
