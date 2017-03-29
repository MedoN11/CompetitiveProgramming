package WF2005;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


/*
The idea is to bruteforce the placement of the N items on every row, coloumn, and the two main diagonals.
The cost of the placement can be be solved quickly by min cost bipartite matching where edge costs are the distance between every 2 nodes
To do this, we consturct a bipartite graph where the left group contains the N nodes in the input, and the other side contains the N cells of the chosen row/col/diag
Then for each node on the left, we connect it with every node on the right where edge costs are the distance between them
Obviously a perfect matching must exist, and our interest is the least cost to do so, which is min cost bipartite matching
I implemented this with min cost max flow instead of hungarian.
*/


public class TheGreatWallGame 
{

	static class Edge {
		int to, f, cap, cost, rev;

		Edge(int v, int cap, int cost, int rev) {
			this.to = v;
			this.cap = cap;
			this.cost = cost;
			this.rev = rev;
		}
	}

	public static List<Edge>[] createGraph(int n) {
		List<Edge>[] graph = new List[n];
		for (int i = 0; i < n; i++)
			graph[i] = new ArrayList<>();
		return graph;
	}

	public static void addEdge(List<Edge>[] graph, int s, int t, int cap, int cost) {
		graph[s].add(new Edge(t, cap, cost, graph[t].size()));
		graph[t].add(new Edge(s, 0, -cost, graph[s].size() - 1));
	}

	static void bellmanFord(List<Edge>[] graph, int s, int[] dist) {
		int n = graph.length;
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[s] = 0;
		boolean[] inqueue = new boolean[n];
		int[] q = new int[n];
		int qt = 0;
		q[qt++] = s;
		for (int qh = 0; (qh - qt) % n != 0; qh++) {
			int u = q[qh % n];
			inqueue[u] = false;
			for (int i = 0; i < graph[u].size(); i++) {
				Edge e = graph[u].get(i);
				if (e.cap <= e.f)
					continue;
				int v = e.to;
				int ndist = dist[u] + e.cost;
				if (dist[v] > ndist) {
					dist[v] = ndist;
					if (!inqueue[v]) {
						inqueue[v] = true;
						q[qt++ % n] = v;
					}
				}
			}
		}
	}

	public static int[] minCostFlow(List<Edge>[] graph, int s, int t, int maxf) {
		int n = graph.length;
		int[] prio = new int[n];
		int[] curflow = new int[n];
		int[] prevedge = new int[n];
		int[] prevnode = new int[n];
		int[] pot = new int[n];

		// bellmanFord invocation can be skipped if edges costs are non-negative
		bellmanFord(graph, s, pot);
		int flow = 0;
		int flowCost = 0;
		while (flow < maxf) {
			PriorityQueue<Long> q = new PriorityQueue<>();
			q.add((long) s);
			Arrays.fill(prio, Integer.MAX_VALUE);
			prio[s] = 0;
			boolean[] finished = new boolean[n];
			curflow[s] = Integer.MAX_VALUE;
			while (!finished[t] && !q.isEmpty()) {
				long cur = q.remove();
				int u = (int) (cur & 0xFFFF_FFFFL);
				int priou = (int) (cur >>> 32);
				if (priou != prio[u])
					continue;
				finished[u] = true;
				for (int i = 0; i < graph[u].size(); i++) {
					Edge e = graph[u].get(i);
					if (e.f >= e.cap)
						continue;
					int v = e.to;
					int nprio = prio[u] + e.cost + pot[u] - pot[v];
					if (prio[v] > nprio) {
						prio[v] = nprio;
						q.add(((long) nprio << 32) + v);
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = Math.min(curflow[u], e.cap - e.f);
					}
				}
			}
			if (prio[t] == Integer.MAX_VALUE)
				break;
			for (int i = 0; i < n; i++)
				if (finished[i])
					pot[i] += prio[i] - prio[t];
			int df = Math.min(curflow[t], maxf - flow);
			flow += df;
			for (int v = t; v != s; v = prevnode[v]) {
				Edge e = graph[prevnode[v]].get(prevedge[v]);
				e.f += df;
				graph[v].get(e.rev).f -= df;
				flowCost += df * e.cost;
			}
		}
		return new int[]{flow, flowCost};
	}

	static class Pair
	{
		int i,j,id;
		public Pair(int i,int j,int id)
		{
			this.i = i;
			this.j = j;
			this.id = id;
		}
		public int dis(Pair p)
		{
			return Math.abs(p.i - i) + Math.abs(p.j - j);
		}
		
	}
	static int source = 0;
	static int sink =   1;
	static int tmpid = 0;
	static int n;
	static int getCost(ArrayList<Pair> left,ArrayList<Pair> right)
	{
		//System.err.println(tmpid);
		List<Edge>[] graph = createGraph(tmpid + tmpid);
		for(Pair p1 : left)
		{
			addEdge(graph,source,p1.id,1,0);
			for(Pair p2 : right)
			{
				addEdge(graph,p1.id,p2.id,1,p1.dis(p2));
			}
		}
		for(Pair p2 : right)
		{
			addEdge(graph,p2.id,sink,1,0);
		}
		int ans[] = minCostFlow(graph,source,sink,Integer.MAX_VALUE);
	//	System.out.println(ans[0] +" "+ans[1]);
		if(ans[0] == n)
			return ans[1];
		return 1 << 30;
	}
	public static void main(String[] args) throws Throwable 
	{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int tc = 1;
		while(true)
		{
			int id = 2;
			n = sc.nextInt();
			if(n == 0)
				break;
			ArrayList<Pair> left = new ArrayList();

			for(int i = 0 ; i < n ; ++i)
			{
				int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
				left.add(new Pair(x,y,id++));

			}
			int res = 1 << 30;
			ArrayList<Pair> right = new ArrayList();
			for(int k = 0 ; k < n ; ++k)
			{
				// row
				tmpid = id;
				for(int j = 0 ; j < n ; ++j)
				{
					right.add(new Pair(k,j,tmpid++));
				}
				// col
				res = Math.min(res, getCost(left,right));
				right.clear();
				tmpid = id;
				for(int j = 0 ; j < n ; ++j)
				{
					right.add(new Pair(j,k,tmpid++));
				}
				res = Math.min(res, getCost(left,right));
				right.clear();

			}
			// diag left
			int offset = 0;
			tmpid = id;
			for(int i = 0 ; i < n ; ++i)
			{
				right.add(new Pair(i,offset,tmpid++));
				offset++;
			}
			res = Math.min(res, getCost(left,right));
			right.clear();
			tmpid = id;
			offset = n - 1;
			// diag right
			for(int i = 0 ; i < n ; ++i)
			{
				right.add(new Pair(i,offset,tmpid++));
				offset--;
			}
			res = Math.min(res, getCost(left,right));
			right.clear();
			out.printf("Board %d: %d moves required.\n\n",tc++,res);

		}
		out.flush();
		out.close();
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
}