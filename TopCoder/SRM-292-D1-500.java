import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Robot {




	public static void main(String[]args)throws Throwable
	{
		String name[] = {"BOB","BOB","BOB"};
		String boss[] = {"BOB","*","BOB"};
		System.out.println(minSupers(name,boss));
	}

	static ArrayList<Integer> tree[];
	public static int minSupers(String[]name,String boss[])
	{

		int n = name.length;
		HashSet<String> set = new HashSet();
		Queue<String> q = new LinkedList();
		q.add("*");
		while(!q.isEmpty())
		{
			String curr = q.poll();
			set.add(curr);
			for(int i = 0 ; i < n ; ++i)
			{
				if(boss[i].equals(curr) && !set.contains(name[i]))
				{
					q.add(name[i]);
				
				}
			}
		}
		
		for(int i = 0 ; i < n ; ++i)
		{
			if(!set.contains(name[i]))
				return -1;
		}

	

		int c = 0;
		HashSet<String> ans = new HashSet();
		for(int i = 0 ; i < n ; ++i)
			ans.add(boss[i]);
		return ans.size() - 1;
	}
}