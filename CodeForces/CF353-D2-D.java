import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class CF205_Queue 

{
	static char c[];
	static int n;

	static int slow(char c[])
	{
		char m[] = new char[c.length];
		int need = 0;
		for(int i = 0 ; i < c.length ; ++i) m[i] = c[i];
		boolean same = false;
		
		while(!same)
		{

			same = true;
			char tmp[] = new char[m.length];
			for(int i = 0 ; i < m.length ; ++i) tmp[i] = m[i];

			for(int i = 0 ; i < m.length - 1;  ++i)
			{
				if(m[i] == 'M' && m[i + 1] == 'F')
				{
					same = false;
					tmp[i] = 'F';
					tmp[i + 1] ='M';
				}
			}
			if(!same) ++need;
			for(int i = 0 ; i < m.length ; ++i) m[i] = tmp[i];
		}
		return need;
	}
	
	static class Girl
	{
		int ans;
		int pos;
		int goal;
		public Girl(int pos,int goal)
		{
			this.pos = pos;
			this.goal = goal;
		}
	}
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		c = sc.next().toCharArray();

		int dest = 0;
		ArrayList<Girl> girls = new ArrayList();
		boolean hasMale = false;
		for(int i = 0 ; i < c.length ; ++i)
		{
			if(c[i] == 'F')
			{
			
				girls.add(new Girl(i,dest++));
				
			}
		
		}
		int ans = 0;
		if(girls.size() != 0)
		{
			Girl g = girls.get(0);
			g.ans = g.pos - g.goal;
			ans = g.ans;
		}
	
		
		for(int i = 1 ; i < girls.size() ; ++i)
		{
			
			Girl right = girls.get(i);
			Girl left = girls.get(i - 1);
			if( (left.ans < right.pos - right.goal) || left.ans == 0)
				right.ans = right.pos - right.goal;
			else right.ans = left.ans + 1;
				//System.out.println(right.ans);
			ans = Math.max(right.ans, ans);

		}
		//System.out.println(ans+" "+slow(c));
		System.out.println(ans);
		
	}

	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }
		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}


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