package textgen;

import java.util.AbstractList;


/** A class that implements a doubly linked list
 * 
 * @author UC San Diego Intermediate Programming MOOC team
 * @author Ronny MacMaster
 * @param <E> The type of the elements stored in the list
 */
public class MyLinkedList<E> extends AbstractList<E> {
	LLNode<E> head;
	LLNode<E> tail;
	int size;

	/** Create a new empty LinkedList */
	/** We will forgo the two sentinel nodes. */
	public MyLinkedList() {
		/* Sentinel Nodes */
		/*	head = new LLNode<E>(null);
			tail = new LLNode<E>(null);
			head.next = tail;
			tail.prev = head;			*/
			size = 0;
	}

	/**
	 * Appends an element to the end of the list
	 * @param element The element to add
	 */
	public boolean add(E element ) 
	{
		if(element == null){
			throw new NullPointerException();
		}
		try{
			LLNode<E> node = new LLNode<E>(element);
			node.prev = tail;
			if(size == 0){
				head = node;
			}
			else{
				tail.next = node;
			}
			tail = node;
			size++;	
			return true;
		}
		catch(Exception e){
			return false;
		}
	}

	/** Get the element at position index 
	 * @throws IndexOutOfBoundsException if the index is out of bounds. */
	public E get(int index) 
	{
		if((index < 0) || (index >= size)){
			throw new IndexOutOfBoundsException();
		}
		//optimize to n/2
		if(index <= size/2){
			LLNode<E> node = head;
			while(index > 0){
				node = node.next;
				index--;
			}
			return node.data;
		}
		else{
			LLNode<E> node = tail;
			while(index < (size-1)){
				node = node.prev;
				index++;
			}
			return node.data;
		}
		
	}

	/**
	 * Add an element to the list at the specified index
	 * @param The index where the element should be added
	 * @param element The element to add
	 */
	public void add(int index, E element ) 
	{
		if((size == 0 && index == 0)||(index == size)){
			//empty List condition
			add(element);
			return;
		}
		if((index < 0) || (index >= size)){
			throw new IndexOutOfBoundsException();
		}
		else if(element == null){
			throw new NullPointerException();
		}
		//optimize to n/2
		LLNode<E> node = new LLNode<E>(element);
		if(index <= size/2){
			LLNode<E> curr = head;
			while(index > 0){
				curr = curr.next;
				index--;
			}
			if(head == curr){
				head = node;
			}
			else{
				curr.prev.next = node;
			}
			node.prev = curr.prev;
			node.next = curr;
			curr.prev = node;
		}
		else{
			LLNode<E> curr = tail;
			while(index < (size-1)){
				curr = curr.prev;
				index++;
			}
			node.prev = curr.prev;
			node.prev.next = node;
			node.next = curr;
			curr.prev = node;
		}
		size++;
	}


	/** Return the size of the list */
	public int size() 
	{
		return size;
	}

	/** Remove a node at the specified index and return its data element.
	 * @param index The index of the element to remove
	 * @return The data element removed
	 * @throws IndexOutOfBoundsException If index is outside the bounds of the list
	 * 
	 */
	public E remove(int index) 
	{
		if((index < 0) || (index >= size)){
			throw new IndexOutOfBoundsException();
		}
		//optimize to n/2
		LLNode<E> node;
		if(index <= size/2){
			node = head;
			while(index > 0){
				node = node.next;
				index--;
			}
		}
		else{
			node = tail;
			while(index < (size-1)){
				node = node.prev;
				index++;
			}
		}
		if(node == head){
			head = node.next;
		}
		else{
			node.prev.next = node.next;
		}
		if(node == tail){
			tail = node.prev;
		}
		else{
			node.next.prev = node.prev;
		}
		size--;	return node.data;
	}

	/**
	 * Set an index position in the list to a new element
	 * @param index The index of the element to change
	 * @param element The new element
	 * @return The element that was replaced
	 * @throws IndexOutOfBoundsException if the index is out of bounds.
	 */
	public E set(int index, E element) 
	{
		if((index < 0) || (index >= size)){
			throw new IndexOutOfBoundsException();
		}
		if(element == null){
			throw new NullPointerException();
		}
		//optimize to n/2
		LLNode<E> node;
		if(index <= size/2){
			node = head;
			while(index > 0){
				node = node.next;
				index--;
			}
		}
		else{
			node = tail;
			while(index < (size-1)){
				node = node.prev;
				index++;
			}
		}
		E value = node.data;
		node.data = element;
		return value;
	}   
}

class LLNode<E> 
{
	LLNode<E> prev;
	LLNode<E> next;
	E data;

	public LLNode(E e) 
	{
		this.data = e;
		this.prev = null;
		this.next = null;
	}

}
