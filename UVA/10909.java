import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class LuckyNumber {

	// sieve and bit
	static ArrayList<Integer> primes;
	static int bit[] = new int[2000001];
	static int max_bit = 2000001;
	static void set(int ind,int delta) {
		while(ind < max_bit) {
			bit[ind] += delta;
			ind += ind & - ind;
		}
	}
	static int get(int ind) {
		int s = 0;
		while(ind > 0) {
			s  += bit[ind];
			ind -= ind & - ind;
		}
		return s;
	}
	static int query(int l,int r) {
		return get(r) - get(l - 1);
	}

	static double log2(int x) {
		return (Math.log(max_bit) / Math.log(2));
	}

	static int getKthLogN(int accum) {
		accum--;	// Function modified to return first occurrence of accum instead of last occurrence
		int base = 0, limit = 1<<(int)(log2(max_bit));

		while(limit > 0) {
			if( (base+limit) < max_bit && accum >= bit[base+limit])
			{
				base += limit; accum -= bit[base];
			}
			limit >>= 1;
		}
		return base + 1;	// to get last occurrence, remove this +1 and line accum--;

	}
	static int getKth(int ind) {
		int lo = 0,hi = max_bit - 1;
		int ans = -1;
		while(lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if(get(mid) <= ind) {
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		return ans;
	}
	
	public static void main(String[]args) throws Throwable {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean prime[] = new boolean[max_bit];
		PrintWriter out = new PrintWriter(System.out);
		ArrayList<Integer> primes = new ArrayList();
		for(int i = 1 ; i < max_bit ; i += 2) {
			set(i,1);
			
		}

		int curr = max_bit / 2;
		for(int i = 2 ; ; ++i) {
			ArrayList<Integer> tmp = new ArrayList();
			if(i > curr)
				break;
			int p = find(i);
			for(int j = p ; j < max_bit; j += p) {
				int ind = find(j);
				tmp.add(ind);

			}
			for(Integer x : tmp)
				set(x,-1);
			--curr;
		}
		ArrayList<Integer> lucky = new ArrayList();
		
		for (int i = 1 ; i < max_bit ; ++i) {
			
			if(query(i,i) == 1) {
				lucky.add(i);
				
			}
		}
		String in = "";
		while((in = br.readLine()) != null) {
			int x = new Integer(in);
			if(x == 0)
				break;
			if((x & 1) > 0) {
				out.printf("%d is not the sum of two luckies!\n",x);
			} else {
				int lo = 0, hi = lucky.size() - 1;
				int ans = -1;
				while(lo <= hi) {
				   int mid = lo + (hi - lo) / 2;
				   if(lucky.get(mid) <= (x / 2)) {
					   ans = mid;
					   lo = mid + 1;
				   }
				   else hi = mid - 1;
				}
				boolean done = false;
				while(ans >= 0) {
					int k = lucky.get(ans);
					if(query(x - k, x - k) == 1) {
						out.printf("%d is the sum of %d and %d.\n", x, k, x - k);
						done = true;
						break;
					}
					--ans;
				}
				if(!done) {
					out.printf("%d is not the sum of two luckies!\n",x);
				}
			}
		}
		out.flush();
		out.close();
	
	}
}
