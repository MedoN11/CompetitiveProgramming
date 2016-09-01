
public class BinarySearchable {
	static int cnt[];


	public static void main(String[]args){
		int arr[]= {1, 5, 7, 11, 12, 18};
		
		System.out.println(howMany(arr));
	}

	public static int howMany(int arr[])
	{
		int N = arr.length; 
		
		int c = 0;
		
		cnt = new int[N];
		
		int max = -10000000;
		
		for( int i = 0 ; i < N; i++ )
		{
			if(arr[i]>max)
				
				cnt[i]++;
			
			max = Math.max(max, arr[i]);
		}
		int min = 1231322332;
		for( int j = N-1 ;j >= 0 ; j--) {

			if(arr[j]<min)
				cnt[j]++;

			min = Math.min(min,arr[j]);

		}
		for(int i=0;i<N;i++)
			
			if(cnt[i]==2)
				
				c++;
		
		
		return c;

		

	}
}
