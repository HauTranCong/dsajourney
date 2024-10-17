class Solution {
public:
    int maximumSwap(int num) {
        string numToStr;
        int maxVal = num;
        while(num) {
            int unit = num % 10;
            numToStr += to_string(unit);
            num /= 10;
        }
        reverse(numToStr.begin(), numToStr.end());
        for(int i = 0; i < numToStr.length(); ++i) {
            for(int j = i+1; j < numToStr.length(); ++j) {
                string tmpStr = numToStr;
                char c = tmpStr[i];
                tmpStr[i] = tmpStr[j];
                tmpStr[j] = c;
                maxVal = max(maxVal, stoi(tmpStr));
            }
        }
        return maxVal;
    }
};