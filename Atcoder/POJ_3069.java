import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class POJ_3069 {


	// Greedy
	// Place as far as possible greedy

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int r = sc.nextInt(), n = sc.nextInt();
			if (r == -1 || n == -1) {
				return;
			}
			int arr[] = new int[n];
			for (int i = 0 ; i < n ; ++i) {
				arr[i] = sc.nextInt();
			}
			Arrays.sort(arr);
			boolean cover[] = new boolean[n];
			int ans = 0;
			for (int i = 0 ; i < n ; ++i) {
				if (cover[i]) {
					continue;
				}
				int delta = arr[i];
				for (int j = i ; j < n ; ++j) {
					if (arr[i] >= arr[j] - r) {
						delta = arr[j];
					}
				}
				++ans;
				for (int j = i ; j < n ; ++j) {
					if (delta + r >= arr[j]) {
						cover[j] = true;
					}
				}
			}
			System.out.println(ans);
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


