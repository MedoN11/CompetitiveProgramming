
public class FindingSquareInTable {

	static int arr[][];
	static int N,M;

	public static void main(String[]args)throws Throwable
	{
		String s[] ={"257240281",
				"197510846",
				"014345401",
				"035562575",
				"974935632",
				"865865933",
				"684684987",
				"768934659",
		"287493867"};
		System.out.println(findMaximalSquare(s));

	}

	static boolean isSqr(long x)
	{
		long lo = 0;
		long hi = x;
		while(lo <= hi)
		{
			long mid = lo +(hi-lo)/2;
			if(mid*mid == x) return true;
			if(x>mid*mid) lo = mid+1;
			else hi = mid - 1;
		}
		return false;
	}


	public static int reverse(long x)

	{
		int c = 0;
		while(x!=0)
		{
			c*=10; c+= x%10;
			x/=10;
		}
		return c;
	}
	public static int count(int i,int j,int di,int dj)
	{

		long k = -1;
		if(di==0&&dj==0)
		{
			if(isSqr(arr[i][j])) return arr[i][j];
			else return -1;
		}
		long num = 0 ;
		int a = i; int b = j;

		while(a < N && b < M && a>=0 && b>=0)
		{
			num*= 10; num += arr[a][b];
			long rev = reverse(num);
			if(isSqr(num)) k = Math.max(k,num);
			if(isSqr(rev)) k = Math.max(k,rev);
			a+=di; b+=dj;

		}
		return (int)k;
	}
	public static int solve()
	{
		N = arr.length;
		int sq = - 1;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ;j++){
				for(int di = 0 ; di < N ; di++)
				{
					for(int dj = 0 ; dj < M ; dj++)
					{
						sq = Math.max(sq,count(i,j,di,dj));
						sq = Math.max(sq,count(i,j,di*-1,dj*-1));
						sq = Math.max(sq, count(i,j,di,dj*-1));
						sq = Math.max(sq, count(i,j,di*-1,dj));

					}
				}
			}
		}
		return (int)sq;
	}
	public static int findMaximalSquare(String[] t)
	{


		N = t.length;
		M = t[0].length();
		arr = new int[N][M];
		for(int i = 0 ; i < N ;i++) for(int j = 0 ; j < M ;j++) arr[i][j] = (t[i].charAt(j)-'0');
		int x = (int)solve();
		return (int)x;
	}
}
