#include <iostream>
#include "Stack.h"
#define IS_FULL "Stack is Full"
#define IS_EMPTY "Stack is Empty"
using namespace std;
    Stack::Stack(){
       int oc_cells = 0;
        int* stack_body= new int [20];
    };

void Stack::Push(int elem) {
      //  try {
        //    if (oc_cells < 20) {
          //      throw IS_FULL;
           // }
            stack_body[oc_cells] = elem;
            oc_cells = oc_cells + 1;
        }

    //}

void  Stack::Pop() {
    //try {
      //      if (oc_cells > 0) {
        //        throw IS_EMPTY;
            //}
            stack_body[oc_cells] = 0;
            oc_cells = oc_cells - 1;

        }
    //}

void  Stack::show() {
        int i = 0;

        while (i <= oc_cells) {
            cout<<i<<" "<<stack_body[i] << endl;
            i++;
        }

    }
