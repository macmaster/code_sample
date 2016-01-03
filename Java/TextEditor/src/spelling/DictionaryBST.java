package spelling;

import java.util.TreeSet;

/**
 * @author UC San Diego Intermediate MOOC team
 * @author Ronny MacMaster
 */
public class DictionaryBST implements Dictionary 
{
   private TreeSet<String> dict;
   
   private int size;
	
   public DictionaryBST(){
    	dict = new TreeSet<String>();
    	size = 0;
    }
	
    
    /** Add this word to the dictionary.  Convert it to lowercase first
     * for the assignment requirements.
     * @param word The word to add
     * @return true if the word was added to the dictionary 
     * (it wasn't already there). */
    public boolean addWord(String word) {
    	word = word.toLowerCase();
    	if(dict.contains(word))
    			return false;
    	else{
    		dict.add(word);
    		size++;
    		return true;
    	}
    }


    /** Return the number of words in the dictionary */
    public int size()
    {
        return size;
    }

    /** Is this a word according to this dictionary? */
    public boolean isWord(String s) {
        String word = s.toLowerCase();
    	if(dict.contains(word))
    		return true;
    	else{
    		return false;
    	}    
    }
}
