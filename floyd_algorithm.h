#ifndef _FLOYD_ALGORITHM_H
#define _FLOYD_ALGORITHM_H

void Short_Path_Recond(int path[][MAX],int i,int j,vexnode vertex_info[])  
{
    int k;
    k = path[i][j];
    if(k == -1)
        return;
    Short_Path_Recond(path,i,k,vertex_info); 
    printf("%s,",vertex_info[k].data);
    Short_Path_Recond(path,k,j,vertex_info);  
}

void Find_Short_Way(int A[][MAX],int path[][MAX],vexnode vertex_info[])
{
    int i,j;
    int start_num,end_num;  
    printf("请输入起始景点编号: ");
    scanf("%d",&start_num);
    printf("请输入终点景点编号: ");
    scanf("%d",&end_num);
    getchar();
    for(i = 1; i <= vertex_num; i++)
        for(j = 1; j <= vertex_num; j++)
        {
            if(A[i][j] != MAXINT && A[i][j] != 0 && i == start_num && j == end_num)
            {
                printf("从%s到%s最短路径顺序为:  ",vertex_info[start_num].data,vertex_info[end_num].data);
                printf("%s,",vertex_info[start_num].data);
                Short_Path_Recond(path,start_num,end_num,vertex_info);
                printf("%s",vertex_info[end_num].data);
                printf("\n路径长度为: %d\n",A[i][j]);
            }
        }
}

void Floyd(adjmax adj,vexnode vertex_info[]) 
{
    int A[MAX][MAX],path[MAX][MAX];  /* A是路径长度，path是路径 */
    int i,j,k;
    for(i = 1; i <= vertex_num; i++) 
    {
        for(j = 1; j <= vertex_num; j++)
        {
            A[i][j] = adj.edges[i][j]; 
            if(i == j)
            {
                A[i][j] = 0;
            }
            path[i][j] = -1;  
        }
    }
    
    for(k = 1; k <= vertex_num; k++)
    {
        for(i = 1; i <=vertex_num; i++)
        {
            for(j = 1; j <= vertex_num; j++)
            {
                if(A[i][j] > (A[i][k] + A[k][j])) 
                {
                    A[i][j] = A[i][k]+A[k][j];  
                    path[i][j] = k;   
                }
            }
        }
    }
    
    Find_Short_Way(A,path,vertex_info);
}
#endif