// C++

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m, ai = 0, aj = 0, bi = 0, bj = 0, flag = 0;
    cin>>n>>m;
 
    vector<string> v(n), direction(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        direction[i] = v[i];

        for(int j=0; j<m; j++){
            char ch = v[i][j];
 
            if(ch == 'A'){
                ai = i;
                aj = j;
            }
            else if(ch == 'B'){
                bi = i;
                bj = j;
            }
        }
    }
    
    vector<vector<int>> vis(n, vector<int>(m));

    queue<pair<int,int>> qu;
    qu.push({ai,aj});
    vis[ai][aj] = 1;

    int x_axis[] = {1, -1, 0, 0};
    int y_axis[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};

    while(qu.size()){
        pair<int,int> node = qu.front();
        qu.pop();

        int x = node.first;
        int y = node.second;

        if(v[x][y] == 'B'){
            flag = 1;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + x_axis[i], ny = y + y_axis[i];
            if(nx >=0 && ny >=0 && nx < n && ny < m && !vis[nx][ny] && v[nx][ny] != '#'){
                direction[nx][ny] = dir[i];
                vis[nx][ny] = 1;
                qu.push({nx,ny});
            }
        }
    }

    if(flag == 0)   cout<<"NO\n";
    else{
        string ans = "";
        while(v[bi][bj] != 'A'){
            ans += direction[bi][bj];

            if(direction[bi][bj] == 'D')    bi--;
            else if(direction[bi][bj] == 'U')    bi++;
            else if(direction[bi][bj] == 'L')    bj++;
            else    bj--;
        }

        reverse(ans.begin(), ans.end());
        cout<<"YES\n"<<ans.size()<<endl<<ans;
    }
    
    return 0;
}

// JAVA
public class Main{
  static class pair{
        public int x, y;

        public pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
 
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();

        int n = sc.nextInt(), m = sc.nextInt(), ai = 0, aj = 0, bi = 0, bj = 0, flag = 0;
        String arr[] = new String[n];
        
        for(int i=0; i<n; i++)  arr[i] = sc.next();

        char direction[][] = new char[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i].charAt(j) == 'A'){
                    ai = i;
                    aj = j;
                }
                else if(arr[i].charAt(j) == 'B'){
                    bi = i;
                    bj = j;
                }
                direction[i][j] = '.';
            }
        }

        int vis[][] = new int[n][m];
        int x_axis[] = {1,-1,0,0};
        int y_axis[] = {0,0,1,-1};
        char dir[] = {'D', 'U', 'R', 'L'};

        Queue<pair> qu = new LinkedList<>();
        qu.offer(new pair(ai, aj));
        vis[ai][aj] = 1;

        while(!qu.isEmpty()){
            pair node = qu.poll();

            int x = node.x;
            int y = node.y;

            if(arr[x].charAt(y) == 'B'){
                flag = 1;
                break;
            }

            for(int i=0; i<4; i++){
                int nx = x+x_axis[i], ny = y + y_axis[i];
                if(nx >=0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 0 && arr[nx].charAt(ny) != '#'){
                    vis[nx][ny] = 1;
                    direction[nx][ny] = dir[i];
                    qu.offer(new pair(nx, ny));
                }
            }
        }

        if(flag == 0)   so.println("NO");
        else{
            StringBuilder s = new StringBuilder();
            while(arr[bi].charAt(bj) != 'A'){
                s.append(direction[bi][bj]);

                if(direction[bi][bj] == 'D')    bi--;
                else if(direction[bi][bj] == 'U')   bi++;
                else if(direction[bi][bj] == 'L')   bj++;
                else    bj--;
            }

            so.println("YES\n" + s.length() + "\n" + s.reverse().toString()); 
        }
 
        so.flush();
        so.close();
        sc.close();
    }
}
