package cs1302.p3;

import java.util.Arrays;

public class SortedArrayList <T extends Comparable<T>> extends ArrayList<T> implements List<T> {
	public SortedArrayList(){
		boxes = Box.<T>array(size); 
	}//default
	/**
	 * Adds an element then sorts the list
	 * @param	elem	element of type T
	 */
	@Override
	public void add(T elem) throws NullPointerException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		size++;
		boxUpdate();
		boxes[boxes.length-1].set(elem);
		Arrays.sort(boxes);	
	}
	/**
	 * Adds an element then sorts the list. index value has no effect on sorting;
	 * @param	elem	element of type T
	 */
	@Override
	public void add(int index, T elem) throws NullPointerException, IndexOutOfBoundsException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		if (index>=boxes.length) throw new IndexOutOfBoundsException("index too high");
		size++;
		boxUpdate();
		boxes[boxes.length-1].set(elem);
		Arrays.sort(boxes);
	}
}

