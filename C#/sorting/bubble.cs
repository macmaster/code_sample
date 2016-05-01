using System;
using System.Collections;
using System.Collections.Generic;

namespace bubble{
	
	public class BubbleSort{
		
		public static void Main(string[] args){
			
			
			// initialize the array
			int n = 10;
			try{n = int.Parse(args[0]);}
			catch{
				Console.WriteLine("Error parsing argument. ");
				Console.WriteLine("using default capacity of 10.");
			}
			int[] arr = new int[n];
			Random rnd = new Random();
			for(int idx = 0; idx < n; idx++){
				arr[idx] = n - idx;
			}
			

			for(int odx = n; odx > 1; odx--){
				for(int idx = 1; idx < odx; idx++){
					// xor-swap check 
					if(arr[idx] < arr[idx-1]){ 
						arr[idx] ^=  arr[idx-1];
						arr[idx-1] ^= arr[idx];
						arr[idx] ^= arr[idx-1];
					}
				}
			}
			
			// print the array
			for(int idx = 0; idx < n; idx++){
				Console.Write(arr[idx] + " ");
			}
		}
		
		
	}
	
}