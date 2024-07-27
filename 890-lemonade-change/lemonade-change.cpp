class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int _5=0,_10=0,_20=0;
        for(auto bill: bills){
            if(bill == 5) _5++;
            if(bill == 10) _5--,_10++;
            if(bill == 20) _10--,_5--;
            if(_10<0){
                _10=0;
                _5-=2;
            }
            if(_5<0) return false;
        }
        return true;
    }
};