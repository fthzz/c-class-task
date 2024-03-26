#include<iostream>
#define MAXSIZE 20
typedef struct QueueList{
    int data[MAXSIZE];
    int front,rear;
}queuelist;

void init_queue(queuelist* q){
    q->front=0;
    q->rear=0;
}

bool is_empty(queuelist* q){
    if(q->front==q->rear)return true;
    return false;
}

bool is_full(queuelist* q){
    if((q->rear+1)%MAXSIZE==q->front)return true;
    return false;
}

void insert(queuelist* q,int n){
    int val;
    if(is_full(q))std::cout<<"failed to insert because of full"<<std::endl;
    else{
        for(int i =0;i<n;i++){
            std::cout<<"请输入要入队的元素:"<<std::endl;
            std::cin>>val;
            q->data[q->rear]=val;
            q->rear=(q->rear+1)%MAXSIZE;
        }
    }
}

void pop(queuelist* q){
    if(is_empty(q))std::cout<<"failed to delete because of empty"<<std::endl;
    else{
        q->front=(q->front+1)%MAXSIZE;
    }
}

void show(queuelist* q){
    if(is_empty(q))std::cout<<"failed because of empty"<<std::endl;
    else{
        for(int i =q->front;i<q->rear-1;i++){
            std::cout<<q->data[i]<<"->";
        }
        std::cout<<q->data[q->rear-1];
    }
}

int queue_length(queuelist* q){
    return (q->rear-q->front+MAXSIZE)%MAXSIZE;
}

int main(){
    queuelist* q=new queuelist;
    init_queue(q);
    insert(q,3);
    show(q);
    delete q;
    return 0;
}