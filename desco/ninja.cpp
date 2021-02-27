int ans=c;
for(int i=0;i<min(n,k);i++){
    int cur=0;
    for(int j=i;j<n;j+=k){
        cur+=a[j];
        if(cur<0)
            cur=0;
        ans=max(ans,cur+c);
    }
}