
public class ELR {



	// Expectation - Linearty of Expectation
	// Expectation is cyclic
	// E(X) is defined in terms of itself
	// Handle it by some algebra, and it becomes non recursive
	// compute it by dp
	static Double dp[][];
	static double suf[];
	static int cnt[];
	static int lim = 55;

	public static double solve(int ind,int rem) {
		if (ind == 51) {
			return 0;
		}
		if (dp[ind][rem] != null) {
			return dp[ind][rem];
		}
		double ret = 0.0;
		if (suf[ind + 1] == 0) {
			return dp[ind][rem] = 1.0;
		}
		if (rem == 0) {
			ret = solve(ind + 1,cnt[ind + 1]);
		} else {
			double p = 1.0;
			if (suf[ind + 1] > 0) {
				p = (rem) / suf[ind + 1];
			}

			ret = 1.0 + p * solve(ind,rem - 1);
			if (suf[ind + 1] != 0) {
				//System.out.println(rem+""+suf[ind + 1]);
				ret /= 1.0*(rem / suf[ind + 1]);
			}
		}
		return dp[ind][rem] = ret;
	}
	static double shuffle(int[] cards) {
		dp = new Double[lim][lim];
		suf = new double[lim];
		cnt = new int[lim];
		for (Integer x : cards) {
			++cnt[x];
		}
		for (int i = 50; i >= 0 ; --i) {
			suf[i] += suf[i + 1];
			suf[i] += cnt[i];
		}
		return solve(0,0);

	}
	public static void main(String[]args) throws Throwable {
		int c[] = {1,1};
		System.out.println(shuffle(c));
	}



}