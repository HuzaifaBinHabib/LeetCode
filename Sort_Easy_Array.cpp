#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "Enter the how much number you want \n";
    cin >> n;
    int arr[n];
    cout << "Enter Number From 1 TO " << n<<"\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    for (int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
        if(arr[i]>arr[j]){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
      }

    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    cout << endl;
    return 0;
}