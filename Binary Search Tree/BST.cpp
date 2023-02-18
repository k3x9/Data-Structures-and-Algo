struct node{
			int data;
			node *left = NULL;
			node *right = NULL;
		};
class bst{
	public:
		node *root = NULL;   	 	//One can access root value using bst.root
		
		void insert(int element){
			node *n = new node;
			n->data = element;
			if(root == NULL){
				root = n;
				return;
			}

			node *t = root;
			node *p = NULL;							// Acts as t's parent
			while(t){								//travelling through tree using variable t.
				p=t;								
				if(t->data > element) t = t->left;	//If current value of pointer(t) is greater than element then the element should be inserted in the left side of pointer.
				else t = t->right;					//And vice-versa.
			}		

			if(p->data > element) p->left = n;
			else p->right = n;
		}
		//O(h)   h : Height of tree

		void inorder(node *temp){
			if(temp){
				inorder(temp->left);
				cout<<temp->data<<" ";
				inorder(temp->right);
			}
		}
		//O(N)

		void preorder(node *temp){
			if(temp){
				cout<<temp->data<<" ";
				preorder(temp->left);
				preorder(temp->right);
			}
		}
		//O(N)

		void postorder(node *temp){
			if(temp){
				postorder(temp->left);
				postorder(temp->right);
				cout<<temp->data<<" ";
			}
		}
		//O(N)

		node *find(int element){
			node *temp = root;
			while(temp){
				if(temp->data == element) return temp;
				if(temp->data > element) temp = temp->left;
				else temp = temp->right;
			}
			return NULL;
		}
		//O(h)

		void erase(int element){
			node *location = root;
			node *p = NULL;
			while(location->data != element){
				p=location;
				if(location->data > element) location = location->left;
				else location = location->right;
			}
			if(location == NULL) return;

			if(location->left==NULL && location->right==NULL){
				if(p==NULL) root=NULL;
				else{
					if(p->data > element) p->left = NULL;
					else p->right = NULL;
					free(location);
				}
			}
			else if(location->left==NULL && location->right){
				if(p==NULL){
					root = root->right;
					free(location);
				}
				else{
					if(p->data > element) p->left = location->right;
					else p->right = location->right;
					free(location);
				}
			}
			else if(location->left && location->right==NULL){
				if(p==NULL){
					root = root->left;
					free(location);
				}
				else{
					if(p->data > element) p->left = location->left;
					else p->right = location->left;
					free(location);
				}
			}
			else{
				node *temp = location->right;
				node *p1 = location;
				while(temp->left){			//Finding next successor
					p1=temp;
					temp = temp->left;
				}
				location->data = temp->data;
				if(p1 == location){
					location->right = temp->right;
					temp->right=NULL;
					free(temp);
				}
				else{
					p1->left = temp->right;
					temp->right = NULL;
					free(temp);
				}
			}
		}
		//O(h)
};
