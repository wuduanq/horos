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

    while(true){
        if(L->next==NULL){
            break;
        }
        LinkNode* temp = L->next;
        free(L);
        L = temp;
    }
}

LinkNode* ReverseMerge(LinkNode* L, LinkNode* M){
    LinkNode* t1;
    LinkNode* t2;
    LinkNode* C;
    InitLink(C);

    while(L->next!=NULL && M->next!=NULL){
        if(L->next->data < M->next->data){
            t1 = L->next;
            L->next = t1->next;
            t1->next = C->next;
            C->next = t1;
        }else{
            t2 = M->next;
            M->next = t2->next;
            t2->next = C->next;
            C->next = t2;
        }
    }

    while(L->next!=NULL){
        t1 = L->next;
        L->next = t1->next;
        t1->next = C->next;
        C->next = t1;
    }

    while(M->next!=NULL){
        t2 = M->next;
        M->next = t2->next;
        t2->next = C->next;
        C->next = t2;
    }

    free(L);
    free(M);
    return C;
}

int main(){
    LinkNode* L;
    LinkNode* M;
    InitLink(L);
    InitLink(M);
    int num;
    ElemType element;

    cout << "Please enter an integer to set the array's length:" << endl;
    cin >> num;
    cout << "Please enter some array elements one by one in a newline:" << endl;
    for (int i=0; i<num; i++){
        cin >> element;
        HeadIns(L, element);
    }
    // DispLink(L);

    cout << "Please enter an integer to set the array's length:" << endl;
    cin >> num;
    cout << "Please enter some array elements one by one in a newline:" << endl;
    for (int i=0; i<num; i++){
        cin >> element;
        HeadIns(M, element);
    }
    // DispLink(M);

    cout << "The merged LinkNode:" << endl;
    DispLink(ReverseMerge(L, M));
    cout << "As shown, the time complexity is O(n); the space complexity if O(1)" << endl;

    return 0;
}