#ifndef _COPE_FILE_H
#define _COPE_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAXNODE 14

static int list_count=0;
int path[MAXNODE],visited[MAXNODE];
struct trip{
    char name1[30];
    int num_line1;
    int touch_check;
    struct trip *next;
};

struct trip * cope_with_data( char * );

void read_way( struct trip **data,int k ){
    FILE *fd;
    char buf[256];
    int i=k;
    fd=fopen( "info.txt","r" );
    while( (fgets( buf,sizeof( buf ),fd ))!=NULL ){
        data[i++]=cope_with_data( buf );
        list_count++;
    }
    fclose( fd );
}

struct trip * cope_with_data( char *line ){
    struct trip *head,*q1,*q2;
    int start=0;
    char name[15][MAXNODE]={'\0'};
    int num_line[15];
    char get[15][10]={'\0'};
    int i=0,j=0,k=0,d=0,l=0;
    
    while( i < (int)strlen( line ) ){
        d=0;
        if( line[i]!=' ' &&( line[i]<'0'||line[i]>'9' )&&line[i]!='\n' ){
            name[k][l]=line[i];
            l++;
        }
        
        else if( line[i]!=' '&&( line[i]>='0'&& line[i]<='9')&&line[i]!='\n' ) {
            name[k][l]='\0';
            l=0;
            k++;
            get[j][d]=line[i];
            if( line[i+1]>='0'&&line[i+1]<='9'&&line[i+1]!='\n' ){
                d++;
                get[j][d]=line[i+1];
                i++;
            }
            get[j][d+1]='\0';
            j++;
        }
        i++;
    }
    
    for( i=0;i<j;i++ ){
        num_line[i]=atoi( get[i] );
        
    }
    
	   head=q2=( struct trip * )malloc( sizeof( struct trip ) );
       
       q2->next=NULL;
       strcpy( head->name1,name[0] );
       q2->num_line1=num_line[0];
       q2->touch_check=0;
       while( start++ < k-1 ){
           q1=( struct trip * )malloc( sizeof( struct trip ) );
           
           strcpy( q1->name1,name[start] );
           q1->num_line1=num_line[start];
           q1->touch_check=0;
           q2->next=q1;
           q2=q1;
       }
       
       q2->next=NULL;
       
       return head;
}
void find_all_path(struct trip **data,int start_num,int end_num,int k)
{
    int i=0,t;
    struct trip *p;
    path[k]=start_num;
    visited[start_num]=1;
    if(start_num==end_num)
    {
        printf("one path\n");
        for(i=0;path[i];i++)
        {
            printf("%s --",data[path[i]]->name1);
        }
        printf("\n");
    }
    else
    {
        for(p=data[start_num];p;p=p->next)
        {
            t=p->num_line1;
            if(!visited[t]){
                find_all_path(data,t,end_num,k+1); 
            }
        }
        
    }
    path[k]=0;
    visited[start_num]=0;
}
void Deep_First_Search(struct trip **data,int v,int n,int visted[])  
{ 
    struct trip *p;
    int flag = 0;
    if(flag == 0 && visted[v] == 0)
    {
        printf("%s",data[v]->name1);
        flag = 1;
        visted[v] = 1;
    }
    p = data[v]->next; 
    while(p!= NULL)
    {
        if(visted[p->num_line1] == 0)
        {
            printf("--%s",p->name1);
            visted[p->num_line1] = 1;
            Deep_First_Search(data,p->num_line1,n,visted);
        }
        p = p->next;
    }
}

void Find_Good_Way(int n,struct trip **data)  
{
    int i,start;
    int visted[MAXNODE];
    for(i = 1; i <= n; i++) 
    {
        visted[i] = 0; 
    }
    /*printf("请输入起始景点编号: ");
    scanf("%d",&start);*/
    getchar();
    printf("最佳线路如下: \n");
    start=1;
    Deep_First_Search(data,start,n,visted);
}
void Find_All_Way(struct trip **data)
{
    int i=0,j=0;
    int k=0;
    int start_num ,end_num;
    printf( "输入起点景点编号：" );
    scanf("%d",&start_num);
    printf( "输入终点景点编号： " );
    scanf("%d",&end_num);
    getchar();
    find_all_path(data,start_num,end_num,k);
}
#endif
