package document;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

/** A class for timing the EfficientDocument and BasicDocument classes
 * 
 * @author UC San Diego Intermediate Programming MOOC team
 * @author Ronny MacMaster
 */

public class DocumentBenchmarking {

	
	public static void main(String [] args) {

	    // Run each test more than once to get bigger numbers and less noise.
	    int trials = 10;

	    // The text to test on
	    String textfile = "data/warAndPeace.txt";
		
	    // The amount of characters to increment each step
		int increment = 40000;

		// The number of steps to run.  
		int numSteps = 40;
		
		// THe number of characters to start with. 
		int start = 50000;
		
		System.out.print("# Chars"+"\t"+"   Basic BM"+"\t"+"Efficient BM"+"\n");
		for (int numToCheck = start; numToCheck < numSteps*increment + start; 
				numToCheck += increment)
		{			
			String filetext = getStringFromFile(textfile, numToCheck);

			/* Read numToCheck characters from the file into a String */
			 System.out.print(numToCheck + "\t");
			
			 double begin, end, time;
			 begin = System.nanoTime();
			 for(int i = 0; i < trials; i++){
				 //Basic Trial
				 BasicDocument b_doc = new BasicDocument(filetext);
				 b_doc.getFleschScore();
			 }
			 end = System.nanoTime();
			 time = (end - begin)/(1000000000f);
			 System.out.print(time + "\t");

			 begin = System.nanoTime();
			 for(int i = 0; i < trials; i++){
				 //Efficient Trial
				 EfficientDocument e_doc = new EfficientDocument(filetext);
				 e_doc.getFleschScore();
			 }
			 end = System.nanoTime();
			 time = (end - begin)/(1000000000f);
			 System.out.print(time + "\n");
			
		}
	
	}
	
	/** Get a specified number of characters from a text file
	 * 
	 * @param filename The file to read from
	 * @param numChars The number of characters to read
	 * @return The text string from the file with the appropriate number of characters
	 */
	public static String getStringFromFile(String filename, int numChars) {
		
		StringBuffer s = new StringBuffer();
		try {
			FileInputStream inputFile= new FileInputStream(filename);
			InputStreamReader inputStream = new InputStreamReader(inputFile);
			BufferedReader bis = new BufferedReader(inputStream);
			int val;
			int count = 0;
			while ((val = bis.read()) != -1 && count < numChars) {
				s.append((char)val);
				count++;
			}
			if (count < numChars) {
				System.out.println("Warning: End of file reached at " + count + " characters.");
			}
			bis.close();
		}
		catch(Exception e)
		{
		  System.out.println(e);
		  System.exit(0);
		}
		
		
		return s.toString();
	}
	
}
