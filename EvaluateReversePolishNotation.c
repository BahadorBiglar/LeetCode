int evalRPN(char** tokens, int tokensSize) {
    int pos, top=0, result;
    bool is_operator;
    char ch;
    int stack[tokensSize];
    
    for (pos = 0; pos<tokensSize; pos++){
        ch=tokens[pos][0];
        is_operator=true;
        if ((ch>='0') && (ch<='9'))
            is_operator=false;
        else if (tokens[pos][1]!='\0')
            is_operator=false;

        if (is_operator){
            switch(ch){
                case '+': result = stack[top-2]+stack[top-1]; stack[top-2] = result; top--; break;
                case '-': result = stack[top-2]-stack[top-1]; stack[top-2] = result; top--; break;
                case '*': result = stack[top-2]*stack[top-1]; stack[top-2] = result; top--; break;
                case '/': if (stack[top-1]==0) return 0; result = stack[top-2]/stack[top-1]; stack[top-2] = result; top--; break;
            }
        }
        else{
                stack[top] = atoi(tokens[pos]);
                top++;
        }
    }
    return stack[0];
}