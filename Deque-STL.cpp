#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    std::deque<int> mydq;
    
    for (int i=0; i<n; i++){        
        if (mydq.empty()){
            mydq.push_back(i);
        }
        if (mydq.front() <= (i - k)){
            mydq.pop_front();
        }
        while (!mydq.empty() && arr[i] >= arr[mydq.back()]){
            mydq.pop_back();
        }
        
        mydq.push_back(i);
        
        if (i >= (k - 1)){
            cout << arr[mydq.front()] << " ";
        }    
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}