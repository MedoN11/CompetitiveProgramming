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
import java.util.StringTokenizer;

// 1 2 3 4 5
public class ABC_002D {


	// bitmasks
	// Max clique using direct bitmasks enumeration
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		boolean adj[][] = new boolean[n][n];
		for (int i = 0 ; i < m ; ++i) {
			int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
			adj[x][y] = adj[y][x] = true;
		}
		int ans = 0;
		for (int msk = 0 ; msk < (1 << n) ; ++msk) {

			boolean bad = false;
			for (int i = 0 ; i < n && !bad; ++i) {
				if ( (msk & (1 << i)) > 0) {
					for (int j = i + 1 ; j < n && !bad ; ++j) {
						if ( (msk & (1 << j)) > 0) {
							if (!adj[i][j]) {
							    bad = true;
							}
						}
					}
				}

			}
			if (!bad) {
			ans = Math.max(ans, Integer.bitCount(msk));
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
