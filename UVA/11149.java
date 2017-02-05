package CodeForces;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

// Matrix class taken from indy's library
public class Matrix {
	static int MOD = 10;
	public static int[][] matrixAdd(int[][] a, int[][] b) {
		int n = a.length;
		int m = a[0].length;
		int[][] res = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = (a[i][j]%MOD + b[i][j]%MOD)%MOD;
			}
		}
		return res;
	}

	public static int[][] matrixMul(int[][] a, int[][] b) {
		int n = a.length;
		int m = a[0].length;
		int k = b[0].length;
		int[][] res = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				for (int p = 0; p < m; p++) {
					res[i][j] = (res[i][j]%MOD + a[i][p]%MOD * b[p][j]%MOD)%MOD;
				}
			}
		}
		return res;
	}

	public static int[][] matrixPow(int[][] a, int p) {
		if (p == 0) {
			return matrixUnit(a.length);
		} else if (p % 2 == 0) {
			return matrixPow(matrixMul(a, a), p / 2);
		} else {
			return matrixMul(a, matrixPow(a, p - 1));
		}
	}

	public static int[][] matrixPowSum(int[][] a, int p) {
		int n = a.length;
		if (p == 0) {
			return new int[n][n];
		}
		if (p % 2 == 0) {
			return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
		} else {
			return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
		}
	}

	public static int[][] matrixUnit(int n) {
		int[][] res = new int[n][n];
		for (int i = 0; i < n; ++i) {
			res[i][i] = 1;
		}
		return res;
	}

	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }

		String next() throws IOException
		{
			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();

		}

		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	}
	// Usage example
	static int n,k;
	public static void main(String[] args) throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		while(true)
		{
			n = sc.nextInt();
			k = sc.nextInt();
			if(n == 0)
				break;
			int[][] mat = new int[n][n];
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < n ; ++j)
					mat[i][j] = sc.nextInt()%10;
			}
			int[][] res = matrixPowSum(mat,k);
			for(int i = 0 ; i < n ; ++i)
			{
				out.print(res[i][0]);
				for(int j = 1 ; j < n ; ++j)
				{
					out.print(" "+(res[i][j]%10));
				}
				out.println("");
			}
			out.println();
			
		}
		out.flush();
		out.close();
		
	}
}
}