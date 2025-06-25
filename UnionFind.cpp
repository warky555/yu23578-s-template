class UnionFind{
  public:
  int Nodes = 0;
  vector<int> siz,par;
  
  //頂点数の設定.
  void init(int N){
    assert (0 <= N);
    for(int i = Nodes; i < N; i++){
      par.emplace_back(-1);
      siz.emplace_back(1);
    }
    Nodes = N;
  }
  
  //リーダーの取得.
  int leader(int x) {
    assert (0 <= x && x < Nodes);
    if (par[x] == -1) return x; // x が根の場合は x を直接返す
    else return par[x] = leader(par[x]); // x の親 par[x] を根に設定する
  }
  
  //aとbが同じ連結成分に属しているかの判定.
  bool same(int a, int b){
    assert (0 <= a && a < Nodes);
    assert (0 <= b && b < Nodes);
    int para = leader(a);
    int parb = leader(b);
    if(para == parb) return true;
    else return false;
  }
  
  //aとbを繋げる.
  bool merge(int a, int b){
    assert (0 <= a && a < Nodes);
    assert (0 <= b && b < Nodes);
    int para = leader(a);
    int parb = leader(b);
    bool res = (para == parb);
    if(!res){
      if(siz[para] < siz[parb]){
        par[para] = parb;
        siz[parb] += siz[para];
      }
      else{
        par[parb] = para;
        siz[para] += siz[parb];
      }
    }
    return res;
  }
  
  //同じ連結成分内の頂点の数.
  int size(int a){
    assert (0 <= a && a < Nodes);
    return siz[leader(a)];
  }
  
  //--O(N)かかるので注意!--
  //同じ連結成分内の頂点.
  vector<int> same_node(int a){
    assert (0 <= a && a < Nodes);
    vector<int> res;
    for(int i = 0; i <= Nodes; i++){
      if(same(a,i)) res.emplace_back(i);
    }
    return res;
  }
  
  vector<vector<int>> groups(){
    vector<vector<int>> res(Nodes);
    vector<vector<int>> ret;
    for(int i = 0; i < Nodes; i++) res[leader(i)].emplace_back(i);
    for(int i = 0; i < Nodes; i++) if((int)(res[i].size()) != 0) ret.emplace_back(res[i]);
    return ret;
  }
};
