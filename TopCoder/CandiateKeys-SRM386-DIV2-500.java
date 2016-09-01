import java.util.ArrayList;
import java.util.HashSet;


public class CandiateKeys {
	static int r[] = new int [2];
	static int g[];
	static String[] arr;
	static ArrayList<Integer> A = new ArrayList();


	public static void main(String[]args)throws Throwable
	{
		String t[] = {
				"ABC",
				"ABD",
				"ABE"
		};
		int a[] = getKeys(t);
		System.out.println(r[0]+" "+r[1]);
	}
	static	int getBit(int num, int idx) {
		if( ((num >> idx) & 1) == 1) return 1;
		else return 0;
	}

	static boolean isKey(int msk) 
	{

		for(int i = 0 ; i < arr.length ; i++)
		{
			for(int j = 0 ; j < arr.length ; j++)
			{
				if( i == j ) continue;
				int K = arr[0].length();
				boolean all_equal = true;
				for(int k = 0 ; k < K ; k++)
				{
					if( getBit(msk,k) == 1 )
					{
						if(arr[i].charAt(k) != arr[j].charAt(k)) all_equal = false;

					}
				}

				if(all_equal) return false;
			}
		}
		return true;

	}
	public static int[] getKeys(String[] t)
	{
		boolean found = false;
		int N = t[0].length();
		arr = t;
		r[0] = 20;
		r[1] = 0;
		for(int msk = 0 ; msk < 1 << N; ++msk)
		{
			if(isKey(msk))
			{

				found = true;
				A.add(msk);
				//				found = true;
				//				r[0] = Math.min(r[0], Integer.bitCount(msk));
				//				r[1] = Math.max(r[1],Integer.bitCount(msk));
			}
		}
		int sz = A.size();
	
		boolean has_subset = false;
		for(int i = 0 ; i < sz; i ++)
		{
			has_subset = false;
			for(int j = 0 ; j < sz; j++)
			{
				if(i == j ) continue;
				if((A.get(i)&A.get(j)) == A.get(j)) has_subset = true;
			}
			if(!has_subset)
			{
				int cnt = Integer.bitCount(A.get(i));
				r[0] = Math.min(r[0],cnt);
				r[1] = Math.max(r[1],cnt);
			}
		}


		return found? r : g ;
	}
}
