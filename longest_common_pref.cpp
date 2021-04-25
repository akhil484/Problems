class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) 
            return "";
	    string str1 = strs[0];
	    if (str1 == "") 
            return "";

	    for (int i = 1; i < strs.size(); ++i) {
		    string str2 = strs[i];
		    if (str2 == "") 
                return "";

		    int ind = 0;
		    while (ind<str1.length()&&ind<str2.length()&&str1[ind] == str2[ind]) 
                ind++;
		    str1 = str1.substr(0, ind);
	    }

	    return str1;
    }
};
