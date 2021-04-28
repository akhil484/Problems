#include<bits/stdc++.h>
using namespace std;



    
    long recalculateHash(char str[],int oldIndex, int newIndex,long oldHash, int patternLen,int prime) {
        long newHash = oldHash - str[oldIndex];
        newHash = newHash/prime;
        newHash += str[newIndex]*pow(prime, patternLen - 1);
        return newHash;
    }
    long createHash(char str[], int end,int prime){
        long hash = 0;
        for (int i = 0 ; i <= end; i++) {
            hash += str[i]*pow(prime,i);
        }
        return hash;
    }
    
    
    bool checkEqual(char str1[],int start1,int end1, char str2[],int start2,int end2){
        if(end1 - start1 != end2 - start2) {
            return false;
        }
        while(start1 <= end1 && start2 <= end2){
            if(str1[start1] != str2[start2]){
                return false;
            }
            start1++;
            start2++;
        }
        return true;
    }
    
    void patternSearch(char text[], char pattern[],int prime){
        int m = strlen(pattern);
        int n = strlen(text);
        long patternHash = createHash(pattern, m - 1,prime);
        long textHash = createHash(text, m - 1,prime);
        for (int i = 1; i <= n - m + 1; i++) {
            if(patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1)) {
                cout<<i - 1<<" ";
            }
            if(i < n - m + 1) {
                textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m,prime);
            }
        }
        // return -1;
    }
    
    
    int main(){
        string s1="TusharRoy";
        string s2="usha";
        int prime = 101;
        char *a = &s1[0];
        char *b = &s2[0];
        patternSearch(a, b,prime);
        // System.out.println(rks.patternSearch("TusharRoy".toCharArray(), "sharRoy".toCharArray()));
        // System.out.println(rks.patternSearch("TusharRoy".toCharArray(), "Roy".toCharArray()));
        // System.out.println(rks.patternSearch("TusharRoy".toCharArray(), "shas".toCharArray()));
        // System.out.println(rks.patternSearch("TusharRoy".toCharArray(), "usha".toCharArray()));
        // System.out.println(rks.patternSearch("TusharRoy".toCharArray(), "Tus".toCharArray()));
    }
