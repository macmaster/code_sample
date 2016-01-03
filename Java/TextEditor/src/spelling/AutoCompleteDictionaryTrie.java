package spelling;

import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;

/** 
 * An trie data structure that implements the Dictionary and the AutoComplete ADT
 * 
 * @author Ronny MacMaster
 */
public class AutoCompleteDictionaryTrie implements  Dictionary, AutoComplete {

    private TrieNode root;
    private int size;
    

    public AutoCompleteDictionaryTrie()
	{
		root = new TrieNode();
		size = 0;
	}
	
	
	/** Insert a word into the trie.
	 * For the basic part of the assignment (part 2), you should ignore the word's case.
	 * That is, you should convert the string to all lower case as you insert it. */
	public boolean addWord(String word)
	{	
		TrieNode node = root;
		word = word.toLowerCase();
		for(int i = 0; i < word.length(); i++){
			char c = word.charAt(i);
			node.insert(c);
			node = node.getChild(c);
		}
		if(node.endsWord())
			return false;
		else{
			node.setEndsWord(true);
			size++;
			return true;
		}
	}
	
	/** 
	 * Return the number of words in the dictionary.  This is NOT necessarily the same
	 * as the number of TrieNodes in the trie.
	 */
	public int size()
	{
	    return size;
	}
	
	
	/** Returns whether the string is a word in the trie */
	@Override
	public boolean isWord(String s) 
	{
		TrieNode node = root;
		String word = s.toLowerCase();
		for(int i = 0; i < word.length(); i++){
			char c = word.charAt(i);
			node = node.getChild(c);
			if(node == null) 
				return false;
		}
		if(node.endsWord())
			return true;
		else{
			return false;
		}
	}

	/** 
	 *  * Returns up to the n "best" predictions, including the word itself,
     * in terms of length
     * If this string is not in the trie, it returns null.
     * @param text The text to use at the word stem
     * @param n The maximum number of predictions desired.
     * @return A list containing the up to n best predictions
     */@Override
     public List<String> predictCompletions(String prefix, int numCompletions) 
     {
    	 // 1. Find the stem in the trie.  If the stem does not appear in the trie, return an
    	 //    empty list
    	 // 2. Once the stem is found, perform a breadth first search to generate completions
    	 //    using the following algorithm:
    	 //    Create a queue (LinkedList) and add the node that completes the stem to the back
    	 //       of the list.
    	 //    Create a list of completions to return (initially empty)
    	 //    While the queue is not empty and you don't have enough completions:
    	 //       remove the first Node from the queue
    	 //       If it is a word, add it to the completions list
    	 //       Add all of its child nodes to the back of the queue
    	 // Return the list of completions
    	Queue<TrieNode> word_queue = new LinkedList<TrieNode>();
    	List<String> word_list = new LinkedList<String>();
    	//find the trie stem
 		TrieNode node = root;
 		String word = prefix.toLowerCase();
 		for(int i = 0; i < word.length(); i++){
 			char c = word.charAt(i);
 			node = node.getChild(c);
 			if(node == null) 
 				return word_list;
 		}
 		word_queue.add(node);
 		while((!word_queue.isEmpty())&&(numCompletions > 0)){
 			//remove head & add children
 			node = word_queue.remove();
 			if(node.endsWord()){
 				word_list.add(node.getText());
 				numCompletions--;
 			}
 			Set<Character> key_set = node.getValidNextCharacters();
 			for(Character c : key_set){
 				TrieNode child = node.getChild(c);
 				if(child != null)
 					word_queue.add(child);
 			}
 		}
 		return word_list;
     }

 	// For debugging
 	public void printTree()
 	{
 		printNode(root);
 	}
 	
 	/** Do a pre-order traversal from this node down */
 	public void printNode(TrieNode curr)
 	{
 		if (curr == null) 
 			return;
 		
 		System.out.println(curr.getText());
 		
 		TrieNode next = null;
 		for (Character c : curr.getValidNextCharacters()) {
 			next = curr.getChild(c);
 			printNode(next);
 		}
 	}
 	

	
}