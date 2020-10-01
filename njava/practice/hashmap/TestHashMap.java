import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeMap;
import java.util.Map.Entry;

public class TestHashMap {
	public static void main(String[] args) {

		// this is how to declare hashmap
		HashMap<Integer, String> hmap = new HashMap<Integer, String>();

		// adding elements to hashmap
		hmap.put(12, "Chaitanya");
		hmap.put(2, "Rahul");
		hmap.put(7, "Singh");
		hmap.put(49, "Ajeet");
		hmap.put(3, "Anuj");

		// Display content using iterator
		Set set = hmap.entrySet();
		/* in HashMap.entrySet() it's like {key1 = value1, key2 = value2}
		   and in set it's like [key1 = value1, key2 = value2] */
		Iterator iterator = set.iterator();
		while (iterator.hasNext()) {
			// this line is changing back set to hashmap type
			Map.Entry mentry = ((Map.Entry) iterator.next());
			System.out.println("key is: " + mentry.getKey() +
					" & value is: " + mentry.getValue());
		}

		System.out.println("--------------------------");

		// Another way to iterate
		for (Map.Entry<Integer, String> newSet: hmap.entrySet()) {
			System.out.println("key is: " + newSet.getKey() +
					" & value is: " + newSet.getValue());
		}

		System.out.println("--------------------------");

		// Using forEach to iterate
		hmap.forEach((key, value) ->
			System.out.println("key is: " + key +
					" & value is: " + value));

		System.out.println("--------------------------");

		// Another way with Iterator
		// TODO: search for Entry class
		Iterator<Entry<Integer, String>> it = hmap.entrySet().iterator();
		// above line is changing HashMap to Set of Entry class type and then
		// using it for the Iterator type, same as the previous example with
		// iterator
		while (it.hasNext()) {
			Map.Entry<Integer, String> lset = (Map.Entry<Integer, String>) it.next();
			System.out.println(lset.getKey() + " = " + lset.getValue());
		}
		// so does it mean that iterator can't directly iterate over HashMap,
		// it needs to be of Entry Class type iterator

		// Get value based on key
		String variable = hmap.get(2);
		System.out.println("Value at index 2 is: " + variable);

		// Remove values based on key
		hmap.remove(3);
		System.out.println("map key after removal:");
		Set set2 = hmap.entrySet();
		Iterator iterator2 = set2.iterator();
		while (iterator2.hasNext()) {
			Map.Entry mentry2 = ((Map.Entry) iterator2.next());
			System.out.println("key is: " + mentry2.getKey() +
					" & value is: " + mentry2.getValue());
		}

		// sorting hashmap
		System.out.println("--------------------------");
		System.out.println("Sorting HashMap:");
		// creating empty tree that will be sorted using its natural order of key
		Map<Integer, String> map = new TreeMap<Integer, String>(hmap);
		Set set3 = map.entrySet();
		Iterator iterator3 = set3.iterator();
		while (iterator3.hasNext()) {
			Map.Entry mentry = (Map.Entry<Integer, String>) iterator3.next();
			System.out.println("key is: " + mentry.getKey() +
					" & value is: " + mentry.getValue());
		}
	}
}
