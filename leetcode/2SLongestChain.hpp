// Complete the longestChain function below.
bool sortWord(string s1, string s2)
{
    return s1.size() < s2.size();
}
int longestChain(vector<string> words) {
    if(!words.size())
        return 0;

    // sort words based on the length
    sort(words.begin(), words.end(), sortWord);

    unordered_map<string, int> m;
    int ret = 0;
    for(int i=0; i<words.size(); i++)
    {
        string word = words[i];
        if(m.count(word))
            continue;
        m[word] = 1;

        for(int j=0; j<word.size(); j++)
        {
            string t = word;
            t.erase(j, 1);

            if(m.count(t) && m[t]+1 > m[word])
                m[word] = m[t]+1;
        }
        ret = max(m[word], ret);
    }
    return ret;
}

