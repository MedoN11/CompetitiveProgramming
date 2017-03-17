

import java.util.PriorityQueue;
import java.util.TreeSet;

public class StringInterspersal 
{
	
	
	public static void main(String[]args)throws Throwable
	{
		String w[] = {"BAADE", "EDEDC", "CCDAF", "FCAFA", "DBFFB"};
		System.out.println(minimum(w));
		
	}
	
	static String s[];
	static class Node implements Comparable<Node>
	{
		
		int idx,id;
		
		public Node(int idx,int id)
		{
			this.idx = idx;
			this.id = id;
		}

		public int compareTo(Node o)
		{
			
			for(int i = this.idx, j = o.idx ; i < s[id].length() && j < s[o.id].length() ; ++i, ++j)
			{
				if(s[this.id].charAt(i) < s[o.id].charAt(j))
					return -1;
				if(s[this.id].charAt(i) > s[o.id].charAt(j))
					return 1;
			}
			return  (s[id].length() - idx + 1) > (s[o.id].length() - o.idx + 1) ? -1 : 1;
		}
	}
	
	public static String minimum(String[] W)
	{
		s = W;
		PriorityQueue<Node> pq = new PriorityQueue();
		for(int i = 0 ; i < W.length ; ++i)
		{
			pq.add(new Node(0,i));
		}
		StringBuilder sb = new StringBuilder();
		while(!pq.isEmpty())
		{
			Node o = pq.poll();
			sb.append(s[o.id].charAt(o.idx));
			if(o.idx + 1 == s[o.id].length())
				continue;
			pq.add(new Node(o.idx + 1,o.id));
		}
		return sb.toString();
	}

}
