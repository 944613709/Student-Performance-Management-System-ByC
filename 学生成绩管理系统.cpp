#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<io.h>
#include<windows.h>
#define N 99
typedef struct course_s
{
    char coursename[100];
    int coursescore;
} COURSE_S;
typedef struct student_s
{
    char num[100];
    char name[100];
    COURSE_S course[6];
} STUDENT_S;
void input(STUDENT_S *student, int *Pnum_student, int *Pnum_course); //OK
void output(STUDENT_S *student, int num_student, int num_course, int stuscore_sum[], float stuscore_ave[], int coursescore_sum[], float coursescore_ave[]); //OK
void Calculatecourse(STUDENT_S *student, int flag_ifprintf, int num_student, int num_course, int coursescore_sum[], float coursescore_ave[]); //一个科目所有学生总分 OK
void Calculatestudent(STUDENT_S *student, int flag_ifprintf, int num_student, int num_course, int *stuscore_sum, float *stuscore_ave); //一个学生各科目总分 OK
void sort_by_XueHao(STUDENT_S *student, int num_student, int num_course); //按学号由小到大排；OK
void sort_by_XingMing(STUDENT_S *student, int num_student, int num_course); //按姓名的字典顺序排OK
void Search_by_num(STUDENT_S *student, int num_student, int num_course); //按学号查询学生排名及其考试成绩OK
void Search_by_XingMing(STUDENT_S *student, int num_student, int num_course); //按姓名查询学生排名及其考试成绩；
int Mymenu(void);
void Myread(void);
void PaiXu_1 (STUDENT_S *student, int num_student, int num_course, int stuscore_sum[]); //从d到g
void PaiXu_2 (STUDENT_S *student, int num_student, int num_course, int stuscore_sum[]); //从高到低
void Mywrite(STUDENT_S *student, int num_student, int num_course, int stuscore_sum[], float stuscore_ave[], int coursescore_sum[], float coursescore_ave[]);
void TongJi(STUDENT_S *student, int num_student, int num_course, int stuscore_sum[], float stuscore_ave[], int coursescore_sum[], float coursescore_ave[]); //按优秀（90~100分别统计每个类别的人数以及所占的百分比
int main()
{
    int coursescore_sum[6] = {0}; //科目所有学生总分
    float coursescore_ave[6] = {0}; //科目平均 分
    int stuscore_sum[30] = {0}; //g学生所有科目总分
    float stuscore_ave[30] = {0}; //一个学生所有科目累计的平均分
    int num_student;//一共多少stu
    int num_course;//一共多少course
    int order;
    STUDENT_S student[30];
    printf("             LOADING!!!!!!!!!!!!!!!!!");
    Sleep(500);//音效加入
    Beep(523, 500); //音效加入
    Beep(587, 500); //音效加入
    Beep(659, 500); //音效加入
    Beep(698, 500); //音效加入
    Beep(784, 500); //音效加入
    system("cls");//清理屏幕和缓冲区

    //1号测试用   没有输入，输出会总分为0，但是取消1号测试就没问题，不用管！

    //Calculatecourse(student);//提前进行计算一个科目所有学生总分
    //Calculatestudent(student);//提前进行计算一个学生各科目总分
    //Search_by_num(student);
    //sort_by_XueHao(student);
    //sort_by_XingMing(student);
    //output(student);
    //input(student);
tag:
    order = Mymenu();
    switch (order)
    {
    case 1:
        input(student, &num_student, &num_course);
        Calculatecourse(student, 0, num_student, num_course, coursescore_sum, coursescore_ave);
        Calculatestudent(student, 0, num_student, num_course, stuscore_sum, stuscore_ave);
        break;
    case 2:
        Calculatecourse(student, 1, num_student, num_course, coursescore_sum, coursescore_ave);
        break;
    case 3:
        Calculatestudent(student, 1, num_student, num_course, stuscore_sum, stuscore_ave);
        break;//1->要打印;
    case 4:
        PaiXu_2(student, num_student, num_course, stuscore_sum);
        break;
    case 5:
        PaiXu_1(student, num_student, num_course, stuscore_sum);
        break;
    case 6:
        sort_by_XueHao(student, num_student, num_course);
        break;
    case 7:
        sort_by_XingMing(student, num_student, num_course);
        break;
    case 8:
        Search_by_num(student, num_student, num_course);
        break;
    case 9:
        Search_by_XingMing(student, num_student, num_course);
        break;
    case 10:
        TongJi(student, num_student, num_course, stuscore_sum, stuscore_ave, coursescore_sum, coursescore_ave);
        break;
    case 11:
        output(student, num_student, num_course, stuscore_sum, stuscore_ave, coursescore_sum, coursescore_ave);
        break;
    case 12:
        Mywrite(student, num_student, num_course, stuscore_sum, stuscore_ave, coursescore_sum, coursescore_ave);
        break;
    case 13:
        Myread();
        break;
    case 0:
        break;
    }
    if (order > 13 || order < 0)
    {
        printf("输入有误请重新尝试\n");
        system("pause");
        system("cls");//清理屏幕和缓冲区
        fflush(stdin);
        goto tag;
    }
    else if (order == 0)
    {
        int temp;
        printf("您确定是否退出？1(yes)/2(no) ");
        while (scanf("%d", &temp) != 1 || temp > 2 || temp < 1)
        {
            printf("输入出错！请重新输入\n");
            while (getchar() != '\n');
        }
        if (temp == 1)
        {
            system("cls");//结束时清理屏幕和缓冲区，打印下方的校徽
            fflush(stdin);
            printf("\n感谢使用！\n");
            printf("\n                                                               \n");
            printf("     ****          ****    ******************    ******************  \n");
            printf("     ****          ****    ******************    ******************  \n");
            printf("     ****          ****           ****                  ****  \n");
            printf("     ****          ****           ****                  **** \n");
            printf("     ******************           ****                  ****      \n");
            printf("     ******************           ****                  ****   \n");
            printf("     ****          ****           ****                  ****   \n");
            printf("     ****          ****           ****                  ****   \n");
            printf("     ****          ****    ******************           ****   \n");
            printf("     ****          ****    ******************           ****   \n");
            system("pause");
            return 0;
        }
        else if (order == 2)
        {
            system("cls");//清理屏幕和缓冲区
            fflush(stdin);
            goto tag;
        }
    }
    else
    {
        printf("\t\t\t\t\t\n成功执行\n");
        system("pause");
        system("cls");//清理屏幕和缓冲区
        goto tag;
    }
}

int Mymenu(void)
{
    int order;
    printf("\n");
    printf("\t\t\t\t\t\t【学生管理系统6.0】\t\t\t\t\t\n");
    printf("\t\t★————————————————————————————————————————★\n\n");
    printf("\t\t\t | 1. 信息录入                   2.计算每门课程的总分和平均分     3.计算每个学生的总分和平均分 |\n\n");
    printf("\t\t\t | 4. 总分由高到低排出名次表     5.总分由低到高排出名次表         6.按学号由小到大排出成绩表  |\n\n");
    printf("\t\t\t | 7.按姓名的字典顺序排出成绩表  8.按学号查询学生排名  	        9. 按姓名查询学生排名  |\n\n");
    printf("\t\t\t | 10.对每门课程分别统计         11.输出每个学生信息              12.记录信息写入文件  |\n\n");
    printf("\t\t\t | 13.从文件中读出学生信息\n\n");
    printf("\t\t★————————————————按0并回车退出——————————————————★\n");
    printf("请输入执行数字:");
    printf("\\ "
       "Please enter your choice: \n"
           );
           printf("欢迎来到学生管理管理系统\n");
           printf("请根据需求执行\n");
           while(scanf(" % d",&order)!=1)
           {   printf("输入出错！请重新输入\n");
           while(getchar()!='\n');
       }
           return order;
       }

           void TongJi(STUDENT_S *student,int num_student,int num_course,int stuscore_sum[],float stuscore_ave[],int coursescore_sum[],float coursescore_ave[])
           {

           int i,j;
           for(i=0;i<num_course;i++)
           {
           printf("科目名称： % s",student[0].course[i].coursename);
           int countperson[5]={0};
           for(j=0;j<num_student;j++)
           {
           if(student[j].course[i].coursescore<=100&&student[j].course[i].coursescore>=90)
           countperson[0]++;//youxiu
           if(student[j].course[i].coursescore<=89&&student[j].course[i].coursescore>=80)
           countperson[1]++;//youxiu
           if(student[j].course[i].coursescore<=79&&student[j].course[i].coursescore>=70)
           countperson[2]++;//youxiu
           if(student[j].course[i].coursescore<=69&&student[j].course[i].coursescore>=60)
           countperson[3]++;//youxiu
           if(student[j].course[i].coursescore<=59&&student[j].course[i].coursescore>=0)
           countperson[4]++;//youxiu
       }
           printf("优秀 % d人占 % f \n",countperson[0],(float)countperson[0]/num_student);
           printf("良好 % d人占 % f \n",countperson[1],(float)countperson[1]/num_student);
           printf("中等 % d人占 % f \n",countperson[2],(float)countperson[2]/num_student);
           printf("及格 % d人占 % f \n",countperson[3],(float)countperson[3]/num_student);
           printf("不及格 % d人占 % f \n",countperson[4],(float)countperson[4]/num_student);
       }
       }
           void PaiXu_1 (STUDENT_S *student,int num_student,int num_course,int stuscore_sum[])
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           int tempint;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(stuscore_sum[j]>stuscore_sum[j+1])
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
           tempint=stuscore_sum[j];
           stuscore_sum[j]=stuscore_sum[j+1];
           stuscore_sum[j+1]=tempint;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
       printf("总成绩: % d\n",stuscore_sum[i]);

       }
       }
           void PaiXu_2 (STUDENT_S *student,int num_student,int num_course,int stuscore_sum[])
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           int tempint;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(stuscore_sum[j]<stuscore_sum[j+1])
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
           tempint=stuscore_sum[j];
           stuscore_sum[j]=stuscore_sum[j+1];
           stuscore_sum[j+1]=tempint;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
       printf("总成绩: % d\n",stuscore_sum[i]);

       }
       }
           void Myread()
           {
           int oldstdin = dup(0);
           freopen("a.txt","r",stdin);
           char ch;
           while((ch=getchar())!=EOF) putchar(ch);
           freopen("con","r",stdin);
           dup2(oldstdin,0);
       }
           void Mywrite(STUDENT_S *student,int num_student,int num_course,int stuscore_sum[],float stuscore_ave[],int coursescore_sum[],float coursescore_ave[])
           {
           int i,j;
           int oldstdout=dup(1);
           freopen("a.txt","w",stdout);
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           printf("该学生所有科目总分  % d \n",stuscore_sum[i]);
           printf("该学生所有科目平均分  % .2f\n",stuscore_ave[i]);
       }
           fclose(stdout);
           freopen("con", "w", stdout);
           dup2(oldstdout,1);
       }
           void Search_by_XingMing(STUDENT_S *student,int num_student,int num_course)//按姓名查询学生排名及其考试成绩；
           {
           int i,j;//i记录找到学生之后的i
           int Found=0;//暂未找到
           char getname[99];
           printf("\n目前进入姓名查询学生排名及其考试成绩\n");
           printf("请输入姓名：");
           fflush(stdin);
           gets(getname);
           for(i=0;i<num_student;i++)
           {
           if(strcmp(student[i].name,getname)==0)
           {
           Found=1;//找到
           break;
       }
       }
           //最后的i记录找到学生之后的i
           if(Found==1)
           {
           printf("该学生信息如下\n");
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
       }
           else
           {
           printf("该学生姓名未存在\n");//进入模糊查找
           int temp;
           printf("您确定要进行模糊查找吗？1(yes) / 2(no) ");
           while(scanf(" % d",&temp)!=1||temp>2||temp<1)
           {   printf("输入出错！请重新输入\n");
           while(getchar()!='\n');
       }
           //!!!!!!!!!!!!!!!!!!!!!
           if(temp==1);//进行模糊查找
           {
           char getname_mohu[99];
           fflush(stdin);
           printf("请输入想要查找的学生姓名中可能含有的字：");
           gets(getname_mohu);
           int count=1;
           int Found_mohu=0;
           for(i=0;i<num_student;i++)
           {
           if(strstr(student[i].name,getname_mohu)!=NULL)
           {
           Found_mohu=1;//模糊匹配到了！
           printf("模糊匹配到的第 % d位学生信息如下\n",count);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           count++;
       }
       }
           if(Found_mohu==0)
           {printf("很抱歉，模糊匹配也并未匹配到含以上字的学生姓名\n");
           return;
       }
       }
           //!!!!!!!!!!
           if(temp==2)
           return;
       }

       }

           void Search_by_num(STUDENT_S *student,int num_student,int num_course)
           {
           int i,j;//i记录找到学生之后的i
           int Found=0;//暂未找到
           char getnum[99];
           printf("\n目前进入按学号查询学生排名及其考试成绩\n");
           printf("请输入学号：");
           fflush(stdin);
           gets(getnum);
           for(i=0;i<num_student;i++)
           {
           if(strcmp(student[i].num,getnum)==0)
           {
           Found=1;//找到
           break;
       }
       }
           //最后的i记录找到学生之后的i
           if(Found==1)
           {
           printf("该学生信息如下\n");
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
       }
           else
           {
           printf("该学号未存在\n");//进入模糊查找
           int temp;
           printf("您确定要进行模糊查找吗？1(yes) / 2(no) ");
           while(scanf(" % d",&temp)!=1||temp>2||temp<1)
           {   printf("输入出错！请重新输入\n");
           while(getchar()!='\n');
       }
           //!!!!!!!!!!!!!!!!!!!!!
           if(temp==1);//进行模糊查找
           {
           char getnum_mohu[99];
           fflush(stdin);
           printf("请输入想要查找的学号中可能含有的数字：");
           gets(getnum_mohu);
           int count=1;
           int Found_mohu=0;
           for(i=0;i<num_student;i++)
           {
           if(strstr(student[i].num,getnum_mohu)!=NULL)
           {
           Found_mohu=1;//模糊匹配到了！
           printf("模糊匹配到的第 % d位学生信息如下\n",count);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           count++;
       }
       }
           if(Found_mohu==0)
           {printf("很抱歉，模糊匹配也并未匹配到含以上数字的学号\n");
           return;
       }
       }
           //!!!!!!!!!!
           if(temp==2)
           return;
       }
       }

           void sort_by_XingMing(STUDENT_S *student,int num_student,int num_course)
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(strcmp(student[j].name,student[j+1].name)>0)
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }

       }
       }
           void sort_by_XueHao(STUDENT_S *student,int num_student,int num_course)
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(strcmp(student[j].num,student[j+1].num)>0)
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }

       }
       }
           void Calculatecourse(STUDENT_S *student,int flag_ifprintf,int num_student,int num_course,int coursescore_sum[],float coursescore_ave[])//一个科目所有学生总分
           {
           int i;
           int j;
           for(i=0;i<num_course;i++)
           {
           for(j=0;j<num_student;j++)
           {
           coursescore_sum[i]+=student[j].course[i].coursescore;//总分
       }
           coursescore_ave[i]=(float)(coursescore_sum[i])/(float)num_student;//平均分
       }
           if(flag_ifprintf==1)//是否要打印
           {
           for(i=0;i<num_course;i++)
           {
           printf("当前第 % d门课程信息如下\n",i+1);
           printf("课程名 % s\n",student[0].course[i].coursename);
           printf("该科目总分  % d \n",coursescore_sum[i]);
           printf("该科目平均分  % .2f\n",coursescore_ave[i]);
       }
       }
           else if(flag_ifprintf==0)//不用打印
           {
           return;
       }
       }
           void Calculatestudent(STUDENT_S *student,int flag_ifprintf,int num_student,int num_course,int *stuscore_sum,float *stuscore_ave)//一个学生各科目总分
           {
           int i;
           int j;
           for(i=0;i<num_student;i++)
           {
           for(j=0;j<num_course;j++)
           {
           stuscore_sum[i]+=student[i].course[j].coursescore;//总分
       }
           stuscore_ave[i]=(float)(stuscore_sum[i])/(float)num_course;//平均分
           //printf(" % f\n",coursescore_ave[i]);
       }
           if(flag_ifprintf==1)//是否要打印
           {
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s",student[i].num);
           printf("       姓名 % s\n",student[i].name);
           printf("该学生所有科目总分  % d \n",stuscore_sum[i]);
           printf("该学生所有科目平均分  % .2f\n",stuscore_ave[i]);
       }
       }
           else if(flag_ifprintf==0)//不用打印
           return;
       }
           void output(STUDENT_S *student,int num_student,int num_course,int stuscore_sum[],float stuscore_ave[],int coursescore_sum[],float coursescore_ave[])
           {

           int i,j;
           for(i=0;i<num_student;i++)
           {
           printf("当前第 % d位学生信息如下\n",i+1);
           printf("学号 % s\n",student[i].num);
           printf("姓名 % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("科目名称： % s      成绩: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           printf("该学生所有科目总分  % d \n",stuscore_sum[i]);
           printf("该学生所有科目平均分  % .2f\n",stuscore_ave[i]);
       }

       }
           void input(STUDENT_S *student,int *Pnum_student,int *Pnum_course)
           {
           char **temp_course=NULL;//动态二维数组 ——！暂时存有哪些科目防止一直重复输入
           int i,j;
           printf("请输入一共多少学生\n");
           while(scanf(" % d",Pnum_student)!=1)
           {   printf("输入出错！请重新输入\n");
           while(getchar()!='\n');
       }
           printf("您确定了一共有 % d学生\n",*Pnum_student);
           printf("*************\n");
           fflush(stdin);
           printf("请输入一共多少科目\n");
           while(scanf(" % d",Pnum_course)!=1)
           {   printf("输入出错！请重新输入\n");
           while(getchar()!='\n');
       }
           printf("您确定了一共有 % d科目\n",*Pnum_course);
           printf("*************\n");
           temp_course=(char **)malloc(sizeof(char*)*(*Pnum_course));
           for(i=0;i<*Pnum_course;i++)//动态二维数组
           temp_course[i]=(char*)malloc(sizeof(char)*N);//动态二维数组
           for(j=0;j<*Pnum_course;j++)//////////////
           {
           printf("请输入第 % d门考试科目名称\n",j+1);
           fflush(stdin);
           gets(temp_course[j]);
           for(i=0;i<*Pnum_student;i++)
           strcpy(student[i].course[j].coursename,temp_course[j]);//for赋值所有的该课程名
           printf("*************\n");
       }
           free(temp_course) ;
           fflush(stdin);
           for(i=0;i<*Pnum_student;i++)
           {
           printf("请输入第 % d位学生学号\n",i+1);
           gets(student[i].num);
           printf("*************\n");
           printf("请输入第 % d位学生姓名\n",i+1);
           gets(student[i].name);
           printf("*************\n");
           printf("准备进行输入各考试科目成绩\n");
           for(j=0;j<*Pnum_course;j++)
           {
           printf("请输入第 % d门 % s考试科目分数\n",j+1,student[i].course[j].coursename);
           while(scanf(" % d",&student[i].course[j].coursescore)!=1)
           {   printf("输入出错！请重新输入\n");
           while(getchar()!='\n');
       }
           fflush(stdin);
           printf("*************\n");
       }
       }
       }
