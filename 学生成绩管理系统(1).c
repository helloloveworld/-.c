#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 2

/*用于排序*/
typedef struct
{ 
	int number;
	int math;
	int English;
	int Cyuyan;
	char Class[MAXSIZE];
	char name[MAXSIZE];
	int score_sum;
} RecordType;
typedef struct
{ 
	RecordType r[MAXSIZE+1];
} RecordList;

/*定义学生信息*/
typedef struct student
{
	int number;
	int math;
	int English;
	int Cyuyan;
	char Class[MAXSIZE];
	char name[MAXSIZE];
	int score_sum;
}student;

/*定义单链表*/
typedef struct Node
{
	student date;
	struct Node *next;
}Node,*LinkList;

/*学生信息的输入*/
LinkList Input_student(LinkList L)
{
	
	Node *r,*s;
  	r=L;
  	printf("输入学生个数");
  	int x;
	scanf("%d",&x);
	printf("\n");
	printf("输入学生信息");
	printf("\n");
	for(int i = 0;i < x; i++)
	{
		s = (LinkList)malloc(sizeof(Node));
		s->next = NULL;
		printf("请输入学号");
		scanf("%d",&s->date.number);
		printf("请输入姓名");
		scanf("%s",s->date.name);
		printf("请输入班级");
		scanf("%s",s->date.Class);
		printf("请输入数学成绩");
		scanf("%d",&s->date.math);
		printf("请输入英语成绩");
		scanf("%d",&s->date.English);
		printf("请输入C语言程序设计成绩");
		scanf("%d",&s->date.Cyuyan);
		r->next = s;
		r = s;
		printf("\n");
	}
}

/*学生信息的输出*/
void print_student(LinkList L)
{
	Node *p;
	p = L;
	printf("---------                   学生信息打印界面                    ---------\n");
	while(p->next != NULL)
	{
		printf("学号\t姓名\t班级\t数学成绩\t英语成绩\tC语言程序设计成绩\n");
		p = p->next;
		printf("%d\t%s\t%s\t%d\t\t%d\t\t%d\n",p->date.number,p->date.name,p->date.Class,p->date.math,p->date.English,p->date.Cyuyan);
	}
	printf("-------------------------------------------------------------------------\n");
}


/*学生信息的修改*/
void change_student(LinkList L,int i)
{
	int x;
	Node *pre;
	int k = 0;
	pre = L;
	printf("请输入你想要修改的位置");
	scanf("%d",&i);
	i = i - 1;
	while(pre != NULL && k <= i)
	{
		pre = pre->next;
		k++;
	}
	if(pre == NULL)
	{
		printf("修改位置不合理！\n");
	}
	else
	{
		printf("\t---------   学生信息选择界面   --------\n");
		printf("\t-----       1.学号                -----\n");
		printf("\t-----       2.姓名                -----\n");
		printf("\t-----       3.班级                -----\n");
		printf("\t-----       4.数学成绩            -----\n");
		printf("\t-----       5.英语成绩            -----\n");
		printf("\t-----       6.C语言程序设计成绩   -----\n");
		printf("\t---------------------------------------\n");
		printf("请输入你想要修改的信息选项");
		scanf("%d",&x);
		switch(x)
		{
			case 1:printf("请输入你想要修改的信息");scanf("%d",&pre->date.number);break;
			case 2:printf("请输入你想要修改的信息");scanf("%s",pre->date.name);break;
			case 3:printf("请输入你想要修改的信息");scanf("%s",pre->date.Class);break;
			case 4:printf("请输入你想要修改的信息");scanf("%d",&pre->date.math);break;
			case 5:printf("请输入你想要修改的信息");scanf("%d",&pre->date.English);break;
			case 6:printf("请输入你想要修改的信息");scanf("%d",&pre->date.Cyuyan);break;
		}
		printf("修改成功！\n");
	}
}

/*学生信息的插入*/
void insert_student(LinkList L,int i)
{
	printf("请输入你想要插入的位置");
	scanf("%d",&i);
	i = i - 1;
	Node *pre,*t;
	int k = 0;
	pre = L;
	t = (Node*)malloc(sizeof(Node));
	t->next = NULL;
	while(pre != NULL && k <= i - 1)
	{
		pre = pre->next;
		k++;
	}
	if(pre == NULL)
	{
		printf("插入位置不合理！\n");
	}
	else
	{
		printf("请输入要插入的学生信息\n");
		printf("请输入学号");
		scanf("%d",&t->date.number);
		printf("请输入姓名");
		scanf("%s",t->date.name);
		printf("请输入班级");
		scanf("%s",t->date.Class);
		printf("请输入数学成绩");
		scanf("%d",&t->date.math);
		printf("请输入英语成绩");
		scanf("%d",&t->date.English);
		printf("请输入C语言程序设计成绩");
		scanf("%d",&t->date.Cyuyan);
		t->next = pre->next;
		pre->next = t;
		printf("插入成功！\n");
	}
}

/*学生信息的删除*/
void del_student(LinkList L,int i)
{
	printf("请输入你想要删除的位置");
	scanf("%d",&i);
	i = i - 1;
	Node *pre,*r;
	int k = 0;
	pre = L;
	while(pre != NULL && k <= i - 1)
	{
		pre = pre->next;
		k++;
	}
	if(pre->next == NULL)
	{
		printf("删除位置不合理！\n");
	}
	else
	{
		r = pre->next;
		pre->next = r->next;
		free(r);
		printf("删除成功！\n");
	}
}

/*数学成绩排序*/
void sort_math(LinkList L)
{
	RecordList I;
	int i = 1;
	int j;
	Node *p;
	p = L->next;
	int n = 0;
	while(p != NULL){
		n++;
		I.r[i].number = p->date.number;
		strcpy(I.r[i].name, p->date.name);
		strcpy(I.r[i].Class, p->date.Class);
		I.r[i].math = p->date.math;
		I.r[i].English = p->date.English;
		I.r[i].Cyuyan = p->date.Cyuyan;
		p = p->next;
		i++;
	}
		for(i = 2;i <= n;i++)
			{
				I.r[0] = I.r[i];j = i - 1;
				while(I.r[0].math > I.r[j].math)
				{
					I.r[j + 1] = I.r[j];
					j = j - 1;
				}
				I.r[j + 1] = I.r[0];
			}
	printf("数学成绩排序\n");
	printf("---------                   学生信息打印界面                    ---------\n");
	for(i = 1;i <= n;i++)
	{
		printf("学号\t姓名\t班级\t数学成绩\t英语成绩\tC语言程序设计成绩\n");
		printf("%d\t%s\t%s\t%d\t\t%d\t\t%d\n",I.r[i].number,I.r[i].name,I.r[i].Class,I.r[i].math,I.r[i].English,I.r[i].Cyuyan);
	}
	printf("-------------------------------------------------------------------------\n");
}

/*英语成绩排序*/
void sort_English(LinkList L)
{
	RecordList I;
	int i = 1;
	int j;
	Node *p;
	p = L->next;
	int n = 0;
	while(p != NULL){
		n++;
		I.r[i].number = p->date.number;
		strcpy(I.r[i].name, p->date.name);
		strcpy(I.r[i].Class, p->date.Class);
		I.r[i].math = p->date.math;
		I.r[i].English = p->date.English;
		I.r[i].Cyuyan = p->date.Cyuyan;
		p = p->next;
		i++;
	}
		for(i = 2;i <= n;i++)
			{
				I.r[0] = I.r[i];j = i - 1;
				while(I.r[0].English > I.r[j].English)
				{
					I.r[j + 1] = I.r[j];
					j = j - 1;
				}
				I.r[j + 1] = I.r[0];
			}
	printf("英语成绩排序\n");
	printf("---------                   学生信息打印界面                    ---------\n");
	for(i = 1;i <= n;i++)
	{
		printf("学号\t姓名\t班级\t数学成绩\t英语成绩\tC语言程序设计成绩\n");
		printf("%d\t%s\t%s\t%d\t\t%d\t\t%d\n",I.r[i].number,I.r[i].name,I.r[i].Class,I.r[i].math,I.r[i].English,I.r[i].Cyuyan);
	}
	printf("-------------------------------------------------------------------------\n");
}

/*C语言程序设计成绩的排序*/
void sort_Cyuyan(LinkList L)
{
	RecordList I;
	int i = 1;
	int j;
	Node *p;
	p = L->next;
	int n = 0;
	while(p != NULL){
		n++;
		I.r[i].number = p->date.number;
		strcpy(I.r[i].name, p->date.name);
		strcpy(I.r[i].Class, p->date.Class);
		I.r[i].math = p->date.math;
		I.r[i].English = p->date.English;
		I.r[i].Cyuyan = p->date.Cyuyan;
		p = p->next;
		i++;
	}
	for(i = 2;i <= n;i++)
		{
			I.r[0] = I.r[i];j = i - 1;
			while(I.r[0].Cyuyan > I.r[j].Cyuyan)
			{
				I.r[j + 1] = I.r[j];
				j = j - 1;
			}
			I.r[j + 1] = I.r[0];
		}
	printf("C语言程序设计成绩排序\n");
	printf("---------                   学生信息打印界面                    ---------\n");
	for(i = 1;i <= n;i++)
	{
		printf("学号\t姓名\t班级\t数学成绩\t英语成绩\tC语言程序设计成绩\n");
		printf("%d\t%s\t%s\t%d\t\t%d\t\t%d\n",I.r[i].number,I.r[i].name,I.r[i].Class,I.r[i].math,I.r[i].English,I.r[i].Cyuyan);
	}
	printf("-------------------------------------------------------------------------\n");
}

/*学生信息成绩的排序*/
void sort_student(LinkList L)
{
	int x;
	printf("\t-------    科目选择界面     --------\n");
	printf("\t-----     1.数学成绩           -----\n");
	printf("\t-----     2.英语成绩           -----\n");
	printf("\t-----     3.C语言程序设计成绩  -----\n");
	printf("\t------------------------------------\n");
	printf("请输入你想要排序的科目");
	scanf("%d",&x);
	switch(x)
	{
		case 1:sort_math(L);break;
		case 2:sort_English(L);break;
		case 3:sort_Cyuyan(L);break;
	}
	printf("排序成功！\n");
}

/*一趟快速排序*/
int QKPass(RecordType r[],int low,int high)
{
	r[0] = r[low];
	while(low < high)
	{
		while(low < high && r[high].number >= r[0].number)
			high--;
		if(low < high)
		{
			r[low] = r[high];
			low++;
		}
		while(low < high && r[low].number < r[0].number)
			low++;
		if(low < high)
			{
				r[high] = r[low];
				high--;
			}
	}
	r[low] = r[0];
	return low;
}

/*完整的快速排序*/
void QKSort(RecordType r[],int low,int high )
{
	if(low<high)
	{
		int pos;
		pos=QKPass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}

/*学生学号的排序*/
void sort_num(LinkList L)
{
	RecordList I;
	int i = 1;
	int j;
	Node *p;
	p = L->next;
	int n = 0;
	while(p != NULL)
	{
		n++;
		I.r[i].number = p->date.number;
		strcpy(I.r[i].name, p->date.name);
		strcpy(I.r[i].Class, p->date.Class);
		I.r[i].math = p->date.math;
		I.r[i].English = p->date.English;
		I.r[i].Cyuyan = p->date.Cyuyan;
		p = p->next;
		i++;
	}
	QKSort(I.r,1,n);
	printf("学号排序\n");
	printf("---------                   学生信息打印界面                    ---------\n");
	for(i = 1;i <= n;i++)
	{
		printf("学号\t姓名\t班级\t数学成绩\t英语成绩\tC语言程序设计成绩\n");
		printf("%d\t%s\t%s\t%d\t\t%d\t\t%d\n",I.r[i].number,I.r[i].name,I.r[i].Class,I.r[i].math,I.r[i].English,I.r[i].Cyuyan);
	}
	printf("-------------------------------------------------------------------------\n");
	printf("排序成功！\n");
}

/*学生信息的查找 */
void find_student(LinkList L)
{
	RecordList I;
	int i = 1,k;
	int low,high,mid;
	Node *p;
	p = L->next;
	int n = 0;
	while(p != NULL)
	{
		n++;
		I.r[i].number = p->date.number;
		strcpy(I.r[i].name, p->date.name);
		strcpy(I.r[i].Class, p->date.Class);
		I.r[i].math = p->date.math;
		I.r[i].English = p->date.English;
		I.r[i].Cyuyan = p->date.Cyuyan;
		p = p->next;
		i++;
	}
	QKSort(I.r,1,n);
	/*折半查找法*/
	printf("请输入你要查找的学号");
	scanf("%d",&k);
	low = 1;
	high = n;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(k == I.r[mid].number)
			break;
		else if(k < I.r[mid].number)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(k != I.r[mid].number)
		printf("无该学号！\n");
	else
		{
			printf("---------                   学生信息打印界面                    ---------\n");
			printf("姓名\t数学成绩\t英语成绩\tC语言程序设计成绩\n");
			printf("%s\t%d\t\t%d\t\t%d\n",I.r[mid].name,I.r[mid].math,I.r[mid].English,I.r[mid].Cyuyan);
			printf("-------------------------------------------------------------------------\n");
			printf("查找成功！\n");
		}
}

/*计算每个学生成绩的总分，并进行排序*/
void sum_score(LinkList L)
{
	Node *p;
	p = L->next;
	RecordList I;
	int j;
	int i = 1;
	int n = 0;
	while(p != NULL)
	{
		n++;
		I.r[i].number = p->date.number;
		strcpy(I.r[i].name, p->date.name);
		strcpy(I.r[i].Class, p->date.Class);
		I.r[i].math = p->date.math;
		I.r[i].English = p->date.English;
		I.r[i].Cyuyan = p->date.Cyuyan;
		I.r[i].score_sum = p->date.math + p->date.English + p->date.Cyuyan;
		p = p->next;
		i++;
	}
	for(i = 2;i <= n;i++)
		{
			I.r[0] = I.r[i];j = i - 1;
			while(I.r[0].score_sum > I.r[j].score_sum)
			{
				I.r[j + 1] = I.r[j];
				j = j - 1;
			}
			I.r[j + 1] = I.r[0];
		}
	printf("学生成绩总分排序\n");
	printf("---------                        学生信息打印界面                          ---------\n");
	for(i = 1;i <= n;i++)
	{
		printf("学号\t姓名\t班级\t数学成绩\t英语成绩\tC语言程序设计成绩\t总分\n");
		printf("%d\t%s\t%s\t%d\t\t%d\t\t%d\t\t\t%d\n",I.r[i].number,I.r[i].name,I.r[i].Class,I.r[i].math,I.r[i].English,I.r[i].Cyuyan,I.r[i].score_sum);
	}
	printf("------------------------------------------------------------------------------------\n");
	printf("排序成功！\n");
}
/*统计数学成绩*/
void stats_math(LinkList L)
{
	Node *p;
	p = L->next;
	int x;
	int i,j,k,l,m,n = 0;
	i = j = k = l = m = n;
	while(p != NULL)
	{
		x = p->date.math;
		if(x < 60)	i++;
		else if(60 <= x && x < 70)	j++;
		else if(70 <= x && x < 80)	k++;
		else if(80 <= x && x < 90)	l++;
		else if(90 <= x && x < 100)	m++;
		else if(x == 100)	n++;
		p = p->next;
	}
	printf("不同数学成绩段的学生数\n");
	printf("不及格的个数：%d\n",i);
	printf("60分段的个数：%d\n",j);
	printf("70分段的个数：%d\n",k);
	printf("80分段的个数：%d\n",l);
	printf("90分段的个数：%d\n",m);
	printf("100分的个数 ：%d\n",n);	
}

/*统计英语成绩*/
void stats_English(LinkList L)
{
	Node *p;
	p = L->next;
	int x;
	int i,j,k,l,m,n = 0;
	i = j = k = l = m = n;
	while(p != NULL)
	{
		x = p->date.English;
		if(x < 60)	i++;
		else if(60 <= x && x < 70)	j++;
		else if(70 <= x && x < 80)	k++;
		else if(80 <= x && x < 90)	l++;
		else if(90 <= x && x < 100)	m++;
		else if(x == 100)	n++;
		p = p->next;
	}
	printf("不同英语成绩段的学生数\n");
	printf("不及格的个数：%d\n",i);
	printf("60分段的个数：%d\n",j);
	printf("70分段的个数：%d\n",k);
	printf("80分段的个数：%d\n",l);
	printf("90分段的个数：%d\n",m);
	printf("100分的个数 ：%d\n",n);	
}

/*统计C语言程序设计成绩*/
void stats_Cyuyan(LinkList L)
{
	Node *p;
	p = L->next;
	int x;
	int i,j,k,l,m,n = 0;
	i = j = k = l = m = n;
	while(p != NULL)
	{
		x = p->date.Cyuyan;
		if(x < 60)	i++;
		else if(60 <= x && x < 70)	j++;
		else if(70 <= x && x < 80)	k++;
		else if(80 <= x && x < 90)	l++;
		else if(90 <= x && x < 100)	m++;
		else if(x == 100)	n++;
		p = p->next;
	}
	printf("不同C语言程序设计成绩段的学生数\n");
	printf("不及格的个数：%d\n",i);
	printf("60分段的个数：%d\n",j);
	printf("70分段的个数：%d\n",k);
	printf("80分段的个数：%d\n",l);
	printf("90分段的个数：%d\n",m);
	printf("100分的个数 ：%d\n",n);	
}

/*统计不同成绩段的个数*/
void stats_student(LinkList L)
{
	int x;
	printf("\t------------------------------------\n");
	printf("\t-----     1.数学成绩           -----\n");
	printf("\t-----     2.英语成绩           -----\n");
	printf("\t-----     3.C语言程序设计成绩  -----\n");
	printf("\t------------------------------------\n");
	printf("请输入你想要统计的科目");
	scanf("%d",&x);	
	switch(x)
	{
		case 1:stats_math(L);break;
		case 2:stats_English(L);break;
		case 3:stats_Cyuyan(L);break;
	}
}

/*密码*/
int code()
{
	int count = 0;
	const char* correct_username = "wqyy";  
    const char* correct_password = "123"; 
	char username[MAXSIZE];
	char password[MAXSIZE];
	printf("请输入管理员姓名：");
	scanf("%s",username);
	printf("\n");
	printf("请输入密码：");
	scanf("%s",password);
	printf("\n");
	while(count < 3)
	{
		if(strcmp(username,correct_username) == 0 && strcmp(password,correct_password) == 0)
		{
			return 1;
			break;
		}
		else
		{
			printf("输入错误！\n");
			printf("请输入正确的管理员姓名：");
			scanf("%s",username);
			printf("\n");
			printf("请输入正确的密码：");
			scanf("%s",password);
			printf("\n");
			count++;
		}
		if(count == 3)
		{
			printf("连续三次输入错误, 系统已关闭！\n");
			return 0;
		}
	}
}

/*退出运行*/
void  exit_1()
{
	printf("退出成功！请按任意键结束！");
	exit(0);
}

/*操作表*/
int scan()
{
	int x = -1;
	while(x != 0)
	{
		printf("\n\n");
		printf("\t---------      功能选择界面    ------------\n");
		printf("\t-----        1.学生信息的输入         -----\n");
		printf("\t-----        2.学生信息的输出         -----\n");
		printf("\t-----        3.学生信息的插入         -----\n");
		printf("\t-----        4.学生信息的修改         -----\n");
		printf("\t-----        5.学生信息的删除         -----\n");
		printf("\t-----        6.学生成绩的排序         -----\n");
		printf("\t-----        7.学生学号的排序         -----\n");
		printf("\t-----        8.学生信息的查找         -----\n");
		printf("\t-----        9.成绩总分的排序         -----\n");
		printf("\t-----        10.不同成绩段的个数      -----\n");
		printf("\t-----        11.退出！                -----\n");
		printf("\t-------------------------------------------\n");
		printf("\n\n");
	 	printf("请输入你想要操作的选项");
		scanf("%d",&x);
		printf("\n");
		return x;
	}
}

/*主函数*/
int main()
{
	int i;
	LinkList L;
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	if(code())
	{
		while(1)
		{
			switch(scan())
			{
				case 1: Input_student(L);break;
				case 2: print_student(L);break;
				case 3: insert_student(L,i);break;
				case 4: change_student(L,i);break;
				case 5: del_student(L,i);break;
				case 6: sort_student(L);break;
				case 7: sort_num(L);break;
				case 8: find_student(L);break;
				case 9: sum_score(L);break;
				case 10:stats_student(L);break;
				case 11:exit_1();break;
			}
		}
	}
	else
		exit(0);
	return 0;
}
	
