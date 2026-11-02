#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *next;
    struct list *prev;
};
void insert_last(struct list **head,struct list **tail,int data);
void print_list(struct list *head,int is_negative);
void add_lists(struct list *tail1,struct list *tail2,struct list **res_head,struct list **res_tail);
int compare_lists(struct list *head1,struct list *head2);
void subtract_lists(struct list *tail1,struct list *tail2,struct list **res_head,struct list **res_tail);
void multiply_lists(struct list *tail1,struct list *tail2,struct list **res_head,struct list **res_tail);
void divide_lists(struct list *head1,struct list *tail1,struct list *head2,struct list *tail2,struct list **res_head,struct list **res_tail);

#endif