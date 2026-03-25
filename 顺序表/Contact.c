#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"

//通讯录的初始化
void ContactInit(Contact* con)
{
	//实际上要进行的是顺序表的初始化
	//顺序表的初始化已经实现好了
	SLInit(con);
}
//通讯录的销毁 
void ContactDesTory(Contact* con)
{
	SLDestory(con);
}
//通讯录添加数据
void ContactAdd(Contact* con)
{
	//获取用户输入的内容：姓名+性别+年龄+电话+地址
	peoInfo info;
	printf("请输入要添加到联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入要添加到联系人姓别：\n");
	scanf("%s", info.gender);//数组名即首元素地址
	printf("请输入要添加到联系人年龄：\n");
	scanf("%d", &info.age);
	printf("请输入要添加到联系人电话：\n");
	scanf("%s", info.tel);
	printf("请输入要添加到联系人住址：\n");
	scanf("%s", info.addr);

	//往通讯录中添加联系人数据
	SLPushBack(con, info);
}
//查找函数，看能否找到
int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->arr[i].name, name))
		{
			//找到了
			return i;
		}
	}
	//没有找到
	return -1;
}
//通讯录删除数据
void ContactDel(Contact* con)
{
		//要删除的数据必须要存在，才能执行删除操作
		//查找
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名：\n");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要删除的联系人数据不存在\n");
		return;
	}
	//要删除的联系人数据存在-->知道了要删除的联系人数据对应的下标
	SLErase(con, find);
	printf("删除成功\n");
}
//展示通讯录的数据
void ContactShow(Contact* con)
{
	//表：姓名 性别 年龄 电话 地址
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	//遍历通讯录，按照格式打印每个联系人的数据
	for (int i = 0; i < con->size; i++)
	{
		printf("%s %s %d %s %s\n",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr
			);
	}
}
//通讯录的修改
void ContactModify(Contact* con)
{
	//要修改的联系人存在
	char name[NAME_MAX];
	printf("请输入要修改的用户姓名\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人数据不存在\n");
		return;
	}
	//直接修改
	printf("请输入新的姓名:\n");
	scanf("%s", con->arr[find].name);
	printf("请输入新的姓别：\n");
	scanf("%s", con->arr[find].gender);//数组名即首元素地址
	printf("请输入新的年龄：\n");
	scanf("%d", &con->arr[find].age);
	printf("请输入新的电话：\n");
	scanf("%s", con->arr[find].tel);
	printf("请输入新的住址：\n");
	scanf("%s", con->arr[find].addr);
	printf("修改成功\n");
}
//通讯录的查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要查找的联系人数据不存在\n");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%s %s %d %s %s\n",
		con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr
	);
}
