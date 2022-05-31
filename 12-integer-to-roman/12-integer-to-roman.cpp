class Solution {
public:
    string intToRoman(int num) {
         int a[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string s;
        map<int,string> m1;
        m1[1]="I";
        m1[5]="V";
        m1[10]="X";
        m1[50]="L";
        m1[100]="C";
        m1[500]="D";
        m1[1000]="M";
        m1[4]="IV";
        m1[9]="IX";
        m1[40]="XL";
        m1[90]="XC";
        m1[400]="CD";
        m1[900]="CM";
        while(num)
        {
            for(int i=12;i>=0;i--)
            {
                if(num>=a[i])
                {
                    s+=m1[a[i]];
                    num-=a[i];
                    break;
                }
            }
        }
        return s;
    }
};