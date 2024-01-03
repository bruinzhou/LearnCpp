#include<iostream>
#include<queue>

int main(){
    std::queue<int> q;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++) q.push(i+1);
    while(q.size()>2){
        std::cout<<q.front()<<" ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    std::cout<<std::endl;
    while(!q.empty()){
        std::cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}