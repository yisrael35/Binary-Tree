#include <iostream>
#include "Btree.h"
using namespace std;
/*yisrael bar 13-14/12/19
update 20-21/12/2019
id 205462948
*/



int main(){
    int size=1;
    //create the array
    Btree ** bt1=(Btree**)malloc(sizeof(Btree)*size+1);
    if(bt1==NULL){
      printf("error could not alocate memmory");
      exit(1);
    }
    int numOfTree=0,order=0,value=0;
    

    while (order!=-1)
    {
    int temp=0;
    cin >> temp;
    if (temp==-1)
    {
      // order =-1;
      break;
    }else
    {
      numOfTree=temp;
      cin >> order;
      if (order==1 || order==7)
      {
        cin >> value;
      }
  
    }
    //chaghe the size of the array
    if (numOfTree>size ){

    bt1=(Btree**)realloc(bt1,(numOfTree+1)*sizeof(Btree));
    size=numOfTree;
    }
    if (bt1==NULL)
    {
      printf("error could not alocete mammory");
      exit(1);
    }
    
    switch (order){
    case 0:
    // set new tree in the array
    bt1[numOfTree]=new Btree();
    
    break;
    case 1:
    //insert to the right place in the tree
        bt1[numOfTree]->insert(value);
    break;
    case 2:
    //find the smallest value in the tree
          cout << ">>";
       cout <<  bt1[numOfTree]->smallest() << endl;
    break;
    case 4:
    //check if its a binary tree
          cout << ">>";
       cout <<  bt1[numOfTree]->checkBinary() << endl;
    break;
        case 5:
    //print  how deep is the tree
          cout << ">>";
    cout <<  bt1[numOfTree]->treeDepth() << endl;
    break;
    case 6:
    //do a mirror to a tree
      bt1[numOfTree]->mirror();
    break;
    case 7:
    //check if the two trees are the same
          cout << ">>";
       cout <<  bt1[numOfTree]->checkEqual(bt1[value]) << endl;
    break;
    case 9:
    //print a specifc tree
      cout << ">>";
     bt1[numOfTree]->print();
      cout << " "<<endl;    
    break;
    case -1:
    order =-1;
    break;
    default :
     order =-1;
    //  break;
      }
    }
    //call to the Destructor for each tree and clean it in dfs 
    for(int i=0; i<size; i++)
    delete(bt1[i]);
    //free the malloc
     free(bt1);
    return 0;
}