import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JimmyRiddles
{

	static final int STATEMENT = 0;
	static final int ACTION = 1;
	static final int ACTIVE_LIST = 2;
	static final int ACTOR = 3;
	static String nouns[] = {"tom","jerry","goofy","mickey","jimmy","dog","cat","mouse"};
	static String articles[] = {"a","the"};
	static String verbs[] = {"hate","love","know","like"};

	public static boolean dfs(String str,int state)
	{

		//System.err.println(str);
	if(str.isEmpty())
		return false;
		str.trim();
		if(str.charAt(0) == ' ')
			return false;
		if(state == STATEMENT)
		{
			int ind = str.indexOf(',');
			if(ind != -1)
			{

				return dfs(str.substring(0, ind - 1),0) && dfs(str.substring(ind + 2,str.length()),0);
			}
			return dfs(str,1);

		}
		if(state == ACTION)
		{
			for(String s : verbs)
			{
				String s2 = s+"s";
				int ind = str.indexOf(s2);
				if(ind != -1 && !(str.charAt(ind - 1) != ' ') && !(str.charAt(ind + 5) != ' '))

				{
					String a = str.substring(0, ind - 1);
					String b = str.substring(ind + 6,str.length());
					return dfs(a,2) && dfs(b,2);
				}

				ind = str.indexOf(s);
				if(ind != -1)
				{					

					if(str.charAt(ind - 1) != ' ' || str.charAt(ind + 4) != ' ')
						continue;
					String a = str.substring(0, ind - 1);

					String b = str.substring(ind + 5,str.length());

					return dfs(a,2) && dfs(b,2);
				}

			}
		}
		if(state == ACTIVE_LIST)
		{
			int ind = str.indexOf("and");
			if(ind != -1)
			{			
				//System.err.println(str+" "+ind);

				if(str.charAt(ind - 1) != ' ' || str.charAt(ind + 3) != ' ')
					return false;
				String a = str.substring(0,ind - 1);
				String b = str.substring(ind + 4,str.length());
			//	ZSystem.err.println(a +"--"+b);
				return dfs(a,3) && dfs(b,2);
			}
			return dfs(str,3);
		}
		if(state == ACTOR)
		{
			StringTokenizer st = new StringTokenizer(str);
			if(st.countTokens() > 2 || st.countTokens() == 0)
				return false;
			if(st.countTokens() == 2)
			{
				String a = st.nextToken(); String b = st.nextToken();
				boolean eq = false;
				for(String s : articles)
					if(a.equals(s))
						eq = true;
				if(!eq)
					return false;
				eq = false;
				for(String s : nouns)
					if(s.equals(b))
						eq = true;
				if(!eq)
					return false;
				return true;

			}
			String b = st.nextToken();
			for(String s : nouns)
				if(s.equals(b))
					return true;
			return false;
		}
		return false;
	}
	public static void main(String[]args)throws Throwable
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
		while(true)
		{
			str = br.readLine();
			if(str == null)
				break;
			try{


				boolean good = dfs(str,0);
				if(good)
					System.out.println("YES I WILL");
				else System.out.println("NO I WON'T");
			}
			catch(Exception e)
			{
				System.out.println("NO I WON'T");
			}
		}
	}
}
