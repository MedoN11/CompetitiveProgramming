import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class POJ_1852 {

	
	// Imagination..easy adhoc but so cool!
	
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		while (t -- > 0) {
			int n = sc.nextInt(), m = sc.nextInt();
			int min = 0, max = 0;
			for (int i = 0 ; i < m ; ++i) {
				int x = sc.nextInt();
				min = Math.max(min, Math.min(x, n - x));
				max = Math.max(max, Math.max(x, n - x));
			}
			out.println(min+" "+max);
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
