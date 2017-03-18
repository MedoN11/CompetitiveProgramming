import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main
{


	static class State implements Comparable<State>
	{
		int i,j,ind,steps;

		public State(int i,int j,int ind,int steps)
		{
			this.i = i; this.j = j; this.ind = ind; this.steps = steps;
		}

		@Override
		public int compareTo(State o) 
		{
			return this.steps - o.steps;
		}
	}

	static int N,M;
	static char grid[][];
	static int DP[][][] = new int[51][51][51];


	static boolean valid(int i,int j)
	{
		return i >= 0 && i < N && j >= 0 && j < M;
	}
	public static void main(String[]args)throws Throwable
	{

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt();
		grid = new char[N][M];
		int startI = - 1, startJ = -1;
		int endI = -1, endJ = -1;
		for(int i = 0 ; i < N ; ++i)
		{
			String str = sc.next();
			for(int j = 0 ; j < M ; ++j)
			{
				grid[i][j] = str.charAt(j);
				if(grid[i][j] == 'R')
				{
					startI = i; startJ = j;
				}
				if(grid[i][j] == 'E')
				{
					endI = i; endJ = j;
				}
			}
		}
		String command = sc.next();
		for(int i = 0 ; i < 51 ; ++i)
			for(int j = 0 ; j < 51 ; ++j)
				Arrays.fill(DP[i][j], 1 << 30);
		PriorityQueue<State> PQ = new PriorityQueue();
		PQ.add(new State(startI,startJ,0,0));
		DP[startI][startJ][0] = 0;
		int min = 1 << 30;
		char dir[] = {'U','D','L','R'};
		while(!PQ.isEmpty())
		{
			State curr = PQ.poll();
			int i = curr.i; int j = curr.j; int ind = curr.ind;
			if(DP[i][j][ind] < curr.steps)
				continue;
			if(i == endI && j == endJ)
				min = Math.min(min, curr.steps);
			// take the current step
			if(ind < command.length())
			{
				int tmpI = i; int tmpJ = j;
				if(command.charAt(ind) == 'U') --tmpI;
				if(command.charAt(ind) == 'D') ++tmpI;
				if(command.charAt(ind) == 'L') --tmpJ;
				if(command.charAt(ind) == 'R') ++tmpJ;
				if(!valid(tmpI,tmpJ) || grid[tmpI][tmpJ] == '#')
				{
					tmpI = i; tmpJ = j;
					
				}
				if(DP[tmpI][tmpJ][ind + 1] > curr.steps)
				{
					DP[tmpI][tmpJ][ind + 1] = curr.steps;
					PQ.add(new State(tmpI,tmpJ,ind + 1,curr.steps));
				}

			}


			// modify by deleting
			if(ind < command.length())
			{
				if(DP[i][j][ind + 1] > 1+ curr.steps)
				{
					DP[i][j][ind + 1] =1 + curr.steps;
					PQ.add(new State(i,j,ind + 1,1 +curr.steps));
				}
			}

			// modify by inserting
			for(int k = 0 ; k < 4;  ++k)
			{
				char c = dir[k];
				int tmpI = i; int tmpJ = j;
				if(c == 'U') --tmpI;
				if(c == 'D') ++tmpI;
				if(c == 'L') --tmpJ;
				if(c == 'R') ++tmpJ;

				if(!valid(tmpI,tmpJ) || grid[tmpI][tmpJ] == '#')
				{
					continue;
				}
				if(DP[tmpI][tmpJ][ind] > curr.steps + 1)
				{
					DP[tmpI][tmpJ][ind] = curr.steps + 1;
					PQ.add(new State(tmpI,tmpJ,ind,curr.steps + 1));
				}


			}
		}

		System.out.println(min);


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
