import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;


public class ICPCBalloons 
{
    // SRM 561 Div2 500

	static int n,m;
	static ArrayList<Integer> medium = new ArrayList();
	static ArrayList<Integer> large = new ArrayList();
	static ArrayList<Integer> entries = new ArrayList();
	static ArrayList<Integer> avaliable = new ArrayList();
	static final int oo = 100000;

	public static boolean getBit(int num, int idx) {
		return ((num >> idx) & 1) == 1;
	}

	public static void main(String[]args)throws Throwable
	{
		int x[] = {5,6,1,5,6,1,5,6,1};
		String s = "MLMMLMMLM";
		int c[] = {7,7,4,4,7,7};
		System.out.println(minRepaintings(x,s,c));

	}

	public static int can(ArrayList<Integer> entries, ArrayList<Integer> avaliable)
	{
		boolean taken[] = new boolean[avaliable.size()];
		Collections.sort(entries);
		Collections.sort(avaliable);
		Collections.reverse(entries);
		Collections.reverse(avaliable);

		int used = 0;
		for(int i = 0 ; i < entries.size() ; i++ )
		{
			int toks = entries.get(i);

			boolean done = false;
			for(int j = 0 ; j < avaliable.size() ; j++)
			{
				if(!taken[j])
				{
					done = true;
					if(avaliable.get(j) >= toks)
					{
						taken[j] = true;
						avaliable.set(j, avaliable.get(j) - toks);
						break;
					}
					else
					{

						taken[j] = true;
						int needed = toks - avaliable.get(j);
						avaliable.set(j,0);

						used += needed;
						break;

					}
				}


			}

			if(!done){
				used += toks;
			}
		}

		int res = used;
		for(Integer e : avaliable) used -= e;

		if(used <= 0) return res;
		return oo;


	}
	public static int solve(int msk,char type,int cnt[])
	{
		entries.clear();
		avaliable.clear();

		if(type == 'M')
		{

			for(Integer e : medium) avaliable.add(e);

		}

		else
		{
			for(Integer e : large) avaliable.add(e);
		}

		for(int i = 0 ; i < m ; i++)
		{
			if(!getBit(msk,i) && type == 'M') entries.add(cnt[i]);
			if(getBit(msk,i) && type == 'L') entries.add(cnt[i]);

		}

		return can(entries,avaliable);
	}
	public static int minRepaintings(int[] balloonCount, String balloonSize, int[] maxAccepted)
	{
		n = balloonCount.length;
		for(int i = 0 ; i < n ; i++)
		{
			if(balloonSize.charAt(i) == 'M')
			{
				medium.add(balloonCount[i]);
			}
			else large.add(balloonCount[i]);
		}
		m = maxAccepted.length;

		int sol = oo;
		for(int msk  = 0 ; msk < 1 << m ; msk++)
		{
			sol = Math.min(sol,solve(msk,'M',maxAccepted) + solve(msk,'L',maxAccepted));
		}



		return sol >= oo ? - 1 : sol;
	}
}
