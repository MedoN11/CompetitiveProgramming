import java.awt.Point;
import java.awt.geom.Area;
import java.awt.geom.Ellipse2D;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class DyckwordUniformer {

	static int n;
	static class Entry implements Comparable<Entry> {
		int s,h;
		int sum;
		public Entry(int s,int h,int sum) {
			this.s = s;
			this.h = h;
			this.sum = sum;
		}
		@Override
		public int compareTo(Entry o) {
			return Long.compare(o.s*this.h,1L*this.s * o.h);
		}

	}
	public static void main(String[]args) throws Throwable {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = new Integer(br.readLine());
		Entry[] entries = new Entry[n];
		for (int i = 0 ; i < n ; ++i) {
			String str = br.readLine();
			int s = 0, h = 0, ans = 0;
			for (int j = 0 ; j < str.length() ; ++j) {
				if(str.charAt(j) == 's') {
					++s;
				} else {
					ans += s;
					++h;
				}
			}
			entries[i] = (new Entry(s,h,ans));
		}
		Arrays.sort(entries);
		long ans = 0;
		int s = 0;
		for (int i = 0 ; i < n ;++i) {
			ans += entries[i].sum;
			ans += 1L *s * entries[i].h;
			s += entries[i].s;
		}
		System.out.println(ans);
	}


}