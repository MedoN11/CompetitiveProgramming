
public class Polynomial {

	// this code assumes that all results will fit within 32 bits
	// Code is intended to be used in Competitive Programming Competitions
	// It can be made faster by storing the degrees in a HashMap ( I might push that later on ).

	int coef[];
	int degree;


	public Polynomial(int[] coef)
	{
		/*
		coef[i] represents the Cofficient of the ith degree polynomial
		assumes the polynomial given is simplified with equal terms.

		Polynomial degree is (length of coef array) - 1 as zero is assumed to be given.
		 */
		this.coef = new int[coef.length];
		for(int i = 0 ; i < coef.length ; i++)
		{
			this.coef[i] = coef[i];
		}

		this.degree = degree(); // update the degree accordingly.
	}

	public Polynomial(int coefValue,int degree)
	{
		/*
			 Ability to set a Monomial by itself.
			 Mainly created as it will be useful in addition and subtraction methods.
		 */
		coef = new int[degree + 1];

		coef[degree] = coefValue;

		// update degree, when might ask why ? what if we are given coefValue = 0, and degree = 1.
		//Setting degree to 1 would be wrong in this case. So we should do it manually.

		this.degree = degree();



	}

	public int degree()
	{
		/*
		 When performing operations on a polynomial, it's degree might change.
		 As an update operation would be required frequently, this method was created.
		 */
		int currentMaxDegree = 0;

		for(int i = 0 ; i < coef.length; i++)
		{
			if(coef[i] != 0) currentMaxDegree = i;
		}

		return currentMaxDegree;
	}


	public Polynomial add(Polynomial b)
	{
		// Set a Polynomial with max degree of the two Polynomials being added, as this is the max degree that can occur.

		Polynomial result = new Polynomial(0,Math.max(this.degree,b.degree));

		// add Cofficients of both Polynomials

		for(int i = 0 ; i <= this.degree ; i++) result.coef[i] += this.coef[i];

		for(int i = 0 ; i <= b.degree ; i++) result.coef[i] += b.coef[i];

		// update degree accordingly

		result.degree = result.degree(); 

		return result;
	}

	public Polynomial subtract(Polynomial b)
	{
		// Set a Polynomial with max degree of the two Polynomials being subtracted, as this is the max degree that can occur.

		Polynomial result = new Polynomial(0,Math.max(this.degree,b.degree));

		// add Cofficients of first Polyonomial, then subtract the other.

		for(int i = 0 ; i <= this.degree ; i++) result.coef[i] += this.coef[i];

		for(int i = 0 ; i <= b.degree ; i++) result.coef[i] -= b.coef[i];

		// update degree accordingly

		result.degree = result.degree(); 

		return result;
	}

	public Polynomial multiply(Polynomial b)
	{
		// Set a Polynomial with max degree of the two Polynomials being multiplied, as this is the max degree that can occur.

		Polynomial result = new Polynomial(0,this.degree + b.degree);

		for(int i = 0 ; i <= this.degree ;i++)
		{
			for(int j = 0 ; j <= b.degree ; j++)
			{
				result.coef[i+j] = this.coef[i] * b.coef[j];
			}
		}
		result.degree = result.degree();
		return result;
	}

	public Polynomial differentiate()
	{
		// special case
		if(this.degree == 0) return new Polynomial(0,0);

		// The derivative will have degree - 1
		Polynomial result = new Polynomial(0,this.degree - 1);

		// Standard Derivation rule
		for(int i = 0 ; i < this.degree  ; i++)
		{
			result.coef[i] = ( i + 1) * coef[i+1];
		}
		result.degree = result.degree();
		return result;
	}

	public int evaluate(int x)
	{
		// evaluates the polynomial at the given value of x.
		// this code makes use of horner's rule so that it would evaluate in O(N)
		// naive Evaluation would take O(N^2)
		int result = 0;
		for(int i = degree ; i >= 0 ; i--)
		{
			result = (coef[i]) + (x * result);
		}
		return result;
	}

	public String toString() {
		if (degree ==  0) return "" + coef[0];

		if (degree ==  1) return coef[1] + "x + " + coef[0];

		String str = coef[degree] + "x^" + degree;

		for (int i = degree-1; i >= 0; i--) {

			if(coef[i] == 0) continue;

			else if (coef[i]  > 0) str = str + " + " + ( coef[i]);

			else if (coef[i]  < 0) str = str + " - " + (-coef[i]);

			if (i == 1) str = str + "x";

			else if (i >= 2) str = str + "x^" + i;
		}
		return str;
	}


	public static void main(String[]args)throws Throwable
	{

		// main method
	}
}
