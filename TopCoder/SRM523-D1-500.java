import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class Ezz {


	// Dynamic Programming
	// generated all tilings using two dp functions
	public static void main(String[]args) throws Throwable {
		System.out.println(countStructures(10,10,3));
	}

	static int w,h,k;

	static final long mod = 1000*1000*1000 + 7;
	static long cache[];
	static Long dp[][][][];
	static long c[][];
	static long getWays(int x) {
		return cache[x]%mod;
	}

	// 0 as you like
	// 1 must skip
	// 2 must not skip
	static long solve(int l,int r,int h,int f) {

		if (h == 0) {
			return 1;
		}
		if (dp[l][r][h][f] != null) {
			return dp[l][r][h][f];
		}
		long ret = f == 2 ? 0 : 1;
		for (int j = l ; j <= r ; ++j) {
			if (f != 2 && j + 1 < w) {
				ret += 1L*solve(j + 1,r,h,2);
				ret %= mod;
			}
			ret %= mod;
			if (f != 1) {
				long tmp = getWays(j - l + 1);
				if (j + 1 < w) {
					tmp *= 1L*solve(j + 1,r,h,1);
				}
				tmp %= mod;
				tmp *= 1L*solve(l,j,h - 1,0);
				tmp %= mod;
				ret += tmp;
				ret %= mod;
			}
		}
		return dp[l][r][h][f] = ret % mod;
	}
	
	public static int countStructures(int w_,int h_,int k_) {
		w = w_;
		h = h_;
		k = k_;
		c = new long[105][105];
		c[0][0] = 1;

		for (int i = 1 ; i < 105 ; ++i) {
			c[i][0] = 1;
			for (int j = 1 ; j < 105 ; ++j) {
				c[i][j] = 1L*c[i - 1][j] + c[i - 1][j - 1];
				c[i][j] %= mod;
			}
		}	
		cache = new long[w + 1];
		cache[0] = 1;
		for (int i = 1 ; i <= w ; ++i) {
			for (int j = 1 ; j <= k ; ++j) {
				if (i - j >= 0) cache[i] += cache[i - j];
				cache[i] %= mod;
			}
		}

		dp = new Long[w][w][h + 1][3];
		return (int)(solve(0,w - 1,h,0)%mod);
	}


}