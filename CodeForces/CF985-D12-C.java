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

// sort and parition greedily
public class Ezz {



	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt(), k = sc.nextInt(), l = sc.nextInt();

		Long arr[] = new Long[n * k];
		for (int i = 0 ; i < n * k ; ++i) {
			arr[i] = sc.nextLong();
		}
		Arrays.sort(arr);
		long sum = 0;
		long cap = arr[0] + l;
		int st = 0;
		for (int i = 1 ; i < n * k ; ++i) {
			if (arr[i] <= cap)
				st = i;
		}

		int need = n;

		if (st + 1 < need) {
			out.println("0");
			out.flush();
			out.close();
			return;
		}
		//System.out.println(st);
		int cur = 0;
		while (need > 0) {
			//System.out.println(arr[cur]);
			sum += 1L*arr[cur];
			++cur;
			--need;
			int has = k - 1;
			while (has-- > 0) {
				if (st - cur + 1  > need)  {
					++cur;
				}
			}
		}
		//System.out.println(need);


		out.println(sum);
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
