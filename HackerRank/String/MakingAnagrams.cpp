int makeAnagram(string a, string b) {
    vector<int> freqOfStrA(26, 0);
    vector<int> freqOfStrB(26, 0);
    
    for (char c : a) 
        freqOfStrA[c - 'a']++;
        
    for (char c : b) 
        freqOfStrB[c - 'a']++;
        
    int deletions = 0; 
    for (int i = 0; i < 26; ++i)
        deletions += abs(freqOfStrA[i] - freqOfStrB[i]);
            
    return deletions;
}