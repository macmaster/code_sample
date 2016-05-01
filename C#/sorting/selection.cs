using System;
using System.Collections;
using System.Collections.Generic;

namespace selection{
	
	public class SelectionSort{
		
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
			
			
			// selection sort loop
			for(int odx = 0; odx < n; odx++){
				for(int idx = odx + 1; idx < n; idx++){
					// xor-swap check 
					if(arr[idx] < arr[odx]){ 
						arr[idx] ^=  arr[odx];
						arr[odx] ^= arr[idx];
						arr[idx] ^= arr[odx];
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