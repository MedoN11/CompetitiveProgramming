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



public class ELR {

	public static void main(String[] args) {new Thread(null, new Runnable() { public void run() {try {
		sol();
	} catch (Throwable e) {

		e.printStackTrace();
	}}}, "2",1<<26).start();}


	static int n,k;
	static boolean adj[][];
	static int dp1[],dp2[];
	static int myMask[];
	static int next1[];
	static int m1,m2;
	public static int solve1(int msk) {
		if (dp1[msk] != -1) {
			return dp1[msk];
		}
		int ret = 0;
		int tmp = msk;
		for (int i = 0 ; i < m1 ; ++i) {
			if ( ((msk & (1 << i)) > 0)) {
				tmp &= (myMask[i]);
			}
		}
		if (tmp == msk) {
			ret = Integer.bitCount(msk);
		}
		for (int i = 0 ; i < m1 ; ++i) {
			if ( (msk & (1 << i)) > 0) {
				ret = Math.max(ret, solve1(msk & ~(1 << i)));
			}
		}
		return dp1[msk] = ret;
	}
	public static int solve2(int msk) {
		if (dp2[msk] != -1) {
			return dp2[msk];
		}
		int ret = 0;
		int tmp = msk;
		for (int i = 0 ; i < m2 ; ++i) {
			if ( ((msk & (1 << i)) > 0)) {
				tmp &= (myMask[i + m1]);
			}
		}
		if (tmp == msk) {
			ret = Integer.bitCount(msk);
		}
		for (int i = 0 ; i < m2 ; ++i) {
			if ( (msk & (1 << i)) > 0) {
				ret = Math.max(ret, solve2(msk & ~(1 << i)));
			}
		}
		return dp2[msk] = ret;
	}
	public static void sol() throws Throwable {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		adj = new boolean[n][n];
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				adj[i][j] = sc.nextInt() == 1;
			}
		}

		m1= (n + 1) / 2;
		m2 = n - m1;
		dp1 = new int[1 << m1];
		dp2 = new int[1 << m2];
		next1 = new int[1 << m2];
		Arrays.fill(dp1, -1);
		Arrays.fill(dp2, -1);
		myMask = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			if (i >= m1) {
				for (int j = m1 ; j < n ; ++j) {
					if (adj[i][j] || i == j) {
						myMask[i] |= (1 << (j - m1));
					}
				}
			} else {
				for (int j = m1 ; j < n ; ++j) {
					if (adj[i][j]) {
						next1[i] |= (1 << (j - m1));
					}
				}
				for (int j = 0 ; j < m1 ; ++j) {
					if (adj[i][j] || i == j) {
						myMask[i] |= (1 << j);
					}
				}
			}
		}
		for (int i = 0 ; i < (1 << m1) ; ++i) {
			solve1(i);
		}
		for (int i = 0 ; i < (1 << m2) ; ++i) {
			solve2(i);
		}
		int ans = 0;
		for (int msk = 0 ; msk < (1 << m1) ; ++msk) {
			int next = (1 << (m2)) - 1;
			if (dp1[msk] != Integer.bitCount(msk)) {
				continue;
			}
			for (int i = 0 ; i < m1 ; ++i) {
				if ( (msk & (1 << i)) > 0) {
					next &= next1[i];
				}
			}
			ans = Math.max(ans, dp1[msk] + dp2[next]);
		}
		double cont = (k / (ans*1.0));
		double edges = (ans) * (ans - 1) / 2.0;
		double res = cont * cont * edges;
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