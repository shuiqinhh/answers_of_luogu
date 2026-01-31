# LuoguCode练习

## 入门篇：

- P1765：手机    （NOI 枚举）
```cpp
#include<iostream>
#include<cstring>
int main(){
    std::string s,a,b,c,d;
    int i,j,n;
    std::getline(std::cin,s);   //不会读入换行符
    a="adgjmptw ";
    b="behknqux";
    c="cfilorvy";
    d="sz";
    n=0;
    for(i=0;i<s.length();i++){
        for(j=0;j<a.length();j++){
            if(s[i]==a[j]){
                n++;
            }
        }
        for(j=0;j<b.length();j++){
            if(s[i]==b[j]){
                n=n+2;
            }
        }
        for(j=0;j<c.length();j++){
            if(s[i]==c[j]){
                n=n+3;
            }
        }
        for(j=0;j<d.length();j++){
            if(s[i]==d[j]){
                n=n+4;
            }
        }
    }
    std::cout<<n;
    return 0;
}
```
std::getline使用：getline(std::cin,s)；读取的一整行字符串输入到s中（默认不会读换行符），getline还可加一个参数用于指定分隔符,读到分隔符就停止。


- P1830:轰炸|||  (枚举遍历)

```cpp
#include<iostream>
#include<vector>
int main(){
    int n,m,x,y,x1,x2,y1,y2,a,b,lun,i,j,last;
    std::cin>>n>>m>>x>>y;
    int explode[x][4];
    for(i=0;i<x;i++){
        std::cin>>explode[i][0]>>explode[i][1]>>explode[i][2]>>explode[i][3];
    }
    for(i=1;i<=y;i++){
        std::cin>>a>>b;
        lun=0;
        for(j=0;j<x;j++){
            if(a<=explode[j][2]&&a>=explode[j][0]&&b<=explode[j][3]&&b>=explode[j][1]){
                lun=lun+1;
                last=j+1;
            }
        }
        if(lun!=0){
            std::cout<<'Y'<<' '<<lun<<' '<<last<<std::endl;
        }
        else{std::cout<<'N'<<std::endl;}
    }
    return 0;
    
}
```
- P1876: 乘积最大3
  由基本不等式知各分支越相近时越接近最大值。只需分类讨论后循环输出。
```cpp
#include<iostream>

int main(){
    long long n,m;
    std::cin>>n>>m;
    if(n%m==0){
        for(int i=1;i<=m;i++){std::cout<<n/m<<' ';}
    }
    else{
        int i=n%m;
        for(int j=1;j<=m-i;j++){std::cout<<n/m<<' ';}
        for(int j=1;j<=i;j++){std::cout<<n/m+1<<' ';}
    }
    return 0;
}
```

- P1867: MC生存经验：尤其注意血量条件与while循环中先扣经验还是先加等级,同时需要注意pow函数始终返回double类型，注意将其转化为int的操作（static_cast<目标类型>(表达式)）
```cpp
#include<iostream>
#include<cmath>
int main(){
    int n,rank,a,ex,modex;
    double blood,x;
    blood=10.0;
    ex=0;
    rank=0;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>x>>a;
        blood=blood-x;
        if(blood>0){
            if(blood>10){
                blood=10;
            }
            ex=ex+a;}
        else{break;}
    }
    modex=ex;
    while(modex>=static_cast<int>(pow(2, rank))){
        modex=modex-static_cast<int>(pow(2, rank));
        rank=rank+1;
    }
    std::cout<<rank<<' '<<modex;
    return 0;
}
```

- P1888: 三角函数 :注意求最大公约数的函数std::__gcd的使用方法
```cpp
#include<iostream>
#include <algorithm>
int main(){
    long long a,b,c,max,min,p;
    std::cin>>a>>b>>c;
    max=a;min=a;
    if(b>max){max=b;}
    if(c>max){max=c;}
    if(b<min){min=b;}
    if(c<min){min=c;}
    p=std::__gcd(max,min);
    std::cout<<min/p<<'/'<<max/p;
    return 0;
}
```

- P1897 电梯里的尴尬（数组元素极值求法、sort排序）
```cpp
#include<iostream>
#include<algorithm>
int main(){
    int time=0,floor=0;
    int n,i;
    std::cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        std::cin>>a[i];
    }
    int max= *std::max_element(a,a+n);     //求普通数组中元素最大值，针对vector数组可以用.begin方法
    int openf=1;
    std::sort(a,a+n);                     //升序排列数组
    for(i=1;i<n;i++){
        if(a[i-1]<a[i]){
            openf++;
        }
    }
    time=time+max*10+n+openf*5;
    std::cout<<time<<std::endl;
    return 0;
}
```

-P1914 小书童（字符串转换）
```cpp
#include<iostream>

int main(){
    int n;
    char s[50];
    std::cin>>n;
    std::cin>>s;
    for(int i=0;s[i]!='\0';i++){
        s[i]=(s[i]-'a'+n)%26+'a';
    }
    std::cout<<s<<std::endl;
    return 0;
}
```
