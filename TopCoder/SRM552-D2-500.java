import java.util.ArrayList;
import java.util.Stack;

public class ELR {

	// Math - Patterns
	// First write a backtracking to generate all valid grids, then you should notice the following
	// if n % 3 == 1, we need for a triangle of height n (m,m,m + 1) otherwise (m,m,m)
	// for a triangle of size n, m = f(n-1), where f(n) = (n+1)*(n+2)/6
	// if n % 3 == 0, simple division
	// otherwise binary search, and make sure you handle over flow checks correctly by division first

	static int n;
	public static void main(String[]args) throws Throwable {
		System.out.println(theMax(10,9,9,7));
	}
	public static long formula(long n) {
		return (n + 1) * (n + 2) / 6;
	}
		public static long theMax(long r,long g,long b,int n) {
			long x = formula(n - 1);
			System.out.println(x);
			if (n == 1) {
				return r + g + b;
			}
			if (n % 3 != 1) {
				return Math.min(r, Math.min(g, b)) / x;
			}
			
			long lo = 1, hi = r + g + b;
			long ans = 0;
			while (lo <= hi) {
				long mid = lo + (hi - lo) / 2;
				if (r / mid >= x  && g / mid >= x && b / mid >= x && (r - x * mid) + (g - x * mid) + (b - mid * x) >= mid) {
					ans = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			return ans;
		}
	public static void gen(int i,int j,char adj[][]) {


		if (i == n + 1) {
			int r = 0, bb = 0, g = 0;

			for (int a = 1 ; a <= n ; ++a) {
				for (int b = 1 ; b <= n - a + 1 ; ++b) {
					//System.out.print(adj[a][b]);
					if (adj[a][b] == 'R') ++r;
					if(adj[a][b] == 'B') ++bb;
					if(adj[a][b] == 'G') ++g;
				}
				//System.out.println("");
			}
			if (r != g || r != bb || g != bb) {
				System.out.println(n);
			}
			//System.out.println("R: "+r+" G: "+g+" B: "+bb+"\n");
			return;
		}
		if (j > n - i + 1) {
			gen(i + 1,1,adj);
			return;
		}
		char c[] = {'R','G','B'};
		for (int a = 0 ; a < 3 ; ++a) {
			char cur = c[a];
			if (j > 1 && cur == adj[i][j - 1]) {
				continue;
			}
			if (i > 1 && (cur == adj[i - 1][j] || cur == adj[i - 1][j + 1]))
				continue;

			adj[i][j] = cur;


			gen(i,j + 1,adj);
		}

	}
	

}