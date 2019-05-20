class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while(x!=0){
            int dig = x%10;
            x/=10;
            if((reverse < INT_MIN/10  ||  (reverse == INT_MIN/10 && dig<-8)) 
                || (reverse > INT_MAX/10  ||  (reverse == INT_MAX/10 && dig>7))){
                return 0;
            }
            reverse = dig + reverse*10;
        }
        return reverse;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}