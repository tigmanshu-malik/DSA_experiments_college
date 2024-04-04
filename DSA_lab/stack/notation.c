#include<stdio.h>

int max = 30;
int top = -1;
int stack[30];

void push(char a){

    if(top == max - 1){

        printf("Stack overflow !!! \n");
        return;
    }

    top++;
    stack[top] = a;

}

void pop(){

    if(top == -1){

        printf("Stack underflow !!!\n");
        return;
    }

    if(stack[top] != '(')
        printf("%c", stack[top]);
    top--;
}

int count_ele(char string[30]){

    int count = 0;

    for(int i = 0; string[i] != '\0'; i++)
        count++;

    return count;    
}

int precedence(char a){

    if(a == '*' || a == '/')
        return 2;

    else if(a == '+' || a == '-')
        return 1;

    else 
        return 0;       
}

void infix_postfix(){

    char expression[30];

    printf("Enter infix expression :-\n");
    getchar();
    fgets(expression, 30, stdin);

    expression[count_ele(expression)] = ')';

    push('(');

    for(int i = 0;expression[i] != '\0' ; i++){

        if(top == -1)
            push('(');

        char x = expression[i];

        if(('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
            printf("%c", x);

        else{

            if(x == ')'){

                while(x != '(' && top != -1)
                    pop();    
            
            }

            else{

                if(precedence(x) >= precedence(stack[top]))
                    push(x);

                else{

                    while(stack[top] != '(')
                       pop();

                    push(x);    
                }  
            }
        }    

    }


}

void postfix_eval(){

    char expression[30];

    printf("Enter infix expression :-\n");
    getchar();
    fgets(expression, 30, stdin);

    expression[count_ele(expression)] = ')';

    for(int i = 0; expression[i] != '\0'; i++){

        char x = expression[i];

        while(x != ')')

        if(('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
            push(x);

        else if {


        }    
    }
}

int main(){

    while(1){

        int choice;
        printf("\n1. Convert infix to postfix\n2. Evaluate postfix\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                infix_postfix();
                break;

            case 2:

                    

        }
    }
}