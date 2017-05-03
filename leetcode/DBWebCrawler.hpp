
/*
Web Crawler

1. Begin with a base URL that you select, and place it on the top of your queue
2. Pop the URL at the top of the queue and download it
3. Parse the downloaded HTML file and extract all links
4. Insert each extracted link into the queue
5. Goto step 2, or stop once you reach some specified limit
*/

#if 0
queue<string> q;
int limit = 2;
unordered_map<string, bool> visited;

void WebCrawler(string base) {
    q.push(base);
    int level = 1;
    while(q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            string t = q.top();
            q.pop();
            if(level == limit)
                continue;
            string web = download(t);
            // parse downloaded webpage
            for(auto it=iterator(web).begin(); it!=iterator(web).end(); it++) {
                string t = *it;
                visited[t] = true;
                q.push(t);
            }
        }
        level++;
    }
}
#endif

queue<string> q;
int limit = 2;
unordered_map<string, bool> visited;
const threadNumber = 6;
std::mutex addQueue;
// multi-thread: slow server latency
vector<string> parseWeb(string base, queue<string> q)
{
    string web = download(t);
    // parse downloaded webpage
    for(auto it=iterator(web).begin(); it!=iterator(web).end(); it++) {
        string t = *it;
        std::lock(addQueue);
        visited[t] = true;
        q.push(t);
        addQueue.unlock();
    }
}

void WebCrawler(string base) {
    q.push(base);
    int level = 1;
    while(q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            string t = q.top();
            q.pop();
            if(level == limit)
                continue;

        }
        level++;
    }
}


pthread_mutex_t lock;
pthread_cond_t cond;
queue<string> seeds;
unordered_set<string> visited;
int nwait = 0;
int nthreads = N;
crawl() {
        while(1) {
                pthread_mutex_lock(&lock);
                while(seeds.empty()){
                        nwait++:
                        if(nwait==N) {
                                pthread_cond_signal(&cond);
                                pthread_mutex_unlock(&lock);
                                return;
                        }
                        pthread_cond_wait(&cond, &lock);
                        nwait—;
                }
                string url = seeds.front();
                seeds.pop();
                pthread_mutex_unlock(&lock);
                vector<string> urls = geturls(url);
                pthread_mutex_lock(&lock);
                for(auto &a:urls) {
                        if(visited.count(a)) continue;
                         visited.insert(a);
                        seeds.push(a);
                }
                if(!seeds.empty()) pthread_cond_broadcast(&cond);
                pthread_mutex_unlock(&lock);
        }
}
