
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
What happen when reading a file
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
