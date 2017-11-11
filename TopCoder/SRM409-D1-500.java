import java.util.ArrayList;
import java.util.Arrays;

public class MagicalSpheres {


	
	public static void main(String[]args)throws Throwable {
		System.out.println(divideWork(3,3,50));
	}
	static long count(long n,long p) {
		long cnt = 0;
		for (long i = p; i <= n ; i *= p) {
			cnt += n / i;
		}
		return cnt;
	}

	static class Prime {
		int b,p;
		public Prime(int b,int p) {
			this.b = b;
			this.p = p;
		}
	}
	public static boolean ok(ArrayList<Prime> primes,int n,int k) {
		for(Prime p : primes) {
			long up = count(n,p.b);
			up -= count(n - k,p.b) + count(k,p.b);
			if(up < p.p)
				return false;
		}
		return true;
	}
	public static int divideWork(int a,int b,int g) {
		int n = (a + b);
		int k = a;
		int sp[] = new int[g + 1];
		boolean prime[] = new boolean[g + 1];
		Arrays.fill(prime, true);

		// O(Log(n)) factorization
		for (int i = 2 ; i <= g ; ++i) {

			if (prime[i]) {
				sp[i] = i;
				if (1L * i * i <= g) {
					for (int j = i * i ; j <= g; j += i) {
						if(sp[j] == 0) {
							sp[j] = i;
						}
						prime[j] = false;
					}
				}
			}
		}
		for (int i = g ; i >= 2 ; --i) {
			ArrayList<Prime> f = new ArrayList();
			int num = i;
			while(num > 1) {
				int p = sp[num];
				Prime pr = new Prime(p,0);
				while(num % p == 0) {
					pr.p++;
					num /= p;
				}
				f.add(pr);
			}
			if(ok(f,n,k)) {
				return i;
			}
		}
		return 1;
	}
}
