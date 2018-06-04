import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class ELR {


	// Sort polygons on area
	// check for each point the first polygon it lies into in the sorted polygons list
	static class Entry implements Comparable<Entry> {
		Polygon p;
		double area;
		int ind;
		public Entry(Polygon p,int ind) {
			this.p = p;
			this.ind = ind;
			this.area = this.p.area();
		}
		@Override
		public int compareTo(Entry o) {
			return Double.compare(this.area, o.area);
		}
	}
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t = sc.nextInt(); 
		while (t-- > 0) {
			ArrayList<Entry> polys = new ArrayList();
			int n = sc.nextInt();
			for (int i = 0 ; i < n ; ++i) {
				String line = sc.nextLine();
				StringTokenizer st = new StringTokenizer(line);
				int m = (st.countTokens() - 1) / 2;
				//System.out.println(m);
				int ind = new Integer(st.nextToken());
				Point p[] = new Point[m + 1];
				int j = 0;
				while (st.hasMoreTokens()) {
					double x = new Double(st.nextToken()), y = new Double(st.nextToken());
					
					p[j++] = new Point(x,y);
				}
				p[m] = p[0];
				polys.add(new Entry(new Polygon(p),ind));
			}
			Collections.sort(polys);
			int q = sc.nextInt();
			int res[] = new int[q];
			for (int j = 0 ; j < q ; ++j) {
				int id = sc.nextInt() - 1; double x = sc.nextDouble(),y = sc.nextDouble();
				//System.out.println(x +" "+y);
				for (Entry e: polys) {
					if (e.p.inside(new Point(x,y))) {
						
						res[id] = e.ind;
						break;
					}
				}
			}
			for (int i = 0 ; i < q ; ++i) {
				out.println((i + 1)+" "+res[i]);
			}
			if (t != 0) {
				out.println();
			}
		}
		out.flush();
		out.close();
	}
	static class Vector {

		double x, y; 

		Vector(double a, double b) { x = a; y = b; }

		Vector(Point a, Point b) { this(b.x - a.x, b.y - a.y); }

		Vector scale(double s) { return new Vector(x * s, y * s); }              //s is a non-negative value

		double dot(Vector v) { return (x * v.x + y * v.y); }

		double cross(Vector v) { return x * v.y - y * v.x; }

		double norm2() { return x * x + y * y; }

		Vector reverse() { return new Vector(-x, -y); }

		Vector normalize() 
		{ 
			double d = Math.sqrt(norm2());
			return scale(1 / d);
		}		
	}
	static class Point implements Comparable<Point>{

		static final double EPS = 1e-9;

		double x, y;                  

		Point(double a, double b) { x = a; y = b; }  

		public int compareTo(Point p)
		{
			if(Math.abs(x - p.x) > EPS) return x > p.x ? 1 : -1;
			if(Math.abs(y - p.y) > EPS) return y > p.y ? 1 : -1;
			return 0;
		}

		public double dist(Point p) { return Math.sqrt(sq(x - p.x) + sq(y - p.y)); }

		static double sq(double x) { return x * x; }

		Point rotate(double angle)
		{
			double c = Math.cos(angle), s = Math.sin(angle);
			return new Point(x * c - y * s, x * s + y * c);
		}
		// for integer points and rotation by 90 (counterclockwise) : swap x and y, negate x

		Point rotate(double theta, Point p)			//rotate around p
		{
			Vector v = new Vector(p, new Point(0, 0));
			return translate(v).rotate(theta).translate(v.reverse());
		}

		Point translate(Vector v) { return new Point(x + v.x , y + v.y); }


		boolean between(Point p, Point q)
		{
			return x < Math.max(p.x, q.x) + EPS && x + EPS > Math.min(p.x, q.x)
					&& y < Math.max(p.y, q.y) + EPS && y + EPS > Math.min(p.y, q.y);
		}

		//returns true if it is on the line defined by a and b
		boolean onLine(Point a, Point b) 
		{
			if(a.compareTo(b) == 0) return compareTo(a) == 0;
			return Math.abs(new Vector(a, b).cross(new Vector(a, this))) < EPS;
		}

		boolean onSegment(Point a, Point b)
		{
			if(a.compareTo(b) == 0) return compareTo(a) == 0;
			return onRay(a, b) && onRay(b, a);
		}

		//returns true if it is on the ray whose start point is a and passes through b
		boolean onRay(Point a, Point b)
		{
			if(a.compareTo(b) == 0) return compareTo(a) == 0;
			return new Vector(a, b).normalize().equals(new Vector(a, this).normalize());	//implement equals()
		}

		// returns true if it is on the left side of Line pq
		// add EPS to LHS if on-line points are accepted
		static boolean ccw(Point p, Point q, Point r)
		{
			return new Vector(p, q).cross(new Vector(p, r)) > 0;
		}

		static boolean collinear(Point p, Point q, Point r)
		{
			return Math.abs(new Vector(p, q).cross(new Vector(p, r))) < EPS;
		}

		static double angle(Point a, Point o, Point b)  // angle AOB
		{
			Vector oa = new Vector(o, a), ob = new Vector(o, b);
			return Math.acos(oa.dot(ob) / Math.sqrt(oa.norm2() * ob.norm2()));
		}

		static double distToLine(Point p, Point a, Point b) //distance between point p and a line defined by points a, b (a != b)
		{
			if(a.compareTo(b) == 0) return p.dist(a);
			// formula: c = a + u * ab
			Vector ap = new Vector(a, p), ab = new Vector(a, b);
			double u = ap.dot(ab) / ab.norm2();
			Point c = a.translate(ab.scale(u)); 
			return p.dist(c);
		}
		// Another way: find closest point and calculate the distance between it and p

		static double distToLineSegment(Point p, Point a, Point b) 
		{
			Vector ap = new Vector(a, p), ab = new Vector(a, b);
			double u = ap.dot(ab) / ab.norm2();
			if (u < 0.0) return p.dist(a);
			if (u > 1.0) return p.dist(b);        
			return distToLine(p, a, b); 
		}
		// Another way: find closest point and calculate the distance between it and p
	}

	static class Polygon { 
		// Cases to handle: collinear points, polygons with n < 3

		static final double EPS = 1e-9;

		Point[] g; 			//first point = last point, counter-clockwise representation

		Polygon(Point[] o) { g = o; }

		double perimeter()
		{
			double sum = 0.0;
			for(int i = 0; i < g.length - 1; ++i)
				sum += g[i].dist(g[i+1]);
			return sum;
		}

		double area() 		//clockwise/anti-clockwise check, for convex/concave polygons
		{
			double area = 0.0;
			for(int i = 0; i < g.length - 1; ++i)
				area += g[i].x * g[i+1].y - g[i].y * g[i+1].x;
			return Math.abs(area) / 2.0;			//negative value in case of clockwise
		}

		boolean isConvex()
		{
			if(g.length <= 3) // point or line
				return false;
			boolean ccw = Point.ccw(g[g.length - 2], g[0], g[1]);		//edit ccw check to accept collinear points
			for(int i = 1; i < g.length - 1; ++i)
				if(Point.ccw(g[i-1], g[i], g[i+1]) != ccw)
					return false;
			return true;
		}

		boolean inside(Point p)	//for convex/concave polygons - winding number algorithm 
		{
			double sum = 0.0;
			for(int i = 0; i < g.length - 1; ++i)
			{
				double angle = Point.angle(g[i], p, g[i+1]);
				if((Math.abs(angle) < EPS || Math.abs(angle - Math.PI) < EPS) && p.between(g[i], g[i+1]))
					return true;
				if(Point.ccw(p, g[i], g[i+1]))
					sum += angle;
				else
					sum -= angle;
			}

			return Math.abs(2 * Math.PI - Math.abs(sum)) < EPS;		//abs makes it work for clockwise
		}
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}

}