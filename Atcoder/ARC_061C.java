import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ARC_061C {


	// Backtracking or bitmasks
	// end here trick!
	static long tot = 0;
	public static void backtrack(int ind,long cur,long sum,String s) {
		if (ind == s.length()) {
			if (cur == 0) {
				tot += sum;
			}
			return;
		}
		backtrack(ind + 1,cur * 10 + (s.charAt(ind) - '0'),sum,s);
		backtrack(ind + 1,0,sum + cur * 10 + s.charAt(ind) - '0',s);


	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		backtrack(0,0,0,s);
		System.out.println(tot);
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
