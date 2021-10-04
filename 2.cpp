#define Size 10
#include <iostream>
using namespace std;
typedef int DataType;

typedef struct
{
    DataType data[Size];
    int length;
} Array;

void CreateArray(Array*& L, DataType a[Size]){
    for(int i=0; i<Size; i++){
        L->data[i] = a[i];
    }
    L->length = Size;
}

Array* DeleteNegative(Array*& L){
    Array* A = (Array*)malloc(sizeof(Array));
    int k = 0;
    for(int i=0; i<L->length; i++){
        if(L->data[i]>=0){
            A->data[k] = L->data[i];
            k++;
        }
    }
    A->length = k;
    return A;
}

void DispArray(Array* L){
    for(int i=0; i<L->length; i++){
        cout << L->data[i] << endl;
    }
    free(L);
}

int main(){
    Array* L = (Array*)malloc(sizeof(Array));
    DataType a[Size];
    DataType element;
    cout << "Please enter the 10 array elements one by one in a newline:" << endl;
    for (int i=0; i<Size; i++){
        cin >> element;
        a[i] = element;
    }
    CreateArray(L, a);
    cout << "The positive array is:" << endl;
    DispArray(DeleteNegative(L));
    cout << "As shown, the time complexity is O(n); the space complexity if O(n)" << endl;
    
    free(L);
    return 0;
}
