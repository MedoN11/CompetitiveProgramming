import java.util.Iterator;
import java.util.TreeSet;


public class ColorfulStrings {


	// Every digit must appear at most once.
	// If it appears more than once, then obviously there exists 2 different substrings with the same product.
	// If n is bigger than 9, then there must exists a digit that appears more than once.
	// if n is 9 or less, we can simply generate all substrings, sort them, and check if there exists a kth string.
	// a bit mask is used to speed up the backtracking as each digit must appear once
	static char c[];
	static int N;
	static TreeSet<Long> T = new TreeSet();
	static TreeSet<Long> products = new TreeSet();

	static boolean getBit(int num, int idx) {
		return ((num >> idx) & 1) == 1;
	}

	static int setBit(int num, int idx) {
		return num | (1<<idx);
	}

	int setBit0(int num, int idx) {
		return num & ~(1<<idx);
	}

	int flipBit(int num, int idx) {
		return num ^ (1<<idx);
	}


	static boolean valid(String str)
	{
		products.clear();
		long p = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			p = 1;
			for(int j = i ; j < str.length() ; j++)
			{
				p = 1;
				for(int k = i ; k <= j; k++) p*= (str.charAt(k)-'0');
				if(products.contains(p)) return false;
				products.add(p);
			}
		}

		return true;

	}
	public static void backtrack(int idx,int msk)
	{
		if(idx == N)
		{
			StringBuilder sb = new StringBuilder();
			for(int i = 0 ; i < N ;i++)sb.append(c[i]);

			String s = sb.toString();
			if(valid(s)) T.add(Long.parseLong(s));
			return;
		}
		for(int i = 0 ; i <= 9 ;i++)
		{
			if(getBit(msk,i)) continue;
			int nmsk = setBit(msk,i);
			c[idx] =(char)( i + '0');
			backtrack(idx+1,nmsk);
		}
	}

	public static void main(String[]args)throws Throwable
	{

		System.out.println(getKth(7,1));
	}

	public static String getKth(int n,int k)
	{
		if(n > 9) return "";
		N = n;
		c = new char[n];
		backtrack(0,0);
		String sol = null;
		for(Long x : T)
		{
			k--;
			if(k == 0) sol = Long.toString(x);
		}

		return sol == null ? "" : sol;
	}
}
