import java.math.BigInteger;
import java.security.SecureRandom;
import java.io.*;
import java.util.*;

public class StrongPrimePower {

	private final static BigInteger ZERO = new BigInteger("0");
	private final static BigInteger ONE  = new BigInteger("1");
	private final static BigInteger TWO  = new BigInteger("2");
	private final static SecureRandom random = new SecureRandom();

	static Vector<BigInteger> v = new Vector<BigInteger>();
	static HashMap<Long,Long> m = new HashMap();

	public static void main(String[]args)throws Throwable
	{
		int a[] = baseAndExponent("576460752303423488");
		System.out.println(a[0] +" " +a[1]);

	}
	public static BigInteger rho(BigInteger N) {

		BigInteger divisor;
		BigInteger c  = new BigInteger(N.bitLength(), random);
		BigInteger x  = new BigInteger(N.bitLength(), random);
		BigInteger xx = x;

		if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

		do {
			x  =  x.multiply(x).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			divisor = x.subtract(xx).gcd(N);
		} while((divisor.compareTo(ONE)) == 0);

		return divisor;
	}

	public static void factor(BigInteger N) {

		if (N.compareTo(ONE) == 0) return;

		if (N.isProbablePrime(20)) {
			v.add(N);
			return;
		}

		BigInteger divisor = rho(N);
		factor(divisor);
		factor(N.divide(divisor));
	}


	public static int[] baseAndExponent(String n)
	{
		BigInteger num1 = new BigInteger(n);
		if(num1.isProbablePrime(20)) return new int[]{};
		factor(num1);
		int sz = v.size();

		if( sz == 0) return new int[] {};



		int primes = 0;
		int p = 0;
		boolean invalid = false;
		for(int i = 0 ; i < sz ; i++)
		{


			if(v.get(i).isProbablePrime(20))
			{

				if(primes > 0 && p != v.get(i).intValue()) invalid = true;
				p = v.get(i).intValue();
				primes++;
			}

		}

		if(invalid) return new int[] {};


		long num = Long.parseLong(n);
		int exp = 0;

		while(num != 0 && num != 1)
		{
			if(num % p != 0)
			{

				invalid = true; break;
			}
			num /= p; exp++;
		}


		if(invalid || exp == 1 || exp == 0) return new int[]{};
		System.out.println("in");
		return new int[]{p,exp};

	}
}