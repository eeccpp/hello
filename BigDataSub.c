#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N  500
//
int main(int argc, char *argv[])
{
	printf("\t\t\t欢迎进入大数减法测试程序\n");
	while(1)
	{ 
	   	char c3;
	   	char sc=0;   // 符号位标志 
	   	char s1[N],s2[N],s3[N+1];
	   	int h1,h2,m1=0,m2=0,error=0;
	   	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("请输入两个长度任意的无符号整数:\n");
		scanf("%s%s",s1,s2);
		printf("------------------------------------------\n");
		//printf("%s\n%s\n",s1,s2);	
		h1 = strlen(s1);
		h2 = strlen(s2);	
		if(h1>0 && h1<N-1 && h2>0 && h2<N-1 && isdigit(s1[0]) && isdigit(s2[0]))
		{
			char *pbig,*psmo,*p3,d=0,flag=0;
			int i,hbig,hsmo;
			for(i=0;i<h1;i++) 	// 检查前零和数字 
			{
				if(!isdigit(s1[i]))
				{
					error |= 0x0002;
					printf("error 2\n");
					break;
				}else if(!flag && '0'==s1[i]) m1++;
				else flag = 1;
			}
			if(!flag) // 全零 
			{ 
				m1=h1-1; h1=1;
			}else
			{
				h1-= m1;
			}
			for(flag=i=0;i<h2;i++)	// 检查前零和数字 
			{
				if(!isdigit(s2[i]))
				{
					error |= 0x0004;
					printf("error 4\n");
					break;
				}else if(!flag && '0'==s2[i]) m2++;
				else flag = 1;
			}
			if(!flag) // 全零 
			{ 
				m2=h2-1; h2=1;
			}else
			{
				h2-= m2;
			}
			hsmo = (h1<h2)?(h1):(h2);
			hbig = (h1<h2)?(h2):(h1);
			if(h1==h2) // 判断大小 
			{
				for(i=0;i<hsmo;i++)
				sc = (s1[i+m1]<s2[i+m2])?(1):(sc);
			}else if(h1<h2)
			{
				sc=1;
			}
			printf("h1=%d,h2=%d,m1=%d,m2=%d,sc=%d\n",h1,h2,m1,m2,(int)d);
			pbig = (sc)?(s2+h2+m2-1):(s1+h1+m1-1);
			psmo = (sc)?(s1+h1+m1-1):(s2+h2+m2-1);
			p3   = &s3[hbig];
			*p3--= '\0';
			for(i=0;i<hsmo;i++)  // 逐步借位减法 
			{
				char a,ng,ns;
				ng = *pbig--;
				ns = *psmo--;
				a = ng -d -ns;
				//printf("ng=%c,ns=%c\n",ng,ns);
				if(a<0)
				{
					d = 1;
					a +=10;
				}else
				{
					d = 0;
				}
				*p3--= a+'0';
				//printf("a=%c\n",(a+'0'));
				
			}
			//printf("i=%d,hbig=%d\n",i,hbig);
			for(;i<hbig;i++)
			{
				char a,ng;
				ng = *pbig--;
				a = ng -d -'0';
				//printf("ng2=%c\n",ng);
				if(a<0)
				{
					d = 1;
					a +=10;
				}else
				{
					d = 0;
				}
				*p3--= a+'0';
				//printf("a2=%c\n",(a+'0'));
			}
			if(!error)
			{
				for(i=0;i<hbig;i++)
				{
					if('0' != s3[i]) break;
				}
				if(i == hbig) i--; // 全零 
				if(sc)
				{
					printf("结果 = -%s\n",&s3[i]);
				}else
				{
					printf("结果 = %s\n",&s3[i]);							
				} 
				
			}
			
		}else
		{
			error |= 0x0001;
			printf("error 1\n");
		}
//-------------------------------------------------
		printf("------------------------------------------\n");
		printf("退出(y/n)?\n");
		c3 = '\n';
		while(1)
		{
		    char c1,c2;			
			c1 = getchar();
			if(c1 == '\n')
			{
				c3 = c1;
				continue;
			}
			c2 = getchar();
			if(c2 != '\n')
			{
				c3 = 0;
				continue;
			}
			if('\n' == c3)
			{
				if('N'==c1 || 'n'==c1)
				break;
				else if('Y'==c1 || 'y'==c1)
				return 0;
			}	
			c3 = '\n';			
		}
//--------------------------------------------------
	}
	return 0;
}
