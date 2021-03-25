
#include <iostream>
using namespace std;

int *nums;

// exchange two integers
inline void swap(int &i, int &j)
{
        int t = i;
        i = j;
        j = t;
}

// full permutation
void perm(int n, int i)
{
        if (i == (n-1)) //check if reach the end of iteration
        {
               // print out the iteration
               for (int j =0; j < n; j ++) cout<< nums[j];
               cout << endl;
        }
        else
        {
               for (int j =i; j < n; j ++)
               {
                       swap(nums[i],nums[j]); // swap
                       perm(n,i + 1);         // recursive
                       swap(nums[i],nums[j]); // swap it back
               }
        }
}

// main entry
int main()
{
        int n;
        cout << "\nEntre com o tamanho do vetor n = ";
        cin >> n;
        nums = new int[n]; // declare a dynamic array
        for (int i = 0; i < n; i ++) nums[i] = i + 1;
        perm(n, 0);
        //cin >> n;
        return 0;

}

