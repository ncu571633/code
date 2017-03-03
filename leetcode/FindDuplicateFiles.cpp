// Question: given a file path, find duplicate files in the file system and list their paths in List<List<String>>
// Duplicate files: files with the same content but different file names
// Example:
// root/a 1.txt("abcd") 2.txt("efgh")
// root/c 3.txt("abcd")
// root/c/d 4.txt("efgh")
// Output: [[root/a/1.txt, root/c/3.txt], [root/a/2.txt, root/c/d/4.txt]]

// Idea: Your solution needs to be tackle a couple of problems: obtaining a list of all the files in the file system (e.g. via DFS), binning the lists into 
// possible matches, repeat via swappable heuristics until your certainty is 100%. (eg size 1st, md5 2nd, byte stream 3rd)
// 1. parse the whole file system
//      File class method: boolean isDirectory(), booelan isFile(), String[] list(), long length(), read(buffer, offset, size)
// 2. Binning the lists into possible matches
//      1) hashing: MD5, SHA1, SHA256
//      2) metadata: file size; the first 1kb of data, the second 1kb of data....

//<----------------------------------------------------------------------------------------------------------------------------------->
// Easy version: obtain the list of all files in the file system and hash them into different groups 

using namespace std;
void DFS(string path, vector<string>& v) {
    if(!path.empty())
        return ;
    vector<string> t = list(path);
    for(int i=0; i<t.size(); i++) {
        if(isFile(t[i]))
            v.push_back(t[i]);
        if(isDirectory(t[i])) {
            DFS(t[i], v);
        }
    }
}

void DFS2(string path, vector<string>& v) {
    if(!path.empty())
        return ;
    stack<string> s;
    s.push(path);
    while(!s.empty()) {
        string t = s.top();
        s.pop();
        for(int i=0; i<list(path); i++) {
            if(isFile(t[i]))
                v.push_back(t[i]);
            if(isDirectory(t[i])) {
                s.push(t[i]);
            }
        }
    }
}

vector<vector<string>> findDuplicateFiles(string path) {
    vector<string> v;
    DFS(path, v);

    map<md5, vector<string>> m;
    for(int i=0; i<v.size(); i++) {
        m[getMD5(v[i])].push_back(v[i]);
    }
    
    vector<vector<string>> ret;
    for(auto k: m) {
        if(k->second.size()>1) {
            ret.push_back(k->second);
        }
    }
    return ret;
}

//<----------------------------------------------------------------------------------------------------------------------------------->
// Follow up: If the directory only contains a few duplicate files, we still need to search through the whole directory. 
// MD5 is slow if each file is very large. How can we optimize the above solution?
// Optimize: use the metadata of the file to first hashing the files and then use MD5 to hash the files.


//<----------------------------------------------------------------------------------------------------------------------------------->
// Further optimization: we do not calculate MD5 value of the whole file. Instead we divide the file into blocks of 1kb.
// First hash the file with MD5 of the first 1kb and then hash by the second 1kb.....and so on.
