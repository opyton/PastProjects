package cs1302.p3;

public class ArrayList <T> extends Box<T> implements List<T>{
	public int size = 0;
	public Box<T>[] boxes,tempBox;
	public ArrayList(){
		boxes = Box.<T>array(size); 
	}//default
	/**
	 * This will adjust the size of the object.
	 */
	public void boxUpdate() {
		tempBox = boxes.clone();
		boxes = Box.<T>array(size); 
		if(tempBox.length<=boxes.length) {
			for(int x = 0; x<tempBox.length-1;x++) {
				boxes[x].set(tempBox[x].get());
			}//for
		}//if
		if(tempBox.length>boxes.length) {
			for(int x = 0; x<boxes.length-1;x++) {
				boxes[x].set(tempBox[x].get());
			}//for
		}//if
	}
	/**
	 * Adds an element to the end of the list
	 * @param	elem	element of type T
	 */
	@Override
	public void add(T elem) throws NullPointerException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		size++;
		boxUpdate();
		boxes[boxes.length-1].set(elem);
	}
	/**
	 * Adds an element to a specified index
	 * @param	elem	element of type T
	 * @param	index	int value representing specified location
	 */
	@Override
	public void add(int index, T elem) throws NullPointerException, IndexOutOfBoundsException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		if (index>=boxes.length) throw new IndexOutOfBoundsException("index too high");
		size++;
		boxUpdate();
		if (index == boxes.length)
			add(elem);
		else {
			for(int k = boxes.length-2; k>=index;k--) {
				boxes[k].set(boxes[k-1].get());
			}//for
		}//else
		boxes[index].set(elem);	
	}
	/**
	 * Clears object array
	 */
	@Override
	public void clear() {
		size = 0;
		boxes = Box.<T>array(size);	
		boxes[0]=null;
	}
	/**
	 * returns boolean value to represent whether two objects are equal
	 * @param	list	object for comparison
	 * @return	bool	value 
	 */

	@Override
	public boolean equals(Object list) {
		boolean isEqual = true;
		for(int i = 0; i<boxes.length; i++) {
			if (!(boxes[i].get().equals(list))) {
				isEqual = false;
				break;
			}
		}
		return isEqual;
	}

	/**
	 * Returns element stored in object array
	 * @param	index	int location
	 * @return	T	element T stored in index
	 */
	@Override
	public T get(int index) throws IndexOutOfBoundsException {
		if (index>=boxes.length) throw new IndexOutOfBoundsException("index too high");
		return boxes[index].get();
	}
	/**
	 * Sets specified location with specified element
	 * @param	index	int value
	 * @param	elem	generic value
	 */
	@Override
	public T set(int index, T elem) throws NullPointerException, IndexOutOfBoundsException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		if (index>=boxes.length) throw new IndexOutOfBoundsException("index too high");
		T var = boxes[index].get();
		boxes[index].set(elem); 
		return var;
	}
	/**
	 * returns size of array
	 * @return	int	size
	 */
	@Override
	public int size() {
		return boxes.length;
	}
	/**
	 * Returns whether the array is empty or not
	 * @return	boolean	
	 */
	@Override
	public boolean isEmpty() {
		return (boxes[0]==null);
	}
	/**
	 * Returns whether a specific element is in the array
	 * @param	elem	Generic T variable
	 * @return	boolean
	 */
	@Override
	public boolean contains(T elem) throws NullPointerException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		boolean inArray =false;
		for(Box<T> x:boxes) {
			if(x.get().equals(elem))
				inArray=true;
		}//for
		return inArray;
	}
	/**
	 * Removes a generic value at its nearest location.
	 * @param	elem	T
	 */
	@Override
	public boolean remove(T elem) throws NullPointerException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		boolean exists = false;
		for(int count = 0;count<boxes.length || exists==true;count++) {
			if(boxes[count].get().equals(elem)) {
				if (count!=boxes.length-1) {
					for(int j=count;j<boxes.length-1;j++) {
						boxes[j].set(boxes[j+1].get());
					}//for
				}//if	
				size--;
				boxUpdate();
				exists=true;
			}//if
		}//for
		return false;
	}
	/**
	 * Locates the index of a specified element.
	 * @param	elem	T value representing the index
	 * @return	val	index location
	 */
	@Override
	public int indexOf(T elem) throws NullPointerException {
		if (elem == null) throw new NullPointerException("elem cannot be null");
		int val = -1;
		boolean found = false;
		for(int c =0; c<boxes.length||found==true;c++) {
			if (boxes[c].get().equals(elem)) {
				val = c;
				found = true;
			}	
		}//for
		return val;
	}
}

