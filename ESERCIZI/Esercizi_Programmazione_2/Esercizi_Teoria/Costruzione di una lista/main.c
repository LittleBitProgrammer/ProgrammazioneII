#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DATA;
struct linked_list{
            DATA d;
            struct linked_list *next;
            };
typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;
LINK array_to_list(DATA []);
int main()
{
    DATA c_arr[100];
    printf("\nInserisci Stringa:\n>>");
    gets(c_arr);
    LINK head_list,p_list;
    head_list=array_to_list(c_arr);
    p_list=head_list;
    while(p_list!=NULL)
    {
        putchar(p_list->d);
        p_list=p_list->next;
    }
    puts("");
return 0;
}

LINK array_to_list(DATA s[])
{
    LINK head;
    if(s[0]=='\0')
        return NULL;
    else
    {
        head=malloc(sizeof(ELEMENT));
        head->d=s[0];
        head->next=array_to_list(s+1);
        return head;
    }
}
