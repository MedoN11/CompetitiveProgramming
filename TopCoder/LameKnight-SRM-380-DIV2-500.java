
public class LameKnight {



	public static void main(String[]args)throws Throwable
	{
		System.out.println(maxCells(2,4));
	}

	public static int maxCells(int H,int W)
	{

		if(H == 1 || W == 1) return 1;
		if(H == 2)
		{
			--W;
			int steps = 0;
			for(int moves = 0 ; moves < 3; moves++)
			{
				if( W >= 2)
				{

					W-=2; ++steps;
				}
			}
			return steps + 1;
		}

		if(W >= 7)
		{
			W-=2; W-=2;
			return W + 2;
		}
		else
		{
			int steps = 0;
			--W;

			for(int moves = 0 ; moves < 3; moves++)
			{
				if( W > 0)
				{

					--W; ++steps;
				}
			}
			return steps +1;

		}



	}
}
