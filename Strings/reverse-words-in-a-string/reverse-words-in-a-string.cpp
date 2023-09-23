class Solution {
public:
    string reverseWords(string s) {
        //TC-O(n+n+n)+O(n), SC-(n)
        // string ans="";
        // int n=s.size();
        // for(int i=n-1;i>=0;i--){
        //     stack<char> stk;
        //     while(i>=0 && s[i]!=' '){
        //         stk.push(s[i]);
        //         i--;
        //     }
        //     int p=stk.size();
        //     int count=0;
        //     while(!stk.empty()){
        //         ans+=stk.top();
        //         stk.pop();
        //         count++;
        //         if(count==p) ans+=' ';
        //     }
        // }
        // int k=ans.size();
        // return ans.substr(0,k-1);

        //we can do it using stringstream tool in STL
        // stringstream ss(s);
        // string token = "";
        // string result = "";
        // while(ss>>token){  //by default breaks the string into tokens by space
        //     result = token + " " + result;
        // }
        // return result.substr(0,result.size()-1);

        //Two pointers
        //Reverse the whole string then reverse individual words
        int n=s.size();
        reverse(s.begin(),s.end());
        //now reverse each word
        int i=0,r=0,l=0;
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                r++;
                i++;
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }
};