import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class CF_377D 
{


	static class SegmentTree 
	{

		int[] lo,hi,lazy,max;
	

		SegmentTree(int n)
		{
			lo = new int[4 * n + 1];
			hi = new int[4 * n + 1]; 
			lazy = new int[4 * n + 1]; 
			max = new int[4 * n + 1];
			init(1,1,n);
		}

		void init(int i,int a,int b)
		{
			lo[i] = a; hi[i] = b;
			if(a == b)
			{
				max[i] = 0;
				return;
			}
			int mid = (a + b) / 2;
			init(i << 1,a,mid);
			init((i << 1) + 1,mid + 1,b);
		}
		void increment(int a,int b,int val)
		{
			increment(1,a,b,val);
		}
		int maximum(int a,int b)
		{
			return maximum(1,a,b);
		}
		void update(int i)
		{
			max[i] = Math.max(max[i << 1] + lazy[i << 1], max[(i << 1) + 1] + lazy[(i << 1) + 1]);
		}
		void prop(int i)
		{
			lazy[i << 1] += lazy[i];
			lazy[(i << 1) + 1] += lazy[i];
			lazy[i] = 0;
		}


		int maximum(int i,int a,int b)
		{
			// out of cover
			if(b < lo[i] || a > hi[i])
				return -(1 << 30);
			// fully covered
			if(a <= lo[i] && hi[i] <= b)

				return max[i] + lazy[i];

			prop(i);

			int maxLeft = maximum(i << 1,a,b);
			int maxRight = maximum((i << 1) + 1,a,b);

			update(i);
			return Math.max(maxLeft, maxRight);
		}
		void increment(int i,int a,int b,int val)
		{
			// out of cover
			if(b < lo[i] || a > hi[i])
				return;
			// fully covered
			if(a <= lo[i] && hi[i] <= b)
			{
				lazy[i] += val;
				return;
			}
			// partial cover

			// propagate
			prop(i);

			// increment
			increment(i << 1,a,b,val);
			increment((i << 1) + 1,a,b,val);


			update(i);

		}
	}
	static class Person implements Comparable<Person>
	{
		int l,v,r,id;
		public Person(int l,int v,int r,int id)
		{
			this.l = l;
			this.r = r;
			this.v = v;
			this.id = id;
		}
		@Override
		public int compareTo(Person o) 
		{
			return this.r - o.r;
		}

	}

	static Person p[];
	static int n;

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		p = new Person[n];
		for(int i = 0 ; i < n ; ++i)
			p[i] = new Person(sc.nextInt(),sc.nextInt(),sc.nextInt(),i + 1);
		Arrays.sort(p,new Comparator<Person>() {

			public int compare(Person a , Person b) 
			{

				return a.v - b.v;
			}

		});
		PriorityQueue<Person> pq = new PriorityQueue();
		SegmentTree st = new SegmentTree(3*100005);
		int ans = 0;
		int opt = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			Person curr = p[i];
			
			while(!pq.isEmpty() && pq.peek().r < curr.v)
			{
				st.increment(1,pq.peek().l,pq.peek().v,-1);
				pq.poll();
			}
			pq.add(curr);
			st.increment(1,curr.l,curr.v,1);
			int tmp = 0;
			ans = Math.max(ans, tmp = st.maximum(curr.l,curr.v));
			if(ans == tmp)
				opt = i;

		}
		 st = new SegmentTree(3*100005);
		 for(int i = opt ; i >= 0 ; --i)
		 {
			 if(p[i].r >= p[opt].v)
			 {
				 st.increment(p[i].l, p[i].v, 1);
				
			 }
		 }
		 int s = -1;
		 int e = p[opt].v;
		 for(int k = 0 ; k <= e; ++k)
		 {
			
			 if(st.maximum(k,k) == ans)
			 {
				 s = k;
				 break;
			 }
			 
		 }
		 
		// System.out.println(s+" "+e);
		
		PrintWriter out = new PrintWriter(System.out);
	
		out.println(ans);
		
		for(int i = 0 ; ans > 0 && i <= opt ; ++i)
		{
			if(p[i].r >= e && p[i].v >= s && p[i].l <= s)
			{
				out.print(p[i].id+" "); --ans;
				
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
