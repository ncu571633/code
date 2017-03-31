Design a data structure that supports insert, delete, search and getRandom in constant time

Design a data structure that supports following operations in Θ(1) time.
insert(x): Inserts an item x to the data structure if not already present.
remove(x): Removes an item x from the data structure if present.
search(x): Searches an item x in the data structure.
getRandom(): Returns a random element from current set of elements


unordered_map<int, int> m;
vector<int> v;

void insert(int val) {
  if(m.count(val))
    return ;
  v.push_back(val);
  m[val] = v.size()-1;
}

void remove(int val) {
  if(!m.count(val))
    return ;
  m[v.back()] = m[val];
  swap(v[m[val]], v.back());
  v.pop_back();
  m.erase(val);
}

int getRandom() {
  int index = rand%(v.size());
  return v[index];
}
