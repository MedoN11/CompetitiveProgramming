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
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ELR {


	static class Car implements Comparable<Car> {
		long arrival;
		int ind;
		public Car(long arrival,int ind) {
			this.arrival = arrival;
			this.ind = ind;
		}
		@Override
		public int compareTo(Car o) {
			if (Long.compare(this.arrival, o.arrival) == 0) {
				return this.ind - o.ind;
			}
			return Long.compare(this.arrival, o.arrival);
		}
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		long cap[] = new long[n], time[] = new long[n];
		Car car[] = new Car[n];
		for (int i = 0 ; i < n ; ++i) {
			cap[i] = sc.nextLong();
			time[i] = sc.nextLong();
			car[i] = new Car(time[i],i);
		}
		PriorityQueue<Integer> pq = new PriorityQueue();
		Arrays.sort(car);
		long t = 0;
		long done[] = new long[n];
		for (Car c :car) {
			while (!pq.isEmpty() && t < c.arrival) {
				Integer cand = pq.poll();
				long cur = Math.min(cap[cand], c.arrival - t);
				cap[cand] -= Math.max(0, cur);
				t += Math.max(0, cur);
				if (cap[cand] > 0) {
					pq.add(cand);
				} else {
					done[cand] = t;
				}
			}
			t = Math.max(t, c.arrival);
			pq.add(c.ind);
		}
		while (!pq.isEmpty()) {
			Integer cand = pq.poll();
			t += cap[cand];
			done[cand] = t;

		}

		for (int i = 0 ; i < n ; ++i) {
			out.println(done[i]);
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