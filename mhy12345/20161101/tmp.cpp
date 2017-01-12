
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
		void sort(int num,char *a)
{ switch(num)
		{ case (1):
				{ strupr(a);
						return ;
				}
				case (2):
				{ strlwr(a);
						return ;
				}
				case(3):
				{ for(int i=strlen(a)-1;i>=0;i--)
						{ cout<<a[i];
						}
						return ;
				}
				case(4):
				{ for(int i=0;i<strlen(a);i++)
						{ if(a[i]>='a'&&a[i]<='z')
								{ cout<<(char)(a[i]-32);
								}
								else
								{ cout<<(char)(a[i]+32);
								}
						}
						return ;
				}
				case(5):
				{  strlwr(a);
						int flag=0;
						cout<<a[0];
						int i;
						for(i=1;i<strlen(a);i++)
						{ if(a[i]-a[i-1]==1)
								{ flag++;
										continue;
								}
								else
								{ if(flag==0)
										{ cout<<a[i];
										}
										else if(flag==1)
										{ cout<<a[i-1]<<a[i];
										}
										else
										{ cout<<'-'<<a[i-1]<<a[i];
										}
										flag=0;
								}
						}
						if(flag==1)
						{ cout<<a[i-1];
						}
						if(flag==2)
						{ cout<<'-'<<a[i-2]<<a[i-1];
						}
						return ;
				}
				default: 
				break;
		}
}
void process()
{ int num;
		char a[300];
		cin>>num;
		cin>>a;
		sort(num,a);
}
int main()
{ process();
		return 0;
}
