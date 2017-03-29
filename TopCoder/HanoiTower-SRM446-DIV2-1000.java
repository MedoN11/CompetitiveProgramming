import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeMap;
import java.util.TreeSet;

public class HanoiTower 

{
//	The solution can be at most 19 so using this you can apply bruteforce from source state by using BFS,
//	but going up to atmost depth 20. ( Since number of steps here is answer, it doesn't make sense to go beyond that) but this is too slow and will get TLE. 
//			So you use meet in the middle, and run 2 BFS's each with depth up to 10 then combine them, and this fits in time.


	static TreeMap<State,Integer> map = new TreeMap();
	
	public static void main(String[]args)throws Throwable
	{
		System.out.println(moves("A","AA","AA"));
	}

	static class State implements Comparable<State>
	{
		int steps;
		String s1,s2,s3;
		public State(String s1,String s2,String s3,int steps)
		{
			this.s1 = s1; this.s2 = s2; this.s3 = s3;
			this.steps = steps;
		}
		public int compareTo(State o)
		{
			if(this.s1.equals(o.s1))
			{
				if(this.s2.equals(o.s2))
					return this.s3.compareTo(o.s3);
				else return this.s2.compareTo(o.s2);
			}
			return this.s1.compareTo(o.s1);
		}

	}

	public static int moves(String pegA, String pegB, String pegC)
	{
		
		String optA = ""; String optB = ""; String optC = "";
		for(int i = 0 ; i < pegA.length() ; ++i)
		{
			if(pegA.charAt(i) == 'A') optA += 'A';
			if(pegA.charAt(i) == 'B') optB += 'B';
			if(pegA.charAt(i) == 'C') optC += 'C';
		}
		for(int i = 0 ; i < pegB.length() ; ++i)
		{
			if(pegB.charAt(i) == 'A') optA += 'A';
			if(pegB.charAt(i) == 'B') optB += 'B';
			if(pegB.charAt(i) == 'C') optC += 'C';
		}
		for(int i = 0 ; i < pegC.length() ; ++i)
		{
			if(pegC.charAt(i) == 'A') optA += 'A';
			if(pegC.charAt(i) == 'B') optB += 'B';
			if(pegC.charAt(i) == 'C') optC += 'C';
		}
		int min = 19;
		Queue<State> q = new LinkedList();
		q.add(new State(pegA,pegB,pegC,0));
		while(!q.isEmpty())
		{
			State curr = q.poll();
			if(map.containsKey(curr))
				continue;
			if(curr.s1.equals(optA) && curr.s2.equals(optB) && curr.s3.equals(optC))
				return curr.steps;
			if(curr.steps == 10)
				break;
			
			map.put(curr,curr.steps);
	
			if(!curr.s1.isEmpty())
			{
				//System.err.println("in");
				char f = curr.s1.charAt(curr.s1.length() - 1);
				String ts1 = curr.s1.substring(0,curr.s1.length() - 1);
				State t = new State(ts1,curr.s2+f,curr.s3,curr.steps + 1);
				State p = new State(ts1,curr.s2,curr.s3+f,curr.steps + 1);
				
				if(!map.containsKey(t))
					q.add(t);
			
				if(!map.containsKey(p))

					q.add(p);
				
			}
			if(!curr.s2.isEmpty())
			{
				//System.err.println("in");

				char f = curr.s2.charAt(curr.s2.length() - 1);
				String ts1 = curr.s2.substring(0,curr.s2.length() - 1);
				State t = new State(curr.s1+f,ts1,curr.s3,curr.steps + 1);
				State p = new State(curr.s1,ts1,curr.s3+f,curr.steps + 1);
				if(!map.containsKey(t))
					q.add(t);
			
				if(!map.containsKey(p))

					q.add(p);
			}
			if(!curr.s3.isEmpty())
			{
				//System.err.println("in");

				char f = curr.s3.charAt(curr.s3.length() - 1);
				String ts1 = curr.s3.substring(0,curr.s3.length() - 1);
				State t = new State(curr.s1+f,curr.s2,ts1,curr.steps + 1);
				State p = new State(curr.s1,curr.s2+f,ts1,curr.steps + 1);
				if(!map.containsKey(t))
					q.add(t);
			
				if(!map.containsKey(p))

					q.add(p);
			}

		}
		 q = new LinkedList();
		q.add(new State(optA,optB,optC,0));
		TreeSet<State> set = new TreeSet();
		
		while(!q.isEmpty())
		{
			State curr = q.poll();
		
			if(curr.steps == 10)
				break;
			if(set.contains(curr))
				continue;
			if(map.containsKey(curr))
				min = Math.min(min,curr.steps + map.get(curr));
	
			set.add(curr);
			if(!curr.s1.isEmpty())
			{
				//System.err.println("in");
				char f = curr.s1.charAt(curr.s1.length() - 1);
				String ts1 = curr.s1.substring(0,curr.s1.length() - 1);
				State t = new State(ts1,curr.s2+f,curr.s3,curr.steps + 1);
				State p = new State(ts1,curr.s2,curr.s3+f,curr.steps + 1);
				
				if(!set.contains(t))
					q.add(t);
			
				if(!set.contains(p))

					q.add(p);
				
			}
			if(!curr.s2.isEmpty())
			{
				//System.err.println("in");

				char f = curr.s2.charAt(curr.s2.length() - 1);
				String ts1 = curr.s2.substring(0,curr.s2.length() - 1);
				State t = new State(curr.s1+f,ts1,curr.s3,curr.steps + 1);
				State p = new State(curr.s1,ts1,curr.s3+f,curr.steps + 1);
				if(!set.contains(t))
					q.add(t);
				if(!set.contains(p))
					q.add(p);
			}
			if(!curr.s3.isEmpty())
			{
				//System.err.println("in");

				char f = curr.s3.charAt(curr.s3.length() - 1);
				String ts1 = curr.s3.substring(0,curr.s3.length() - 1);
				State t = new State(curr.s1+f,curr.s2,ts1,curr.steps + 1);
				State p = new State(curr.s1,curr.s2+f,ts1,curr.steps + 1);
				if(!set.contains(t))
					q.add(t);
				if(!set.contains(p))
					q.add(p);
			}

		}
		
		return min;
	}


}