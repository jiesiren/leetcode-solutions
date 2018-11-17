class Solution {
public:
    
    static bool decreasing(pair<char, int> a, pair<char, int> b) { return (a.second > b.second); }
    
    string frequencySort(string s) {
        map<char, int> count_map;
        
        for (char &c : s) {
            if (count_map.find(c) == count_map.end()) {
                count_map[c] = 1;
            } else {
                count_map[c]++;
            }
        }
        
        vector<pair<char, int>> all_chars(count_map.begin(), count_map.end());
        
        sort(all_chars.begin(), all_chars.end(), Solution::decreasing);
        
        string sorted_string;
        for (auto it = all_chars.begin(); it != all_chars.end(); it++) {
            string chunk(it->second, it->first);
            sorted_string += chunk;
        }
        
        return sorted_string;
    }
};
