import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class FirstFollow {

	static long mod = 1000*1000*1000 + 7;
	public static void main(String[]args) throws Throwable {
		System.out.println(countsets(5,5,3));
	}
	// Fix slope (dx,dy) and fix start point
	// how to avoid over counting?
	// if gcd(dx,dy) != 1, then this means it can be written as (gcd*p,gcd*q)
	// let p and q be another (dx,dy) generated pair, and gcd the steps...using that we overcount
	// so generate only pairs with gcd(x,y) == 1
	static class Point {
		int x,y;
		public Point(int x,int y) {
			this.x = x;
			this.y = y;
		}
	}
	static long gcd(long a,long b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a,a);
	}
	public static int countsets(int L,int H,int K) {
		long C[][] = new long[301][301];
		if (K == 1) {
			return (L + 1) * (H + 1);
		}
		
		C[0][0] = 1;
		for (int i = 1 ; i < 300 ; ++i) {
			C[i][0] = 1;
			for (int j = 1 ; j < 300 ; ++j) {
				C[i][j] += C[i - 1][j - 1] + C[i - 1][j];
				C[i][j] %= mod;
			}
		}
		long res = 0;
		for (int i = 0 ; i <= L ; ++i) {
			
			for (int dx = -205 ; dx <= 205 ; ++dx) {
				for (int dy = 1 ; dy <= 205 ; ++dy) {
					if (gcd(Math.abs(dx),dy) == 1) {
						int done = 0;
						Point tmp = new Point(i,0);
						while(tmp.x >= 0 && tmp.y >= 0 && tmp.x <= L && tmp.y <= H) {
							tmp.x += dx;
							tmp.y += dy;
							++done;
						}
						res += C[done][K];
						res %= mod;
					}
				}
			}
		}
		return (int)res;
	}
}
