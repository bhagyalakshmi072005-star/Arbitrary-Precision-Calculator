#include"APC.h"

void multiply_single_digit(struct list *tail1,int digit,struct list **res_head,struct list **res_tail)
{
    struct list *t1=tail1;
    int carry=0;

    while(t1!=NULL||carry!=0)
    {
        int prod=carry;
        if(t1!=NULL)
        {
            prod+=(t1->data*digit);
            t1=t1->prev;
        }

        carry=prod/10;
        int d=prod%10;

        struct list *temp=(struct list*)malloc(sizeof(struct list));
        temp->data=d;
        temp->next=*res_head;
        temp->prev=NULL;
        if(*res_head!=NULL)
        {
            (*res_head)->prev=temp;
        }
        else
        {
            *res_tail=temp;
        }
        *res_head=temp;
    }
}

void append_zeros(struct list **head,struct list **tail,int count)
{
    for(int i=0;i<count;i++)
    {
        struct list *temp=(struct list*)malloc(sizeof(struct list));
        temp->data=0;
        temp->next=NULL;
        temp->prev=*tail;
        if(*head==NULL)
        {
            *head=temp;
            *tail=temp;
        }
        else
        {
            (*tail)->next=temp;
            *tail=temp;
        }
    }
}

void multiply_lists(struct list *tail1,struct list *tail2,struct list **res_head,struct list **res_tail)
{
    struct list *t2=tail2;
    int shift=0;

    struct list *final_head=NULL,*final_tail=NULL;
    insert_last(&final_head,&final_tail,0);

    while(t2!=NULL)
    {
        struct list *row_head=NULL,*row_tail=NULL;
        multiply_single_digit(tail1,t2->data,&row_head,&row_tail);

        if(!(row_head->data==0&&row_head->next==NULL))
        {
            append_zeros(&row_head,&row_tail,shift);
            struct list *sum_head=NULL,*sum_tail=NULL;
            add_lists(final_tail,row_tail,&sum_head,&sum_tail);
            final_head=sum_head;
            final_tail=sum_tail;
        }

        t2=t2->prev;
        shift++;
    }

    *res_head=final_head;
    *res_tail=final_tail;
}