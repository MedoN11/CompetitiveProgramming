import java.util.ArrayList;

public class TVGameWinnings 
{

	static class DSU 
	{
		int rank[];
		int parent[];
		int N;
		int sets;
		int setsize[];

		public DSU(int N){
			this.N = N;
			sets = N;
			parent = new int[N];
			rank = new int[N];
			setsize = new int[N];
			for(int i=0;i<N;i++){ parent[i] = i; setsize[i] = 1; }

		}

		public void union(int x,int y)
		{
			if(isSameSet(x,y)) return;
			sets--;
			int xp = getParent(x);
			int yp = getParent(y);
			if(rank[xp]>rank[yp]){ parent[yp] = xp; setsize[xp]+=setsize[yp];}
			else{
				if(rank[xp]==rank[yp]){
					rank[yp]++;
					parent[xp] = yp;
					setsize[yp]+=setsize[xp];
				}
				else
				{ parent[xp] =yp; setsize[yp] += setsize[xp]; }
			}

		}

		public int getParent(int x){
			if(x==parent[x]) return x;
			return parent[x] = getParent(parent[x]);
		}

		public boolean isSameSet(int x,int y){
			return getParent(x)==getParent(y);
		}

		public int numDisjointSets(){
			return sets;
		}
		public int getSetSize(int x){
			return setsize[getParent(x)];
		}



	}
	public static void main(String[] args)
	{
		String grid[] = {"35","44"};
		int ans[] = getMinMax(grid);
		System.out.println(ans[0]+" "+ans[1]);
		
	}
	static int[][] grid;
	static class Tuple
	{
		int i,j;
		int val;
		public Tuple(int i,int j,int val)
		{
			this.i = i;
			this.j = j;
			this.val = val;
		}
	}
	static int n;
	static int max = -(1 << 30), min = 1 << 30;
	static ArrayList<Tuple> cands = new ArrayList();
	public static void solve(int i,int j,int msk)
	{

		if(cands.size() == n)
		{
			DSU dsu = new DSU(n);
			int ans = 1;
			for(int x = 0 ; x < n ; ++x)
			{
				for(int y = x + 1 ; y < n ; ++y)
				{
					if(cands.get(x).i ==  cands.get(y).i || cands.get(x).j == cands.get(y).j)
					{
						dsu.union(x, y);
					}
					if(cands.get(x).i ==  cands.get(y).j || cands.get(x).j == cands.get(y).i)
					{
						dsu.union(x, y);
					}
				}
				ans *= cands.get(x).val;
			}
			if(dsu.numDisjointSets() % 2 == 0) ans *= -1;
			min = Math.min(min, ans);
			max = Math.max(max, ans);
		}
		if(i == n)
			return;
		if(j == n)
			solve(i + 1,0,msk);
		else
		{
			if( (msk & (1 << j)) == 0)
			{
				cands.add(new Tuple(i,j,grid[i][j]));
				solve(i + 1,0,msk | (1 << j));
				cands.remove(cands.size() - 1);
			}
			solve(i,j + 1,msk);
			
		}
	}
	public static int[] getMinMax(String board[])
	{
		n = board.length;
		grid = new int[n][n];
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n; ++j)
			{
				
				char c = board[i].charAt(j);
				if(Character.isDigit(c))
				{
					grid[i][j] = c - '1' + 1;
				}
				else grid[i][j] =-1*( c - 'A' + 1);
			}
		}
		solve(0,0,0);
		int ret[] = {min,max};
		return ret;
	}

}
