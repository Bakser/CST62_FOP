#ifndef __MAGICCUBE_H__
#define __MAGICCUBE_H__
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
class MagicCube
{
		private:
				static const int maxn = 3;//魔方每一面是maxn*maxn，默认3*3
				static const int neighbors[6][4];//每一个面的相邻面
				static const char* fname[6];//每一个面的名称，用于输出
				static const int trs[6][12][2];//每一个面那一层的12个颜色坐标
				int face[6][maxn*maxn];//储存颜色
				int fliptimes;//程序执行次数，如果超出限制，说明无解
		public:
				MagicCube();
				void read_config(FILE* fin);
				void print();//输出魔方
				void set_face(int x,int y,int t);//修改face数组
				void flip(int faceId,int dir);//将第faceId个面旋转，方向为dir，dir取1或-1
				void rotate(int dir);//整体旋转
				void operations(const char* str);//输入公式，执行翻转操作
				void operations2(const char* str);//输入公式，执行翻转操作
};

#endif

using namespace std;
//定义面编号
#define FACE_FRONT 0
#define FACE_RIGHT 1
#define FACE_BACK 2
#define FACE_LEFT 3
#define FACE_TOP 4
#define FACE_BOTTOM 5
const int MagicCube::neighbors[6][4]={{1,4,3,5},{2,4,0,5},{3,5,1,4},{2,3,0,1},{0,3,2,1},{3,2,1,0}};
const char* MagicCube::fname[6]= {"front","right","back","left","top","bottom"};
const int MagicCube::trs[6][12][2]={
		{{1,0},{1,3},{1,6},{5,2},{5,1},{5,0},{3,8},{3,5},{3,2},{4,6},{4,7},{4,8}},
		{{4,8},{4,5},{4,2},{2,0},{2,3},{2,6},{5,8},{5,5},{5,2},{0,8},{0,5},{0,2}},
		{{4,2},{4,1},{4,0},{3,0},{3,3},{3,6},{5,6},{5,7},{5,8},{1,8},{1,5},{1,2}},
		{{4,0},{4,3},{4,6},{0,0},{0,3},{0,6},{5,0},{5,3},{5,6},{2,8},{2,5},{2,2}},
		{{3,2},{3,1},{3,0},{2,2},{2,1},{2,0},{1,2},{1,1},{1,0},{0,2},{0,1},{0,0}},
		{{0,6},{0,7},{0,8},{1,6},{1,7},{1,8},{2,6},{2,7},{2,8},{3,6},{3,7},{3,8}},
};
MagicCube::MagicCube()
{
		fliptimes=0;
}
void MagicCube::read_config(FILE * fin = stdin)
{
		FILE *fcfg = fopen("config.ini","r");
		char buf[100];
		bool do_digit=false,do_onedim=false;
		while (fgets(buf,sizeof(buf),fcfg))
		{
				if (strstr(buf,"NAME = digit")!=NULL)
						do_digit = true;
				else if (strstr(buf,"DIM = 1")!=NULL)
						do_onedim = true;
		}
		fclose(fcfg);
		const int seq[6] = {0,2,3,1,4,5};
		const char col[7]="RGBOWY";
		int ptr[26];
		memset(ptr,-1,sizeof(ptr));
		for (int i=0;i<6;i++)
				ptr[col[i]-'A']=i;
		for (int i=0;i<6;i++)
		{
				if (do_onedim)
				{
						fgets(buf,sizeof(buf),fin);
						if (do_digit)
						{
								for (int j=0;j<9;j++)
										face[seq[i]][j] = buf[j]-'0';
						}else
						{
								for (int j=0;j<9;j++)
										face[seq[i]][j] = ptr[buf[j]-'A'];
						}
				}else
				{
						//fgets(buf,sizeof(buf),fin);
						int t=0;
						for (int h=0;h<3;h++)
						{
								fgets(buf,sizeof(buf),fin);
								for (int j=0;j<3;j++)
								{
										if (do_digit)
												face[seq[i]][t++] = buf[j] - '0';
										else
												face[seq[i]][t++] = ptr[buf[j]-'A'];
								}
						}
				}
		}
}
void MagicCube::print()
{
		const char col[7]="RGBOWY";
		const char* col2[7]={"RED","GREEN","BLUE","ORANGE","WHITE","YELLOW"};
		const int seq[6] = {0,2,3,1,4,5};
		for (int i=0;i<6;i++)
		{
				printf("[%s]\n",col2[face[seq[i]][4]]);
				for (int j=0;j<3;j++)
				{
						for (int k=0;k<3;k++)
						{
								printf("%c",col[face[seq[i]][j*3+k]]);
						}
						printf("\n");
				}
		}
}
void MagicCube::set_face(int x,int y,int t)
{
		face[x][y]=t;
}
void MagicCube::flip(int faceId,int dir)//将第faceId个面旋转，方向为dir，dir取1或-1
{
		if (fliptimes++>10000)
		{
				cerr<<"Error!\n"<<endl;
				exit(0);
		}
		//		cout<<">>>FLIP "<<fname[faceId]<<" "<<(dir==1?"clockwise":"anticlockwise")<<endl;
		MagicCube tmp=*this;
		for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
						if (dir==1)
								tmp.set_face(faceId,k*3+(2-j),face[faceId][j*3+k]);
						else
								tmp.set_face(faceId,(2-k)*3+j,face[faceId][j*3+k]);
		for (int i=0;i<12;i++)
		{
				tmp.set_face(trs[faceId][(i+3*dir+12)%12][0],trs[faceId][(i+3*dir+12)%12][1],
								face[trs[faceId][i][0]][trs[faceId][i][1]]);
		}
		*this=tmp;
}
void MagicCube::rotate(int dir)
{
		//cout<<">>>ROTATE "<<(dir==1?"clockwise":"anticlockwise")<<endl;
		MagicCube tmp=*this;
		for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
						if (dir==1)
						{
								tmp.set_face(FACE_TOP,k*3+(2-j),face[FACE_TOP][j*3+k]);
								tmp.set_face(FACE_BOTTOM,(2-k)*3+j,face[FACE_BOTTOM][j*3+k]);
						}
						else
						{
								tmp.set_face(FACE_TOP,(2-k)*3+j,face[FACE_TOP][j*3+k]);
								tmp.set_face(FACE_BOTTOM,k*3+(2-j),face[FACE_BOTTOM][j*3+k]);
						}
		for (int i=0;i<4;i++)
				for (int j=0;j<9;j++)
						tmp.set_face((i+4-dir)%4,j,face[i][j]);
		*this = tmp;
}
void MagicCube::operations(const char* str)
{
		while (*str)
		{
				switch(*(str++))
				{
						case 'F':
								flip(FACE_FRONT,1);break;
						case 'f':
								flip(FACE_FRONT,-1);break;
						case 'U':
								flip(FACE_TOP,1);break;
						case 'u':
								flip(FACE_TOP,-1);break;
						case 'R':
								flip(FACE_RIGHT,1);break;
						case 'r':
								flip(FACE_RIGHT,-1);break;
						case 'L':
								flip(FACE_LEFT,1);break;
						case 'l':
								flip(FACE_LEFT,-1);break;
						case 'B':
								flip(FACE_BACK,1);break;
						case 'b':
								flip(FACE_BACK,-1);break;
						case 'T':
								flip(FACE_BOTTOM,1);break;
						case 't':
								flip(FACE_BOTTOM,-1);break;
						default:
								fprintf(stderr,"Wrong opeation");
								exit(0);
				}
		}
}
void MagicCube::operations2(const char* str)
{
		char buf[100]="";
		int topb=0;
		int n=strlen(str);
		for (int i=0;i<n;i++)
		{
				if (str[i]=='\n')continue;
				if (str[i]=='i')
						buf[topb-1]+='a'-'A';
				else
						buf[topb++]=str[i];
		}
		buf[topb++]='\0';
		operations(buf);
}

int main()
{
	//	freopen("input.txt","r",stdin);
		MagicCube mc;
		mc.read_config();
	//	mc.read_config(fopen("input.txt","r"));
		mc.print();
		while (true)
		{
				char buf[1000];
				printf(">>> ");
				fgets(buf,sizeof(buf),stdin);
				mc.operations2(buf);
				mc.print();
		}
		return 0;
}
