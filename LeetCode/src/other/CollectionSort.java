package other;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CollectionSort {

	public static void main(String[] args) {
		List<Person> pList = new ArrayList<>();
		Person p = new Person(4, "222");
		pList.add(p);
		p = new Person(3, "222");
		pList.add(p);
		p = new Person(5, "222");
		pList.add(p);
		
		Collections.sort(pList,new Comparator<Person>(){
			@Override
			public int compare(Person a,Person b){
				return 0;
			}
		});
		System.out.println(pList.get(0).getId());
	}

}
