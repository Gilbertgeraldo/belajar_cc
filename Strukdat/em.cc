#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int N){ //Kompleksitas O(N^2)
   for(int i = 1;i <= N-1;++i){
        for(int j = 0;j < N-i;++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
   }
}

void SelectionSort(int arr[],int N){ //O(N^2)
    for(int i = 0;i < N;++i){
        int min = i;
        for(int j = i+1;j < N;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

void insertionsort(int arr[],int N){
    int sub = 0;
    while(sub < N){
        int ins = sub + 1;
        int t = sub;
        while(t >= 0 && arr[ins] < arr[t]){ //Kompleksitas O(N^2)
            swap(arr[ins],arr[t]);
            ins--;
            t--;
        }
        sub++;
    }
}

void MergeSort(int arr[],int aLeft,int aRight,int bLeft,int bRight){ 
    int size = (aRight - aLeft + 1) + (bRight - bLeft + 1);
    int *temp = new int[size];

    int tIdx = 0;
    int aIdx = aLeft;
    int bIdx = bLeft;

    while(aIdx <= aRight && bIdx <= bRight){
        if(arr[aIdx] < arr[bIdx]){
            temp[tIdx] = arr[aIdx];
            aIdx++;
        }else{
            temp[tIdx] = arr[bIdx];
            bIdx++;
        }
        tIdx++;
    }

    while(aIdx <= aRight){
        temp[tIdx] = arr[aIdx];
        aIdx++;
        tIdx++;
    }

    while(bIdx <= bRight){
        temp[tIdx] = arr[bIdx];
        bIdx++;
        tIdx++;
    }

    for(int i = 0;i < size;++i){
        arr[aLeft+i] = temp[i];
    }
    delete[] temp;

}

void quickSort(int arr[],int left,int right){
    if(left >= right){
        return;
    }

    int pivot = arr[(left + right)/2];
    int pLeft = left;
    int pRight = right;

    while(pLeft <= pRight){
        while(arr[pLeft] < pivot){
            pLeft++;
        }
    }

    while(arr[pRight] > pivot){
        pRight-- ;
    }

    if(pLeft <= pRight){
        swap(arr[pLeft],arr[pRight]);
        pLeft++;
        pRight--;
    }
}

void countingsort(int arr[],int N){
    int ft[1000001] = {0};
    for(int i = 0;i < N;++i){
        int x = arr[x];
        ft[x] = ft[x]+1;
    }

    int idx = 0;
    for(int i = 1;i <= 1000000;++i){
        for(int j = 1;j < ft[i];++j){
            arr[idx] = i;
            idx++;
        }
    }
}

void cetakArray(int arr[],int size){
    for(int i = 0;i < size;++i){
        cout << arr[i] << " ";         
    }
    cout << endl;
}

bool isPrime(int N){
    if(N <= 1){
        return false;
    }
    int i = 2;
    while(i*i <= N){
        if(N % i == 0){
            return false;
        }
        i++;
    }
    return true;
}

int main(){
    int h[] = {64, 34, 25, 12, 22, 11, 90};
    int N = sizeof(h)/sizeof(h[0]);
    int a[N];

    copy(h,h+N,a);
    cout << "Before Bubble sort :\n";
    cetakArray(h,N);

    copy(h,h+N,a);
    cout << "Before selection sort :\n";
    cetakArray(h,N);

    copy(h,h+N,a);
    cout << "Before Insertion Sort\n";
    cetakArray(h,N);

    copy(h,h+N,a);
    cout << "Before Counting sort :\n";
    cetakArray(h,N);

    copy(h,h+N,a);
    bubble_sort(h,N);
    cout << "After Bubble sort :\n";
    cetakArray(h,N);

    copy(h,h+N,a);
    selection_sort(h,N);
    cout << "After selection sort :\n";
    cetakArray(h,N); 

    copy(h,h+N,a);
    insertionsort(h,N);
    cout << "After Insertion sort : \n";
    cetakArray(h,N);

    copy(h,h+N,a);
    countingSort(h,N);
    cout << "After Counting sort :\n";
    cetakArray(h,N);

    return 0;
}