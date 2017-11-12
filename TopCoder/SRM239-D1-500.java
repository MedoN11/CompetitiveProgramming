import java.awt.Point;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class MathCounting {

	//Standard problem to minimize a property about a number using BFS.
    // BFS
	public static void main(String[]args)throws Throwable {
		System.out.println(count(1));
	}

	static int get(int x) {
		if(x == 8)
			return 7;
		if(x == 0 || x == 6 || x == 9)
			return 6;
		if(x == 2 || x == 3 || x == 5)
			return 5;
		if(x == 4 || x == 7)
			return 4;
		return 2;
	}
	public static long count(int x) {

		int offset = 250;
		Point pr[] = new Point[x + 1 + offset];
		Queue<Integer> Q = new LinkedList();
		boolean seen[] = new boolean[x + 1 + offset];
		Q.add(x);
		StringBuilder res = new StringBuilder();
		boolean first = true;
		while(!Q.isEmpty()) {
			int u = Q.poll();
			if(u < 0) {
				Point p = pr[u + offset];
				while(p != null) {
					res.append(p.y);
					p = pr[p.x];
				}
				return Long.parseLong(res.reverse().toString());
			}
			for(int k = 0 ; k <= 9 ; ++k) {
				if(first && k == 0)
					continue;
				int c = get(k);
				if(!seen[u - c + offset]) {
					Q.add(u - c);
					seen[u - c + offset] = true;
					pr[u - c + offset] = new Point(u + offset,k);
				}
				first = false;
			}
		}


		return 0;
	}
}
