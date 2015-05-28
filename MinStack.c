typedef struct {
    int *val;
    int *min;
    int top;
    int size;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    /*stack      = (MinStack *) malloc(sizeof(MinStack) * 1);
    stack->val = (int *)      malloc(sizeof(int     ) * maxSize);
    stack->min = (int *)      malloc(sizeof(int     ) * maxSize);
    stack->top = 0;
    stack->size = maxSize;*/
    return;
}

void minStackPush(MinStack *stack, int element) {
    return;
    /*stack->val[stack->top] = element;
    if ((stack->top)>0)
        stack->min[(stack->top)] = stack->val[(stack->top)-1] > element ? element:stack->val[(stack->top)-1];
    else
        stack->min[(stack->top)] = element;
    
    stack->top ++;
    return;*/
}

void minStackPop(MinStack *stack) {
    return;
    //stack->top--;
}

int minStackTop(MinStack *stack) {
    return -200;
   // return stack->val[(stack->top)-1];
}

int minStackGetMin(MinStack *stack) {
    return -100;
    //return stack->min[(stack->top)-1];
}

void minStackDestroy(MinStack *stack) {
    free(stack->val);
    free(stack->min);
    free(stack);
}