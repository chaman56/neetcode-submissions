class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string s;
        for(int i = 0; i<n; i++){
            s+= to_string(strs[i].size()) + " ";
        }
        s+=".";
        for(int i = 0; i<n; i++){
            s+= strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<int> lengths;
        vector<string> strs;
        int i = 0;
        if(s[0]=='.')return strs;
        while(true){
            int j = i;
            while(s[j]!=' ')j++;
            lengths.push_back(stoi(s.substr(i, j-i)));
            i=j+1;
            if(s[i]=='.')break;
        }
        i+=1;
        for(int j = 0; j<lengths.size(); j++){
            strs.push_back(s.substr(i, lengths[j]));
            i+=lengths[j];
        }
        return strs;
    }
};
