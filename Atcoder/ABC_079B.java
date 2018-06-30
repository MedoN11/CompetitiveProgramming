import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ABC_079B {

	// Nice usage of bitmask for compact solution

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		char c[] = sc.next().toCharArray();
		int d[] = new int[4];
		for (int i = 0 ; i < 4 ; ++i) {
			d[i] = c[i] - '0';
		}
		for (int msk = 0 ; msk < (1 << 3) ; ++msk) {
			int cur = d[0];
			for (int i = 0 ; i < 3 ; ++i) {
				if ( (msk & (1 << i)) > 0) {
					cur += d[i + 1];
				} else {
					cur += -d[i + 1];
				}
			}
			if (cur == 7) {
				System.out.print(d[0]);
				for (int i = 0 ; i < 3 ; ++i) {
					String sign = (msk & ( 1 << i)) > 0 ? "+" : "-";
					System.out.print(sign + d[i + 1]);
				}
				System.out.println("=7");
				return;
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
