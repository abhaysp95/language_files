// implementation of dynamic array with help of static array

package com.server;

import java.util.Iterator;

//@SuppressWarnings("unchecked")
public class Array<T> implements Iterable<T> {
	private T[] arr;
	private int capacity = 0;  // length user thinks of array
	private int len = 0;  // actual array size

	public Array() { this(16); }

	public Array(int capacity) {
		if (capacity < 0) {
			throw new IllegalArgumentException("Illegal capacity: " + capacity);
		}
		this.capacity = capacity;
		this.len = capacity;
		this.arr = (T[]) new Object[capacity];  // check, type-casting
	}

	public int size() { return len; }
	public boolean isEmpty() { return size() == 0; }

	public T get(int index) { return this.arr[index]; }
	public void set(int index, T elem) { this.arr[index] = elem; }

	public void clear() {
		for (int i = 0; i < capacity; ++i) {
			this.arr[i] = null;
		}
		len = 0;
	}

	public void add(T elem) {
		if (len + 1 >= capacity) {
			if (capacity == 0) { capacity = 1; }
			else capacity *= 2;  // double the size
			T[] new_arr = (T[]) new Object[capacity];
			for (int i = 0; i < len; ++i) {
				new_arr[i] = this.arr[i];
			}
			this.arr = new_arr;
		}
		this.arr[len++] = elem;
	}

	// Removes the element at the specified index in this list
	public T removeAt(int rm_index) {
		if (rm_index >= len && rm_index < 0) {
			throw new IndexOutOfBoundsException();
		}
		T data = this.arr[rm_index];
		T[] new_arr = (T[]) new Object[len - 1];
		for (int i = 0, j = 0; i < len; ++i, ++j) {
			if (i == rm_index) { j--; }
			else {
				new_arr[j] = this.arr[i];
			}
		}
		this.arr = new_arr;
		capacity = --len;
		return data;
	}

	public boolean remove(Object obj) {
		try {
			for (int i = 0; i < len; ++i) {
				System.out.println("Got obj: " + (T)obj);
				if (this.arr[i].equals((T) obj)) {
					// null pointer exception, why ?
					// does equals automatically gives error in comparision, like
					// Integer with Double, like that ?
					removeAt(i);
					return true;
				}
			}
		}
		catch (NullPointerException npe) {
			System.out.println("npe: " + npe.getMessage());
		}
		return false;
	}

	public int indexOf(Object obj) {
		for (int i = 0; i < len; ++i) {
			if (this.arr[i].equals(obj)) {
				return i;
			}
		}
		return -1;
	}

	public boolean contains(Object obj) {
		return indexOf(obj) != -1;
	}

	// Iterator is still fast but not as fast as Iterative for loop

	@Override
	public Iterator<T> iterator() {
		return new Iterator<T>() {
			int index = 0;
			public boolean hasNext() {
				return index < len;
			}
			public T next() {
				return arr[index++];
			}
		};
	}

	@Override
	public String toString() {
		if (len == 0) { return "[]"; }
		else {
			StringBuilder sb = new StringBuilder(len).append("[");
			for (int i = 0; i < len - 1; ++i) {
				sb.append(arr[i] + ", ");
			}
			return sb.append(arr[len - 1] + "]").toString();
		}
	}
}
