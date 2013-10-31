#ifndef _INTRODUCE_H
#define _INTRODUCE_H


#define INFOMAX 256
#define MAXINT 1000
#define MAX_INFO 500
#define    MAX       20   //图中顶点数的最大值
#define    MAXedg   30   //图中边数的最大值 

typedef struct
{
    char  data[30];  
    char  str[INFOMAX];
}vexnode;               
typedef  struct Edge
{
    int lengh;   
    int ivex, jvex;    
} EdgeType;   

typedef struct
{          
    int    edges[MAX][MAX];  
}adjmax;   

void List_info_num()
{
    printf("景点编号如下 ：\n");
    printf("< 1 : 接待中心 > ");
    printf("< 2 : 停车场 > ");
    printf("< 3 : 封仙潭 > \n");
    printf("< 4 : 钟潭 > ");
    printf("< 5 : 月宫潭 > ");
    printf("< 6 : 悬丝架 > \n");
    printf("< 7 : 印池 > ");
    printf("< 8 : 龙口瀑布 > ");
    printf("< 9 : 玉带瀑布 > \n");
    printf("< 10 : 雷风檀瀑布 > ");
    printf("< 11 : 烟霞瀑布 > ");
    printf("< 12 : 仙鹤桥瀑布 >\n ");
    printf("< 13 : 彩虹瀑布 > \n");
}
void Choose_option()
{
    puts("  ------------------------------------");
    puts("    **** 太平森林公园旅游查询 ****    ");
    puts("    **** < 所有选项功能如下 > ****    ");
    printf("    ---- 1 . 景区总体介绍 ----    \n");
    printf("    ---- 2 . 查看景区导览图 ----    \n");
    printf("    ---- 3 . 查询各个景点信息 ----    \n");
    printf("    ---- 4 . 查询道路信息 ----    \n");
    printf("    ---- 5 . 查询两个景点之间的一条简单路径（景点数目最小） ----    \n");
    printf("    ---- 6 . 两个景点之间的最短距离 ----    \n");
    printf("    ---- 7 . 参观全部景点的一条路线 ！ ----    \n");
    printf("    ---- 8 . 任意两个景点之间的所有简单路径 ！ ----    \n");
    printf("    ---- 0 . 退出应用  ----    \n");
    puts("  ------------------------------------");
}
void Print_Graph()
{
	printf(" \n                                     **** 西安市太平森林公园导览图 ****\n  ");
    printf("\n--------------------------------------------------------------------------------------------------\n");
	printf("                                              【接待中心】                                     /|\\  N");
	printf("\n                                                    /                                           |");
	printf("\n                                                   /                                            |");
	printf("\n                                                  /                                             |   S");
	printf("\n                                                 /");
	printf("\n                                                /");
	printf("\n                                         【停车场】");
	printf("\n                                              |");
	printf("\n                                              /");
	printf("\n                                             |");
	printf("\n                                         【封仙潭】");
	printf("\n                                             /     \\");
	printf("\n                                            /         \\---\\");
	printf("\n                                           /                \\");
	printf("\n                                          /                /");
	printf("\n                                     【钟潭】            \\");
	printf("\n                                        /     \\          \\");
	printf("\n   【玉带瀑布】                        /--      \\          \\");
	printf("\n          \\                       --/--           \\          \\");
	printf("\n           \\                     |                 \\          \\");
	printf("\n            \\                    |                   \\            -----\\");
	printf("\n             \\ -------------【龙口瀑布】             /                   \\");
	printf("\n                           /   /                     /                     \\");
	printf("\n                         /    /                      \\--                   \\");
	printf("\n            ------- ---/     /                          \\                    \\");
	printf("\n            /               /                             \\                【月宫潭】");
	printf("\n           /        【雷风檀瀑布】                           \\                     \\");
	printf("\n          /           |                                       \\                      \\");
	printf("\n         /             \\                                       \\                     \\");
	printf("\n        /               \\                                       \\                     /");
	printf("\n       /                 \\                                       \\                   /");
	printf("\n      /                   /                                         \\              【悬丝架】 ");
	printf("\n      |                  /                                          \\                   \\");
	printf("\n      |                  |                                            \\                   \\");
	printf("\n      |             【烟霞瀑布】                                      \\                     \\");
	printf("\n      |                  /                                              --\\                    \\");
	printf("\n      |                 /                                                   \\---                \\");
	printf("\n      |                /                                                        \\  ---------【印池】");
	printf("\n      |        【仙鹤桥瀑布】");
	printf("\n      |              /");
	printf("\n      |             /");
	printf("\n      |            /");
	printf("\n      |           /");
	printf("\n      |          /");
	printf("\n     【彩虹瀑布】");
    printf("\n--------------------------------------------------------------------------------------------------\n");
	printf("\n");
}
void introduce()
{
    FILE *fd;
    char buf[MAX_INFO]={'\0'};
    fd=fopen("show.txt","r");
    while((fgets( buf,sizeof( buf ),fd ))!=NULL)
    {
        printf("%s",buf);
    }
    printf("\n");
}
vexnode cope_with_vexnode(char *line)
{
    char name[30]={'\0'};
    char info[INFOMAX]={'\0'};
    vexnode temp;
    int i=0,j=0;

    while(line[i]!='&')
    {
        name[i]=line[i];
        i++;
    }
    while( line[++i]!='\0')
    {
        info[j]=line[i];
        j++;
    }
    strcpy(temp.data,name);
    strcpy(temp.str,info);
    return temp ;
    
}

EdgeType cope_with_edgetype(char *line)
{
    char lengh[2],ivex[2],jvex[2];
    int i=0,j=0,k=0;
    EdgeType temp;
    while(line[i]!='&'){
        lengh[i]=line[i];
        i++;
    }
    i++;
    while(line[i]!='|'){
        ivex[j]=line[i];
        j++;i++;
    }
    i++;
    while(line[i]!='\0'){
        jvex[k]=line[i];
        i++;k++;
    }
    temp.lengh=atoi(lengh);
    temp.ivex=atoi(ivex);
    temp.jvex=atoi(jvex);
    return temp;
}
void read_trip_info(vexnode g[],EdgeType e[])
{
    int i=1,j=1;
    FILE *fd;
    char buf1[INFOMAX]={'\0'};
    char buf2[INFOMAX]={'\0'};
    fd=fopen( "trip-info.txt","r" );
    while( (fgets( buf1,sizeof( buf1 ),fd ))!=NULL ){
        g[i++]=cope_with_vexnode( buf1 );
    }
    fclose(fd);
    
    fd=fopen( "Edge-vertex-info.txt","r" );
    while( (fgets( buf2,sizeof( buf2 ),fd ))!=NULL ){
        e[j++]=cope_with_edgetype(buf2);
    }
    fclose( fd );
}

#endif