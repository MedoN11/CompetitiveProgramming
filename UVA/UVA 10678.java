import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ELR {



	// Geometry
	// Area of ellipse
	// the maximum radius on x-axis is l / 2
	// the maximum for radius on y-axis is solved by pyth. theorm
	// Calculate area of ellipse for these 2

	public static void main(String[]args)throws Throwable {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		double pi = 2.0*Math.acos(0);
		PrintWriter out = new PrintWriter(System.out);
		for (int i = 0 ; i < t ; ++i) {
			double d = sc.nextDouble() / 2.0, l = sc.nextDouble() / 2.0;
			double ret = Math.sqrt(l*l-d*d);
			
			out.printf("%.3f\n",pi*ret*l);
			
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