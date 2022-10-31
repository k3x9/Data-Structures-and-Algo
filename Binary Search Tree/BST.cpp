class bst{
	private:
		struct node{
			int data;
			node *left = NULL;
			node *right = NULL;
		};
	public:
		node *root = NULL;

		void insert(int element){
			node *n = new node;
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

		void inorder(node *temp = root){
			if(temp){
				inorder(temp->left);
				cout<<temp->data<<" ";
				inorder(temp->right);
			}
		}
		//O(N)

		void preorder(node *temp = root){
			if(temp){
				cout<<temp->data<<" ";
				preorder(temp->left);
				preorder(temp->right);
			}
		}
		//O(N)

		void postorder(node *temp = root){
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
			node *location = find(element);
			if(location){							//Finding next successor
				node *temp = location->right;
				node *p = NULL;
				while(temp->left){
					p = temp;
					temp = temp->left;
				}
				location->data = temp->data;
				p->left = temp->right;
				temp->right = NULL;
				free(temp);
			}
		}
};
