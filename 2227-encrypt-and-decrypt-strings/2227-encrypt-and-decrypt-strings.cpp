class Encrypter {
public:
    unordered_map<char,string> mp;
    unordered_map<string,int> d;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for(int i=0;i<n;i++)
        {
            mp[keys[i]] = values[i];
        }
        n = dictionary.size();
        for(int i=0;i<n;i++)
        {
            string x = dictionary[i];
            int len = x.length();
            string p="";
            for(int j=0;j<len;j++)
            {
                p+=mp[x[j]];
            }
            d[p]++;
        }
    }
    
    string encrypt(string word1) {
        int n = word1.size();
        string p="";
        for(int i=0;i<n;i++)
        {
            p+=mp[word1[i]];   
        }
        return p;
    }
    
    int decrypt(string word2) {
        if(d.find(word2)==d.end())
            return 0;
        return d[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */