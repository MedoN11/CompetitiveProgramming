import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ARC_077C {

	
	// Bruteforce + Binary Search

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Integer c[] = new Integer[n],b[] = new Integer[n],a[] = new Integer[n];
		for (int i = 0 ; i < n ; ++i) {
			c[i] = sc.nextInt();
		}
		for (int i = 0 ; i  < n ; ++i) {
			b[i] = sc.nextInt();
		}
		for (int i = 0 ; i < n ; ++i) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		Arrays.sort(c);
		long tot = 0;
		for (int i = 0 ; i < n ; ++i) {
			int lo = 0, hi = n - 1;
			int ans = -1;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (a[mid] > b[i]) {
					hi = mid - 1;
					ans = mid;
				} else {
					lo = mid + 1;
				}
			}
			if (ans == -1) {
				continue;
			}
			long left = (n - ans);
			lo = 0;
			hi = n - 1;
			ans = -1;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (c[mid] < b[i]) {
					lo = mid + 1;
					ans = mid;
				} else {
					hi = mid - 1;
				}
			}
			if (ans == -1) {
				continue;
			}
			long right = ans + 1;
			tot += 1L*(right * left);
		}
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
