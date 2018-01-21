import java.util.ArrayList;
import java.util.Collections;

public class DyckwordUniformer {

	static String dfs(String s) {
		ArrayList<String> arr = new ArrayList();
		int e = 0;
		String run = "";
		for (int i = 0 ; i < s.length(); ++i) {
			if (s.charAt(i) == 'X') {
				++e;
			}
			else {
				--e;
			}
			if(e < 0) return "";
			run += s.charAt(i);

			if (e == 0) {
				arr.add(run);
				run = "";
			}
		}
		if(e != 0) {
			return "";
		}
		if(arr.size() == 1) {
			return 'X' + dfs(s.substring(1,s.length() - 1)) + 'Y';
		}
		for (int i = 0 ; i < arr.size() ; ++i) {
			arr.set(i, dfs(arr.get(i))); 
		}
		Collections.sort(arr);
		String res = "";
		for(String t: arr) res += t;
		return res;


	}
	public static String uniform(String s) {
		return dfs(s);
	}
	public static void main(String[] args) {
	
	}
}