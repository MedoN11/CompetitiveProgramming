import java.util.ArrayList;
import java.util.Stack;

public class ELR {


	// It is always optimal to create the shapes as triangles
	// Greedy approach : for each point pick the closest two points that form a triangle with it, but this fails
	// Optimize it to backtracking and try all possible combinations
	// but this has overlapping subproblems
	// use dp bitmask to enumerate all pickings, and get min cost

	public static void main(String[]args) throws Throwable {
		int a[] = {0,10,0,-10};
		int b[] = {-10,0,10,0};
		System.out.println(getArea(a,b));
	}

	static double area(int x1, int y1, int x2, int y2,
			int x3, int y3)
	{
		return Math.abs((x1*(y2-y3) + x2*(y3-y1)+
				x3*(y1-y2))/2.0);
	}
	static class Point {
		int x,y;
		public Point (int x,int y) {
			this.x = x;
			this.y = y;
		}
	}
	static class Triangle {
		Point a,b,c;
		public Triangle(Point x,Point y ,Point z) {
			this.a = x;
			this.b = y;
			this.c = z;
		}
	}
	static int n;
	static double area = 1<<30;

	static boolean isInside(int x1, int y1, int x2,
			int y2, int x3, int y3, int x, int y)
	{   

		double A = area (x1, y1, x2, y2, x3, y3);

		double A1 = area (x, y, x2, y2, x3, y3);

		double A2 = area (x1, y1, x, y, x3, y3);

		double A3 = area (x1, y1, x2, y2, x, y);

		return (A == A1 + A2 + A3);
	}

	static Double dp[];
	public static double go(int msk,int x[],int y[]) {
		if (msk == (1 << n) - 1) {

			return 0;
		}
		if (dp[msk] != null) {
			return dp[msk];
		}
		double ret = 1 << 30;
		for (int i = 0 ; i < n ; ++i) {

			for (int j = i + 1 ; j < n ; ++j) {

				for (int k = j + 1 ; k < n ; ++k) {
					if ( (((msk) & (1 << k)) > 0) && (((msk) & (1 << j)) > 0) && (((msk) & (1 << i)) > 0))
						continue;
					Triangle t = new Triangle(new Point(x[i],y[i]),new Point(x[j],y[j]),new Point(x[k],y[k]));
					int nmsk = msk;
					nmsk |= (1 << i) | (1 << j) | (1 << k);
					for (int a = 0 ; a < n ; ++a) {
						if ((nmsk & (1 << i)) > 0)
							continue;
						if (isInside(t.a.x,t.a.y,t.b.x,t.b.y,t.c.x,t.c.y,x[i],y[i])) {
							nmsk |= (1 << a);
						}
					}
					ret = Math.min(ret,area(t.a.x,t.a.y,t.b.x,t.b.y,t.c.x,t.c.y) + go(nmsk,x,y));

				}
			}
		}
		return dp[msk] = ret;
	}
	public static double getArea(int x[],int y[]) {
		n = x.length;
		dp = new Double[1 << n];
		return go(0,x,y);

	}

}