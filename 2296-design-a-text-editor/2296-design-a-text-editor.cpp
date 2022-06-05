class TextEditor {
public:
    
    stack<char> left;
    stack<char> right;
    TextEditor() {
    }
    
    void addText(string text) {
        for(auto &c : text){
            left.push(c);
        }
    }
    
    int deleteText(int k) {
        int cnt=0;
        while(!left.empty() and k>0){
            left.pop();
            cnt++;
            k--;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() and k>0){
            char c = left.top();left.pop();
            right.push(c);
            k--;
        }
        return cursorShiftString();
    }
    
    string cursorRight(int k) {
       while(!right.empty() and k>0){
            char c = right.top();right.pop();
            left.push(c);
            k--;
        }
        return cursorShiftString();
    }
    
    string cursorShiftString()
    {
        string lastString="";
        int cnt=10;
        while(!left.empty()&&cnt>0)
        {
            char c = left.top();
            left.pop();
            lastString+=c;cnt--;
        }
        reverse(lastString.begin(),lastString.end());
        for(int i=0;i<lastString.length();i++)
        {
            left.push(lastString[i]);
        }
        return lastString;
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */