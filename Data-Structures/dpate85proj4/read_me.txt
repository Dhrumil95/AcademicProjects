

Name: Dhrumil Patel (dpate85)

-----------------------------------------------

Describe what augmentations to the bst data structures you made to complete the 
project -- i.e., what typedefs did you change and why?
I have changed bst_node and bst .In bst I have added three variables int bst_size; int bst_min; int bst_max; to maintain size ,maximum and minimum element of tree. After every insertion and deletion these variables are updated so that bst_size(), bst_min() bst_max()  functions runs in O(1) time complexity.The book keeping information i.e no of nodes in a node subtree is maintained in int n_nodes variable which is added to bst_node struct.This addition of n_nodes is nessessory for functions int bst_get_ith(BST_PTR t,int i), int bst_num_geq(BST_PTR t, int x) and int bst_num_leq(BST_PTR t, int x) to run in O(h)
time complexity. the n_nodes variable of struct bst_node is updated in insertion deletion and insert_from_sorted_arr() functions






-----------------------------------------------
Which functions did you need to modify as a result of the augmentations from the previous
question?
bst_insert(BST_PTR t, int x) ,NODE * insert(NODE *r, int x,int * is_inserted),
bst_create(),bst_remove(BST_PTR t, int x),NODE *remove_r(NODE *r, int x, int *success),BST_PTR bst_from_sorted_arr(int *a, int n), NODE * from_arr(int *a, int n) are the functions which are modified due to augmentations  









-----------------------------------------------
For each function from the previous question, how did you ensure that the (assymptotic) runtime 
remained the same?

n_nodes for each node is updated after each recursive call in insert and delete so the time complexity still remains O(h) for deletion and insertion .
in each insertion bst_min and bst_max are updated depending upon new value inserted which is a linear time job.

In deletion if max of min value is deleted only then max_h or min_h is called to get new bst_min or bst_max respectively.
both min_h and max_h take O(h) time and deletion also takes O(h)
time so O(h)+O(h) is still O(h) assymptoticly so runtime remains the same. 
In built_from_sorted_arr  in every recursive call to form_arr n_node variable is updated takes O(1) time .



-----------------------------------------------
For each of the assigned functions, tell us how far you got using the choices 0-5 and
answer the given questions.  


0:  didn't get started
1:  started, but far from working
2:  have implementation but only works for simple cases
3:  finished and I think it works most of the time but not sure the runtime req is met. 
4:  finished and I think it works most of the time and I'm sure my design leads to 
       the correct runtime (even if I still have a few bugs).
5:  finished and confident on correctness and runtime requirements


bst_to_array level of completion:  _5__________  


-----------------------------------------------
bst_get_ith level of completion:  __5_________  

    How did you ensure O(h) runtime?

    ANSWER:As I have n_nodes variable for each node which tells no of nodes in the node subtree inclusive of it.if the no of nodes in left child + 1 == i then given node has ith value .else if nodes in left child is less then i we search for (i- nodes in left child - 1)th element in  right child
if(nodes in left child > i) then we search for ith in left child 
hence at max we have to go to the leaf in O(h) time complexity

-----------------------------------------------
bst_get_nearest level of completion:  ____5_______  

    How did you ensure O(h) runtime?

    ANSWER:First set closest value equal to root value, traversing the tree depending upon variable value while checking if the abs difference between closest value and the given variable is lesser than the difference between current node value and given variable  and updating closest value accordingly.As this function is similer to search so its time complexity is O(h)
  
-----------------------------------------------
bst_num_geq level of completion:  _____5______  

    How did you ensure O(h) runtime?

    ANSWER:Initialize a variable num_of_values to zero.
take the root node as traverse node and see if its value is greater than given integer x then we add n_nodes in right child +1 to num_of_values and traverse left child of traverse node.
if its value is less than given integer x then we traverse right child of traverse node .if its value is equal to integer x then we add n_nodes in right child +1 to num_of_values and break the loop.And we return num_of_values Here due to n_nodes value in each node we dont have to see for how many are there in the subtree.We only traverse either child in the loop so time complexity become O(h)

-----------------------------------------------
bst_num_leq level of completion:  ______5______

    How did you ensure O(h) runtime?

    ANSWER:Here also we use n_node value in bst_node to see the no of values less than equal to given variable x. This function is very similar to bst_num_geq .For the same reason it is O(h)

-----------------------------------------------
EXTRA CREDIT FUNCTIONS:

bst_min level of completion:  _______5_____

    How did you ensure O(1) runtime?

    ANSWER:By storing bst_min variable is struct bst already described above

-----------------------------------------------
bst_max level of completion:  _______5_____

    How did you ensure O(1) runtime?

    ANSWER:By storing bst_max variable is struct bst already described above

----------------------------------------------

Write a few sentences describing how you tested your solutions.  Are there
any tests that in retrospect you wish you'd done?
