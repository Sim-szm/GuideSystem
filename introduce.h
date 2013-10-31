#ifndef _INTRODUCE_H
#define _INTRODUCE_H


#define INFOMAX 256
#define MAXINT 1000
#define MAX_INFO 500
#define    MAX       20   //ͼ�ж����������ֵ
#define    MAXedg   30   //ͼ�б��������ֵ 

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
    printf("���������� ��\n");
    printf("< 1 : �Ӵ����� > ");
    printf("< 2 : ͣ���� > ");
    printf("< 3 : ����̶ > \n");
    printf("< 4 : ��̶ > ");
    printf("< 5 : �¹�̶ > ");
    printf("< 6 : ��˿�� > \n");
    printf("< 7 : ӡ�� > ");
    printf("< 8 : �����ٲ� > ");
    printf("< 9 : ����ٲ� > \n");
    printf("< 10 : �׷�̴�ٲ� > ");
    printf("< 11 : ��ϼ�ٲ� > ");
    printf("< 12 : �ɺ����ٲ� >\n ");
    printf("< 13 : �ʺ��ٲ� > \n");
}
void Choose_option()
{
    puts("  ------------------------------------");
    puts("    **** ̫ƽɭ�ֹ�԰���β�ѯ ****    ");
    puts("    **** < ����ѡ������� > ****    ");
    printf("    ---- 1 . ����������� ----    \n");
    printf("    ---- 2 . �鿴��������ͼ ----    \n");
    printf("    ---- 3 . ��ѯ����������Ϣ ----    \n");
    printf("    ---- 4 . ��ѯ��·��Ϣ ----    \n");
    printf("    ---- 5 . ��ѯ��������֮���һ����·����������Ŀ��С�� ----    \n");
    printf("    ---- 6 . ��������֮�����̾��� ----    \n");
    printf("    ---- 7 . �ι�ȫ�������һ��·�� �� ----    \n");
    printf("    ---- 8 . ������������֮������м�·�� �� ----    \n");
    printf("    ---- 0 . �˳�Ӧ��  ----    \n");
    puts("  ------------------------------------");
}
void Print_Graph()
{
	printf(" \n                                     **** ������̫ƽɭ�ֹ�԰����ͼ ****\n  ");
    printf("\n--------------------------------------------------------------------------------------------------\n");
	printf("                                              ���Ӵ����ġ�                                     /|\\  N");
	printf("\n                                                    /                                           |");
	printf("\n                                                   /                                            |");
	printf("\n                                                  /                                             |   S");
	printf("\n                                                 /");
	printf("\n                                                /");
	printf("\n                                         ��ͣ������");
	printf("\n                                              |");
	printf("\n                                              /");
	printf("\n                                             |");
	printf("\n                                         ������̶��");
	printf("\n                                             /     \\");
	printf("\n                                            /         \\---\\");
	printf("\n                                           /                \\");
	printf("\n                                          /                /");
	printf("\n                                     ����̶��            \\");
	printf("\n                                        /     \\          \\");
	printf("\n   ������ٲ���                        /--      \\          \\");
	printf("\n          \\                       --/--           \\          \\");
	printf("\n           \\                     |                 \\          \\");
	printf("\n            \\                    |                   \\            -----\\");
	printf("\n             \\ -------------�������ٲ���             /                   \\");
	printf("\n                           /   /                     /                     \\");
	printf("\n                         /    /                      \\--                   \\");
	printf("\n            ------- ---/     /                          \\                    \\");
	printf("\n            /               /                             \\                ���¹�̶��");
	printf("\n           /        ���׷�̴�ٲ���                           \\                     \\");
	printf("\n          /           |                                       \\                      \\");
	printf("\n         /             \\                                       \\                     \\");
	printf("\n        /               \\                                       \\                     /");
	printf("\n       /                 \\                                       \\                   /");
	printf("\n      /                   /                                         \\              ����˿�ܡ� ");
	printf("\n      |                  /                                          \\                   \\");
	printf("\n      |                  |                                            \\                   \\");
	printf("\n      |             ����ϼ�ٲ���                                      \\                     \\");
	printf("\n      |                  /                                              --\\                    \\");
	printf("\n      |                 /                                                   \\---                \\");
	printf("\n      |                /                                                        \\  ---------��ӡ�ء�");
	printf("\n      |        ���ɺ����ٲ���");
	printf("\n      |              /");
	printf("\n      |             /");
	printf("\n      |            /");
	printf("\n      |           /");
	printf("\n      |          /");
	printf("\n     ���ʺ��ٲ���");
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