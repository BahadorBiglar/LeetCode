bool isValid(char* s) {
    int len=strlen(s);
    char stack[len];
    int top = 0;
    
    for (int i=0; *(s+i); i++)
        if ((*(s+i)=='(') || (*(s+i)=='[') || (*(s+i)=='{'))
            stack[top++] = (*(s+i));
        else{
            top--;
            if (top<0)
                return false;
            char temp = stack[top];
            if (*(s+i)==')' && (temp != '('))
                return false;
            if (*(s+i)==']' && (temp != '['))
                return false;
            if (*(s+i)=='}' && (temp != '{'))
                return false;
        }
    if (top!=0)
        return false;
    return true;
}