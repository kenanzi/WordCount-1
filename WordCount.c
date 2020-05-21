#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<io.h>
#pragma warning(disable:4996)
int main(int argc, char* argv[]) {
	if (!strcmp(argv[1], "-c"))
		printf("字符数：%d\n",CharSum(argv[2]));
	else if (!strcmp(argv[1], "-w"))
		printf("单词数：%d\n",WordSum(argv[2]));
	else
	{
		printf("控制参数错误！请重试！");
	}
	return 0;
}

int WordSum(char* Path)//计算单词数
{
	FILE* file = fopen(Path,"r");
	assert(file != NULL);
	char ch;
	int is_word = 0;
	int sum = 0;
		while (!feof(file))
		{
			ch = fgetc(file);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
				is_word = 1;
			else
			{
				sum++;
				is_word = 0;
			}
		}
	fclose(file);
	return sum;
}
int CharSum(char* Path)//计算字符数
{
	FILE* file = fopen(Path, "r");
	assert(file != NULL);
	char ch;
	int sum = 0;
	while ((ch = fgetc(file)) != EOF) 	//读取字符直到结束
	{
		if ((ch== ' ') || (ch== '\n') || (ch== '\t'))
		{
			sum++;
		}
	}
	fclose(file);
	return sum;
}
