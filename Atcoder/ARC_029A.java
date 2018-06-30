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
public class ARC_029A {
	// Bitmasks + Try all

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		if ( n == 1 ) {
			System.out.println(a[0]);
			return;
		}
		if (n == 2) {
			System.out.println(Math.max(a[0], a[1]));
			return;
		}
		if (n == 3) {
			System.out.println(Math.max(a[2], a[0] + a[1]));
			return;
		}
		if (n == 4) {
			int f = 0, s = 0;
			int res = 1<<30;
			for (int msk = 0 ; msk < (1 << n) ; ++msk) {
				
				f = 0; s = 0;
				for (int i = 0 ; i < n ; ++i) {
					if ( (msk & (1 << i)) > 0) {
						f += a[i];
					} else {
						s += a[i];
					}
				}
				res = Math.min(res, Math.max(f, s));


			}
			System.out.println(res);
		}
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
