#include <bits/stdc++.h>
using namespace std;
typedef pair<int,long long>Pair;
long long lcm = 0, temp = 0,llcm=LONG_LONG_MAX;
long long b[100],x;
Pair c[100];
long long gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

void combinationUtil(int arr[], int n, int r,
                     int index, int data[], int i);

// The main function that prints all
// combinations of size r in arr[]
// of size n. This function mainly
// uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store
    // all combination one by one
    int data[r];

    // Print all combination using
    // temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}

/* arr[] ---> Input Array
n ---> Size of input array
r ---> Size of a combination to be printed
index ---> Current index in data[]
data[] ---> Temporary array to store current combination
i ---> index of current element in arr[] */
void combinationUtil(int arr[], int n, int r,
                     int index, int data[], int i)
{
    if (index == r)
    {
    // Current cobination is ready, now get the lcm
        long long g = gcd(data[0],data[1]),l;
        l = data[0]*data[1]/g;

        for (int j = 2; j < r; j++)
        {
            g = gcd(l,data[j]);
            l = l*data[j]/g;
        }
        llcm = min(llcm,l);
        for(int j=0; j<x; j++)
        {
            if(c[j].first > b[j]%l)
            {
                c[j].first = b[j]%l;
            }

            long long t = b[j]-b[j]%l + l;
            c[j].second = min(t,c[j].second);
        }
        lcm = 0, temp = 0;
        return;
    }
    if (i >= n)
        return;
    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1);
    combinationUtil(arr, n, r, index, data, i+1);
}
int main()
{
    int arr[100005];
    int r=4,n;
    while(cin>>n>>x && n>0 && x>0)
    {
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0; i<x; i++)
            cin>>b[i];
        for(int i=0; i<x; i++)
            c[i].first=INT_MAX,c[i].second = LONG_LONG_MAX;
        printCombination(arr, n, r);
        for(int i=0; i<x; i++)
        {
            if(c[i].first==0)
            {
                cout<<b[i]<<" "<<b[i]<<endl;
            }
            else
            {
                cout<<b[i] - c[i].first<<" "<<c[i].second<<endl;
            }
        }
        lcm = 0, temp = 0,llcm=LONG_LONG_MAX;
    }
    return 0;
}
