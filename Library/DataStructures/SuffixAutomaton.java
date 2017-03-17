import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.TreeMap;


	public class SuffixAutomaton 
	{

		// code for suffix automaton
		int last = 0;
		final int nil = 0;
		int stateID = 1;
		State state[];
		int suffixLink[];
		String str;

		static class State
		{
			int maxLen;
			TreeMap<Character,Integer> transitions;

			public State(int maxLen)
			{
				this.maxLen = maxLen;
				transitions	= new TreeMap<Character,Integer>();
			}

		}

		public SuffixAutomaton(String str)
		{
			this.str = str;
			state = new State[str.length() << 1 + 10];
			suffixLink = new int[str.length() << 1 + 10];
			this.build();
		}

		public void build()
		{
			state[nil] = new State(0);
			last = nil;
			suffixLink[nil] = -1;
			for(int i = 0 ; i < str.length() ; ++i)
			{
				add(str.charAt(i));
			}
		}

		public void add(char c)
		{
			int curr = stateID++;
			state[curr] = new State(state[last].maxLen + 1);
			int pos = last;
			while(pos != -1)
			{
				if(state[pos].transitions.get(c) != null) break;
				state[pos].transitions.put(c,curr);
				pos = suffixLink[pos];
			}
			if(pos == -1)
			{
				// does not fall on anything so our choice is nil.

				suffixLink[curr] = nil;
			}
			else
			{
				int rightPos = state[pos].transitions.get(c);
				if(state[rightPos].maxLen == state[pos].maxLen + 1)
				{
					// falls correctly
					suffixLink[curr] = rightPos;
				}
				else
				{

					// let's split this node into two nodes
					// first one will accept all strings from minlen(rightPos) till maxlen(pos) + 1
					// and other accept anything greater
					int newNode = stateID++;

					state[newNode] = new State(state[pos].maxLen + 1);
					// copy TreeMap
					state[newNode].transitions.putAll(state[rightPos].transitions);

					// suffixes of pos (including pos) must now point to newNode as they are smaller !
					while(pos != -1 && state[pos].transitions.get(c) == rightPos)
					{
						state[pos].transitions.put(c,newNode);
						pos = suffixLink[pos];
					}
					// update suffix links accordingly
					suffixLink[newNode] = suffixLink[rightPos];
					suffixLink[rightPos] = suffixLink[curr] = newNode;

				}
			}


			last = curr;


		}
	
	public static void main(String[]args)throws Throwable
	{
		

	}


}