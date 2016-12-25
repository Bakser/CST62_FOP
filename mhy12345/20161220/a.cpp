
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1010

void upper(char *str)
{
		--str;
		while (*(++str))
				if (!isupper(*str))
						*str+='A'-'a';
}
void lower(char *str)
{
		--str;
		while (*(++str))
				if (!islower(*str))
						*str+='a'-'A';

}
void reverse(char *str)
{
		int l=strlen(str);
		for (int i=0;i<l/2;i++)
				swap(str[i],str[l-i-1]);
}
void haha(char *str)
{
		while (*str)
		{
				if (islower(*str))
						*str+='A'-'a';
				else
						*str-='A'-'a';
				str++;
		}
}
void work(char *str)
{
		char *toptmp=str;
		lower(str);
		while (*str)
		{
				while (*(str+1) && (*str)+1==(*(str+1)))
						str++;
				char* prv=str;
				while (*(prv-1) && *(prv-1) == (*prv)-1)
						prv--;
				if (prv+1<str)
				{
						*toptmp++ = *prv;
						*toptmp++ = '-';
						*toptmp++ = *str;
				}else if (prv+1==str)
				{
						*toptmp++ = *prv;
						*toptmp++ = *str;
				}else
				{
						*toptmp++ = *prv;
				}
				str++;
		}
		*toptmp++='\0';
		//	cout<<tmp<<endl;
		//	strcpy(str,tmp);
}


int main()
{
		//	freopen("input.txt","r",stdin);
		int n;
		char buf[MAXN];
		scanf("%d %s",&n,buf+1);
		buf[0]=0;
		switch(n)
		{
				case 1:upper(buf+1);break;
				case 2:lower(buf+1);break;
				case 3:reverse(buf+1);break;
				case 4:haha(buf+1);break;
				case 5:work(buf+1);break;
		}
		printf("%s\n",buf+1);
}
