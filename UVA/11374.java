import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

public class AirPortExpress 
{


	static class State implements Comparable<State>
	{
		int ind,weight;
		int used;
		public State(int ind,int weight,int used)
		{
			this.ind = ind;
			this.weight = weight;
			this.used = used;
		}
		@Override
		public int compareTo(State o) 
		{

			return this.weight - o.weight;
		}
	}

	static class Pair
	{
		int ind,used;
		public Pair(int ind,int used)
		{
			this.ind = ind;
			this.used = used;
		}
	}
	static class Edge
	{
		int v,cost;
		public Edge(int v,int cost)
		{
			this.v = v;
			this.cost = cost;
		}
	}
	static int dis[][];
	static Pair pr[][];
	static ArrayList<Edge> G[],enhanced[];
	static int n;
	static PrintWriter out = new PrintWriter(System.out);
	public static void diji(int src,int sink)
	{
		PriorityQueue<State> pq = new PriorityQueue();
		pq.add(new State(src,0,0));
		for(int i = 0 ; i < n ; ++i)
			dis[i][0] = dis[i][1] = 1 << 29;
		dis[src][0] = 0;
		pr[src][0] = new Pair(-1,-1);
		while(!pq.isEmpty())
		{
			State s = pq.poll();
			int ind = s.ind; int used = s.used; int w = s.weight;
			if(dis[ind][used] < w)
				continue;
			dis[ind][used] = w;
			// move normally
			for(Edge e : G[ind])
			{
				
				if(dis[e.v][used] > e.cost + w)
				{
					dis[e.v][used] = e.cost + w;
					pr[e.v][used] = new Pair(ind,used);
					pq.add(new State(e.v,e.cost + w,used));
				}
			}
			if(used == 0)
			{
				// try to enhance
				for(Edge e : enhanced[ind])
				{
					if(dis[e.v][1] > e.cost + w)
					{
						dis[e.v][1] = e.cost + w;
						pr[e.v][1] = new Pair(ind,used);
						pq.add(new State(e.v,e.cost + w,1));
					}
				}
			}
		}
		if(dis[sink][0] < dis[sink][1])
		{
			Stack<Integer> path = new Stack();
			int curr = sink; int used = 0;
			path.push(sink);
			while(pr[curr][used].ind != -1)
			{
				path.add(pr[curr][used].ind);
				Pair p = pr[curr][used];
				curr = p.ind; used = p.used;
				
			}
			out.print(path.pop() + 1);
			while(!path.isEmpty())
				out.print(" "+(1+path.pop()));
			out.print("\n");
			out.println("Ticket Not Used");
			out.println(dis[sink][0]);
		}
		else
		{
			Stack<Integer> path = new Stack();
			int curr = sink; int used = 1;
			path.push(sink);
			int node = 0;
			while(pr[curr][used].ind != -1)
			{
				if(pr[curr][used].used == 0 && used == 1)
					node = pr[curr][used].ind;
				path.add(pr[curr][used].ind);
				Pair p = pr[curr][used];
				curr = p.ind; used = p.used;
			}
			out.print(path.pop() + 1);
			while(!path.isEmpty())
				out.print(" "+(1+path.pop()));
			out.print("\n");
			out.println(node+1);
			out.println(dis[sink][1]);
		}
	}


	public static void main(String[]args)throws Throwable
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";
		int c = 0;
		while((line = br.readLine()) != null)
		{
		
			c++;
			StringTokenizer st = new StringTokenizer(line);
			n = new Integer(st.nextToken()); int src = new Integer(st.nextToken());
			int sink = new Integer(st.nextToken());
			--src; --sink;
			G = new ArrayList[n]; enhanced = new ArrayList[n];
			dis = new int[n][2]; pr = new Pair[n][2];
			for(int i = 0 ; i < n ; ++i)
			{
				G[i] = new ArrayList();
				enhanced[i] = new ArrayList();
			}
			int m = new Integer(br.readLine());

			for(int i = 0 ; i < m ; ++i)
			{
				st = new StringTokenizer(br.readLine());
				int u = new Integer(st.nextToken()) - 1;
				int v = new Integer(st.nextToken()) - 1;
				int dis = new Integer(st.nextToken());
				G[u].add(new Edge(v,dis));
				G[v].add(new Edge(u,dis));
			}
			m = new Integer(br.readLine());

			for(int i = 0 ; i < m ; ++i)
			{
				st = new StringTokenizer(br.readLine());
				int u = new Integer(st.nextToken()) - 1;
				int v = new Integer(st.nextToken()) - 1;
				int dis = new Integer(st.nextToken());
				enhanced[u].add(new Edge(v,dis));
				enhanced[v].add(new Edge(u,dis));
			}
			diji(src,sink);
			if(c == 6)
				break;
			
		  line = br.readLine();
		  if(line == null)
			  break;
		  out.print("\n");
			
		}
		out.flush();
		out.close();
	}

}
