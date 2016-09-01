import java.util.Iterator;
import java.util.TreeSet;


public class ArithmeticProgression {


	static TreeSet<Double> T = new TreeSet();

	static int a0;
	static int arr[];


	public static void main(String[]args)throws Throwable
	{
		int a[] = {-3};
		System.out.println(minCommonDifference(1,a));
	}

	public static boolean valid(double d)
	{
		for(int i = 1 ;i <= arr.length ; i++)
		{
			
			int curr = (int) Math.floor(a0+(i/1.0)*d*1.0);
			if(curr!=arr[i-1]) return false;
		}
		return true;
	}
	public static double minCommonDifference(int a,int seq[])
	{
		if(seq.length == 0) return 0.0;
		a0 = a;
		arr = seq;
		for(int i = 1; i <= seq.length ;i++)
		{
			double curr = seq[i-1]/1.0;
			curr -= a/1.0;
			curr /= i/1.0;
			if(curr < 0) continue;
			T.add(curr);
		}

		Iterator it = T.iterator();

		while(it.hasNext())
		{
			double val =(double) it.next();
			if(valid(val)) return val;
		}

		return -1.0;


	}
}
