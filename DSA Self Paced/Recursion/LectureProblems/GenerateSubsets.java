public class GenerateSubsets {
    
    static void generateSubsets(String str, int start, String current)
    {
        if (str.length() == start)
        {
            if (current == "")
                System.out.print("{Empty Set}" + " ");
            
            else
                System.out.print(current + " ");
            
            return;
        }
    
        generateSubsets(str, start+1, current);
        generateSubsets(str, start+1, current + str.charAt(start));
    }
    

    public static void main(String[] args) {
        
        String str = "ABC";
        generateSubsets(str, 0, "");
    }
}
