import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TC_a 
{
	static final double EPS = 1e-9;
	static class Point
	{
		long x,y;
		public Point(int x,int y)
		{
			this.x = x; this.y = y;
		}
		public String toString()
		{
			return "("+x+","+y+")";
		}
		boolean onLine(Point a, Point b) 
		{
			if(a.compareTo(b) == 0) return compareTo(a) == 0;
			return Math.abs(new Vector(a, b).cross(new Vector(a, this))) < EPS;
		}
		public int compareTo(Point p)
		{
			if(Math.abs(x - p.x) > EPS) return x > p.x ? 1 : -1;
			if(Math.abs(y - p.y) > EPS) return y > p.y ? 1 : -1;
			return 0;
		}
	}
	static class Vector
	{
		long x,y;
		public Vector(Point a, Point b)
		{
			x = a.x - b.x;
			y = a.y - b.y;
		}
		public long cross(Vector c)
		{
			return this.x*c.y - this.y*c.x;
		}
	}

	static long side(long x1, long y1, long x2, long y2,long x, long y){
		return 1L*(y2 - y1)*1L*(x - x1) + 1L*(-x2 + x1)*(y - y1);
	}

	static	boolean pointInTriangle(long x1, long y1, long x2, long y2, long x3, long y3, long x, long y)
	{
		boolean checkSide1 = side(x1, y1, x2, y2, x, y) >= 0;
		boolean checkSide2 = side(x2, y2, x3, y3, x, y) >= 0;
		boolean checkSide3 = side(x3, y3, x1, y1, x, y) >= 0;
		//System.out.println(checkSide1+" "+checkSide2+" "+checkSide3);
		return checkSide1 && checkSide2 && checkSide3;
	}

	static boolean inside(Point a, Point b, Point c, Point pt)
	{
		return pointInTriangle(a.x,a.y,b.x,b.y,c.x,c.y,pt.x,pt.y);
	}

	static boolean bad(int i,int j)
	{
		if((i + 1) % n == j || (j + 1) % n == i)
			return true;
		return false;
	}
	
	static boolean notOnLine(Point a, Point b,Point ch)
	{
		return !ch.onLine(a, b);
	}
	static int n;
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		Point p[] = new Point[n];
		for(int i = 0 ; i < n ; ++i) p[i] = new Point(sc.nextInt(),sc.nextInt());
		int m = sc.nextInt();
		while(m-- > 0)
		{
			Point pt = new Point(sc.nextInt(),sc.nextInt());
			int lo = 1, hi = n - 1;
			int ans = -1;
			while(lo <= hi)
			{
				int mid = lo + (hi - lo) / 2;
				
				Vector v1 = new Vector(p[mid],p[0]);
				Vector v2 = new Vector(pt,p[0]);
				//System.err.println(mid +" "+v1.cross(v2));
				if(v1.cross(v2) < 0)
				{
					
					ans = mid + 1;
					lo = mid + 1;
				}
				else hi = mid - 1;
			}
			
	
			
			if(ans == -1 || ans == n || ans == 1)
			{

				System.out.println("NO"); return;
			}
			
			if(!inside(p[0],p[ans - 1],p[ans],pt))
			{
				
				System.out.println("NO"); return;
			}
			else
			{
			
				//System.out.println(ans);
				boolean ok = true;
				if(bad(0,ans - 1))
				{
					
					ok &= notOnLine(p[ans - 1],p[0],pt);
				}
				if(bad(0,ans))
				{
					
					ok &= notOnLine(p[ans],p[0],pt);
				}
				if(bad(ans - 1,ans))
				{
					ok &= notOnLine(p[ans],p[ans - 1],pt);
				}
				if(!ok)
				{
					System.out.println("NO"); return;
				}
			}
		}
		System.out.println("YES");

	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }
		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}


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
