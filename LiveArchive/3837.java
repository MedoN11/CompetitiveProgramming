import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BrokenRobot {


	static char male[],female[];
	static int revMale[],revFemale[];
	static int prefFemale[][];
	static Queue<Integer> prefMale[];
	static int husband[];
	static int n;

	static class Pair implements Comparable<Pair> {
		char m,f;
		public Pair(char m,char f){
			this.m = m;
			this.f = f;
		}
		@Override
		public int compareTo(Pair o) {
			return (int)(this.m - o.m);
		}
	}
	static void stableMarriage() {
		Queue<Integer> free = new LinkedList();

		for (int i = 0 ; i < n ; ++i) {
			free.add(i);
			husband[i] = -1;
		}
		while(!free.isEmpty()) {
			int curr = free.poll();
			
		
			int choice = prefMale[curr].poll();
			if(husband[choice] == -1) {
				husband[choice] = curr;
			}
			else {
				if(prefFemale[choice][curr] < prefFemale[choice][husband[choice]]) {
					free.add(husband[choice]);
					husband[choice] = curr;
				}
				else {
					free.add(curr);
				}


			}
		}
	}
	public static void main(String[]args)throws Throwable {
		Scanner sc =  new Scanner(System.in);
		int t = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);

		while(t-- > 0) {

			n = sc.nextInt();
			male = new char[n];
			female = new char[n];
			revMale = new int[26];
			revFemale = new int[26];
			prefFemale = new int[n][n];
			prefMale = new LinkedList[n];
			for (int i = 0 ; i < n ; ++i) {
				prefMale[i] = new LinkedList();
				char c = sc.next().charAt(0);
				male[i] = c;
				revMale[c - 'a'] = i;
			}
			husband = new int[n];
			for (int i = 0 ; i < n ; ++i) {
				char c = sc.next().charAt(0);
				female[i] = c;
				revFemale[c - 'A'] = i;
			}
			StringTokenizer st;
			for(int i = 0 ; i < n ; ++i) {
				st = new StringTokenizer(sc.next(),":");
				String p = st.nextToken();
				String list = st.nextToken();
				int ind = p.charAt(0) - 'a';
				for(int j = 0 ; j < list.length() ;++j) {


					int nxt = revFemale[list.charAt(j) - 'A'];
					prefMale[revMale[ind]].add(nxt);
				}

			}

			for(int i = 0 ; i < n ; ++i) {
				st = new StringTokenizer(sc.next(),":");
				String p = st.nextToken();
				String list = st.nextToken();
				int ind = p.charAt(0) - 'A';

				for(int j = 0 ; j < list.length() ;++j) {
					int nxt = revMale[list.charAt(j) - 'a'];
					prefFemale[ind][nxt] = j;
				}

			}
			stableMarriage();
			Pair p[] = new Pair[n];
			for(int i = 0 ; i < n ; ++i) {
				p[i] = new Pair(male[husband[i]],female[i]);
			}
			Arrays.sort(p);
			for(int i = 0 ; i < p.length ; ++i) {
				out.println(p[i].m + " " + p[i].f);
			}
			if(t != 0)
			out.println();


		}
		out.flush();
		out.close();



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
