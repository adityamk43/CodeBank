import java.util.HashMap;

/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 45
 * @author ADITYA BHARDWAJ
 *         14/09/2023 9:55PM
 * 
 * @description
 *              146. LRU Cache
 *              Solved
 *              Medium
 *              Topics
 *              Companies
 *              Design a data structure that follows the constraints of a Least
 *              Recently Used (LRU) cache.
 * 
 *              Implement the LRUCache class:
 * 
 *              LRUCache(int capacity) Initialize the LRU cache with positive
 *              size capacity.
 *              int get(int key) Return the value of the key if the key exists,
 *              otherwise return -1.
 *              void put(int key, int value) Update the value of the key if the
 *              key exists. Otherwise, add the key-value pair to the cache. If
 *              the number of keys exceeds the capacity from this operation,
 *              evict the least recently used key.
 *              The functions get and put must each run in O(1) average time
 *              complexity.
 * 
 * 
 * 
 *              Example 1:
 * 
 *              Input
 *              ["LRUCache", "put", "put", "get", "put", "get", "put", "get",
 *              "get", "get"]
 *              [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 *              Output
 *              [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 *              Explanation
 *              LRUCache lRUCache = new LRUCache(2);
 *              lRUCache.put(1, 1); // cache is {1=1}
 *              lRUCache.put(2, 2); // cache is {1=1, 2=2}
 *              lRUCache.get(1); // return 1
 *              lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is
 *              {1=1, 3=3}
 *              lRUCache.get(2); // returns -1 (not found)
 *              lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is
 *              {4=4, 3=3}
 *              lRUCache.get(1); // return -1 (not found)
 *              lRUCache.get(3); // return 3
 *              lRUCache.get(4); // return 4
 * 
 * 
 *              Constraints:
 * 
 *              1 <= capacity <= 3000
 *              0 <= key <= 104
 *              0 <= value <= 105
 *              At most 2 * 105 calls will be made to get and put.
 *              Accepted
 *              1.4M
 *              Submissions
 *              3.4M
 *              Acceptance Rate
 *              41.6%
 * 
 * @returns
 *          Accepted
 * 
 *          Runtime
 *          Details
 *          47ms
 *          Beats 73.17%of users with Java
 * 
 *          Memory
 *          Details
 *          116.37MB
 *          Beats 85.99%of users with Java
 * 
 * 
 */

class LRUCache {

    class Node {
        int key;
        int value;
        Node next;
        Node prev;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return "[key:" + key + " " + ", value:" + value +  " ]";
        }

    }

    private final int capacity;
    private Node head;
    private Node tail;
    private HashMap<Integer, Node> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);

        head.next = tail;
        tail.prev = head;

        map = new HashMap<>();
    }

    public void addNode(Node newNode) {
        Node temp = head.next;
        head.next = newNode;
        newNode.next = temp;

        newNode.prev = head;
        temp.prev = newNode;
    }

    public void deleteNode(Node currNode) {
        Node next = currNode.next;
        Node prev = currNode.prev;

        prev.next = next;
        next.prev = prev;

        currNode.next = null;
        currNode.prev = null;

    }

    public int get(int key) {
        if (map.containsKey(key)) {
            Node curr = map.get(key);
            int value = curr.value;

            map.remove(key);
            deleteNode(curr);

            addNode(curr);

            map.put(key, head.next);

            return value;
        }

        return -1;
    }

    public void put(int key, int value) {

        if (map.containsKey(key)) {
            Node prev = map.get(key);
            deleteNode(prev);
            map.remove(key);
        }

        if (map.size() == capacity) {
            map.remove(tail.prev.key);
            deleteNode(tail.prev);
        }

        addNode(new Node(key, value));

        map.put(key, head.next);

    }

    // custom print Map for printing hashmap just to get idea
    public void printMap() {
        System.out.println(map);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

public class Day45LRUCache {
    public static void main(String[] args) {

        // Test Case

        // Case 1
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // cache is {1=1}
        lRUCache.put(2, 2); // cache is {1=1, 2=2}
        lRUCache.get(1); // return 1
        lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        lRUCache.get(2); // returns -1 (not found)
        lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        lRUCache.get(1); // return -1 (not found)
        lRUCache.get(3); // return 3
        lRUCache.get(4); // return 4

        // custom print Map for printing hashmap just to get idea
        lRUCache.printMap();
    }
}
