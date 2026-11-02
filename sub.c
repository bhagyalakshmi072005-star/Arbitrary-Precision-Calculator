#include"APC.h"

int compare_lists(struct list *head1,struct list *head2)
{
    int len1=0,len2=0;
    struct list *t1=head1,*t2=head2;
    while(t1!=NULL) {len1++;t1=t1->next;}
    while(t2!=NULL) {len2++;t2=t2->next;}

    if(len1>len2)return 1;
    if(len1<len2)return -1;

    t1=head1;
    t2=head2;
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->data>t2->data)return 1;
        if(t1->data<t2->data)return -1;
        t1=t1->next;
        t2=t2->next;
    }
    return 0;
}

void subtract_lists(struct list *tail1,struct list *tail2,struct list **res_head,struct list **res_tail)
{
    struct list *t1=tail1;
    struct list *t2=tail2;
    int borrow=0;

    while(t1!=NULL)
    {
        int sub=t1->data-borrow;
        if(t2!=NULL)
        {
            sub-=t2->data;
            t2=t2->prev;
        }

        if(sub<0)
        {
            sub+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }

        struct list *temp=(struct list*)malloc(sizeof(struct list));
        temp->data=sub;
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
        t1=t1->prev;
    }

    while(*res_head!=NULL&&(*res_head)->data==0&&(*res_head)->next!=NULL)
    {
        struct list *temp=*res_head;
        *res_head=(*res_head)->next;
        (*res_head)->prev=NULL;
        free(temp);
    }
}