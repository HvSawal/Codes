class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solIndices(2);
        solIndices[0] = -1;
        solIndices[1] = -1;        
        //Better Solution
        /*vector<int>::iterator it;
        for(int i=0;i<nums.size()-1;i++){
            //int m=i+1;
            it = find(nums.begin()+i+1,nums.end(),target-nums[i]);
            //cout<<*it<<endl;
            if(it!=nums.end()){
                solIndices[0]=i;
                solIndices[1]=it-nums.begin();
                break;
            }
        }*/
        //Even better Solution
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            //int comp = target-nums[i];
            //check if comp already exists
            unordered_map<int,int>::const_iterator it = mymap.find(target-nums[i]);
            if(it!=mymap.end()){
                solIndices[1]=i;
                solIndices[0]=mymap.at(target-nums[i]);
                return solIndices;
            }
            pair<int,int> elem (nums[i],i);
            
            //mymap.insert(make_pair<int,int>(nums[i],i));
            mymap.insert(elem);
            //cout<<mymap.at(nums[i])<<endl;
        }
        return solIndices;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}