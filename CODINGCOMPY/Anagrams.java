import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.Map.Entry;
import java.util.*;

public class Anagrams {

    static boolean AnagramChecker(String s1, String s2)
    {
        HashMap<Character, Integer> h = new HashMap<>();

        if (s1.length()==s2.length())
        {
            for (int i=0; i<s1.length(); i++)
            {
                h.put(s1.charAt(i), 1);
            }

            for (int i=0; i<s2.length(); i++)
            {
                if (h.containsKey(s2.charAt(i)))
                {
                    h.merge(s2.charAt(i), 1, Integer::sum);
                }
                else
                    h.put(s2.charAt(i), 1);
            }


            Set<Entry<Character, Integer>> set=h.entrySet();

            Iterator<Entry<Character, Integer>> i = set.iterator();

            while(i.hasNext())
            {
                Map.Entry<Character, Integer> m = (Map.Entry<Character, Integer>) i.next();

                // System.out.print(m.getKey() + ":");
                // System.out.print(m.getValue() + "\n");

                if (m.getValue().equals(Integer.valueOf(1)))
                    return false;
            }

            return true;
        }
        else
        {
            return false;
        }

    }

    public static void main(String args[])
    {
        String s1="race";
        String s2="care";

        if (AnagramChecker(s1, s2) == true)
            System.out.println("It is an Anagram");
            else
            System.out.println("It is not an Anagram");

    }
}
