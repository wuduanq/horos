#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LinkNode;

void InitLink(LinkNode*& L){
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void CreateLink(LinkNode*& L, ElemType a[], int n){
    LinkNode* T;
    for(int i=0; i<n; i++){
        T = (LinkNode*)malloc(sizeof(LinkNode));
        T->data = a[i];
        T->next = L->next;
        L->next = T;
    }
}

void HeadIns(LinkNode*& L, ElemType a){
    LinkNode* T;
    T = (LinkNode*)malloc(sizeof(LinkNode));
    T->data = a;
    T->next = L->next;
    L->next = T;
}

void DispLink(LinkNode* L){
    while(L->next!=NULL){
        cout << L->next->data << endl;
        L = L->next;
    }
}

LinkNode* NegativeFormer(LinkNode*& L){
    LinkNode* R = L; // Replicas
    LinkNode* T = L; // Temp pointer
    LinkNode* S = T; // Successor of temp pointer
    while(S->next!=NULL){
        T = S->next; // refresh temp pointer
        if(T->data<0){
            S->next = T->next; // delete the node the temp pointer points now
            T->next = L->next;
            L->next = T; // head insert
            L = L->next; // move negative integers sequentially
        }else{
            S = T; // normal pointer progression
        }
    }
    return R;
}

int main(){
    LinkNode* L;
    InitLink(L);
    int num;
    ElemType element;

    cout << "Please enter an integer to set the array's length:" << endl;
    cin >> num;
    cout << "Please enter some array elements one by one in a newline:" << endl;
    for (int i=0; i<num; i++){
        cin >> element;
        HeadIns(L, element);
    }

    cout << "The moved LinkNode:" << endl;
    // DispLink(L);
    DispLink(NegativeFormer(L));
    cout << "As shown, the time complexity is O(n); the space complexity if O(1)" << endl;


    return 0;
}