// boolean paranthization 
// Evalute Expression True / False;

#include<bits/stdc++.h>


using namespace std;

// this fuction count number of ways to make string true or false
int evalute (string str, int k, bool isTrue,int lT, int lF, int rT, int rF){
   int Ans = 0;
    if(str[k] == '&'){
          
          if(isTrue){
              Ans += lT * rT;
          }
          else{
              Ans += rF * lT + rF * lF + rT * lF ;
          }
      }
      else if(str[k] == '^'){
          
          if(isTrue){
              Ans += lT * rF + rT * lF;
          }
          else{
              Ans += lT * rT + lF * rF;
          }
      }
      else if(str[k] == '|'){
          
          if(isTrue){
              Ans += lF * rT + lT * rT + lT * rF ;
          }
          else{
              Ans += lF * rF ;
          }
      } 

      return Ans;
}
//Recursive Approch
int booleanParanthizaton(string str, int i, int j,bool isTrue){
   
    if(i > j){
      return 0;
    }
    if(i == j ){

        if(str[i] == 'T' && isTrue || str[i] == 'F' && !isTrue){
            return 1;
        }
        return 0;
    }
     int Ans = 0;
    for(int k=i+1; k<=j-1;k+=2){
       
      // lt = left true lly    
       int lT =  booleanParanthizaton(str,i,k-1,true);
       int lF =  booleanParanthizaton(str,i,k-1,false);
       int rT =  booleanParanthizaton(str,k+1,j,true);
       int rF =  booleanParanthizaton(str,k+1,j,false);

      // counting number of ways to get desired ans for isTrue        
      Ans += evalute(str,k,isTrue,lT,lF,rT,rF);      
    }

    return Ans;
}

//Using Memoization by using 3D matrix

// dp = i X j X isTrue
int dp[100][100][2];

int countWays(string str, int i, int j, bool isTrue){
    if(i > j){
        return dp[i][j][isTrue] = 0;
    }
    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }
    if(i == j){
        
        if((str[i] == 'T' && isTrue) || (str[i] == 'F' && !isTrue)){
            return dp[i][j][isTrue] = 1;
        }
        return dp[i][j][isTrue] = 0 ;
    }
    
    int Ans = 0;
    for(int k=i+1; k<=j-1; k+=2){

        int lT = dp[i][k-1][true];
        int lF = dp[i][k-1][false];
        int rT = dp[k+1][j][true];
        int rF = dp[k+1][j][false];

        if(lT ==-1){
            lT = countWays(str,i,k-1,true);
            dp[i][k-1][true] = lT;
        }
        if(lF ==-1){
            lF = countWays(str,i,k-1,false);
            dp[i][k-1][false] = lF;
        }
        if(rT ==-1){
            rT = countWays(str,k+1,j,true);
            dp[k+1][j][true] = rT;
        } 
        if(rF ==-1){
            rF = countWays(str,k+1,j,false);
            dp[k+1][j][false] = rF;
        }

        Ans += evalute(str,k,isTrue,lT,lF,rT,rF);
    }

    return dp[i][j][isTrue] = Ans;
}
//Using map 
unordered_map < string ,int > mp;

int totalWays(string str, int i, int j, bool isTrue){

    if(i > j){
        return 0;
    }
    string idx = to_string(i) + " " + to_string(j) + " " + to_string(isTrue); 
    // cout << idx <<endl;
    if(mp.find(idx) != mp.end()){
        return mp[idx];
    }

    if(i == j){

        if((str[i] == 'T' && isTrue) || (str[i] == 'F' && !isTrue)){
            mp[idx] = 1;
            cout << 1 <<endl;
            return mp[idx];
        }
            cout << 1 <<endl;
        return mp[idx] = 0;
    }
    
    int Ans = 0;
    for(int k=i+1; k<=j-1; k+=2){
        

        string LT = to_string(i) + " " + to_string(k-1) + " " + to_string(1);
        string LF = to_string(i) + " " + to_string(k-1) + " " + to_string(0);
        string RT = to_string(k+1) + " " + to_string(j) + " " + to_string(1);
        string RF = to_string(k+1) + " " + to_string(j) + " " + to_string(0);
       
        if(mp.find(LT) != mp.end()){ 
            cout << "kese ho sare" <<endl;
        }
        else{
            mp[LT] = totalWays(str,i,k-1,true);
        }
        if(mp.find(LF) != mp.end()){
            cout << "kese ho sare" <<endl;

        }
        else{
            mp[LF] = totalWays(str,i,k-1,false);
        }
        if(mp.find(RT) != mp.end()){
            cout << "kese ho sare" <<endl;

         }
        else{
            mp[RT] = totalWays(str,k+1,j,true);
        }
        if(mp.find(RF) != mp.end()){ 
            cout << "kese ho sare" <<endl;

        }
        else{
            mp[RF] = totalWays(str,k+1,j,false);
        }
        
        cout << mp[LT] <<" " << mp[LF] << " " << mp[RT] << " " << mp[RF] << endl; 
        Ans += evalute(str,k,isTrue,mp[LT],mp[LF],mp[RT],mp[RF]);
        cout << Ans <<endl;
    }
    return mp[idx] = Ans;
}
int main(){

    string str; cin >> str;

    // cout << booleanParanthizaton(str,0,str.length()-1,true) << endl;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){

            dp[i][j][0] = -1;  // isTrue = false
            dp[i][j][1] = -1;  // isTrue = true
        }
    }
    cout << countWays(str,0,str.length()-1,true) << endl;
    
    mp.clear();
    // cout << totalWays(str,0,str.length()-1,true) << endl;
    
    for(auto it : mp){
        cout << it.first << " " << it.second <<endl; 
    }
    return 0;
}