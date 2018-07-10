import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class ELR {

	// Greedy..after we sort it's always optimal to remove from the prefix or suffix
	// now to maintan best contigious segment we use a deque
	static Long arr[];
	static TreeMap<Long,Integer> map;
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		map = new TreeMap();
		arr = new Long[n];
		for (int i = 0 ; i < n ; ++i) {
			arr[i] = sc.nextLong();
			map.put(arr[i], i + 1);

		}
		int k = sc.nextInt();
		Arrays.sort(arr);
		long sum = 0;
		long cost = 0;
		Deque<Integer> q = new LinkedList();
		for (int i = 0 ; i < k ; ++i) {
			cost += (q.size()) * arr[i] - sum;
			q.addLast(i);
			sum += arr[i];
		}
		long best = cost;
		int l = q.peekFirst(), r = q.peekLast();
		for (int i = k ; i < n ; ++i) {
			int x = q.pollFirst();
			sum -= arr[x];
			cost -= (sum) - (arr[x] * (k - 1));
			q.addLast(i);
			cost += arr[i] * 1L*(k - 1) - sum;
			sum += arr[i];
			if (cost < best) {
				best = cost;
				l = q.peekFirst();
				r = q.peekLast();
			}
		}
		for (int i = l ; i <= r ; ++i) {
			out.print(map.get(arr[i])+" ");
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