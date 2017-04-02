package WF2004;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class IntersectingDates 
{

	
    static TreeMap<Integer,Integer> map = new TreeMap();
    
    public static void add(int date)
    {
    	 map.put(date, 0);
    	 map.put(prev(date), 0);
    	 map.put(next(date), 0);
    }
  
    public static int prev(int x)
    {
    	int daysFelMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    	
    	int year = x / 10000; int month = (x % 10000) / 100;
    	int day = x % 100;
    	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    	{
    		daysFelMonth[2] = 29;
    	}
    	if(month == 1 && day == 1)
    	{
    		--year; month = 12; day = 31;
    	}
    	else
    	{
    		--day;
    		if(day < 1)
    		{
    			month--;
    			day = daysFelMonth[month];
    		}
    	}
    	return year * 10000 + month * 100 + day;
    }
    
    public static int next(int x)
    {
int daysFelMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    	
    	int year = x / 10000; int month = (x % 10000) / 100;
    	int day = x % 100;
    	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    	{
    		daysFelMonth[2] = 29;
    	}
    	if(month == 12 && day == 31)
    	{
    		++year; month = 1; day = 1;
    	}
    	else
    	{
    		++day;
    		if(day > daysFelMonth[month])
    		{
    			month++;
    			day = 1;
    		}
    	}
    	return year * 10000 + month * 100 + day;
    }
    
 
    
    
    public static void putDate(int x,PrintWriter out)
    {
		out.printf("%d/%d/%d",(x%10000)/100,x % 100,x/10000);

    }
	public static void main(String[]args)throws Throwable
	{
		int tc = 1;
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n,Q;
		while(true)
		{
			n = sc.nextInt(); Q = sc.nextInt();
			map.clear();
			if(n + Q == 0)
				break;
			if(tc > 1)
				out.print("\n");
			out.printf("Case %d:\n",tc++);
			int nL[],nR[],qL[],qR[];
			nL = new int[n]; nR = new int[n];
			qL = new int[Q]; qR = new int[Q];
			for(int i = 0 ; i < n ; ++i)
			{
				int from = sc.nextInt(); int to = sc.nextInt();
				add(from); add(to);
				nL[i] = from; nR[i] = to;
			
			}
			for(int qq = 0 ; qq < Q ; ++qq )
			{
				int from = sc.nextInt(); int to = sc.nextInt();
				add(from); add(to);
				qL[qq] = from; qR[qq] = to;
			}
	
			int size = 0;
			TreeMap<Integer,Integer> datetoID = new TreeMap();
			ArrayList<Integer> dates = new ArrayList();
			for(Entry<Integer,Integer> e : map.entrySet())
			{
				datetoID.put(e.getKey(),size++);
				dates.add(e.getKey());
			}
			int ptr = 0;
			int color[] = new int[size];
			for(int i = 0 ; i < Q ; ++i)
			{
				int from = datetoID.get(qL[i]); int to = datetoID.get(qR[i]);
				for(int j = from; j <= to ; ++j)
				{
					color[j] = 1;
				}
			}
			for(int i = 0 ; i < n ; ++i)
			{
				int from = datetoID.get(nL[i]); int to = datetoID.get(nR[i]);
				for(int j = from; j <= to ; ++j)
				{
					color[j] = 0;
				}
			}
			boolean added = false;
			while(ptr < size)
			{
				if(color[ptr] == 1)
				{
					added = true;
					out.printf("    ");
					putDate(dates.get(ptr),out);
					if(ptr + 1 < size && color[ptr + 1] == 1)
					{
						out.print(" to ");
						while(ptr + 1 < size && color[ptr + 1] == 1) ++ptr;
						putDate(dates.get(ptr),out);
						out.printf("\n");
					}
					else out.printf("\n");
				}
				ptr++;
			}
			if(!added)
			{
				out.print("    No additional quotes are required.\n");
			}
			
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

		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }


	}
}
