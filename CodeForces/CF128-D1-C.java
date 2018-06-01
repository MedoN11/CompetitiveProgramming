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
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ELR {


	// The two dimensions are independent.
	// we can calculate the ways for each dimension alone then multiply the
	// for a single dimension let's start with slow dp then optimize
	// when doing the dp, we are just counting ways to choose k nested intervals
	// it's simply c(n,2*k) where n is length of interval
	static final int mod = 1000*1000*1000 + 7;
	static Integer dp[][][];
	public static int solve(int l,int r,int k) {
		if (l > r)
			return 0;
		if (k == 0) {
			return 1;
		}
		if (dp[l][r][k] != null) {
			return dp[l][r][k];
		}
		int ret = 0;
		for (int i = l ; i <= r ; ++i) {
			for (int j = i + 1 ; j <= r ; ++j) {
				ret += solve(i + 1,j - 1,k - 1);
			}
		}
		return ret;
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
			
		long C[][] = new long[2001][2001];
		C[0][0] = 1;
		for (int i = 1 ; i <= 2000 ; ++i) {
			C[i][0] = 1;
			for (int j = 1 ; j <= 2000 ; ++j) {
				C[i][j] += C[i - 1][j - 1] + C[i - 1][j];
				C[i][j] %= mod;
			}
		}
	
		
		
		out.println((1L*C[n - 1][2*k]*C[m - 1][2*k])%mod);
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