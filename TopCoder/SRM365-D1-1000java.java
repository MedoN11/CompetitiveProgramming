import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class RelabelingOfGraph {

	static ArrayList<Integer> G[];
	static ArrayList<Integer> rev[];
	static int min[];
	public static void main(String[]args) throws Throwable {
		String s[] = {"0100", "0010", "0001", "0000"};
		int x[] = renumberVertices(s);
		for(int a : x) {
			System.out.print(a+" ");
		}
	}
	static boolean seen[];
	static int col[];
	static int c = 0;
	static int state[];
	static boolean cycle = false;
	static void dfs(int u) {
		if(u == 2) {
			System.out.println(state[0]);
		}
		state[u] = 1;
		for(Integer x : G[u]) {
			if(state[x] == 2)
				continue;
			if(state[x] == 1)
				cycle = true;
			if(state[x] == 0)
				dfs(x);
		}
		state[u] = 2;
	}

	public	static int[] renumberVertices(String[] m) {
		int n = m.length;
		min = new int[n];
		Arrays.fill(min, 1 << 30);
		G = new ArrayList[n];
		rev = new ArrayList[n];
		for (int i = 0 ; i < n ; ++i) {
			G[i] = new ArrayList();
			rev[i] = new ArrayList();
		}
		col = new int[n];
		int deg[] = new int[n];
		for(int i = 0  ; i < n ; ++i) {
			for(int j = 0 ; j < m[i].length() ; ++j) {
				if(m[i].charAt(j) == '1') {
					G[i].add(j);
					rev[j].add(i);
					deg[i]++;
				}
			}
		}
		state = new int[n];
		for(int i = 0 ; i < n ; ++i) {
			if(state[i] == 0) {
				dfs(i);
			}
		}
		if(cycle) {
			return new int[] {};
		}
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		for (int i = 0 ; i < n ; ++i) {
			if(deg[i] == 0) {
				pq.add(i);
			}
		}
		int c = n - 1;
		while(!pq.isEmpty()) {
			
			int u = pq.poll();
			col[u] = c--;
			for(Integer v: rev[u]) {
				if(--deg[v] == 0) {
					pq.add(v);
				}
			}
		}
		return col;
	
	}
}