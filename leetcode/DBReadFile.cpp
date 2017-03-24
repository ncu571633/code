
// find whether the string is in a file

bool substr(string s, string buffer) {
    if(buffer.empty())
        return false;
    return buffer.find(s)!=string:npos; // -1
}

bool findStringInFile(string s, string path) {
    if(s.empty())
        return true;
    
    string buffer = read(path);
    return substr(s, buffer);
}

/////////////////////////////////////////////////////////////////
// buffer size = 2*s.size()
bool substr(string s, string buffer) {
    int m = s.size();
    for(int i=0; i<m; i++) {
        string temp = buffer.substr(i, m);
        if(temp == s)
            return true;
    }
    return false;
}

bool findStringInFile(string s, string path) {
     if(s.empty())
        return true;

     int m = s.size();
     FILE* id = fopen(path, 'r');
     string buffer = read(id, 2*m);
     while(!buffer.empty()) {
        if(substr(s, buffer))
            return true;
        buffer = buffer.substr(m, m);
        buffer += read(id, m);
     }
     close(id);
}

// s: size m
// text: size n
// time complexity: m*n
/*
KMP:
A, B
Try to find A in B.
starting from B[i], check each element of A and B
you can skip some iterations for which no match is possible
B[i+1], a partial match of j characters starting at position i, you know what's in positions T[i]...T[i+j-1].

Partial match table
B[i], don't need to start from B[i+1]
know which index to start

overlap[j] array stores the values of overlap(pattern[0..j-1],pattern)

bool substr(string s, string buffer) {
    int n = s.size();

    // i for buffer, j for s
    int i=0, k=0;
    while (i<n)
    {
        int j;
        for (j=k; i+j<2*n && j<n && buffer[i+j]==s[j]; j++) ;
        
        if (j==n) 
            return true;
        
        k = overlap(table, j-1);
        i = i + max(1, j-k);
    }
    return false;
}



What happen when reading a file
1. OS make a system call
2. check path
3. permission
.....inode
4. open file return a file id, descriptor
5. use id to access the file



Time for reading a large array, small array
Buffer IO
Unbuffered IO

Memory Mapping:
Mapping Files into virtual Memory
treat the mapped portion as if it were primary memory.
Memory mapped files are loaded into memory one entire page at a time

The standard I/O approach any system call or context switch overhead
 Seeking around the mapping involves trivial pointer manipulations. There is no need for the lseek() system call. 

memory-mapped files relates to a given architecture's address space:
a file larger than the addressable space can have only portions mapped at a tim
*/
