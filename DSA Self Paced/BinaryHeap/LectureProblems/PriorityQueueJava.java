
// Java program to demonstrate working of
// PriorityQueue in Java
import java.util.*;

public class PriorityQueueJava {
    public static void main(String args[]) {

        //MAXHEAP EXAMPLE
        // Creating empty priority queue Default in Java is MinHeap
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

        // Adding items to the pQueue using add()
        pq.add(10);
        pq.add(20);
        pq.add(15);

        System.out.println("Max Heap: ");
        // Printing the top element of PriorityQueue
        System.out.println(pq.peek());
        
        // Printing the top element and removing it
        // from the PriorityQueue container
        System.out.println(pq.poll());
        
        // Printing the top element again
        System.out.println(pq.peek());

        //Traversing PQ
        System.out.println();
        while(!pq.isEmpty())
        {
            System.out.print(pq.poll() + " ");
        }

        //MINHEAP EXAMPLE
        // Creating empty priority queue Min Heap
        PriorityQueue<Integer> pqm
        = new PriorityQueue<Integer>(
            Collections.reverseOrder());
            
            // Adding items to the pQueue using add()
            pqm.add(10);
            pqm.add(20);
            pqm.add(15);
            
            // Above PriorityQueue is stored as following
            //       20
            //      /  \
            //    10    15
            
        System.out.println("\nMin Heap: ");
        // Printing the top element of PriorityQueue
        System.out.println(pqm.peek());

        // Printing the top element and removing it
        // from the PriorityQueue container
        System.out.println(pqm.poll());

        // Post poll() PriorityQueue looks like
        //       15
        //      /  
        //    10   

        // Printing the top element again
        System.out.println(pqm.peek());

        //Traversing PQ
        System.out.println();
        while(!pqm.isEmpty())
        {
            System.out.print(pqm.poll() + " ");
        }

    }
}
