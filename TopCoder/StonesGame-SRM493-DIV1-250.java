import java.util.TreeSet;


public class StonesGame {

	static TreeSet<Integer> fromL = new TreeSet();
	static TreeSet<Integer> fromW = new TreeSet();

	public static void main(String[]args)throws Throwable
	{
		System.out.println(winner(1000000,100000,500000,600000));
	}

	public static String winner(int N,int W,int K,int L)
	{
		// generate positions of L
		for(int i = 1 ; i <= N ; i ++)
		{
			if(i + K - 1 < L) continue;
			//possible placement
			int start = i;
			int end = i + K - 1;

			int mid = (start) + (end-start) / 2;
			int pos = L;
			//System.out.println(end +" "+start);
			//System.out.println("Before :"+pos);
			if(mid <= pos) pos = (pos - start) - (end - pos);
			else pos = (end - pos) - (pos - start);
				//	System.out.println("after: " + (pos));
			fromL.add(pos);
		}
		boolean losingPos = true;
		if(fromL.contains(W)) return "Romeo";
		for(int i = 1 ; i <= N ; i ++)
		{
			if(i + K - 1 < W) continue;
			//possible placement
			int end = i + K - 1;
			int start = i;
			int mid = (start) + (end-start) / 2;
			int pos = W;
			if(mid < pos) pos = (pos - start) - (end - pos);
			else pos = (end - pos) - (pos - start);
			fromW.add(pos);
			losingPos &= fromL.contains(pos);
		}
		if(losingPos) return "Strangelet";

		return "Draw";


	}
}
