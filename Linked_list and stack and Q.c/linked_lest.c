#include <stdio.h>
#include <stdlib.h>
#include "linked_lest.h"
struct data
{
        int s;
        struct data *next;
};
struct data *start=NULL;
void create(void)
{
    struct data *temp;
    temp=(struct data *)malloc(sizeof(struct data));
    if(temp==NULL)
    {
        printf(" no space in mimory\n");
    }
    else
    {
        if(start==NULL)
        {
            printf("enter the data \n");
            scanf("%d",&temp->s);
            temp->next=NULL;
            start=temp;
        }

        else
            printf(" these linked list are created before so kindly chose insert option\n");
    }
}
void add_at_last(void)
{

        struct data *temp,*ptr;
        temp=(struct data *)malloc(sizeof(struct data));
        if(temp==NULL)
            printf("no memory space\n");
        else
       {
            printf("enter the data \n" );
            scanf("%d",&temp->s );
            temp->next =NULL;
            if(start==NULL)
                start=temp;
        else
        {
            ptr=start;
            while(ptr->next !=NULL)
                ptr=ptr->next ;
            ptr->next =temp;
        }
    }
}
void add_at_start(void)
{
    struct data * temp;
    temp=(struct data *)malloc(sizeof(struct data));
    printf(" enter the data \n");
    scanf("%d",&temp->s);
    if (start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}
void add_at_middle(int n)
{
    struct data *temp,*ptr;
    int nn;
    temp=(struct data *)malloc(sizeof(struct data));
    printf(" enter the data \n");
    scanf("%d",&temp->s);
    printf("enter the place of data \n");
    scanf("%d",&nn);
    if (start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        ptr=start;
        for(int i=0;i<nn;i++)
        {
            if(nn<=n)
                ptr=ptr->next;
            else
                {
                    printf("the space not found \n");
                    return;
                }
        }
        if(nn<n)
        {
            temp->next=ptr->next;
            ptr->next=temp;
        }
        else if(nn==n)
        {
            ptr->next=temp;
            temp->next=NULL;
        }
    }
}
void delat_at_start(void)
{
    struct data *ptr;
    if(start==NULL)
    {
        printf(" no linked list\n");
        return;
    }
        else
        {
                ptr=start;
                start=start->next ;
                free(ptr);
        }
}
void dalet_at_list(void)
{
    struct data *temp,*ptr;
    if(start==NULL)
    {
            printf(" no linked list \n");
            return;
    }
    else if(start->next ==NULL)
    {
            ptr=start;
            start=NULL;
            free(ptr);
    }
    else
    {
            ptr=start;
            while(ptr->next!=NULL)
            {
                    temp=ptr;
                    ptr=ptr->next;
            }
            temp->next=NULL;
            free(ptr);
        }
}
void dalet_at_midlle(void)
{
    int i,pos;
    struct data *temp,*ptr;
    if(start==NULL)
    {
        printf("no linked list\n");
        return;
    }
    else
    {
        printf("enter the place:\t");
        scanf("%d",&pos);
        if(pos==0)
        {
            ptr=start;
            start=start->next ;
            free(ptr);
        }
        else
        {
            ptr=start;
            for(i=0;i<pos;i++)
        {
            temp=ptr; ptr=ptr->next ;
            if(ptr==NULL)
            {
                printf("\nPosition not Found:\n");
                return;
            }
        }
            temp->next =ptr->next ;
            free(ptr);
        }
    }
}
void print(void)
{
    struct data *ptr;
    ptr=start;
    do
    {
        printf("%d\t",ptr->s);
        ptr=ptr->next;
    }
    while(ptr!=NULL);
    printf("\n");
}
