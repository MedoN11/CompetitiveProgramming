
public class OrderedSuperString {



	public static void main(String[]args)
	{
		String[] s ={"ab","bc", "de","ef","abcdef"};
		System.out.println(getLength(s));
	}
	public static int matchLast(String last, String curr)
	{

		int r = 0;
		for(int i = 0 ; i < last.length() ; i++)
		{
			String sub = last.substring(i,last.length());

			if(sub.length() > curr.length()) continue;
			boolean eq = true;
			for(int j = 0 ; j < Math.min(sub.length(), curr.length()) ; j++)
			{
				eq &= curr.charAt(j) == sub.charAt(j);

			}
			if(eq) r = Math.max(r, sub.length());
		}

		return r;
	}

	public static int getLength(String[] words)
	{

		String last = "";
		int len = 0;
		int max = 0;
		int goal_idx = 0;
		int lastMatch = 0;
		for(String curr : words)
		{
			max = 0;
			goal_idx = 0;
			lastMatch = 0;
			for(int i = 0 ; i < last.length() ; i++)
			{

				int matchLen = 0;
				int k = 0;
				for(int j = i ; j  < last.length() && k < curr.length() ; j++, k++)
				{

					if(last.charAt(j) == curr.charAt(k)) matchLen++;
					else break;

				}

				if(matchLen > max)
				{
					goal_idx = i;

					max = matchLen;


				}
			}
			if(max == curr.length())
			{
				last = last.substring(goal_idx, last.length());
			}
			else
			{
				len += curr.length() - matchLast(last,curr);
				last = curr;

			}

		}



		return len;
	}
}
