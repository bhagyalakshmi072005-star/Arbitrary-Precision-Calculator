#include"APC.h"

void insert_last(struct list **head,struct list **tail,int data)
{
    struct list *temp=(struct list*)malloc(sizeof(struct list));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(*head==NULL)
    {
        *head=temp;
        *tail=temp;
        return;
    }
    (*tail)->next=temp;
    temp->prev=*tail;
    *tail=temp;
}

void print_list(struct list *head,int is_negative)
{
    // Remove leading zeros for clean output (unless the whole number is just 0)
    while(head!=NULL&&head->data==0&&head->next!=NULL)
    {
        struct list *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }

    if(is_negative&&(head!=NULL&&!(head->data==0&&head->next==NULL)))
    {
        printf("-");
    }
    struct list *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int parse_number(char *str, struct list **head, struct list **tail)
{
    int i=0;
    int is_neg=0;

    if(str[0]=='-')
    {
        is_neg=1;
        i=1;
    }
    else if(str[0]=='+')
    {
        i=1;
    }

    while(str[i]!='\0')
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            insert_last(head,tail,str[i]-'0');
        }
        else
        {
            printf("Error: Invalid character '%c' in input\n", str[i]);
            exit(1);
        }
        i++;
    }
    return is_neg;
}

int main(int argc,char *argv[])
{
    if(argc!=4)
    {
        printf("Usage: ./APC.out <num1> <op> <num2>\n");
        return 1;
    }

    struct list *head1=NULL,*tail1=NULL;
    struct list *head2=NULL,*tail2=NULL;
    struct list *res_head=NULL,*res_tail=NULL;

    int sign1 = parse_number(argv[1], &head1, &tail1);
    char op=argv[2][0];
    int sign2 = parse_number(argv[3], &head2, &tail2);

    if(op=='+')
    {
        if(sign1==sign2)
        {
            add_lists(tail1,tail2,&res_head,&res_tail);
            print_list(res_head,sign1);
        }
        else
        {
            int cmp=compare_lists(head1,head2);
            if(cmp>=0)
            {
                subtract_lists(tail1,tail2,&res_head,&res_tail);
                print_list(res_head,sign1);
            }
            else
            {
                subtract_lists(tail2,tail1,&res_head,&res_tail);
                print_list(res_head,sign2);
            }
        }
    }
    else if(op=='-')
    {
        // Equivalent to num1 + (-num2)
        sign2 = !sign2;
        if(sign1==sign2)
        {
            add_lists(tail1,tail2,&res_head,&res_tail);
            print_list(res_head,sign1);
        }
        else
        {
            int cmp=compare_lists(head1,head2);
            if(cmp>=0)
            {
                subtract_lists(tail1,tail2,&res_head,&res_tail);
                print_list(res_head,sign1);
            }
            else
            {
                subtract_lists(tail2,tail1,&res_head,&res_tail);
                print_list(res_head,sign2);
            }
        }
    }
    else if(op=='x'||op=='*')
    {
        multiply_lists(tail1,tail2,&res_head,&res_tail);
        int final_sign = (sign1 != sign2);
        print_list(res_head, final_sign);
    }
    else if(op=='/')
    {
        divide_lists(head1,tail1,head2,tail2,&res_head,&res_tail);
        int final_sign = (sign1 != sign2);
        print_list(res_head, final_sign);
    }
    else
    {
        printf("Error: Invalid operator. Use +, -, x, or /\n");
    }

    return 0;
}