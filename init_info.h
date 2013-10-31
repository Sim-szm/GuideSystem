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
    printf("请输入您要查询的景点序号: ");
    scanf("%d",&len);
    getchar();
    while(i <= vertex_num&&flag) 
    {
        if(i == len) 
        {
            printf("此景点的名称是: %s\n",vertex_info[i].data);
            printf("此景点的介绍是: %s\n",vertex_info[i].str); 
            flag=0;
        }
        else
            i++;
    }
}

void Find_Way_Info(vexnode vertex_info[],EdgeType edges_info[]) 
{
    int road_num;
    printf("请输入您要查询的道路编号: ");
    scanf("%d",&road_num);
    getchar();
      printf("此道路长度是:%d米\n",edges_info[road_num].lengh);
      printf("此道路连接的两个景点是:%s—%s\n",vertex_info[edges_info[road_num].ivex].data,vertex_info[edges_info[road_num].jvex].data);
      if(road_num==1)
      {
          printf("道路类型为： 盘山公路 .\n");
      }
      else{
          printf("道路类型为： 山路，阶梯台阶。\n");
      }
}
#endif