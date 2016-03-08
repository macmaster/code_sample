/*******************Cubic_eff.java**************************
 * Solves the famous problem:
 * Maximum contiguous subsequence sum problem
 * "Given (possibly negative) integers a1, a2, a3, ..., an,
 *  find (and identify the sequence corresponding to) 
 *  the maximum value of sum(ai..aj)
 *  If all the integers are negative,
 *  The maximum contiguous subsequence sum is zero .
 ***********************************************************/

import java.util.ArrayList;

public class cubic_eff{
	
	public static void main(String args[]){
		// build array list {-2, 11, -4, 13, -5, 2}
		ArrayList<Integer> arr = new ArrayList<Integer>();
		arr.add(-2); arr.add(11); arr.add(-4);
		arr.add(13); arr.add(-5); arr.add(2);
		
		// print list
		System.out.println("ArrayList: ");
		for(int i = 0; i < arr.size(); i++){
			System.out.print(arr.get(i) + "  ");	
		}System.out.print("\n");
		
		// search for sum
		int sum = findsum(arr);
		
		// print sum
		System.out.println("max sum: " + sum);
	}
	
	public static int findsum(ArrayList<Integer> arr){
		return 0;
	}
}