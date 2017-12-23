import java.util.Scanner;

public class GridCut {
	
	// Math
	
	
	
	// Solution must be a rectangle + exactly one non filled row or column
	// Rectangle must start from (0,0)
	// Removing k is same as removing n * m - k
	// handle all cases by bruteforce except the row/col case, do it by mod.
	public static void print(int m,int n) {
		for(int i = 0 ;i  < n ; ++i) {
			for(int j = 0 ; j < m; ++j) {
				System.out.print("0");
			}
			System.out.println();
		}
	}
	static int n,m,k;

	public static void main(String[]args)throws Throwable {
		Scanner sc = new Scanner(System.in);
		System.out.println(cutLength(sc.nextInt(),sc.nextInt(),sc.nextInt()));

	}

	static int solve(int n,int m,int k) {
		if(k == 0)
			return 0;
		int ans = 1 << 30;
		for (int i = 1 ; i <= n ; ++i) {
			for (int j = 1 ; j <= m ; ++j) {
				if (i * j >= k) {
					ans = Math.min(i  + j, ans);

				}

			}
		}
		if(k % n == 0) ans = Math.min(ans, n);
		else ans = Math.min(ans, n + 1);
		if(k % m == 0) ans = Math.min(ans, m);
		else ans = Math.min(ans, m + 1);
		return ans;

	}

	public static int cutLength(int a,int b,int c) {
		n = b;
		m = a;
		k = c;
		//System.out.println(cut(2,2));
		int ans = 1 << 30;
		ans = Math.min(ans,solve(n,m,k));
		ans = Math.min(ans, solve(n,m,n * m - k));

		return ans;
	}
}