#include<iostream>
#define MAXSIZE 20

typedef struct{
    int data[MAXSIZE];
    int top;
}stack_;

void init_stack(stack_* s){
    s->top=-1;
}

bool is_full(stack_* s){
    if(s->top==MAXSIZE-1)return true;
    return false;
}

bool is_empty(stack_* s){
    if(s->top==-1)return true;
    return false;
}

void push(stack_* s,int n){
    int val;
    if(is_full(s))std::cout<<"failed because of full"<<std::endl;
    else{
        for(int i=0;i<n;i++){
            std::cout<<"请输入要入队的元素:"<<std::endl;
            std::cin>>val;
            s->top++;
            s->data[s->top]=val;
        }
    }
}

void pop(stack_* s){
    if(is_empty(s))std::cout<<"failed because of empty"<<std::endl;
    else{
        s->top--;       
    }
}

int main(){
    stack_* s=new stack_;
    init_stack(s);
    push(s,3);
    delete s;
    return 0;
}