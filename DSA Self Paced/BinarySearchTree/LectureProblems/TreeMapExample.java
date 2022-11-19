// Java program to demonstrate 
// the working of TreeMap 

import java.util.*; 
class TreeMapExample { 
    public static void main(String args[]) 
    { 
        // Initialization of a TreeMap 
        // using Generics 
        TreeMap<Integer, String> t 
            = new TreeMap<Integer, String>(); 

        // Inserting the Elements 
        t.put(10, "geeks"); 
        t.put(15, "ide"); 
        t.put(5, "courses"); 
        
        // Prints the TreeMap
        System.out.println(t);
        
        // Check for the key in the map
        System.out.println(t.containsKey(10));
        
        // Iterating over TreeMap
        for(Map.Entry<Integer, String>e : t.entrySet())
            System.out.println(e.getKey() + " " + e.getValue());

          // returns the smallest key greater 
        // than the passed key i.e., 15
        System.out.println(t.higherKey(10));
        
        // returns the greatest smaller key 
        // than the passed key i.e., 5
        System.out.println(t.lowerKey(10));
        
        // greatest key <= passed key i.e., 10
        System.out.println(t.floorKey(10));
        
        // greatest key >= passed key i.e., 10
        System.out.println(t.ceilingKey(10));

          // returns the key-value pair corresponding
        // to higher key and prints the associated value
        System.out.println(t.higherEntry(10).getValue());
        
        // returns the key-value pair corresponding
        // to lower key prints the associated value
        System.out.println(t.lowerEntry(10).getValue());
        
        // returns a key-value mapping associated 
        // with the greatest key <= to the given key
        System.out.println(t.floorEntry(10).getValue());
        
        // returns a key-value mapping associated 
        // with the least key >= to the given key
        System.out.println(t.ceilingEntry(10).getValue());
    } 
} 
