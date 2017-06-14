import java.util.StringTokenizer;

public class OneArmedBandit
{


	public static double calc(String pat,String[] wheel)
	{
		double prob = 1.0;
		for(int i = 0 ; i < pat.length() ; ++i)
		{
			int cnt = 0;
			if(pat.charAt(i) == '-')
				continue;
			for(int k = 0 ; k < wheel[i].length() ; ++k)
			{
				if(wheel[i].charAt(k) == pat.charAt(i))
					++cnt;
			}
			prob *= cnt / (1.0*wheel[i].length());
		}
		return prob;
	}

	public static void main(String[]args)throws Throwable
	{
		String wheel[] = {"ABC", "ABC", "ABC"};
		String str = "AAA";
		String pay[] = {"AA- 5", "A-- 2"};
		System.out.println(progressiveJackpot(wheel, str, pay));
	}

	public static double progressiveJackpot(String w[],String jackpot,String payoff[])
	{
		StringTokenizer st;
		double ans = 0.0;
		for(String s : payoff)
		{
			st = new StringTokenizer(s);
			String pat = st.nextToken();
			int ben = new Integer(st.nextToken());
			ans += calc(pat,w) * ben;
		}

		double other = 1 - ans;
		other /= calc(jackpot,w);
		if(other < 0.0)
			return 0.0;
		if(calc(jackpot,w) == 0)
			return -1.0;

		return other;
	}
}
