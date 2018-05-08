import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Permutation {


	// Simple Backtracking
	static String ans = "";
	static int n,m;
	static boolean done = false;
	static char res[];
	static void backtrack(int ind,int mod[]) {
		if (done) {
			return;
		}
		if (ind == m) {
			ans = new String(res);
			done = true;
			return;
		}
		int tmp[] = new int[m];
		for (int i = 0 ; i <= 9 ; ++i) {
			if (ind == 0 && i == 0)
				continue;
			for (int j = ind ; j < m ; ++j)  {
				tmp[j] = (mod[j] * 10 + i) % (j + 1);
			}
			if (ind < n || tmp[ind] == 0) {
				res[ind] = (char)(i + '0');
				if (!done) {
				backtrack(ind + 1,tmp);
				}
			}
		}
	}
	public static void main(String[]args)throws Throwable {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		int tc = 1;
		while (t-- > 0) {
			n = sc.nextInt();
			--n;
			ans = "-1";
			m = sc.nextInt();
			done = false;
			res = new char[m];
			backtrack(0,new int[m]);
			out.printf("Case %d: %s\n", tc++,ans);
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





