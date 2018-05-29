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
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class Ezz {



	static int mt[][] = new int[101][101];
	boolean xorMagic(ArrayList<Long> arr) 
	{ 
		for (int i = 0; i < arr.size(); i++) 
		{ 
			for (int j = 0; j < 55; j++) 
			{ 
				mt[j][i] = (int) ((arr.get(i) >> j) & 1); 
			} 
		} 
		int n = arr.size(); 
		for (int i = 0; i < n; i++) 
		{ 
			int r = -1; 
			for (int j = i; j < 55; j++) 
			{ 
				if (mt[j][i] > 0) 
				{ 
					r = j; 
					break; 
				} 
			} 
			if (r == -1) return false; 
			for (int j = 0; j < n; j++)  {
				int tmp = mt[r][j];
				mt[r][j] = mt[i][j];
				mt[i][j] = tmp;
			}
			for (int j = i + 1; j < 55; j++) 
			{ 
				if (mt[j][i] == 0) continue; 
				for (int k = 0; k < n; k++) 
					mt[j][k] ^= mt[i][k]; 
			} 
		} 
		return true; 
	} 

	public long bestSet(String[] heaps) {
		int n = heaps.length;
		long arr[] = new long[n];
		for (int i = 0 ; i < n ; ++i) {
			arr[i] = new Integer(heaps[i]);
		}
		long sum = 0;
		Arrays.sort(arr);
		ArrayList<Long> cand = new ArrayList();
		for (int i = n - 1 ; i >= 0 ; --i) {
			cand.add(arr[i]);
			if (!xorMagic(cand)) {
				cand.remove(cand.size() - 1);
			} else {
				sum += arr[i];
			}
		}
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