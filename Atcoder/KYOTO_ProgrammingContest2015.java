import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class KYOTO_ProgrammingContest2015 {


	// Bruteforce + Binary Search

	public boolean ok(char arr[], char tokyo[],int i) {
		int n = arr.length, m = tokyo.length;
		if (i + m  - 1 < n) {
			boolean bad = false;
			for (int j = 0 ; j < m ; ++j) {
				if (arr[i + j] != tokyo[j]) {
					bad = true;
				}
			}
			if (!bad) {
				++res;
				i += m - 1;
				continue;
			}
		}
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		char tokyo[] = "tokyo".toCharArray();
		char kyoto[] = "kyoto".toCharArray();
		int m = 5;
		while (t-- > 0) {
			char arr[] = sc.next().toCharArray();
			int res = 0;
			int n = arr.length;
			for (int i = 0 ; i < n ; ++i) {

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
