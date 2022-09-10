import java.util.HashMap;

class Node
{

    int key;
    Node left;
    Node right;

    Node(int key)
    {
        this.key = key;;
    }
}

class BinaryTreeFromPreorderAndInOrder {

    static int preIndex = 0;
    static Node constructTree(int pre[], int in[], HashMap<Integer, Integer> inorderMap, int is, int ie)
    {
        if (is > ie)
            return null;
        
        //as explained earlier, preorder has stores data as first root then left then right child node
        Node root = new Node(pre[preIndex++]);

        // O(1) operation to retreive value using key from hashmap
        int inIndex = inorderMap.get(root.key);

        //recursive call for left and right child nodes untill whole tree is fullly constructed, then we return the root node to the parent call..
        root.left = constructTree(pre, in, inorderMap, is, inIndex-1);
        root.right = constructTree(pre, in, inorderMap, inIndex+1, ie);

        return root;
    }



    static void inorder(Node root){
        if(root!=null){
            inorder(root.left);
            System.out.print(root.key + " ");
            inorder(root.right);    
        }
    }  

    public static void main(String[] args) {
            int in[]={20,10,40,30,50};
            int pre[]={10,20,30,40,50};

            int n=in.length;

            //This hasing technique is specifically to construct tree in O(n) time instead of O(n^2)
            HashMap<Integer, Integer> inorderMap = new HashMap<>();

            for (int i=0; i<n; i++)
                inorderMap.put(in[i], i);

            Node root = constructTree(pre, in, inorderMap, 0, n-1);

            inorder(root);

    }
}