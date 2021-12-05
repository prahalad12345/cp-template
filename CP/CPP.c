#include<stdio.h>

char caps(char *s){
    *s+=32;
    return *s;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long x,y,count=0;
        scanf("%lld %lld",&x,&y);
        if(y-x>0)
            count+=((y-x)/10);
        else 
            count+=((x-y)/10);

        if((y-x)%10!=0 || (x-y)%10!=0 )
            count+=1;
        printf("%lld\n",count);
        char c='A';
        printf("%c",caps(&c));
    }
}
/* input a string and traverse using while(ch[i]!='\0' end of character)*/
