import java.util.ArrayList;
import java.util.Arrays;


public class SurveillanceSystem {

	static int n;
	static int cnt[] = new int[55];
	static char c[] = new char[55];
	static int prefix[] = new int[55];
	static ArrayList<Range>[] arr = new ArrayList[55];


	public static void main(String[]args)
	{
		String ss = "-X--XX";
		int arr[] = {1,2};

		System.out.println(getContainerInfo(ss,arr,3));
	}
	static class Range
	{
		int L,R;
		public Range(int L,int R)
		{
			this.L = L;
			this.R = R;
		}
	}

	public static void check(int x)
	{
		int r[] = new int[55];
		for(Range ran : arr[x])
		{
			for(int i = ran.L ; i <= ran.R ; i++) r[i]++;
		}
		int allRanges = arr[x].size();
		int cameras = cnt[x];
		for(int i = 0 ; i < n ; i++)
		{
			if(r[i] == 0) continue;
			int myRanges = r[i];
			if(cameras >= allRanges) c[i] ='+';
			else
			{
				// trying not to place a camera
				int newRanges = allRanges;
				newRanges -= myRanges;
				if(newRanges < cameras) c[i] = '+';
				else if(c[i] != '+')c[i] = '?';
				
			}

		}
	}


	public static String getContainerInfo(String str,int[]reps,int L)
	{
		for(int i = 0 ; i < 55 ; i++) arr[i] = new ArrayList();

		Arrays.fill(c, '-');
		n = str.length();
		for(Integer x: reps) cnt[x]++;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(i > 0) prefix[i] += prefix[i-1];
			prefix[i] += str.charAt(i) == 'X' ? 1 : 0;
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = i ; j < n ; j++)
			{
				if(j - i + 1 != L) continue;
				int sR = prefix[j];
				int sL = i == 0 ? 0 : prefix[i-1];
				int toks = sR - sL;
				arr[toks].add(new Range(i,j));


			}
		}
		for(int i = 0 ; i < 55 ; i++)
		{
			if(cnt[i] == 0) continue;
			check(i);

		}

		StringBuilder sb = new StringBuilder();
		for(int i = 0 ; i < n ; i++){
			sb.append(c[i]);
		}

		return sb.toString();
	}
}
