// C++
// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;

class TrieNode{
public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode(){
        children.resize(26,NULL);
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(auto& ch : word){
            int idx = ch-'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    ll search(string word, int l, int n, vector<ll>& dp) {
        TrieNode *node = root;
        ll count = 0;
        for(int i = l; i<n; i++){
            int idx = word[i]-'a';
            if(!node->children[idx])    break;

            node = node->children[idx];

            if(node->isEnd){
                count = (count + dp[i+1])%mod;
            }
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int m, n;
    cin>>m;
    n = s.size();

    Trie obj;

    for(int i=0; i<m; i++){
        string temp;
        cin>>temp;
        
        obj.insert(temp);
    }

    vector<ll> dp(n+1);
    dp[n] = 1;
    
    for(int i=n-1; i>=0; i--){
        dp[i] = obj.search(s, i, n, dp);
    }

    cout<<dp[0]<<endl;

    
    return 0;
}





//******************* JAVA **********************
public class Main{
  static long mod = (long)1e9+7;

    static class TrieNode{
        public TrieNode children[];
        public boolean isEnd;

        public TrieNode(){
            children = new TrieNode[26];
            isEnd = false;
        }
    };

    static class Trie {
        private TrieNode root;
        public String s;
        public Trie(String s) {
            root = new TrieNode();
            this.s = s;
        }
        
        public void insert(String word) {
            TrieNode node = root;
            int n = word.length();
            for(int i=0; i<n; i++){
                int idx = word.charAt(i)-'a';
                if(node.children[idx] == null){
                    node.children[idx] = new TrieNode();
                }
                node = node.children[idx];
            }
            node.isEnd = true;
        }
        
        public long search(int l, int n, long dp[]) {
            TrieNode node = root;
            long count = 0;
            for(int i = l; i<n; i++){
                int idx = s.charAt(i)-'a';
                if(node.children[idx] == null)    break;

                node = node.children[idx];

                if(node.isEnd){
                    count = (count + dp[i+1])%mod;
                }
            }
            return count;
        }
    };

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();


        String s = sc.next();
        
        Trie obj = new Trie(s);

        int m = sc.nextInt(), n=s.length();
        for(int i=0; i<m; i++){
            String temp = sc.next();
            obj.insert(temp);
        }

        long dp[] = new long[n+1];
        dp[n] = 1;

        for(int i=n-1; i>=0; i--){
            dp[i] = obj.search(i, n, dp);
        }
        so.println(dp[0]);



        so.flush();
        so.close();
        sc.close();
    }
}
