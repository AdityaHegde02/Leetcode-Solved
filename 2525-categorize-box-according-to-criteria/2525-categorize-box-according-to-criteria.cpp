class Solution {
public:
    bool isBulky(int l,int w,int h,int m){
        long long vol = (long long)l*w;
        vol = (long long)vol*h;
        if(l >= 1e4 or w >= 1e4 or h >= 1e4 or vol >= 1e9){
            return true;
        }    
        return false;
    }
    
    bool isHeavy(int m){
        if(m >= 100){
            return true;
        }    
        return false;
    }
    
    string categorizeBox(int l, int w, int h, int m) {
        bool b = isBulky(l,w,h,m);
        bool he = isHeavy(m);
        if(b and he){
            return "Both";
        }
        else if(!b and !he){
            return "Neither";
        }
        else if(b and !he){
            return "Bulky";
        }
        else{
            return "Heavy";
        }
        return "";
    }
};