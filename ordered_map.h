template<class T,class U> class ordered_map{

    class node{ 

        public:

        T key;
        U value;
        node *left;
        node *right;
        node *parent;
        long height;
        
        node(T k, U v, node* par){
            key=k;
            value=v;
            left=NULL;
            right=NULL;
            parent=par;
            height=1;
        }
    };
    
    node* root;
    long siz;

    node* bstinsert(T k, U v){

        if(root==NULL){
            root=new node(k,v,NULL);
            siz++;
            return root;
        }
        node *temp=root,*temp2;

        while(temp){
            if(temp->key==k){
                temp->value=v;
                return NULL;
            }
            if(k<temp->key){
                temp2=temp;
                temp=temp->left;
            }
            else{
                temp2=temp;
                temp=temp->right;
            }
        }
        if(!temp2->left&&k<temp2->key){
            temp2->left=new node(k,v,temp2);
            return temp2->left;
        }
        else{
            temp2->right=new node(k,v,temp2);
            return temp2->right;
        }
    }   

    bool isleft(node* nde){

        if(nde->parent)
            if(nde->parent->key>nde->key)return true;
            else return false;
        return true;
    }

    void leftrotate(node* nde){

        node *gpar=nde->parent->parent;
        node *par=nde->parent;
        if(gpar){
            if(isleft(par))
                gpar->left=nde;
            else 
                gpar->right=nde;
        }
        nde->parent=gpar;
        par->right=nde->left;
        par->parent=nde;
        if(nde->left)
            nde->left->parent=par;
        nde->left=par;
        if(par==root)
            root=nde;

        if(par->left&&par->right)
            par->height=max(par->left->height,par->right->height)+1;
        else if(par->left)
            par->height=par->left->height+1;
        else if(par->right)
            par->height=par->right->height+1;
        else 
            par->height=1;
        if(nde->left&&nde->right)
            nde->height=max(nde->left->height,nde->right->height)+1;
        else if(nde->left)
            nde->height=nde->left->height+1;
        else if(nde->right)
            nde->height=nde->right->height+1;
        else nde->height=1;
    }

    void rightrotate(node* nde){
        node *gpar=nde->parent->parent;
        node *par=nde->parent;
        if(gpar){
            if(isleft(par))
                gpar->left=nde;
            else 
                gpar->right=nde;
        }
        nde->parent=gpar;
        par->left=nde->right;
        if(nde->right)
            nde->right->parent=par;
        nde->right=par;
        par->parent=nde;
        if(par==root)
            root=nde;
        if(par->left&&par->right)
            par->height=max(par->left->height,par->right->height)+1;
        else if(par->left)
            par->height=par->left->height+1;
        else if(par->right)
            par->height=par->right->height+1;
        else 
            par->height=1;
        if(nde->left&&nde->right)
            nde->height=max(nde->left->height,nde->right->height)+1;
        else if(nde->left)
            nde->height=nde->left->height+1;
        else if(nde->right)
            nde->height=nde->right->height+1;
        else nde->height=1;

    }

    node* balancethetree(node* nde){
        node* par=nde->parent;
        if(nde->left&&nde->right){
            if(nde->left->height>nde->right->height){
                node* lftchld=nde->left;
                if(lftchld->left&&lftchld->right){
                    if(lftchld->left->height<lftchld->right->height)
                        leftrotate(lftchld->right);
                }
                else if(lftchld->right){
                    leftrotate(lftchld->right);
                }
                rightrotate(lftchld);       
            }
            else{
                node* rghtchld=nde->right;
                if(rghtchld->left&&rghtchld->right){
                    if(rghtchld->left->height>rghtchld->right->height)
                        rightrotate(rghtchld->left);
                }
                else if(rghtchld->left){
                    rightrotate(rghtchld->left);
                }
                leftrotate(rghtchld);
            }
        }
        else if(nde->left){
            node* lftchld=nde->left;
            if(lftchld->left&&lftchld->right){
                if(lftchld->left->height<lftchld->right->height)
                    leftrotate(lftchld->right);
            }
            else if(lftchld->right){
                leftrotate(lftchld->right);
            }
            rightrotate(lftchld);
        }
        else if(nde->right){
            node* rghtchld=nde->right;
            if(rghtchld->left&&rghtchld->right){
                if(rghtchld->left->height>rghtchld->right->height)
                    rightrotate(rghtchld->left);
            }
            else if(rghtchld->left){
                rightrotate(rghtchld->left);
            }
            leftrotate(rghtchld);
        }
        else ;
        return par;
    }

    void updateheight(node* nde){

        node* temp=nde;
        while(temp){
            if(temp->left&&temp->right){
                temp->height=max(temp->left->height,temp->right->height)+1;
                if(abs(temp->left->height-temp->right->height)>1)
                    temp=balancethetree(temp);
                else temp=temp->parent;
            }
            else if(temp->left){
                temp->height=temp->left->height+1;
                if(temp->left->height>1)
                    temp=balancethetree(temp);
                else temp=temp->parent;
            }
            else if(temp->right){
                temp->height=temp->right->height+1;
                if(temp->right->height>1)
                    temp=balancethetree(temp);
                else temp=temp->parent;
            }
            else{
                temp->height=1;
                temp=temp->parent;
            }
        }
    }

    void utilinorder(node *root){
        if(!root)return;
        utilinorder(root->left);
        cout<<root->key<<" ";
        utilinorder(root->right);
    }

    node* utilfind(node *root,T k){
        if(root==NULL)return NULL;
        if(root->key==k)return root;
        if(k<root->key)return utilfind(root->left,k);
        if(k>root->key)return utilfind(root->right,k);
        return NULL;
    }

    void for_none_or_one(node* nde){
        node* par=nde->parent;
        bool b=isleft(nde);
        if(!nde->left&&!nde->right){
            if(b)
                par->left=NULL;
            else 
                par->right=NULL;
        }
        if(nde->left){
            if(b)
                par->left=nde->left;
            else
                par->right=nde->left;
            nde->left->parent=par;
        }
        if(nde->right){
            if(b)
                par->left=nde->right;
            else 
                par->right=nde->right;
            nde->right->parent=par;
        }
        free(nde);
    }

    node* lsuccesor(node* nde){
        node* temp=nde;
        while(nde){
            temp=nde;
            nde=nde->left;
        }
        return temp;
    }

    void util_clear(node* nde){
        if(!nde)return;
        util_clear(nde->left);
        util_clear(nde->right);
        free(nde);
    }

    public:

    ordered_map(){
        root=NULL;
        siz=0;
    }

    node* insert(T k,U v){
     
        node* nde=bstinsert(k,v);
        if(!nde||nde==root)return NULL;
        updateheight(nde);
        siz++;
        return nde;
    }

    void inorder(){
        utilinorder(root);
    }

    bool find(T k){
        if(utilfind(root,k))return true;
        else return false;
    }

    long size(){return siz;}

    U &operator [](T k){
        node* temp=this->utilfind(root,k);
        if(!temp){
            U v;
            temp=this->insert(k,v);
        }
        return temp->value;
    }

    void erase(T k){

        node* todel=this->utilfind(root,k);
        if(!todel)return;
        node* par=todel->parent;
        if(todel->left&&todel->right){
            node* temp=lsuccesor(todel->right);
            todel->key=temp->key;
            todel->value=temp->value;
            par=temp->parent;
            for_none_or_one(temp);
        }
        else{
            for_none_or_one(todel);
        }
        updateheight(par);
        siz--;
    }

    void clear(){
        util_clear(root);
        siz=0;
        root=NULL;
    }

};
