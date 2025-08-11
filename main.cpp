#include<iostream>
#include "binarysearchtree.cpp"
#include "binarysearchtree.h"

using namespace std;

void blt(TreeType<int>& tree, int seq[], int l, int r){
    if(l>r) return;
    int mid = (l+r)/2;
    tree.InsertItem(seq[mid]);
    blt(tree, seq, l, mid-1);
    blt(tree, seq, mid+1, r);
}

int main(){
    TreeType<int> tree;
    cout<<(tree.IsEmpty()? "Empty":"Not")<<endl;
    int val[] = {4, 9, 2, 7, 3, 11, 17, 0, 5, 1};
    for(int i: val) tree.InsertItem(i);
    cout<<(tree.IsEmpty()? "Empty":"Not")<<endl;
    cout<<tree.LengthIs()<<endl;
    int s=9; bool found=false;
    tree.RetrieveItem(s, found);
    cout<<(found ? "Found": "Not Found")<<endl;
    {int s=13; bool found=false;
    tree.RetrieveItem(s, found);
    cout<<(found ? "Found": "Not Found")<<endl;}
    {int v; bool finished=false;
    tree.ResetTree(IN_ORDER);
    while(!finished){
        tree.GetNextItem(v,IN_ORDER, finished);
        cout<<v<<" ";
    }cout<<endl;}
    {int v; bool finished=false;
    tree.ResetTree(PRE_ORDER);
    while(!finished){
        tree.GetNextItem(v, PRE_ORDER, finished);
        cout<<v<<" ";
    }cout<<endl;}
    {int v; bool finished=false;
        tree.ResetTree(POST_ORDER);
    while(!finished){
        tree.GetNextItem(v, POST_ORDER, finished);
        cout<<v<<" ";
    }cout<<endl;}
    tree.MakeEmpty();
    int seq[] = {11, 9, 4, 2, 7, 3, 17, 0, 5, 1};
    int n = sizeof(seq)/sizeof(seq[0]);
    for(int i:seq) tree.InsertItem(i);
    int j=0;
    int v; bool finished=false;
    tree.ResetTree(IN_ORDER);
    while(!finished){
        tree.GetNextItem(seq[j], IN_ORDER, finished);
        if(!finished) j++;
    }for(int i:seq) cout<<i<<" ";cout<<endl;
    TreeType<int> bl;
    blt(bl, seq, 0, n-1);
    int v1; bool finished1=false;
    bl.ResetTree(PRE_ORDER);
    while(!finished1){
        bl.GetNextItem(v1, PRE_ORDER, finished1);
        cout<<v1<<" ";
    }cout<<endl;
    return 0;
}
