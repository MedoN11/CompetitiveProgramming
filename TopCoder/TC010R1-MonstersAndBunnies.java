

import java.util.Arrays;

public class MonsterAndBunnies 
{
	
	public static double survivalProbability(int m,int b)
	{
		if((m & 1) > 0)
			return 0.0;
		return 1.0 / (m + 1);
		
	}

}
