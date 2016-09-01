import java.util.ArrayList;
import java.util.Collections;


public class AddElectricalWires {

	static ArrayList<Integer> Graph[] = new ArrayList[55];
	static int curr_nodes = 0;
	static int n,b;
	static ArrayList<Integer> bcnt = new ArrayList();
	static boolean[] seen = new boolean[55];

	public static void main(String[]args)throws Throwable
	{
		String a[] = {"101","10"};
		int n[] = {0};
		System.out.println(maxNewWires(a,n));
	}

	static void dfs(int idx)
	{
		if(seen[idx]) return;
		seen[idx] = true;
		curr_nodes++;
		for(Integer x: Graph[idx])
		{
			if(!seen[x]) dfs(x);

		}


	}
	public static int maxNewWires(String[]wires, int[] black)
	{

		int existing_edges = 0;
        
		n = wires.length;
        b = black.length;
		for(int i = 0 ; i < n ; i++) Graph[i] = new ArrayList();

		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ;j++)
			{
				if(wires[i].charAt(j) == '1'){
					Graph[i].add(j);
                    
					existing_edges++;
				}
			}
		}

		existing_edges >>= 1;
        
			for(int i  = 0 ; i < b ; i++)
			{
				curr_nodes = 0;
				dfs(black[i]);
				bcnt.add(curr_nodes);

			}
			int free_nodes = 0;
        
			for(int i = 0 ; i < n ; i++) if(!seen[i]) free_nodes++;
        
			Collections.sort(bcnt);
        
			int maxblack = bcnt.get(bcnt.size() - 1);
        
			maxblack += free_nodes;
        
			int tot = maxblack*(maxblack-1)/2;
        
			for(int i = 0 ; i < bcnt.size() - 1 ; i++)
			{
				tot += bcnt.get(i)*(bcnt.get(i)-1)/2;
			}
        
			tot -= existing_edges;
			return tot;



	}
}
