import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Survived {


	
	public static void main(String[]args)throws Throwable {
		System.out.println(findNext("2008"));
	}
	public static String getParity(int n) {
		StringBuilder sb = new StringBuilder();
		if (n % 2 == 0) {
			for (int i = 0 ; i < n ; ++i) {
				if(i % 2 == 0) sb.append("1");
				else sb.append("0");
			}
		} else {
			for (int i = 0 ; i < n ; ++i) {
				sb.append("1");
			}
		}
		return sb.toString();

	}

	public static String compare(String s,String t) {
		if(s.length() > t.length()) return t;
		if(t.length() > s.length()) return s;
		for (int i = 0 ; i < s.length() ; ++i) {
			if(s.charAt(i) > t.charAt(i))
				return t;
			if(s.charAt(i) < t.charAt(i))
				return s;
		}
		return s;
	}

	public static String solve(int ind,int rep,int at,int msk,String s) {
		//System.out.println(rep * Integer.bitCount(msk));
		int n = s.length();
		int arr[] = new int[n];
		Arrays.fill(arr, -1);
		arr[ind] = at;
		int f[] = new int[10];
		for(int j = 0 ; j <= 9; ++j) {
			if( ((1 << j) & msk) == 0)
				continue;
			f[j] = rep;
			if(j == at) --f[j];
		}
		for (int i = 0 ; i < ind ; ++i) {
			int p = s.charAt(i) - '0';
			if(f[p] == 0) {
				return null;
			}
			f[p]--;
			arr[i] = p;
		}
		ArrayList<Integer> lake = new ArrayList();
		for (int i = 0 ; i <= 9 ; ++i) {
			while(f[i] > 0) {
				lake.add(i);
				--f[i];
			}
		}
		int ptr = 0;
		for(int i = ind + 1 ; i < n ; ++i) {
			arr[i] = lake.get(ptr++);
		}

		StringBuilder res = new StringBuilder();
		for (int i = 0 ; i < n ; ++i) res.append(arr[i]);
		if(res.toString().equals("2009")) {
			System.out.println(ind+" "+rep +" "+at+" "+Integer.toBinaryString(msk));
		}
		return res.toString();
	}
	public static long findNext(String s) {
		// same string rep ??
		int x[] = new int[10];
		for (int i = 0 ; i < s.length() ; ++i) {
			char c = s.charAt(i);
			x[c - '0']++;
		}
		int min = 1 << 30, max = 0;
		for (int i = 0 ; i <= 9 ; ++i) {
			if(x[i] == 0)
				continue;
			min = Math.min(min, x[i]);
			max = Math.max(max, x[i]);
		}
		if (min == max) {
			return Long.parseLong(s);
		}
		String sol = getParity(s.length() + 1);
		
		for (int i = 0 ; i < s.length() ; ++i) {
			for(int j = 1 ; j <= 18 ; ++j) {
				for(int k = 0 ; k <= 9 ; ++k) {
					for(int msk = 0 ; msk < (1 << 10) ; ++msk) {
						if((msk & (1 << k)) == 0)
							continue;
						if(s.charAt(i) - '0' >= k)
							continue;
						int ones = Integer.bitCount(msk);
						if(j * ones != s.length())
							continue;
						String res = solve(i,j,k,msk,s);
						if(res != null) {
							sol = compare(sol,res);
						}
					}
				}
			}
		}
		long num = 0;
		for (int i = 0 ; i < sol.length() ; ++i) {
			num *= 10;
			num += sol.charAt(i) - '0';
		}
		return num;
	}
	
}
