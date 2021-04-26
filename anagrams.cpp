// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C


//Function is to check whether two strings are anagram of each other or not.
bool isAnagram(char a[], char b[]){
    
    // Your code here
    int count[256]={0};
    int i=0;
    for(i=0;a[i]&&b[i];i++)
    {
        count[a[i]]++;
        count[b[i]]--;
    }
    if(a[i]||b[i])
        return false;
    for(int i=0;i<256;i++)
    {
        if(count[i]!=0)
            return false;
    }
    return true;
}


// { Driver Code Starts.

int main() {
    
    int t;

    scanf("%d", &t);

    while(t--){
        char c[10000], d[10000];

        scanf("%s%s", &c, &d);

        if(isAnagram(c, d)) printf("YES\n");
        else  printf("NO\n");
    }

}
  // } Driver Code Ends
