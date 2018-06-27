import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;



public class ELR {

	static double solveUnweighted (int nodes, long curr, long pool, long excl) {
		if (pool == 0 && excl == 0) {
			int cnt = 0;
			for (int i = 0; i < nodes; i++)
				if ((curr & 1 << i) > 0)
					cnt++;
			
			double cont = (k / (cnt*1.0));
			double edges = (cnt) * (cnt - 1) / 2.0;
			return cont * cont * edges;
		}
		double res = 0;
		int j = 0;
		for (int i = 0; i < nodes; i++)
			if ((pool & 1 << i) > 0 || (excl & 1 << i) > 0)
				j = i;

		for (int i = 0; i < nodes; i++) {
			if ((pool & 1 << i) == 0 || adj[i][j])
				continue;
			long ncurr = curr, npool = 0, nexcl = 0;
			ncurr |= 1 << i;

			for (int k = 0; k < nodes; k++) {
				if (adj[i][k]) {
					npool |= pool & 1 << k;
					nexcl |= excl & 1 << k;
				}
			}
			res = Math.max(res, solveUnweighted(nodes, ncurr, npool, nexcl));

			pool &= ~(1 << i);
			excl |= 1 >> i;
		}
		return res;
	}
	public static void main(String[] args) {new Thread(null, new Runnable() { public void run() {try {
		sol();
	} catch (Throwable e) {
		
		e.printStackTrace();
	}}}, "2",1<<26).start();}
	
	static int n,k;
	static boolean adj[][];
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
		double ans = solveUnweighted(n, 0, (1L << n) - 1, 0);
		System.out.println(ans);
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