/*******************Linear_eff.java**************************
 * Solves the famous problem in O(n):
 * Maximum contiguous subsequence sum problem
 * "Given (possibly negative) integers a1, a2, a3, ..., an,
 *  find (and identify the sequence corresponding to) 
 *  the maximum value of sum(ai..aj)
 *  If all the integers are negative,
 *  The maximum contiguous subsequence sum is zero .
 *
 * Key Concept: "if the current sum is negative,
 * we can advance past all subsequences that include it.
 * ie. advance the outer pointer past the lower subsequence.
 *  
 * Author: Ronny Macmaster
 * Date: 3/8/2016
 ***********************************************************/

import java.util.ArrayList;

public class linear_eff{
	
	// sum start and end indices
	public static int start = 0;;
	public static int end = 0;;
	
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
		System.out.print("start: " + start + "   ");
		System.out.print("end: " + end + "\n\n");
	}
	
	public static int findsum(ArrayList<Integer> arr){
		// sum and size
		int maxsum = 0;
		int currsum = 0; 
		int n = arr.size(); 
		
		// i = lower pointer. j = upper pointer
		for(int i = 0, j = 0; j < n; j++){ // pointer 1
		
				// subsequence sum
				currsum += arr.get(j);
				
				// mark maxsum
				if(currsum > maxsum){
					maxsum = currsum;
					start = i;
					end = j;
				}
				else if(currsum < 0){
					currsum = 0; // skip subsequence
					i = j + 1; // advance base
				}
				
		}	
		
		return maxsum;
		
	}
}