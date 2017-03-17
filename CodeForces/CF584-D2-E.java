package CodeForces;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class WateringFlowers
{

	static int n;
	static int arr[];
	static int desire[];
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n + 1]; desire = new int[n + 1];
		for(int i = 1 ; i <= n ; ++i)
			arr[i] = sc.nextInt();
		for(int i = 1 ; i <= n ; ++i)
			desire[sc.nextInt()] = i;
		int ans = 0;
		ArrayList<Point> res = new ArrayList();
		for(int i = n ; i >= 1 ; --i)
		{
			int pos = i;
			for(int j = pos + 1 ; j <= desire[arr[pos]] ; ++j)
			{
				if(desire[arr[j]] <= pos)
				{
					ans += Math.abs(pos - j);
					res.add(new Point(pos,j));
					int tmp = arr[j]; arr[j] = arr[pos]; arr[pos] = tmp;
					pos = j;
				}
			}
		}
		PrintWriter out = new PrintWriter(System.out);
		out.println(ans);
		out.println(res.size());
		for(Point p : res)
			out.println(p.x +" " +p.y);
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
	// dis is abs(i - j)
		// if no swaps along way from i to j, then we will get i - j for that pair
		// if a swapping happens then it moves j closer to it's position, so it doesn't affect the answer
		// lower bound now becomes upper bound
}
