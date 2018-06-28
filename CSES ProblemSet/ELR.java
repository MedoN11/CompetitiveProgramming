import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;



public class ELR {

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt(),x = sc.nextInt();
		Integer arr[] = new Integer[n];
		for (int i = 0; i < n ; ++i) {
			arr[i] = sc.nextInt();
		}
		int ans = 0;
		Arrays.sort(arr);
		int l = 0, r = n - 1;
		while (l <= r) {
			if (l == r) {
				++ans;
				break;
			}
			if (arr[r] + arr[l] <= x) {
				++l;
				--r;
				++ans;
			} else {
				++ans;
				--r;
			}
		}
		
		out.println(ans);
		out.flush();
		out.close();
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