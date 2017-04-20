package WF2011;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class AncientMessages 
{


	static int dx[] = {0,1,-1,0,1,-1,-1,1};
	static int dy[] = {1,0,0,-1,1,-1,1,-1};
	static int n,m;
	static char grid[][];
	static int myComp[][];
	static ArrayList<Integer> comp[];
	static boolean seen[][];
	static TreeMap<Character,String> map = new TreeMap();

	static void put()
	{
		map.put('0', "0000");
		map.put('1',"0001");
		map.put('2', "0010");  
		map.put('3', "0011");  
		map.put('4', "0100"); 
		map.put('5', "0101");
		map.put('6', "0110"); 
		map.put('7', "0111"); 
		map.put('8', "1000");
		map.put('9', "1001");
		map.put('a', "1010");
		map.put('b', "1011"); 
		map.put('c', "1100");
		map.put('d', "1101");
		map.put('e', "1110");
		map.put('f', "1111");
	}

	public static String get(String s)
	{

		StringBuilder sb  = new StringBuilder();
		for(int i = 0 ; i < s.length() ; ++i)
			sb.append(map.get(s.charAt(i)));

		return sb.toString();
	}

	static boolean valid(int i,int j)
	{
		return i >= 0 && j >= 0 && i < n && j < m;
	}


	public static void dfs(int i,int j,int c)
	{
		if(seen[i][j])
			return;
		seen[i][j] = true;
		myComp[i][j] = c;
		comp[c].add(i * m + j);
		for(int k = 0 ; k < 4 ; ++k)
		{
			int xc = dx[k] + i; int yc = dy[k] + j;
			if(valid(xc,yc) && !seen[xc][yc] && grid[xc][yc] == '1')
				dfs(xc,yc,c);
		}
	}

	public static void dfsWhite(int i,int j,int c)
	{
		if(seen[i][j])
			return;
		myComp[i][j] = c;
		seen[i][j] = true;
		for(int k = 0 ; k < 8 ; ++k)
		{
			int xc = dx[k] + i; int yc = dy[k] + j;
			if(valid(xc,yc) && !seen[xc][yc] && grid[xc][yc] == '0')
				dfsWhite(xc,yc,c);
		}
	}
	public static void main(String[] args) throws Throwable {new Thread(null, new Runnable() { public void run() {try {
		sol();
	} catch (Throwable e) {

		e.printStackTrace();
	} 
	}}, "2",1<<26).start();}


	public static void sol() throws Throwable
	{

		put();
		PrintWriter out = new PrintWriter(System.out);
		int tc = 1;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		while(true)
		{
			st = new StringTokenizer(br.readLine());
			n = new Integer(st.nextToken()); m = new Integer(st.nextToken());


			if(n + m == 0)
				break;
			m <<= 2;
			n += 2; m += 2;
		
			grid = new char[n][m];
			for(int j = 0 ; j < m ; ++j)
			{
				grid[0][j] = grid[n - 1][j] = '0';
			}
			
			for(int i = 1 ; i < n - 1; ++i)
			{
			;
				String str = get(br.readLine());
				grid[i][0] = grid[i][m - 1] = '0';
				for(int j = 1 ; j < m - 1; ++j)
				{
					
					grid[i][j] = str.charAt(j - 1);
				}
				

			}
//			for(int i = 0 ; i < n ; ++i)
//			{
//				for(int  j = 0 ; j < m ; ++j)
//				{
//					System.out.print(grid[i][j]);
//				}
//				System.out.println("");
//			}
//			

			seen = new boolean[n][m];
			comp = new ArrayList[n * m];
			for(int i = 0 ; i < n * m ; ++i) comp[i] = new ArrayList();
			myComp = new int[n][m];
			ArrayList<Character> ans = new ArrayList();
			int cnt = 0;
			int whiteCnt = 0;

			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < m  ; ++j)
				{
					if(seen[i][j])
						continue;
					if(grid[i][j] == '1')
					{

						dfs(i,j,cnt++);
					}
					else
					{

						dfsWhite(i,j,whiteCnt++);
					}
				}
			}

			for(int c = 0 ; c < cnt ; ++c)
			{
				TreeSet<Integer> set = new TreeSet();
				for(Integer x: comp[c])
				{
					int i = x / m; int j = x % m;
					for(int k = 0 ; k < 4 ; ++k )
					{
						int xc = dx[k] + i; int yc = dy[k] + j;
						if(valid(xc,yc) && grid[xc][yc] == '0')
							set.add(myComp[xc][yc]);
					}
				}
				int size = set.size();

				if(size == 2)
					ans.add('A');
				if(size == 4)
					ans.add('J');
				if(size == 6)
					ans.add('D');
				if(size == 5)
					ans.add('S');
				if(size == 1)
					ans.add('W');
				if(size == 3)
					ans.add('K');
			}
			Collections.sort(ans);
			out.printf("Case %d: ",tc++);
			for(int i = 0 ; i < ans.size() ; ++i)
				out.printf("%c", ans.get(i));
			out.printf("\n");


		}
		out.flush();
		out.close();
	}

}
