
public class ReFactorableNumber
{

	static int cnt[];
	
	public static void main(String[]args)throws Throwable
	{
		System.out.println(count(1,10));
	}
	public static int count(int low,int high)
	{
		cnt = new int[high + 1];
		for(int i = 1 ; i <= high ; ++i)
		{
			for(int j = i ; j <= high ; j += i)
			{
				cnt[j]++;
			}
				
		}
		int res = 0;
		for(int i = low ; i <= high ; ++i)
		{
			if(i % cnt[i] == 0)
			{
				System.out.println(i);
				++res;
			}
		}
		return res;
	}
}
