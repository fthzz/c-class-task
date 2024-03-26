#include<iostream>
typedef struct QueueNode{
    int data;
    QueueNode* next;
    QueueNode(int val):data(val),next(nullptr){}
}queuenode;

typedef struct QueueList{
    queuenode* front;
    queuenode* rear;
}queuelist;

void init_queuelist(queuelist* q){
    queuenode* head_node=new queuenode(-1);//首元节点
    q->front=head_node;
    q->rear=head_node;
}

bool is_empty(queuelist* q){
    if(q->front==q->rear)return true;
    return false;
}

void insert(queuelist* q,int n){
    int val;
    
    for(int i =0;i<n;i++){
        std::cout<<"请输入要入队的元素:"<<std::endl;
        std::cin>>val;
        queuenode* p=new queuenode(val);
        q->rear->next=p;
        q->rear=p;
    }
}

void pop(queuelist* q){
    if(is_empty(q))std::cout<<"failed because of empty"<<std::endl;
    else{
        queuenode* s=q->front->next;
        q->front->next=s->next;
        std::cout<<s->data<<"已出队"<<std::endl;
        delete s;
    }
}

void destroy_queuelist(queuelist* q){
    queuenode* s;
    if(is_empty(q))delete q->front;
    else{
        while(q->front->next!=nullptr){
            s=q->front->next;
            q->front=s->next;
            delete s;
        }
        delete q->front;
    }
}

int main(){
    queuelist* q=new queuelist;
    init_queuelist(q);
    insert(q,3);
    pop(q);
    destroy_queuelist(q);
    std::cout<<"success";
    delete q;
    return 0;
}