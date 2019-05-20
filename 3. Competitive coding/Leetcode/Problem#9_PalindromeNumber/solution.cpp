class Solution {
public:
    bool isPalindrome(int x) {
        long int num = x;
        if(x < 0) {
            //cout<<"its less than zero!"<<endl;
            return false;
        }
        long int reverse=0;
        while(x>0){
            int dig = 0;
            dig = x%10;
            reverse = reverse*10 + dig;
            x /= 10;
        }
        //cout<<reverse-x<<endl;
        if(reverse==num){
            //cout<<"its Equal!"<<endl;
            return true;
        }
        return false;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}