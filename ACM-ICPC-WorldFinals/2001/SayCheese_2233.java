package WF2001;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SayCheese_2233 

{


	static class Sphere
	{
		int x,y,z,r;

		public Sphere(int x,int y,int z,int r)
		{
			this.x = x; this.y = y; this.z = z; this.r = r;
		}


	}

	
	static double pow2(double x)
	{
		return x * x;
	}

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n;
		int tc = 1;
		while(true)
		{
			n = sc.nextInt();
			if(n == -1)
				break;
			Sphere s[] = new Sphere[n + 2];
			for(int i = 0 ; i < n ; ++i)
				s[i] = new Sphere(sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt());
			s[n] = new Sphere(sc.nextInt(),sc.nextInt(),sc.nextInt(),0);
			s[n + 1] = new Sphere(sc.nextInt(),sc.nextInt(),sc.nextInt(),0);
			n += 2;
			double dp[][] = new double[n + 2][n + 2];
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < n ; ++j)
				{
					double dis = pow2(s[i].x - s[j].x) + pow2(s[i].y - s[j].y) + pow2(s[i].z - s[j].z);
					dis = Math.sqrt(dis);
					dis -= (s[i].r + s[j].r);
					if(dis >= 0)
						dp[i][j] = dis;
				}
			}
			
			for(int k = 0 ; k < n ; ++k)
			{
				for(int i = 0 ; i < n ; ++i)
				{
					for(int j = 0 ; j < n ; ++j)
					{
						dp[i][j] = Math.min(dp[i][k] + dp[k][j], dp[i][j]);
					}
				}
			}
		//	System.out.println("here");
			double ans = dp[n - 2][n - 1];
			ans *= 10.0;
			int res = (int) Math.round(ans);
			out.printf("Cheese %d: Travel time = %d sec\n", tc++,res);

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

		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }


	}
}
