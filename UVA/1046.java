import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Test
{

	static class Custom implements Comparator<Event> {
		 
	   

		@Override
		public int compare(Event o1, Event o2) {
			return o1.time - o2.time;
		}
	}

	static class Room implements Comparable<Room>
	{
		int cap,time;
		int idx;
		public Room(int cap,int time,int idx)
		{
			this.cap = cap;
			this.time = time;
			this.idx = idx;
		}
		@Override
		public int compareTo(Room o) {
			if(this.time == o.time)
				return this.cap - o.cap;
			return this.time- o.time;
		}
	}
	
	static class Event implements Comparable<Event>
	{
		int cap;
		int time;
		int idx;
		public Event(int cap,int time,int idx)
		{
			this.cap = cap;
			this.time = time;
			this.idx = idx;
		}
		@Override
		public int compareTo(Event o) {
			if(this.cap == o.cap)
			{
				if(this.time == o.time)
					return this.idx - o.idx;
				return this.time - o.time;
			}
			return this.cap - o.cap;
		}
	}

	static int w,rr;
	public static void main(String[]args)throws Throwable
	{
		int tc = 1;
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		while(true)
		{
			ArrayList<Room> rooms = new ArrayList();
			w = sc.nextInt();
			if(w == 0)
				break;	
			ArrayList<Event> events = new ArrayList();
			for(int i = 0 ; i < w ; ++i)
			{
				int cap = sc.nextInt();
				int time = sc.nextInt();
				events.add(new Event(cap,time,i));
			}
			int rr = sc.nextInt();
			for(int i = 0 ; i < rr ; ++i)
			{
				int cap = sc.nextInt();
				String str = sc.next();
				int ind = str.indexOf(':');
				int time = (Integer.parseInt(str.substring(0, ind)) - 14) * 60 + Integer.parseInt(str.substring(ind + 1,str.length()));
				rooms.add(new Room(cap,time,i));
			}
	
			Collections.sort(rooms);
			Collections.sort(events,new Custom());
					
			int ind = 0;
			TreeSet<Event> set = new TreeSet();
			for(int i = 0 ; i < rr ; ++i)
			{
				while(ind < w && events.get(ind).time <= rooms.get(i).time) 
					set.add(events.get(ind++));
			
				Event targ = set.floor(new Event(rooms.get(i).cap, 1 << 30, 1 << 30));
				if(targ != null)
				{
				set.remove(targ);
				}
			}
			while(ind < w)
				set.add(events.get(ind++));
			int wasted = 0;
			for(Event e : set)
			{
				wasted += e.cap;
			}
			out.printf("Trial %d: %d %d\n\n", tc++,set.size(),wasted);
						
		}
		out.flush();
		out.close();
	}




	static class SC
	{
		BufferedReader br;
		StringTokenizer st;


		SC(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }

		String next() throws IOException
		{
			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();

		}
		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }


		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	}
}