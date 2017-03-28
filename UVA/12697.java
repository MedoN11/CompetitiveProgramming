import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Map.Entry;

import javax.swing.plaf.synth.SynthScrollBarUI;

import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class MinimalSubarray 
{


	static int t;
	static int n,x;
	
	
	static class Pair
	{
		int i;
		long val;
		long oldDelta;
		
		public Pair(int i,long val,long oldDelta)
		{
			this.i = i;
			this.val = val;
			this.oldDelta = oldDelta;
		}
	}
	
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		

		PrintWriter out = new PrintWriter(System.out);
		while(t-- > 0)
		{
			n = sc.nextInt(); x = sc.nextInt();
			
			
			long delta = 0;
			int ans = 1 << 30;
			Deque<Pair> q = new LinkedList();
			for(int i = 0 ; i < n ; ++i)
			{	
				
				int curr = sc.nextInt();
				delta += curr;
				while(!q.isEmpty() && q.getLast().val + delta - q.getLast().oldDelta < curr)
				{
					q.pollLast();
				}
			
				q.addLast(new Pair(i,curr,delta));
				//System.out.println(i +" "+curr +" "+delta);
				while(!q.isEmpty() && q.getFirst().val + delta - q.getFirst().oldDelta >= x)
				{
				
					ans = Math.min(ans, i - q.getFirst().i + 1);
					q.pollFirst();
				}
				//System.err.println(q.getFirst().val + delta - q.getFirst().oldDelta);
			}
			if(ans == 1 << 30)
				ans = -1;
			out.print(ans+"\n");
			
		}
		out.flush();
		out.close();
		


	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }

		String next() throws IOException
		{

			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();

		}
		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }



	}
}

