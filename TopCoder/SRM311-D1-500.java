

public class ELR {

	// Digit DP
	// sum of digits for any number in range <= 100
	public static void main(String[] args) throws Throwable {
		System.out.println(getSum(24660,308357171));
	}
	static Long dp[][][][];
	static String base,lim;
	static int len = 0;
	static long solve(int ind,int ls,int br,int sum) {
		if (ind == len) {
			return sum;
		}
		if (dp[ind][ls][br][sum] != null) {
			return dp[ind][ls][br][sum];
		}
		long ret = 0;
		for (int i = 0 ; i <= 9 ; ++i) {
			int a = base.charAt(ind) - '0', b = lim.charAt(ind) - '0';
			if (i < a && ls == 0)  {
				continue;
			}
			if (i > b && br == 0) {
				continue;
			}
			ret += solve(ind + 1, ls | ((i > a) ? 1 : 0),br | ((b > i) ? 1 : 0),sum + i);
		}
		return dp[ind][ls][br][sum] = ret;

	}
	public static long getSum(int lb,int rb) {
		base = lb + "";
		lim =  rb  + "";
		len = lim.length();
		while (base.length() < len) {
			base = '0' + base;
		}
		dp = new Long[len][2][2][200];
		return solve(0,0,0,0);
	}
}