import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Ezz {

	// Game Theory + adhoc proof
	// Proof/Intution as follows:
	// Assume all piles are greater than 1.
	// Claim if sum is odd, first player wins, else second player.
	// Why?
	// Play any move that doesn't make a pile less than 2.
	// Proof the sequence of moves exist because the state at the end will be 2 2 2 2 2 2 2 2 ( a sequence of 2's). 
	//( If at any stage, second player decreases a two just take it)
	// Sum of them is even, so the sequence of moves are odd - even = odd..only the first player can make odd moves.
	// If sum is even, proof is similar, but instead we end with even - even - even, so only second can.
	// Now for case of piles with one, just greedily keep taking most expensive ones.
	// Convince yourself this is optimal :)
	public static void main(String[]args) throws Throwable {
		int arr[] = {3,2};
		int a[] = {1,2};
		System.out.println(getScore(arr,a));
	}
	public static int getScore(int[] treasure,int cnt[]) {

		int n = cnt.length;
		int turn = 0;
		int take = 0;
		while (true) {
			boolean zero = true;
			int ch = -1 ,val = 0;
			int d = -1;
			int t = -1;
			for (int i = 0 ; i < n ; ++i) {
				zero &= cnt[i] == 0;

				if (cnt[i] == 1) {
					val = Math.max(val, treasure[i]);
					if (val == treasure[i]) {
						ch = i;
					}
				} else {
					if (cnt[i] > 2) {
						d = i;
					}
					if (cnt[i] == 2) {
						t = i;
					}
				}
			}
			if (zero) {
				break;
			}
			
			if (ch != -1) {
				--cnt[ch];
				if (turn == 0) {
					take += treasure[ch];
				}
			} else {
				if (d != -1) {
					--cnt[d];
				} else {
					--cnt[t];
				}
			}
			turn ^= 1;
		}





		return take;

	}
}