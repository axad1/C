#include<iostream>
using namespace std;
 
int Factorial(int n){
    static int i=1;// to make one time initialization
    cout<<i<<" : time"<<endl; // counting the function calls
 
    if(n==1){
      return 1;//base case
       }
   else{
        i++;
        return  n=n*Factorial(n-1);
        }
}
 
int main(){
 
    cout<<"Enter to number to find Factorial: ";
    int num;
    cin>>num;
    num=Factorial(num); // function call
    cout<<"\nFactorial of number is: "<<num << endl;
return 0;
}
 
/*
OUTPUT
Enter to number to find Factorial: 5                                                                                                                                            
1 : time                                                                                                                                                                        
2 : time                                                                                                                                                                        
3 : time                                                                                                                                                                        
4 : time                                                                                                                                                                        
5 : time                                                                                                                                                                        
                                                                                                                                                                                
Factorial of number is: 120 
 
*/
