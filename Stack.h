

#ifndef STACK_STACK_H
#define STACK_STACK_H
struct Stack {
    int oc_cells=0 ;
    int *stack_body=new int [20] ;
    Stack();

    void Push(int ) ;

    void Pop() ;

    void show() ;
};


#endif //STACK_STACK_H
