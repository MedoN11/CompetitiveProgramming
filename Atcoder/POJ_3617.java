import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class POJ_3617 {

	// Nice usage of bitmask for compact solution

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char s[] = new char[n];
		for (int i = 0 ; i < n ; ++i) {
			s[i] = sc.next().charAt(0);
		}
		int l = 0, r = n - 1;
		StringBuilder res = new StringBuilder();
		while (l <= r) {

			if (s[l] == s[r]) {
				int a = l, b = r;
				while (a < b && s[a] != s[b]) {
					++a; --b;
				}
				if (s[a] < s[b]) {
					res.append(s[l++]);
				} else {
					res.append(s[r--]);
				}
			}
			if (s[l] < s[r]) {
				res.append(s[l++]);
			} else {
				res.append(s[r--]);
			}
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
