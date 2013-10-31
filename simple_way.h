#ifndef _SIMPLE_WAY_H
#define _SIMPLE_WAY_H


#include "cope_file.h"

struct tree{
    struct tree *father;
    struct tree *brother;
    struct tree *child;
    int line;
    struct trip *line_recond;
};

struct trip * search_point_find( char *route_name,struct trip **data ){
    int i=0;
    while( strcmp( data[i]->name1,route_name )!=0 ||( i>list_count-1 ) ){
        i++;
    }
    return data[i];
}
struct tree * BFLS( struct trip **data,char *start_road,char *end_road ){
    struct tree *p1,*p2;
    struct tree *root,*chain_root;
    struct tree *creat;
    struct trip *line,*start,*p;
    p1=( struct tree *)malloc( sizeof( struct tree ) );
    start=search_point_find( start_road,data );
    p1->line_recond=start;
    p1->line_recond->touch_check=1;
    p1->child=NULL;
    p1->father=NULL;
    p1->brother=NULL;
    root=p1;
    while( 1 ){
        p1=root;
        chain_root=NULL;
        p2=NULL;
        while( p1!=NULL ){
            line=p1->line_recond->next;
            while( line!=NULL ){
               p=search_point_find( line->name1,data );
                if( p->touch_check ){
                    line=line->next;
                    continue;
                }
                p->touch_check=1;
                creat=( struct tree * )malloc( sizeof( struct tree ) );
                creat->line_recond=p;
                if( chain_root==NULL ){
                    chain_root=creat;
                    root->child=chain_root;
                    chain_root->brother=NULL;
                    chain_root->father=p1;
                    chain_root->child=NULL;
                    p2=chain_root;
                }
                else {
                    p2->brother=creat;
                    p2=p2->brother;
                    p2->brother=NULL;
                    p2->father=p1;
                    p2->child=NULL;
                }
                if( strcmp( p2->line_recond->name1,end_road )==0 ){
                    return p2;
                }
                line=line->next;
            }
            p1=p1->brother;
        }
        root=chain_root;
    }
}
struct tree *inverse_line( struct tree *back_print ){
    struct tree *t=NULL,*r=NULL,*y=NULL;
    if( back_print==NULL ){
        return NULL;
    }
    y=back_print;
    while( y!=NULL ){
        t=y->father;
        y->father=r;
        r=y;
        y=t;
    }
    return r;
    
}
void Find_Simple_Way( )
{
    struct trip *data[MAXNODE];
    struct tree *format_print,*back_print;
    int count=0;
    int i=0,j=0,start_num,end_num;
    printf( "输入起点景点编号：" );
    scanf("%d",&start_num);
    printf( "输入终点景点编号： " );
    scanf("%d",&end_num);
    getchar();
    read_way( data,0);
    while(data[i]->num_line1!=start_num)
        i++;
     while(data[j]->num_line1!=end_num)
         j++;
    back_print=BFLS( data,data[i]->name1,data[j]->name1);
    format_print=inverse_line( back_print );
    printf("\n   ---- 路线如下 ： ----   \n");
    while( format_print!=NULL ){
        printf( "%s>",format_print->line_recond->name1 );
        count++;
        format_print=format_print->father;
    }
    printf( "\n途径%d个景点\n",count );
}
#endif
