import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ELR {


	public static void main(String[]args) throws Throwable {
		int r[] = {2,15};
		int q[] = {};
		int p[] = {2,21};
		System.out.println(amountOfMoney(r,q,p,13));
	}
	static class Pair implements Comparable<Pair>{
		long first,second;
		public Pair(long first,long second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int compareTo(Pair o) {
			if (Long.compare(this.first, o.first) == 0) {
				return Long.compare(this.second, o.second);
			}
			return Long.compare(this.first, o.first);
		}
	}
	public static long best(long money,ArrayList<Pair> first,ArrayList<Pair> sec) {
		long ans = 0;
		for (Pair p : first) {
			long tmp = p.second;
			long fix = p.first;
			if (fix > money) {
				continue;
			}
			int lo = 0, hi = sec.size() - 1;
			int till = -1;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if(sec.get(mid).first <= money - fix) {
					lo = mid + 1;
					till = mid;
				} else {
					hi = mid - 1;
				}
			}
			if (till != -1) {
				tmp += dp[till];
			}
			ans = Math.max(ans, tmp);
		}
		return ans;
	}
	static long dp[];
	public static int amountOfMoney(int prices[],int have[],int values[],int K) {
		int n = prices.length;
		long money = 0;
		for (int i = 0 ; i < have.length ; ++i) {
			money += prices[have[i]];
		}
		ArrayList<Pair> half = new ArrayList();
		int m = n / 2 ;
		for (int msk = 0 ; msk < (1 << m) ; ++msk) {
			long p = 0, v = 0;
			for (int i = 0 ; i < m ; ++i) {
				if (((msk & (1 << i))) > 0) {
					p += prices[i];
					v += values[i];
				}
			}
			half.add(new Pair(p,v));

		}
		Collections.sort(half);
		ArrayList<Pair> sec = new ArrayList();
		int q = n - m;

		long ans = -1;
		for (int msk = 0 ; msk < (1 << q) ; ++msk) {
			long p = 0, v = 0;
			for (int i = 0 ; i < q ; ++i) {
				if (((msk & (1 << i))) > 0) {
					p += prices[i + m];
					v += values[i + m];
				}
			}
			sec.add(new Pair(p,v));
		}
		Collections.sort(sec);
		int len = sec.size();
		dp = new long[len];
		//		tree = new long[len * 4];
		//		lo = new int[len * 4];
		//		hi = new int[len * 4];
		//		build(1,0,sec.size() - 1,sec);

		for (int i = 0 ; i < sec.size() ; ++i) {
			dp[i] = sec.get(i).second;
			if (i > 0) {
				dp[i] = Math.max(dp[i - 1], dp[i]);
			}
		}
		long lo = 0, hi = 1 << 30;
		while (lo <= hi) {
			long mid = lo + (hi - lo) / 2;
			long has = mid + money;
			if (best(has,half,sec) >= K) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		return (int)(ans);
	}

}