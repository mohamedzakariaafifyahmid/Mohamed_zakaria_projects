#include <stdio.h>
#include <stdlib.h>
#include"linked_lest.h"
void main(void)
{
    int n=0,xx;
    char x;
    while(1)
    {
        printf(" these program made to control in \n 1:linked list \n 2:STACK \n 3:Q \n so kindly write the order as following\n");
        scanf("%d",&xx);
            if(xx==1)
            {
                l:
                printf(" 1:create lined list \n");
                printf(" 2:add at last \n");
                printf(" 3:add at start \n");
                printf(" 4:add at middle \n");
                printf(" 5:remove at last \n");
                printf(" 6:remove at start \n");
                printf(" 7:remove at midlle \n");
                printf(" 8:print the linked lest \n");
                printf(" 9:end \n");
                scanf(" %d",&x);
                if(x==1)
                {
                     printf(" you chose 1 create \n");
                     create();
                     goto l;
                }
                    else if(x==2)
                {
                    printf("you chose 2 add at last \n");
                    add_at_last();
                    goto l;
                }
                else if(x==3)
                {
                    printf("you chose 3 add at start \n");
                    add_at_start();
                    goto l;
                }
                else if(x==4)
                {
                    printf("you chose 4 add at middle\n");
                    add_at_middle(n);
                    goto l;
                }
                else if(x==5)
                {
                    printf("you chose 5 dalet at start \n");
                    delat_at_start();
                    goto l;
                }
                else if(x==6)
                {
                    printf("you chose 6 dalet at list \n");
                    dalet_at_list();
                    goto l;
                }
                else if(x==7)
                {
                    printf("you chose 7 dalet at midlle \n");
                    dalet_at_midlle();
                    goto l;
                }
                else if(x==8)
                {
                    printf("you chose 8 print \n");
                    print ();
                    goto l;
                }
                else if(x==9)
                     break;
                else
                     printf(" you chose %d \n not found back to menu \n",x);
                n++;
            }
        else if(xx==2)
            {
                ss:
                printf(" 1:create stack \n");
                printf(" 2:add \n");
                printf(" 3:remove  \n");
                printf(" 4:print the stack \n");
                printf(" 5:end \n");
                scanf(" %d",&x);
                if(x==1)
                {
                     printf(" you chose 1 create \n");
                     create();
                     goto ss;
                }
                else if(x==2)
                {
                    printf("you chose 2 add  \n");
                    add_at_start();
                    goto ss;
                }
                else if(x==3)
                {
                    printf("you chose 4 delat \n");
                    delat_at_start();
                    goto ss;
                }
                else if(x==4)
                {
                    printf("you chose 8 print \n");
                    print ();
                    goto ss;
                }
                else if(x==5)
                     break;
                else
                     printf(" you chose %d \n not found back to menu \n",x);
            }
        else if(xx==3)
            {
                Q:
                printf(" 1:create Q \n");
                printf(" 2:add \n");
                printf(" 3:remove  \n");
                printf(" 4:print the stack \n");
                printf(" 5:end \n");
                scanf(" %d",&x);
                if(x==1)
                {
                     printf(" you chose 1 create \n");
                     create();
                     goto Q ;
                }
                else if(x==2)
                {
                    printf("you chose 2 add  \n");
                    add_at_start();
                    goto Q ;
                }
                else if(x==3)
                {
                    printf("you chose 4 delat \n");
                     dalet_at_list();
                     goto Q ;
                }
                else if(x==4)
                {
                    printf("you chose 8 print \n");
                    print ();
                    goto Q ;
                }
                else if(x==5)
                     break;
                else
                     printf(" you chose %d \n not found back to menu \n",x);
            }
        else
            printf("wrong data \n");
    }
}
