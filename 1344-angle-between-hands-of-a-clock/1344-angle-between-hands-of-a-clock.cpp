class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourMins = hour*5;
        hourMins += ((double)minutes/60)*5;
        
        double diff = abs(minutes - hourMins)*6;
        return min(diff,360-diff);
    }
};