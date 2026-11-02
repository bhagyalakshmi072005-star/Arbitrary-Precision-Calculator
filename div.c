#include"APC.h"

// Check if list represents zero
int is_zero(struct list *head)
{
    return (head!=NULL&&head->data==0&&head->next==NULL);
}

// Division function
void divide_lists(struct list *head1,struct list *tail1,struct list *head2,struct list *tail2,struct list **res_head,struct list **res_tail)
{
    if(is_zero(head2))
    {
        printf("Error: Division by zero\n");
        exit(1);
    }

    if(is_zero(head1)||compare_lists(head1,head2)<0)
    {
        insert_last(res_head,res_tail,0);
        return;
    }

    // Repeated subtraction-based division counter
    long long quotient=0;
    struct list *current_head=NULL,*current_tail=NULL;
    
    // Copy head1 to working list for subtraction
    struct list *t=head1;
    while(t!=NULL)
    {
        insert_last(&current_head,&current_tail,t->data);
        t=t->next;
    }

    while(compare_lists(current_head,head2)>=0)
    {
        // Subtract divisor from current dividend
        struct list *sub_head=NULL,*sub_tail=NULL;
        subtract_lists(current_tail,tail2,&sub_head,&sub_tail);
        current_head=sub_head;
        
        // Recalculate tail for current_head
        struct list *curr_t=current_head;
        while(curr_t&&curr_t->next) curr_t=curr_t->next;
        current_tail=curr_t;

        quotient++;
    }

    // Convert quotient to linked list
    char q_str[50];
    sprintf(q_str,"%lld",quotient);
    int i=0;
    while(q_str[i]!='\0')
    {
        insert_last(res_head,res_tail,q_str[i]-'0');
        i++;
    }
}