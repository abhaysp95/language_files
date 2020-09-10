// implementing two methods to populate arraylist and to read from it

package practice.udemy_tut.section9.interfaces.challenge1;

import java.util.List;

public interface ISavable {
	// using List instead of ArrayList or LinkedList, provides max flexibility
	List<String> write();
	void read(List<String> savedValues);
}
