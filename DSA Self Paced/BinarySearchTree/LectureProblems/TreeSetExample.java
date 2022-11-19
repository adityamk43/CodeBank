// Java program to demonstrate TreeSet
import java.util.*;

class TreeSetExample {

    public static void main(String[] args)
    {
        
        // Creating an empty TreeSet
        TreeSet<String> s = new TreeSet<String>();

        // Elements are added using add() method
        s.add("gfg");
        s.add("courses");
        s.add("ide");
        
        // Displaying the TreeSet
        // in sorted order
        System.out.println(s);
        
        // Checking whether "ide" is present 
        // or not
        System.out.println(s.contains("ide"));

        // Iterator to traverse the TreeSet
        Iterator<String> i = s.iterator();
        while(i.hasNext())
            System.out.print(i.next() + " ");
        System.out.println();

        // Removing 5 from TreeSet
        s.remove("ide");

        // foreach way of traversal
        for(String x:s)
            System.out.print(x + " ");
        System.out.println();

        System.out.println('\n');
        // Creating an empty TreeSet
        TreeSet<Integer> si = new TreeSet<Integer>();

        // Elements are added using add() method
        si.add(10);
        si.add(5);
        si.add(2);
        si.add(15);
        
        // Prints the largest value lower than 5
        // Here it is 2
        System.out.println(si.lower(5));
        
        // Prints the smallest higher value than 5
        // Between 10 and 15 smallest is 10
        System.out.println(si.higher(5));
        
        // Value <= 5
        System.out.println(si.floor(5));
        
        // Value >= 5
        System.out.println(si.ceiling(5));
    }
}
