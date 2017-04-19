
public class LR 
{


	static  long[] get(long tmp[],String s)
	{
		long arr[] = new long[tmp.length];
		for(int i = 0 ; i < tmp.length; ++i)
			arr[i] = tmp[i];
		//System.out.println(s);
		int n = arr.length;
		for(int i = 0 ; i < s.length() ; ++i)
		{
			long old[] = new long[arr.length];
			for(int j = 0 ; j < arr.length ; ++j) old[j] = arr[j];
			if(s.charAt(i) == 'L')
			{
				for(int j = 0 ; j < arr.length ; ++j)
				{
					
					arr[j] = old[j] + old[(j - 1 + n) % n];
				}
			}
			else
			{
				for(int j = 0 ; j < arr.length ; ++j)
				{
					arr[j] = old[j] + old[(j + 1) % n];
				}
			}
		}
		return arr;
	}

	public static void main(String[]args) throws Throwable
	{
		long s[] = {1,0};
		long t[] = {0,0};
		System.out.println(construct(s,t));
	}
	public static String construct(long[] s,long[] t)
	{

		long sumS = 0;
		for(int i = 0 ; i < s.length ; ++i)
			sumS += s[i];
		long sumT = 0;
		for(int i = 0 ; i < t.length ; ++i)
			sumT += t[i];
		
		if(sumT == 0 && sumS == 0)
			return "";
		if(sumS == 0)
			return "No Solution";
		if(sumT % sumS != 0)
			return "No solution";
	
		
		
		
		for(int i = 0 ; i <= 100 ; ++i)
		{
			for(int j = 0 ; j <= 100 ; ++j)
			{
				if(i + j > 100)
					continue;
				StringBuilder sb = new StringBuilder();
				for(int k = 0 ; k < i ; ++k) sb.append("L");
				for(int k = 0 ; k < j ; ++k) sb.append("R");
				
				long ret[] = get(s,sb.toString());
				boolean eq = true;
				for(int k = 0 ; k < t.length ; ++k)
				{
					eq &= t[k] == ret[k];
				}
			
				
				if(eq)
				{
					return sb.toString();
				}
			}
		}
		return "No solution";
	}

	// 190 150 124 147 189 

}
