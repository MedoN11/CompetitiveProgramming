import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class CF_462C {

	// Huffman coding greedy
	// merge largest two togther
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		PriorityQueue<Long> pq = new PriorityQueue();
		long res = 0;
		for (int i = 0 ; i < n ; ++i) {
			long x = sc.nextLong();
			pq.add(-x);
			res += x;
		}

		while (pq.size() >= 2) {
			long cur = -pq.poll() + -pq.poll();
			res += cur;
			pq.add(-cur);
		}
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
