#include <iostream>
#include <vector>
using namespace std;

// function declaration
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    tmp.resize(right - left + 1);
    int i = left;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= right){
        if(a[i]<a[j]){
            tmp[k] = a[i];
            k++;
            i++;
        } else{
            tmp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <=middle){
        tmp[k] = a[i];
        k++;
        i++;
    }
    while (j <= right){
        tmp[k] = a[j];
        k++;
        j++;
    }
    for(int b = left, c= 0; b <= right; b++,c++){
        a[b] = tmp[c];
    }
}


void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){
    if(left<right){
        int middle = (left + right) / 2;
        mergeSort(a,tmp,left,middle);
        mergeSort(a, tmp,middle + 1, right);
        mergeSortedLists(a,tmp,left,middle,right);
    }
}


int main() {
    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    vector<int> test1(5);
    test1 = {5,4,3,2,1};
    vector<int> result1(5);
    result1 = {1,2,3,4,5};
    vector<int> tmp1(5);

    mergeSort(test1,tmp1,0,test1.size() - 1);
    if(test1 == result1){
        cout << "Unit test passed" << endl;
    } else{
        cout<< "Unit test failed" <<endl;
    }
/* your code here */
    // initialize and print input
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v,t,0,length - 1);
   /* your code here */

        // print output
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << '\t';
        }
        cout << endl;

        // check output, make sure it's sorted
        for (int i = 1; i < v.size(); i++) {
            assert(v.at(i - 1) <= v.at(i));
        }

        return 0;
    }
    /* your code here */