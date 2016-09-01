import java.util.ArrayList;


public class RGBTree {
    
    
    //	Explanation :
    //	Dynamic Programming or Memoization with BitMasks.( E * (2 ^ N) * (5 ^ 3) )
    //	State is (msk,r,g,b). Your return value is a boolean.
    //	The mask represents nodes with degree bigger than zero.
    //	Suppose we have an edge connecting nodes u and v.
    //	An edge can only be added if at least one of deg(u) or deg(v) is zero to maintain growing a spanning tree. (
    //	We can only have up to (n-1) / 3 edges of each colour given the constraints, both r ,g and b cannot exceed 5. ( otherwise we just prune this impossible state. 2^13 * 13 * 13 * 13 will give MLE ( Java ) ).
    //	In our DP:
    //	Iterate over all edges, if it’s possible to add this edge, set both nodes it connects to 1 in the bitmask, increase r,g or b depending on the edge’s colour.
    //	After each step recurse further.
    //	Base case: When mask contains n 1’s it means we have used (n-1) edges which means our tree ready. Check if every colour in our state equals k / 3.
    static ArrayList<Edge> arr = new ArrayList();
    static class Edge
    {
        int from;
        int to;
        int color = 0;
        
        public Edge(int from,int to,int color)
        {
            this.from = from;
            this.to = to;
            this.color = color;
        }
    }
    static boolean DP[][][][] = new boolean[1 << 14][5][5][5];
    static boolean seen[][][][]  = new boolean[1<<14][5][5][5];
    static int n;
    static int k;
    
    static	int getBit(int num, int idx) {
        if( ((num >> idx) & 1) == 1) return 1;
        else return 0;
    }
    
    
    static	int setBit1(int num,int idx){
        
        return num|((1<<idx));
        
    }
    
    public static void main(String[]args)throws Throwable
    {
        String a[] = {".RGB",
            "R...",
            "G...",
            "B..."};
        System.out.println(exist(a));
    }
    public static boolean solve(int msk, int r, int g,int b)
    {
        if(Integer.bitCount(msk) == n)
        {
            return r==k/3 && g == k/3 && b == k/3;
        }
        
        if(r > k/3 || g > k/3 || b > k/3) return false;
        
        if(seen[msk][r][g][b]){
            
            return DP[msk][r][g][b];
        }
        seen[msk][r][g][b] = true;
        boolean f = false;
        for(Edge e: arr)
        {
            int nr =r; int ng = g; int nb = b;
            
            int from = e.from; int to = e.to; int col = e.color;
            
            if(getBit(msk,from) == 1 || getBit(msk,from) == 1) continue;
            
            int newmsk = msk;
            
            newmsk = setBit1(msk,from);
            
            newmsk = setBit1(newmsk,to);
            
            if(col == 0) nr++; if(col == 1) ng++; if(col == 2) nb++;
            
            f |= solve(newmsk,nr,ng,nb);
            
        }
        return DP[msk][r][g][b] = f;
    }
    
    public static String exist(String[] G)
    {
        n = G.length;
        k = n - 1;
        for(int i = 0 ; i < G.length ; i++)
        {
            for(int j = 0 ; j < G[i].length() ;j++)
            {
                int col = 0;
                char c = G[i].charAt(j);
                if(c == '.') continue;
                if(c == 'G') col = 1;
                if(c == 'B') col = 2;
                arr.add(new Edge(i,j,col));
            }
        }
        boolean can = solve(0,0,0,0);
        if(can)return "Exist";
        else return"Does not exist";
    }
    
    
}
