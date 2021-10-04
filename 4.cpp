#define Size 50
#include <iostream>
using namespace std;
typedef int DataType;

typedef struct
{
    DataType data[Size];
    int length;
} Array;

void CreateArray(Array*& L, DataType element){
    L->data[L->length] = element;
    L->length++;
}

void InitArray(Array*& L){
    L = (Array*)malloc(sizeof(Array));
    L->length = 0;
}

void DispArray(Array* L){
    for(int i=0; i<L->length; i++){
        cout << L->data[i] << endl;
    }
    free(L);
}

Array* FindMerge(Array*& L, Array*& M){
    Array* A;
    InitArray(A);
    int l = 0, m = 0, a = 0;
    while(l<L->length && m<M->length){
        if(L->data[l]<M->data[m]){
            A->data[a] = L->data[l];
            a++; l++;
        }
        else if(L->data[l]==M->data[m]){
            A->data[a] = M->data[m];
            a++; l++; m++;
        }
        else{
            A->data[a] = M->data[m];
            a++; m++;
        }
    }

    while(l<L->length){
        A->data[a] = L->data[l];
            a++; l++;
    }
    
    while(m<M->length){
        A->data[a] = M->data[m];
            a++; m++;
    }

    A->length = a;

    return A;
}

int main(){
    Array* L;
    Array* M;
    InitArray(L);
    InitArray(M);
    DataType element;
    int num;

    cout << "Please enter an integer to set the array's length(below 10):" << endl;
    cin >> num;
    cout << "Please enter some array elements(below 10) one by one in a newline:" << endl;
    for (int i=0; i<num; i++){
        cin >> element;
        CreateArray(L, element);
    }

    cout << "Please enter an integer to set the array's length(below 10):" << endl;
    cin >> num;
    cout << "Please enter some array elements(below 10) one by one in a newline:" << endl;
    for (int i=0; i<num; i++){
        cin >> element;
        CreateArray(M, element);
    }

    cout << "The merged array is:" << endl;
    DispArray(FindMerge(L, M));
    cout << "As shown, the time complexity is O(n); the space complexity if O(n)" << endl;

    free(L);
    free(M);
    return 0;
}

