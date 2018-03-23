import java.util.ArrayList;
import java.util.TreeSet;

public class CandidatesSelection {

	// DFS + bitmasks
	public static void main(String[]args)throws Throwable {
		
		String res[] = {
				"#....",
				"^#...",
				"#...."};
		System.out.println(capture(res));
	}
	static char grid[][];
	static boolean seen[][];
	static int n,m;
	static int r1 = -1,r2 = -1,c1 = -1, c2 = -1;
	static int dx[] = {0,1,-1,0};
	static int dy[] = {1,0,0,-1};
	static boolean ok(int i,int j) {
		if(i < 0 || j < 0 || i >= n || j >= m)
			return false;
		if(grid[i][j] == '#')
			return false;
		if(i == r1 || i == r2 || j == c1 || j == c2)
			return false;
		return true;
	}
	static boolean go(int i,int j) {
		if(seen[i][j]) {
			return false;
		}
		seen[i][j] = true;
		if(i == n - 1 || j == m - 1 || i == 0 || j == 0)
			return true;
		boolean reach = false;
		for(int k = 0 ; k < 4;  ++k) {
			int xc = dx[k] + i, yc = dy[k] + j;
			if(ok(xc,yc))
				reach |= go(xc,yc);
		}
		return reach;
	}
	public static int capture(String[] lab) {
		grid = new char[lab.length][lab[0].length()];
		n = grid.length;
		m = grid[0].length;
		ArrayList<Integer> pos = new ArrayList();
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				grid[i][j] = lab[i].charAt(j);
				if(grid[i][j] == '^') pos.add(i * m + j);
			}
		}
		int ans = 5;
		// UDLR
		for (Integer a : pos) {
			int i = a / m , j = a % m;

			for (int msk = 0 ; msk < (1 << 4) ; ++msk) {
				r1 = -1;
				r2 = -1;
				c1 = -1;
				c2 = -1;
				if((msk & (1 << 0)) > 0) {
					r1 = i - 1;
				}
				if((msk & (1 << 1)) > 0) {
					r2 = i + 1;
				}
				if((msk & (1 << 2)) > 0) {
					c1 = j - 1 ;
				}
				if((msk & (1 << 3)) > 0) {
					c2 = j + 1;
				}
				seen = new boolean[n][m];
				if(!go(i,j)) {
					ans = Math.min(ans, Integer.bitCount(msk));
				}
			}


		}
		if(ans == 5) ans = -1;
		return ans;
	}
}