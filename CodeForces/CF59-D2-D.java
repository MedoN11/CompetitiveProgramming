package CodeForces;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class TeamArrangment {

	
	
	static class Team
	{
		int a,b,c;
		int id;
		
		public Team(int a,int b,int c,int id)
		{
			int arr[] = {a,b,c};
			this.id = id;
			Arrays.sort(arr);
			this.a = arr[0]; this.b = arr[1]; this.c = arr[2];
		}
	}
	public static void main(String[]args)throws Throwable
	{
		System.out.println(3^4^3^4);
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n,arr[];
		n = sc.nextInt(); arr = new int[3 * n];
		for(int i = 0 ; i < 3 * n ; ++i)
			arr[i] = sc.nextInt();
		ArrayList<Team> teams = new ArrayList();
		for(int i = 0 ; i < n ; ++i)
			teams.add(new Team(sc.nextInt(),sc.nextInt(),sc.nextInt(),i));
		int k = sc.nextInt();
		int myTeam = -1;
		int mx = 0;
		for(Team t : teams)
		{
			if(t.a == k || t.b == k || t.c == k)
				myTeam = t.id;
			if(t.a == k)
				mx = t.c;
			if(t.b == k)
				mx = t.c;
			if(t.c == k)
				mx = t.b;
		
		}
		boolean myChoice = false;
		for(int i = 0 ; i < 3 * n ; ++i)
		{
			if(arr[i] == k)
			{
				myChoice = true;
				break;
			}
			if(arr[i] == teams.get(myTeam).a)
			   break;
			if(arr[i] == teams.get(myTeam).b)
				   break;
			if(arr[i] == teams.get(myTeam).c)
				   break;
					
		}
		if(!myChoice)
		{
			for(int i = 1 ; i <= 3 * n ; ++i)
				if(i != k)
				out.print(i+" ");
		}
		else
		{
			ArrayList<Integer> above = new ArrayList();
			ArrayList<Integer> below = new ArrayList();
			int i;
			for(i = 0 ; i < n ; ++i)
			{
				Team t = teams.get(i);
				if(t.a != k)
				above.add(t.a);
				if(t.b != k)
				above.add(t.b);
				if(t.c != k)
				above.add(t.c);
				if(t.a == k || t.b == k || t.c == k)
					break;
			
			}
			++i;
			for(; i < n ; ++i)
			{
				Team t = teams.get(i);
				
				below.add(t.a); below.add(t.b); below.add(t.c);
			
			}
			Collections.sort(above); Collections.sort(below);
			int L = 0;
			while(L < above.size() && above.get(L) <= mx)
			{
				out.print(above.get(L++)+" ");
			}
			int R = 0;
			while(L < above.size() && R < below.size())
			{
				if(above.get(L) < below.get(R))
				{
					out.print(above.get(L++)+" ");
				}
				else out.print(below.get(R++)+" ");
			}
			while(L < above.size())
			{
				out.print(above.get(L++)+" ");
			}
			while(R < below.size())
			{
				out.print(below.get(R++)+" ");
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

	}
}