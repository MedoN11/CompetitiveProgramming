import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Test {



	static int cost[];
	static long DP[];

	static long get(int i)
	{
		return DP[i - 1] + cost[i];
	}
	public static void main(String[]args)throws Throwable
	{

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k =  sc.nextInt();
		cost = new int[n + 1];
		DP = new long[n + 1];
		long sum = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			cost[i] = sc.nextInt();
			sum += 1L*cost[i];
		}
		Deque<Integer> allowedStates = new ArrayDeque();

		for(int i = 1 ; i <= k ; ++i)
		{
			while(!allowedStates.isEmpty() && get(allowedStates.peekLast()) >= get(i))
				allowedStates.pollLast();
			allowedStates.addLast(i);
		}
		for(int i = k + 1 ; i <= n ; ++i)
		{
			while(!allowedStates.isEmpty() && allowedStates.peekFirst() + k + 1 < i ) allowedStates.pollFirst();

			while(!allowedStates.isEmpty() && get(allowedStates.peekLast()) >= get(i))
				allowedStates.pollLast();
			allowedStates.addLast(i);
			DP[i] = get(allowedStates.peekFirst());




		}
		System.out.println(sum - DP[n]);
	}

	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;

		Scanner(InputStream s) { br = new BufferedReader(new InputStreamReader(s)); }

		String next() throws IOException
		{
			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }
	}
}
