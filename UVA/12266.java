package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class StockPrice 
{


	static class Pair implements Comparable<Pair>
	{
		int first,second;
		public Pair(int first,int second)
		{ 
			this.first = first; this.second = second;
		}
		public int compareTo(Pair o)
		{
			
			return this.first - o.first;
		}
	}
	
	static class Entry implements Comparable<Entry>
	{
		int first,second;
		public Entry(int first,int second)
		{ 
			this.first = first; this.second = second;
		}
		public int compareTo(Entry o)
		{
			
			return o.first - this.first;
		}
		
	}
	static PriorityQueue<Entry> buy = new PriorityQueue();
	static PriorityQueue<Pair> sell = new PriorityQueue();
	static int tc,n;
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		tc =  sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		while(tc-- > 0 )
		{
			n = sc.nextInt();
			buy.clear(); sell.clear();
			int lst = -1;
			while(n-- > 0)
			{
				
				String type = sc.next(); int amount = sc.nextInt(); sc.next(); sc.next(); int price = sc.nextInt();
				if(type.equals("buy"))
					buy.add(new Entry(price,amount));
				else sell.add(new Pair(price,amount));

				int ask = -1, bid = -1;
				while(!sell.isEmpty() && !buy.isEmpty())
				{
					Pair p = sell.poll(); Entry e = buy.poll();
					//System.out.println(e.first +" "+p.first);
					if(e.first >= p.first)
					{
						int min = Math.min(p.second, e.second);
						p.second -= min; e.second -= min;
						lst = p.first;
					}
					else
					{
						sell.add(p); buy.add(e);
						break;
					}
					if(p.second > 0)
						sell.add(p);
					if(e.second > 0)
						buy.add(e);
					
				}
				if(!sell.isEmpty()) ask = sell.peek().first;
				if(!buy.isEmpty()) bid = buy.peek().first;
				//System.out.println(lst+" "+ask+" "+bid);
				String a = (lst == -1 ? "-" : ""+lst);
				String b = (ask == -1 ? "-" : ""+ask);
				String c = (bid == -1 ? "-" : ""+bid);
				out.println(b+" "+c+" "+a);
				
			}
			
		}
		out.flush(); out.close();
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

