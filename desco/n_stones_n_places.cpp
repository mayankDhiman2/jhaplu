int Stones(vector<int>& v){
    
    int ans=0;
    int s=0;
    
    for(int i=0;i<v.size();i++){
        s+=v[i];
        if(s!=i+1)ans++;
    }
    return ans;    
}