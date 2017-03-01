import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HELPR2D2
{


	static int lo[],hi[],res[];
	static int arr[];


	static void upd(int ind)
	{
		res[ind] = Math.max(res[ind << 1], res[(ind << 1) + 1]);
	}
	static void build(int ind,int a,int b)
	{
		lo[ind] = a; hi[ind] = b;
		if(a == b)
		{
			res[ind] = arr[a];
			return;
		}
		int mid = (a + (b - a) / 2);
		build(ind << 1,a,mid);
		build((ind << 1) + 1,mid + 1,b);
		upd(ind);
	}

	static void query(int ind,int val)
	{

		if(lo[ind] == hi[ind])
		{
			
			arr[lo[ind]] -= val;
			res[ind] = arr[lo[ind]];
			return;
		}
		if(res[ind << 1] >= val)
		{
			query(ind << 1,val);
		}
		else query((ind << 1) + 1,val);

		upd(ind);
	}
	
	public static void main(String[]args)throws Throwable
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = new Integer(br.readLine());
		PrintWriter out = new PrintWriter(System.out);
		while(t-- > 0)
		{
			int k = new Integer(br.readLine());
			int n = new Integer(br.readLine());
			arr = new int[n + 1];
			lo = new int[4 * (n + 1)];
			hi = new int[4 * (n + 1)];
			res = new int[4 * (n + 1)];
			Arrays.fill(arr, k);
			arr[0] = 0;
			build(1,1,n);
			int m = n;
			while(m > 0)
			{
				st = new StringTokenizer(br.readLine());
				if(st.countTokens() == 1)
				{
					int x = new Integer(st.nextToken());
					query(1,x);
					--m;
				}
				else
				{
					st.nextToken();
					int r = new Integer(st.nextToken());
					int x = new Integer(st.nextToken());
					m -= r;
					while(r-- > 0)
						query(1,x);
					
				}
			}
			long waste = 0, used = 0;
			for(int i = 1 ; i <= n ; ++i)
			{
				
				if(arr[i] == k)
					break;
				waste += (arr[i]);
				++used;
			}
			out.println(used+" "+waste);
		}
		out.flush();
		out.close();
		
	}

}
