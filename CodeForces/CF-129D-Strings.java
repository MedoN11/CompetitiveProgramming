import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Stringss 
{

	static long H[];
	static long P[];
	static String str;

	static class Substring implements Comparable<Substring>
	{
		int start,end;
		public Substring(int start,int end)
		{
			this.start = start;
			this.end = end;
		}
		public int compareTo(Substring o)
		{
			long thisHash = getHash(this.start,this.end);
			long oHash = getHash(o.start,o.end);
			int thisLen = this.end - this.start + 1;
			int oLen = o.end - o.start + 1;
			if(thisHash == oHash && thisLen == oLen)
				return 0;
			if(thisHash == oHash && thisLen < oLen)
				return -1;
			if(thisHash == oHash && thisLen > oLen)
				return 1;			

			int lo = 0;
			int hi = Math.min(thisLen, oLen) - 1 ;
			int lastSamePos = -1;
			while(lo <= hi)
			{
				int mid = lo + (hi -lo) / 2;
				if(getHash(this.start,this.start + mid) == getHash(o.start,o.start + mid))
				{
					lo = mid + 1;
					lastSamePos = mid;
				}
				else hi = mid - 1;
			}
			if(lastSamePos == Math.min(thisLen, oLen) - 1)
				return thisLen == oLen ? 0 : thisLen <= oLen ? -1 : 1;
			return str.charAt(this.start + lastSamePos + 1) < str.charAt(o.start + lastSamePos + 1) ? - 1 : 1;
		}
	}
	static int p = 31;

	public static long getHash(int i, int j)
	{
		return H[j + 1] - P[j - i + 1] * H[i];
	}

	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		str = sc.next();
		int k = sc.nextInt();
		int len = str.length();
		long lim = 1L*(len) * (len + 1); lim >>= 1;
			if(k > lim)
			{
				System.out.println("No such line.");
				return ;
			}
			H = new long[len + 1];
			P = new long[len + 1];
			P[0] = 1;
			for(int i = 1 ; i <= len ; ++i)
			{
				H[i] = p * H[i - 1] + str.charAt(i - 1);
				P[i] = p * P[i - 1];
			}

			PriorityQueue<Substring> PQ = new PriorityQueue();

			for(int i = 0 ; i < len ; ++i)
				PQ.add(new Substring(i,i));
			while(k > 1)
			{
				Substring curr = PQ.poll();
				--k;
				//System.out.println(str.substring(curr.start,curr.end + 1));
				curr.end++;
				if(curr.end < len)
					PQ.add(curr);

			}
			Substring res = PQ.poll();
			System.out.println(str.substring(res.start, res.end + 1));


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