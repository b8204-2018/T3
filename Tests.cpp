#include "gtest\gtest.h"
#include "Stack.h"
TEST(Stack,Stack_Is_worcking){
    Stack Stack1;
    int elem=1213;
    Stack1.Push(elem);
    Stack1.Pop();
    Stack1.Push(elem);
    EXPECT_EQ(Stack1.oc_cells,1);
};
TEST(Stack,Stack_Is_empty){
    Stack Stack1;
    EXPECT_EQ(Stack1.oc_cells,0);
}
