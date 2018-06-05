import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;


public class ELR {


	// Maximizing a function is same as maximizing it's log
	// so we used a 2 nested ternary search

	static class Pair implements Comparable<Pair> {
		int coef;
		int ind;
		public Pair(int coef,int ind) {
			this.coef = coef;
			this.ind = ind;
		}
		@Override
		public int compareTo(Pair o) {
			return o.coef - this.coef;
		}

	}
	static double res = 0.0;
	static Pair p[] = new Pair[3];
	public static double solve2(double z) {
		double l = 0,r = z;
		for (int i = 0 ; i < 100 ; ++i) {
			double m1 = l + (r - l) / 3.0;
			double m2 = r - (r - l) / 3.0;
			double f1 = func2(m1,z),f2 = func2(m2,z);
			if (f1 <= f2) {
				l = m1;
			} else {
				r = m2;
			}
		}
		res = l;
		return func2(l,z);
	}
	public static double func2(double x,double z) {
		return p[1].coef * Math.log(x) +  p[2].coef * Math.log(z - x);
	}
	public static double func1(double x) {
		return p[0].coef * Math.log(x) + solve2(s - x);
	}
	static int s;
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		s = sc.nextInt();
		int x = sc.nextInt(), y = sc.nextInt(), z = sc.nextInt();

		p[0] = new Pair(x,0);
		p[1] = new Pair(y,1);
		p[2] = new Pair(z,2);
		Arrays.sort(p);
		double l = 0,r = s;
		for (int i = 0 ; i < 100 ; ++i) {
			double m1 = l + (r - l) / 3.0;
			double m2 = r - (r - l) / 3.0;
			double f1 = func1(m1),f2 = func1(m2);
			if (f1 <= f2) {
				l = m1;
			} else {
				r = m2;
			}
		}
		func1(l);
		double ans[] = new double[3];
		ans[p[0].ind] = l;
		ans[p[1].ind] = res;
		ans[p[2].ind] = s - (res + l);
		System.out.printf("%.12f %.12f %.12f",ans[0],ans[1],ans[2]);
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



