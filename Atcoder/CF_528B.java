import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CF_528B {

	
	// greedy
	// unexpected idea
	// manipulate equations
	// becomes a greedy interval scheduling problem
	static class Interval implements Comparable<Interval> {
		int start,end;
		public Interval(int start,int end) {
			this.start = start;
			this.end = end;
		}
		@Override
		public int compareTo(Interval o) {
			if (this.end == o.end) {
				return this.start - o.start;
			}
			return this.end - o.end;
		}
	}

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Interval> intervals = new ArrayList();
		for (int i = 0 ; i < n ; ++i) {
			int x = sc.nextInt(), w = sc.nextInt();
			intervals.add(new Interval(x - w,x + w));
		}
		Collections.sort(intervals);
		int cur = -(1<<30);
		int res = 0;
		for (Interval v : intervals) {
			if (v.start >= cur) {
				++res;
				cur = v.end;
			}
		}
		System.out.println(res);
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
