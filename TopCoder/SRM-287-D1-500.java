package Sheet1;

public class MooresLaw 
{
	
	static double months;
	public static double getRate(double x)
	{
		return  x / 18.0;
	}
	public static double f(double i)
	{
		double rate = getRate(i);
		
		return i + ((1.0*months) / Math.pow(2, rate));
	}
	
	public static void main(String[]args)throws Throwable
	{
		System.out.println(shortestComputationTime(123));
	}
	
	public static double shortestComputationTime(int y)
	{
		months = y * 12.0;
		double left = 0, right = 10e18; // set your range
	
		for(int i = 0 ; i < 5000 ;++i)
		{ // stop when reaching almost right = left
			double g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

			if (f(g) < f(h)) // use > if f increase then decrease
				right = h;
			else
				left = g;
		}
		return f(left)/12.0;
	
	}

}
