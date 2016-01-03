package spelling;

import java.util.LinkedList;

/**
 * A class that implements the Dictionary interface using a LinkedList
 *
 */
public class DictionaryLL implements Dictionary 
{

	private LinkedList<String> dict;
	
	private int size;

    public DictionaryLL(){
    	dict = new LinkedList<String>();
    	size = 0;
    }


    /** Add this word to the dictionary.  Convert it to lowercase first
     * for the assignment requirements.
     * @param word The word to add
     * @return true if the word was added to the dictionary 
     * (it wasn't already there). */
    public boolean addWord(String word) {
    	word = word.toLowerCase();
    	for(String dict_word : dict){
    		if(dict_word.equals(word))
    			return false;
    		else if(dict_word.compareTo(word) > 0)
    			break;
    	}
        dict.add(word);
    	size++;
        return true;
    }


    /** Return the number of words in the dictionary */
    public int size()
    {
        return size;
    }

    /** Is this a word according to this dictionary? */
    public boolean isWord(String s) {
        String word = s.toLowerCase();
        for(String dict_word : dict)
        	if(dict_word.equals(word))
        		return true;
        	else if(dict_word.compareTo(word) > 0)
    			break;
        return false;
    }

    
}
