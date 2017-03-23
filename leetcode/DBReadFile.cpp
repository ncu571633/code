
// find whether the string is in a file

bool substr(string s, string buffer) {
    return buffer.substr(s);
}

bool findStringInFile(string s, string path) {
    if(s.empty())
        return true;
    
    string buffer = read(path); 
    return substr(s, buffer);
}

/////////////////////////////////////////////////////////////////
bool findStringInFile(string s, string path) {
     if(s.empty())
        return true;

     int size = s.size();
     string buffer = read(s, 2*size);
     while() {

     }
}

// What happen when reading a file
// time for reading a large array, small array


/*
Memory Mapping:
Mapping Files into virtual Memory
treat the mapped portion as if it were primary memory.
Memory mapped files are loaded into memory one entire page at a time

The standard I/O approach any system call or context switch overhead
 Seeking around the mapping involves trivial pointer manipulations. There is no need for the lseek() system call. 

memory-mapped files relates to a given architecture's address space:
a file larger than the addressable space can have only portions mapped at a tim
*/
