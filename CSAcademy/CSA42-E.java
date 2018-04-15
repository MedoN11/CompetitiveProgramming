import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class XorSubMatrix {

	static final int maxAlpha = 2;
	static final int len = 32;
	static int root = 0;
	static int states = 0;
	public static int trie[][] = new int[maxAlpha][8000005];


	static void init() {
		for (int i = 0; i < maxAlpha ; ++i) {
			Arrays.fill(trie[i],-1);
		}
	}
	public static void add(int x) {

		int node = root;
		for (int i = 31 ; i >= 0 ; --i) {
			int curr = ((x & (1 << i)) > 0) ? 1 :0;

			if (trie[curr][node] == - 1) {
				trie[curr][node] = ++states;
			}
			node = trie[curr][node];
		}
	}
	public static int getMax(int x) {
		int node = root;
		int res = 0;
		for (int i = 31 ; i >= 0 ; --i) {
			int curr = ((x & (1 << i)) > 0) ? 1 : 0;

			if (trie[curr ^ 1][node] != -1) {
				res |= (1 << i);
				node = trie[curr ^ 1][node];
			} else {
				node = trie[curr][node];
			}

		}
		return res;
	}


	public static void main(String[]args)throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		int a[] = new int[n], b[] = new int[m];

		for (int i = 0 ; i < n ; ++i) {
			a[i] = sc.nextInt();
		}

		for (int i = 0 ; i < m ; ++i) {
			b[i] = sc.nextInt();
		}
		int res = 0;
		init();
		HashSet<Integer> set = new HashSet();
		for (int i = 0 ; i < m ; ++i) {
			int xor = 0;
			int parity = 0;
			for (int j = i ; j < m ; ++j) {
				parity ^= 1;
				xor ^= b[j];
				if (parity == 0)
				res = Math.max(res, xor);
				if (parity == 1) {
					add(xor);
				}
			}

		}

		
		for (int i = 0 ; i < n ; ++i) {
			int parity = 0;
			int xor = 0;
			for (int j = i ; j < n ; ++j) {
				parity ^= 1;
				xor ^= a[j];
				if (parity == 0)
				res = Math.max(res, xor);
				if (parity == 1) {
					res = Math.max(res,getMax(xor));
				}
			}

		}
		System.out.println(res);
	}
	static class Scanner
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

		public Scanner(FileReader s){	br = new BufferedReader(s);}

		public String next() throws IOException
		{
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}

		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}

		public double nextDouble() throws IOException { return Double.parseDouble(next()); }

		public boolean ready() throws IOException {return br.ready();}
	}
}
