using System;
using System.Collections;
using System.Collections.Generic;

namespace insertion{
	
	public class InsertionSort{
		
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
			for(int odx = 1; odx < n; odx++){
				int val = arr[odx];
				int idx = odx - 1;
				while(idx >= 0 && arr[idx] > val){
					// propogate upward
					arr[idx+1] = arr[idx--];
				}
				arr[idx+1] = val;
			}
			
			// print the array
			for(int idx = 0; idx < n; idx++){
				Console.Write(arr[idx] + " ");
			}
		}
		
		
	}
	
}