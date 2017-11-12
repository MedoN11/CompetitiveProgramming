import java.util.Arrays;
import java.util.TreeSet;

public class YankeeSwap {

    
 // Constructive - Greedy
	static StringBuilder main = new StringBuilder();

	public static void main(String[]args) throws Throwable {
		String res[] = {"AECDBF",
				"BAEDCF",
				"DEBACF",
				"BEDCAF",
				"CEABDF",
		"CBDEAF"};
		System.out.println(sequenceOfSwaps(res));
	}

	static int n;
	
	
	static boolean ok(int ind,StringBuilder res,char take[]) {
		//System.out.println(ind+" "+res.toString());
		StringBuilder tmp = new StringBuilder();
		tmp.append(res.toString());
		for(int i = ind ; i < n ; ++i) {
			if(tmp.charAt(i) != take[i]) {
				tmp.setCharAt(tmp.indexOf(take[i]+""), tmp.charAt(i));
				tmp.setCharAt(i,take[i]);
			}
			
		}
		for(int i = 0 ; i < n ;++i) {
			if(take[i] != tmp.charAt(i))
				return false;
		}
		return true;
	}
	public static String sequenceOfSwaps(String[] pref) {
		for (String s : pref) {
			s = s.toLowerCase();
		}
		for (char c = 'a' ; c <= 'z' ; ++c) { 
			main.append(c);
		}
		n = pref.length;
		TreeSet<Character> seen = new TreeSet();
		char take[] = new char[n];
		char rev[] = new char[n];
		for (int i = n - 1 ; i >= 0 ; --i ) {
			String s = pref[i].toLowerCase();
			for(int j = 0 ; j < s.length() ; ++j) {

				if(!seen.contains(s.charAt(j))) {
					seen.add(s.charAt(j));
					take[i] = s.charAt(j);
					rev[s.charAt(j) - 'a'] = (char)(i + 'a');
					break;
				}
			}
		}
		String res = "";
		for (int i = 0 ; i < n ; ++i) {

			// dont swap
			if(ok(i + 1,main,take)) {
				res += '-';
			}
			else {
				for(int j = 0 ; j < n ; ++j) {

					StringBuilder tres = new StringBuilder();
					// copy
					for(int k = 0 ; k < main.length() ; ++k) 
						tres.append( main.charAt(k));

					char tc = tres.charAt(i);
					tres.setCharAt(i, tres.charAt(j));
					tres.setCharAt(j, tc);
					if(ok(i + 1,tres,take)) {
						main.setCharAt(i, main.charAt(j));
						main.setCharAt(j, tc);
						res += (char)(j +'a');
						break;

					}

				}
			}


		}
		return res;
	}
}
