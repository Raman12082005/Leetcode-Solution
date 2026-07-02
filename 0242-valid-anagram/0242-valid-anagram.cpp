class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;

        vector<int> stvector(26, 0);
        for(int i=0; i<s.size(); i++) stvector[s[i]-'a']++;

        for(int i=0; i<t.size(); i++){
            if(stvector[t[i]-'a'] == 0) return false;
            else stvector[t[i]-'a']--;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//         if(s.size() != t.size()) return false;

//         vector<int> svector(26, 0);
//         vector<int> tvector(26, 0);

//         for(int i=0; i<s.size(); i++){
//             svector[s[i]-'a']++;
//             tvector[t[i]-'a']++;
//         }
//         return svector == tvector;
//     }
// };


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//         if(s.size() != t.size()) return false;

//         unordered_map<char, int> smap;
//         unordered_map<char, int> tmap;
//         for(int i=0; i<s.size(); i++){
//             smap[s[i]]++;
//             tmap[t[i]]++;
//         }
//         return smap == tmap;
//     }
// };


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//         if(s.size() != t.size()) return false;

//         unordered_map<char, int> stmap;
//         for(int i=0; i<s.size(); i++) stmap[s[i]]++;

//         for(int i=0; i<t.size(); i++){
//             if(stmap.find(t[i]) == stmap.end() || stmap[t[i]] == 0) return false;

//             else stmap[t[i]]--;
//         }
//         return true;
//     }
// };