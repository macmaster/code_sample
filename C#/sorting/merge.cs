using System;
using System.Collections;
using System.Collections.Generic;

namespace merge{
	
	public class MergeSort{
		
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
			
			// run mergesort on the array
			Sort(arr, 0, n);
			
			// print the array
			for(int idx = 0; idx < n; idx++){
				Console.Write(arr[idx] + " ");
			}
		}
		
		/////////////////////////////////////////////////////////////////////
		/// MergeSort
		/// performs the sort partitioning
		///
		/// arr is the array to be sorted
		/// low is the lower index of the subarray
		/// high is the higher index of the subarray
		/////////////////////////////////////////////////////////////////////
		public static void Sort(int[] arr, int low, int high){
			// split the array
			int size = high - low;
			int middle = low + size / 2;
			
			/// Debug split
			// visit lower 
			Console.Write("\nlow:  ");
			for(int idx = low; idx < middle; idx++){
				Console.Write(arr[idx]+" ");
			}
			// visit higher
			Console.Write("\nhigh: ");
			for(int idx = middle; idx < high; idx++){
				Console.Write(arr[idx]+" ");
			}
			Console.Write("\n");
						
			// recursively call the mergesort
			if(size <= 1) return;
			Sort(arr, low, middle);
			Sort(arr, middle, high);
			Merge(arr, low, middle, high);
		}
		
		public static void Merge(int[] arr, int low, int middle, int high){
			// indices and temp memory
			int idx = 0;
			int ldx = low;
			int hdx = middle;
			int size = high - low;
			int[] temp = new int[size];
			
			// first merge
			while(ldx < middle && hdx < high){
				int lval = arr[ldx];
				int hval = arr[hdx];
				if(lval < hval){
					temp[idx++] = lval;
					ldx++;
				}
				else{
					temp[idx++] = hval;
					hdx++;
				}
			}
			
			// leftover low merge
			while(ldx < middle){
				temp[idx++] = arr[ldx++];
			}
			
			// leftover high merge
			while(hdx < high){
				temp[idx++] = arr[hdx++];
			}
			
			// write to arr
			for(int cdx = 0; cdx < size; cdx++){
				arr[cdx + low] = temp[cdx];
			}
		}
		
	}
	
}