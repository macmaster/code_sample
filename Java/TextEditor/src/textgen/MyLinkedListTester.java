/**
 * 
 */
package textgen;

import static org.junit.Assert.*;

import java.util.LinkedList;

import org.junit.Before;
import org.junit.Test;

/**
 * @author UC San Diego MOOC team
 * @author Ronny MacMaster
 */
public class MyLinkedListTester {

	private static final int LONG_LIST_LENGTH =10; 

	MyLinkedList<String> shortList;
	MyLinkedList<Integer> emptyList;
	MyLinkedList<Integer> longerList;
	MyLinkedList<Integer> list1;
	MyLinkedList<Character> singleList;
	
	/**
	 * @throws java.lang.Exception
	 */
	@Before
	public void setUp() throws Exception {
		// Feel free to use these lists, or add your own
	    shortList = new MyLinkedList<String>();
		shortList.add("A");
		shortList.add("B");
		singleList = new MyLinkedList<Character>();
		singleList.add('x');
		emptyList = new MyLinkedList<Integer>();
		longerList = new MyLinkedList<Integer>();
		
		for (int i = 0; i < LONG_LIST_LENGTH; i++)
		{
			longerList.add(i);
		}
		list1 = new MyLinkedList<Integer>();
		list1.add(65);
		list1.add(21);
		list1.add(42);	
		
	}

	
	/** Test if the get method is working correctly.
	 */
	/*You should not need to add much to this method.
	 * We provide it as an example of a thorough test. */
	@Test
	public void testGet()
	{
		//test empty list, get should throw an exception
		try {
			emptyList.get(0);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		// test short list, first contents, then out of bounds
		assertEquals("Check first", "A", shortList.get(0));
		assertEquals("Check second", "B", shortList.get(1));
		
		try {
			shortList.get(-1);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		
		}
		try {
			shortList.get(2);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		
		}
		// test longer list contents
		for(int i = 0; i<LONG_LIST_LENGTH; i++ ) {
			assertEquals("Check "+i+ " element", (Integer)i, longerList.get(i));
		}
		
		// test off the end of the longer array
		try {
			longerList.get(-1);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		
		}
		try {
			longerList.get(LONG_LIST_LENGTH);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		}
		
	}
	
	
	/** Test removing an element from the list.
	 * We've included the example from the concept challenge.
	 * You will want to add more tests.  */
	@Test
	public void testRemove()
	{
		int a = list1.remove(0);
		assertEquals("Remove: check a is correct ", 65, a);
		assertEquals("Remove: check element 0 is correct ", (Integer)21, list1.get(0));
		assertEquals("Remove: check size is correct ", 2, list1.size());
		
		assertEquals("Remove: check end", "B", shortList.remove(1));
		assertEquals("Remove: check front", "A", shortList.remove(0));
		
		char c = singleList.remove(0);
		assertEquals("Remove: check c is correct", 'x', c);
		assertEquals("Remove: check size is correct", 0, singleList.size());
		
		try {
			emptyList.remove(0);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		try {
			list1.remove(-1);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		for(int i = LONG_LIST_LENGTH-1; i>=0; i--) {
			assertEquals("Check "+i+ " element", (Integer)i, longerList.remove(i));
		}
		
	}
	
	/** Test adding an element into the end of the list, specifically
	 *  public boolean add(E element)
	 * */
	@Test
	public void testAddEnd()
	{
		boolean flag = list1.add(100);
		assertEquals("AddEnd: check element added is correct ", (Integer)100, list1.get(3));
		assertEquals("AddEnd: check element 0 is correct ", (Integer)65, list1.get(0));
		assertEquals("AddEnd: check element 1 is correct ", (Integer)21, list1.get(1));
		assertEquals("AddEnd: check element 1 is correct ", (Integer)42, list1.get(2));
		assertEquals("AddEnd: check size is correct ", 4, list1.size());
		assertEquals("AddEnd: flag ", true, flag);
		
		flag = emptyList.add(100);
		assertEquals("AddEnd: check element 0 is correct ", (Integer)100, emptyList.get(0));
		assertEquals("AddEnd: check size is correct ", 1, emptyList.size());
		assertEquals("AddEnd: flag ", true, flag);
		
		
	}

	
	/** Test the size of the list */
	@Test
	public void testSize()
	{
		assertEquals("Remove: check size is correct", 1, singleList.size());
		assertEquals("Remove: check size is correct", 0, emptyList.size());
		assertEquals("Remove: check size is correct", LONG_LIST_LENGTH, longerList.size());

	}

	
	
	/** Test adding an element into the list at a specified index,
	 * specifically:
	 * public void add(int index, E element)
	 * */
	@Test
	public void testAddAtIndex()
	{
		list1.add(1, 19);
		assertEquals("AddIndex: check element added is correct ", (Integer)19, list1.get(1));
		assertEquals("AddIndex: check element 0 is correct ", (Integer)65, list1.get(0));
		assertEquals("AddIndex: check element 1 is correct ", (Integer)21, list1.get(2));
		assertEquals("AddIndex: check element 1 is correct ", (Integer)42, list1.get(3));
		assertEquals("AddIndex: check size is correct ", 4, list1.size());
		
		emptyList.add(0, 100);
		assertEquals("AddIndex: check element 0 is correct ", (Integer)100, emptyList.get(0));
		assertEquals("AddIndex: check size is correct ", 1, emptyList.size());
		
		list1.add(4, 24);
		assertEquals("AddIndex: check element added is correct ", (Integer)19, list1.get(1));
		assertEquals("AddIndex: check element 0 is correct ", (Integer)65, list1.get(0));
		assertEquals("AddIndex: check element 1 is correct ", (Integer)21, list1.get(2));
		assertEquals("AddIndex: check element 1 is correct ", (Integer)42, list1.get(3));
		assertEquals("AddIndex: check element 1 is correct ", (Integer)24, list1.get(4));
		assertEquals("AddIndex: check size is correct ", 5, list1.size());
		try {
			list1.add(-1, 4);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		try {
			list1.add(1, null);
			fail("Check out of bounds");
		}
		catch (NullPointerException e) {
			
		}
		
	}
	
	/** Test setting an element in the list */
	@Test
	public void testSet()
	{	
		
		char c = singleList.set(0, 'y');
		assertEquals("Set: check result is correct", 'x', c);
		assertEquals("Set: check char is correct", (Character)'y', singleList.get(0));
		assertEquals("Set: check size is correct", 1, singleList.size());
		
		try{
			list1.set(0, null);
			fail("Check null");
		}
		catch(NullPointerException e){
			
		}
		int i = list1.set(0, 101);
		assertEquals("Set: check result is correct", 65, i);
		assertEquals("Set: check char is correct", (Integer)101, list1.get(0));
		assertEquals("Set: check size is correct", 3, list1.size());
		i = list1.set(2, 200);
		assertEquals("Set: check result is correct", 42, i);
		assertEquals("Set: check char is correct", (Integer)200, list1.get(2));
		assertEquals("Set: check size is correct", 3, list1.size());
		
		try{
			emptyList.set(0, 101);
			fail("Check out of bounds");
		}
		catch(IndexOutOfBoundsException e){
			
		}

	}
	
}
