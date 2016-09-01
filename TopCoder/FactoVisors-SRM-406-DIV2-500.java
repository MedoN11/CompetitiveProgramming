
public class FactoVisors {



	static int gcd(int a,int b)
	{
		if(b==0) return a;
		return gcd(b,a%b);
	}
	
	public static void main(String[]args)throws Throwable
	{
		int[] a = {6,9};
		int b[] = {96,180};
		System.out.println(getNum(a,b));
	}
	public static boolean check(int n,int[] div)
	{
		for(int i = 0 ; i < div.length ; i++)
		{
			if(n % div[i] != 0) return false;
		}
		return true;
	}

	public static int getNum(int[] div,int mul[])
	{
		int gcd = mul[0];
		for(int i = 1; i < mul.length ;i++)
		{
			gcd = gcd(gcd,mul[i]);
		}
		int cnt = 0;
		int i = 1;
		for( ; i*i < gcd ; i++)
		{
			if(gcd % i == 0)
			{
				if(check(gcd/i,div)) ++cnt;
				if(check(i,div)) ++cnt;
			}

		}
		if(i * i == gcd) if(check(i,div))++cnt;
		return cnt;
	}
}
