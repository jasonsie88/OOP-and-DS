#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tree{
	int data;
	struct tree *llink;
	struct tree *rlink;
}node_type;
class bintree{
	private:
		node_type *root;
		node_type *ptr;
	public:
		bintree(){
			root=NULL;
		}
		void acess(int dataOftree){
			node_type *node, *prev;
			ptr=new node_type;
			ptr->data=dataOftree;
			ptr->llink=ptr->rlink=NULL;
			if(root==NULL){
				root=ptr;
			}else{
				node=root;
				while(node != NULL){
					prev=node;
					if((ptr->data)-(node->data)<0){
						node=node->llink;
					}else{
						node=node->rlink;
					}
				}
				if((ptr->data)-(prev->data)<0){
					prev->llink=ptr;
				}else{
					prev->rlink=ptr;
				}
			}
		}
		void postorder(node_type *node){
			if(node!=NULL){
				postorder(node->llink);
				postorder(node->rlink);
				cout<<node->data<<endl;
			}
		}
		void show_tree(){
			postorder(root);
		}
};
int main() {
    int input;
    bintree obj;
	while(cin>>input){
		obj.acess(input);
	}
		obj.show_tree();
    return 0;
}
