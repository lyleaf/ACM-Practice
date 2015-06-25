vector<long long> v[2], w[2]; 
unsigned int N, M;

int main(){
    int ret = scanf("%d%d", &N, &M); 
    if (ret < 2) break;
    for (int c = 0; c < 2; c++) {
        v[c].clear();
        for (unsigned int i = 0; i < (c ? M : N); i++) {
            long long t;
            scanf("%lld", &t); v[c].push_back(t);
        }
        sort(v[c].begin(), v[c].end());//由小到大
        w[c] = v[c]; 
        //把两个公司的子公司的数据分别读入两个vector中.
        //vector的等于号会重新copy一个vector.
    }
    bool wins = play(v, false) || play(w, true); 
    printf("Case %d: %s\n", ncase,wins ? "Takeover Incorporated" : "Buyout Limited");

    return 0;
}


bool play(vector<long long> t[2], bool force) { 
    int p = 0;
    while (t[0].size() && t[1].size()) {
        if (t[p].back() > t[1-p].back() && !force) { 
            t[1-p].pop_back(); // hostile
        }
        else if (t[p].size() > 1) 
        { 
            t[p][t[p].size() - 2] += t[p].back(); t[p].pop_back(); // friendly
        }
    force = false;
    p = 1-p;
    }
    return t[0].size() > 0; 
}
