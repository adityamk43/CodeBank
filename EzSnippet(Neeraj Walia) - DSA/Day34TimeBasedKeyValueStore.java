import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 34
 * @author ADITYA BHARDWAJ
 * 03/09/2023 03:45PM
 * 
 * @description
 * 981. Time Based Key-Value Store
    Medium
    4.4K
    429
    Companies
    Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

    Implement the TimeMap class:

    TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
    String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
    

    Example 1:

    Input
    ["TimeMap", "set", "get", "get", "set", "get", "get"]
    [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
    Output
    [null, null, "bar", "bar", null, "bar2", "bar2"]

    Explanation
    TimeMap timeMap = new TimeMap();
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    timeMap.get("foo", 1);         // return "bar"
    timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    timeMap.get("foo", 4);         // return "bar2"
    timeMap.get("foo", 5);         // return "bar2"
    

    Constraints:

    1 <= key.length, value.length <= 100
    key and value consist of lowercase English letters and digits.
    1 <= timestamp <= 107
    All the timestamps timestamp of set are strictly increasing.
    At most 2 * 105 calls will be made to set and get.
    Accepted
    351.3K
    Submissions
    692.5K
    Acceptance Rate
    50.7%

    @returns
    Accepted

    Runtime
    Details
    129ms
    Beats 74.33%of users with Java

    Memory
    Details
    118.17MB
    Beats 86.75%of users with Java
 */

//  Creating our custom Pair class as for some reason "javafx.util.Pair" class is not working
class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) obj;
        return Objects.equals(key, pair.key) &&
                Objects.equals(value, pair.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(key, value);
    }
}

// Approach: Using Array + Binary Search
class TimeMap {

    HashMap<String, ArrayList<Pair<Integer, String>>> timeMap;

    public TimeMap() {
        timeMap = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!timeMap.containsKey(key))
            timeMap.put(key, new ArrayList<>());
        
        timeMap.get(key).add(new Pair<>(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        
        if (!timeMap.containsKey(key))
            return "";

        if (timestamp < timeMap.get(key).get(0).getKey())
            return "";

        // Binary Search
        int left=0;
        int right=timeMap.get(key).size();

        while(left < right)
        {
            int mid = (left+right)/2;

            if (timeMap.get(key).get(mid).getKey()<=timestamp)
                left=mid+1;
            else
                right=mid;
        }

        if (right==0)
            return "";
        
        else
            return timeMap.get(key).get(right-1).getValue();
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
class Day34TimeBasedKeyValueStore{
    public static void main(String args[])
    {
        // Test Case

        // Case 1
        TimeMap obj = new TimeMap();
        
        obj.set("foo", "bar", 1);
        System.out.println(obj.get("foo", 1));
        System.out.println(obj.get("foo", 3));
        obj.set("foo", "bar2",4);
        System.out.println(obj.get("foo", 4));
        System.out.println(obj.get("foo", 5));

    }
}