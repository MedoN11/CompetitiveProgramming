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
import java.util.Stack;
import java.util.StringTokenizer;

public class Ezz {


// Start with slow n*k dp then the formula can be optimized with a BIT.


	static int n,k,l;
	static int tree[];
	static void update(int ind,int x) {
		++ind;
		while (ind < n + 5) {
			tree[ind] = Math.max(tree[ind], x);
			ind += ind & -ind;
		}
	}
	static int query(int ind) {
		++ind;
		int best = -(1 << 30);
		while (ind > 0) {
			best = Math.max(best, tree[ind]);
			ind -= ind & -ind;
		}
		return best;
	}
	static int getBest(int ind) {
		return query(ind);
	}
	static void updateBox(int ind,int val) {
		update(ind,val);
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		k = sc.nextInt();
		l = sc.nextInt();
		tree = new int[n + 5];
		Arrays.fill(tree, -1 << 30);
		Integer arr[] = new Integer[n];
		for (int i = 0 ; i < n ; ++i) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
//		for (Integer x : arr) {
//			System.err.print(x+" ");
//		}
//		System.err.println("");
		boolean dp[] = new boolean[n];
		for (int i = 0 ; i < n ; ++i) {
			boolean can = false;
			if (i - k + 1 >= 0) {
				//System.err.println(i+" "+getBest(i - k + 1));
				can |= Math.abs(arr[i] - getBest(i - k + 1)) <= l;
			}
			can |= arr[i] - arr[0] <= l && i + 1 >= k;
			dp[i] = can;
			if (can) {
				if (i + 1 < n)
				updateBox(i + 1,arr[i + 1]);
			}
			//System.err.println(i+" "+dp[i]);
		}

		out.println(dp[n - 1] ? "YES" : "NO");
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
