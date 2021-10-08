#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(){
        data=0;
        left=right=NULL;
    }

    node(int d){
        data=d;
        left=right=NULL;
    }

    node(int d,node* l,node* r){
        data=d;
        left=l;
        right=r;
    }
};


int main()
{
    
    return 0;
}