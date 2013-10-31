#ifndef _INIT_INFO_H
#define _INIT_INFO_H

#include "introduce.h"
#define vertex_num 14
#define edges_num 15

void Graph_Init(vexnode vertex_info[],EdgeType edges_info[],adjmax *adj) 
{
    int i,j,start,end,len;   
    read_trip_info(vertex_info,edges_info);   
    for(i = 1; i <= vertex_num; i++)  /* init MAXINT */
    {
        for(j = 1; j <= vertex_num; j++)
        {
            adj->edges[i][j] = MAXINT;    
        }
    }
    for(i = 1; i < edges_num ; i++)
    {  
        start = edges_info[i].ivex; 
        end = edges_info[i].jvex;
        len = edges_info[i].lengh;
        adj->edges[start][end] = edges_info[i].lengh; 
        adj->edges[end][start] = edges_info[i].lengh;
    }
}
void Find_Trip_Info(vexnode vertex_info[]) 
{
    int i = 1,flag = 1,len;  
    printf("��������Ҫ��ѯ�ľ������: ");
    scanf("%d",&len);
    getchar();
    while(i <= vertex_num&&flag) 
    {
        if(i == len) 
        {
            printf("�˾����������: %s\n",vertex_info[i].data);
            printf("�˾���Ľ�����: %s\n",vertex_info[i].str); 
            flag=0;
        }
        else
            i++;
    }
}

void Find_Way_Info(vexnode vertex_info[],EdgeType edges_info[]) 
{
    int road_num;
    printf("��������Ҫ��ѯ�ĵ�·���: ");
    scanf("%d",&road_num);
    getchar();
      printf("�˵�·������:%d��\n",edges_info[road_num].lengh);
      printf("�˵�·���ӵ�����������:%s��%s\n",vertex_info[edges_info[road_num].ivex].data,vertex_info[edges_info[road_num].jvex].data);
      if(road_num==1)
      {
          printf("��·����Ϊ�� ��ɽ��· .\n");
      }
      else{
          printf("��·����Ϊ�� ɽ·������̨�ס�\n");
      }
}
#endif