#include"APC.h"

void add_lists(struct list *tail1,struct list *tail2,struct list **res_head,struct list **res_tail)
{
    struct list *t1=tail1;
    struct list *t2=tail2;
    int carry=0;

    while(t1!=NULL||t2!=NULL||carry!=0)
    {
        int sum=carry;
        if(t1!=NULL)
        {
            sum+=t1->data;
            t1=t1->prev;
        }
        if(t2!=NULL)
        {
            sum+=t2->data;
            t2=t2->prev;
        }

        carry=sum/10;
        int digit=sum%10;

        struct list *temp=(struct list*)malloc(sizeof(struct list));
        temp->data=digit;
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