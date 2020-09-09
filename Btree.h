#ifndef it
#define it
/*yisrael bar 13-14/12/19
update 20-21/12/2019
*/
struct node {
    int value;
    node *left;
    node *right;
   
};

class Btree {
public:
    
    Btree();
    ~Btree();
    void insert(int key);
    void insertMirror(int key);
    void print();
    int smallest ();
    int checkBinary();
    int treeDepth();
    void mirror();
    int checkEqual(Btree * other);
private:
    node *root;
    void delet_haelper(node * root);
    void insert(int key, node *leaf);
    void insertMirror(int key, node *leaf);

    void print(node *leaf);
    void doTheMirror(node *root, Btree * newRoot);
    
   
};


#endif