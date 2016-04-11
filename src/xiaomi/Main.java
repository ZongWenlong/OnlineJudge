package xiaomi;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class Main {
	public static final void main(String[] args){
		Map<String,String> map = new HashMap<String,String>();
		Set<String> set = map.keySet();
		Iterator<String> i = set.iterator();
		while(i.hasNext()){
			String key = i.next();
			String value = map.get(key);
		}
		
		for(Object object : map.keySet()){
			String key = (String)object;
			String value = map.get(key);
		}
		
		Set set2 = map.entrySet();
		Iterator i2 = set2.iterator();
		while(i2.hasNext()){
			Map.Entry e= (Entry)i2.next();
			String key = (String)e.getKey();
		}
		ddd.ddd.ordinal()ordinal
	}
	
	public enum ddd{
		ddd
	}
}
