
public class HyperKnight {


	
	public static void main(String[]args)
	{
		System.out.println(countCells(50,70,1000,1000,6));
	}
	public static long countCells(int a1,int b1,int n1,int m1,int k1)
	{
        
        // Write backtracking code, and print for different values
        // you will spot a pattern
        // with some observations you can arrive at the following formulas
		long a = a1; long b = b1; long n = n1; long m = m1; long k = k1;
		long all = n * m;

		if(a > b)
		{
			long tmp = b;
			b = a;
			a = tmp;
		}
		long bs = b - a;

		if(k == 2)
		{
			return 4L*a*a;
		}

		if(k == 3)
		{

			return 2L *(2*a*bs) + 2L *(bs*2*a);
		}
		if(k == 4)
		{
			return 2L * a * (m - 2*b) +  4*(b-a)*(b-a) + 2L * a * (n - (2 * b));

		}

		if(k == 6)
		{
			return 2L * bs * (m - 2 *b) + bs* 2 * (n - 2 * b);
		}
		if(k == 8)
		{
			all -=  4*a*a;
			all -= 2L *(2*a*bs) + 2L *(bs*2*a);
			all -=  2L * a * (m - 2*b) +  4*(b-a)*(b-a) + 2L * a * (n - (2 * b));
			all -=  2L * bs * (m - 2 *b) + bs* 2 * (n - 2 * b);

			return all;
		}

		return 0L;

	}
}
