#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "simple_way.h"
#include "cope_file.h"
#include "init_info.h"
#include "floyd_algorithm.h"
int main()
{
    vexnode  vertex_info[MAX];   
    EdgeType edges_info[MAXedg];
    struct trip *temp[MAXNODE];
    adjmax adj;   
    int choice_case;
    char pos='y';
    Graph_Init(vertex_info,edges_info,&adj);
    read_way( temp,1);
    Choose_option();
    while(1)
    {
loop:   printf("输入你的选择:  ");
        scanf("%d",&choice_case);
        switch(choice_case)
        {
        case 1:
            introduce();
            printf("\n按任意键返回主菜单！\n");
            scanf("%c",&pos);
            getchar();
            system("cls");
            Choose_option();
            break;
        case 2:
           // Print_Graph();
            system("graph.jpg");
            printf("\n按任意键返回主菜单！\n");
            scanf("%c",&pos);
            getchar();
            system("cls");
            Choose_option();
            goto loop;
        case 3:
            pos='y';
            List_info_num();
            while(pos=='y'||pos=='Y')
            {
                Find_Trip_Info(vertex_info);
                printf("是否继续查询景点信息？（y / n）: ");
                scanf("%c",&pos);
                getchar();
            }
            printf("\n    ---- restat ! ----  \n");_sleep(10);
            system("cls");
            Choose_option();
            goto loop;
        case 4:  
            pos='y';
            while(pos=='y'||pos=='Y')
            {
                Find_Way_Info(vertex_info,edges_info); 
                printf("是否继续查询线路信息？（y / n）: ");
                scanf("%c",&pos);
                getchar();
            }
            printf("\n    ---- restat ! ----  \n");_sleep(10);
            system("cls");
            Choose_option();
            goto loop;
        case 5:
            pos='y';
            List_info_num();
            while(pos=='y'||pos=='Y'){
                Find_Simple_Way( );
                printf("是否继续查询任意两个景点之间的一条简单路径？（y / n ）：");
                scanf("%c",&pos);
            }
            _sleep(10);
            system("cls");
            Choose_option();
            goto loop;  
        case 6:
            pos='y';
            List_info_num();
            while(pos=='y'||pos=='Y')
            {
                Floyd(adj,vertex_info);
                printf("是否继续查询任意两个景点间最短路径？（y / n）: ");
                scanf("%c",&pos);
                getchar();
            }
            
            system("cls");
            Choose_option();
            goto loop;
        case 7:  
            Find_Good_Way(vertex_num,temp);
            printf("\n按任意键返回主菜单！\n");
            getchar();
            system("cls");
            Choose_option();
            goto loop;
        case 8:
           Find_All_Way(temp);
           printf("\n按任意键返回主菜单！\n");
            getchar();
            system("cls");
            Choose_option();
            goto loop;
        case 0:
            exit(0);
        default:
            printf("    **** 不正确的选项！****  \n");
            printf("\n    ---- restat ! ----  \n");
            goto loop;
        }
    }
    return 0;
}