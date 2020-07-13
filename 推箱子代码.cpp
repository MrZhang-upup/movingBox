#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	int m=5,n=7 ;         //记录地图的大小 （初值5和7是第一关的地图大小） 
	int chapter=1;    //记录是第几关 
	int score=4;		//通关分数 （4为第一关通关分数） 
	int i,j,k; 
	char input;
	int count=0;     //用户当前得分 
	//记录每一关的初始地图 
	int map[5][50][50]={{{1,1,1,1,1,1,1},
						 {1,3,0,4,0,3,1},
						 {1,0,4,6,4,0,1},
						 {1,3,0,4,0,3,1},
						 {1,1,1,1,1,1,1}},
						{{1,1,1,1,1,1},
					     {1,0,0,0,0,1},
						 {1,0,4,0,6,1},
						 {1,1,7,0,0,1},
						 {1,0,7,0,1,1},
						 {1,0,7,0,1,2},
						 {1,0,7,0,1,2},
						 {1,0,3,0,1,2},
						 {1,1,1,1,1,2}},
						{{2,2,1,1,1,1,2},
						 {2,2,1,0,0,1,2},
						 {1,1,1,4,0,1,1},
						 {1,0,0,7,0,6,1},
						 {1,0,0,7,0,0,1},
						 {1,0,0,7,0,1,1},
						 {1,1,1,7,0,1,2},
						 {2,2,1,3,1,1,2},
						 {2,2,1,1,1,2,2}},
						{{2,1,1,1,1,1,1,2},
						 {2,1,0,0,0,0,1,1},
						 {1,1,3,1,1,4,0,1},
						 {1,0,3,3,4,0,0,1},
						 {1,0,0,1,4,0,0,1},
						 {1,0,0,6,0,1,1,1},
						 {1,1,1,1,1,1,2,2}},
						{{1,1,1,1,1,1},
						 {1,0,0,3,0,1},
						 {1,6,1,0,7,1},
						 {1,0,0,4,0,1},
						 {1,0,1,7,0,1},
						 {1,0,0,0,0,1},
						 {1,1,1,1,1,1}}};

	while(1)
	{	
		system("CLS");  //清屏 
		k=chapter-1;     //关卡数减一等于对应关卡的地图ID 
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					switch(map[k][i][j])
					{
					case 0:
						printf(" ");  //代表空地 
						break;
					case 1:
						printf("#");   //代表墙 
						break;
					case 2:
						printf(" ");   //代表墙边缘的空地 
						break;
					case 3:
						printf("*");   //代表目的地 
						break;
					case 4:
						printf("O");   //代表箱子 
						break;
					case 6:
						printf("@");   //代表人 
						break;
					case 7:
						printf("!");   //代表进入目的地的箱子 
						break;
					case 9:
						printf("@");   //代表进入目的地的人 
						break;
					}
				}
				printf("\n");
			}
		//找到玩家的坐标 
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(map[k][i][j]==6||map[k][i][j]==9)
					break;
			}
			if(map[k][i][j]==6||map[k][i][j]==9)
				break;
		}
		input=getch();     //不用按回车获取玩家的行走方向 
		switch(input)
		{
		case 'w':
			//判断前面是否为空地 
			if(map[k][i-1][j]==0)
			{
				map[k][i-1][j]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//判断前面是否为目的地 
			if(map[k][i-1][j]==3)
			{
				map[k][i-1][j]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//判断前面是否为箱子 
			if(map[k][i-1][j]==4)
			{
				if(map[k][i-2][j]==0)  //判断箱子前面是否为空地 
				{
					map[k][i-2][j]=4;
					map[k][i-1][j]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i-2][j]==3)    //判断箱子前面是否为目的地 
				{
					map[k][i-2][j]=7;
					map[k][i-1][j]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count++;
				}
					
			}
			//判断前面是否为目的地的箱子 
			if(map[k][i-1][j]==7)
			{
				if(map[k][i-2][j]==0)  //判读在目的地的箱子前面是否为空地 
				{
					map[k][i-2][j]=4;
					map[k][i-1][j]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i-2][j]==3)  //判读在目的地的箱子前面是否为目的地  
				{
					map[k][i-2][j]=7;
					map[k][i-1][j]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
			}
			break;
		case 'a':
			//判断前面是否为空地 
			if(map[k][i][j-1]==0)
			{
				map[k][i][j-1]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//判断前面是否为目的地 
			if(map[k][i][j-1]==3)
			{
				map[k][i][j-1]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//判断前面是否为箱子 
			if(map[k][i][j-1]==4)
			{
				if(map[k][i][j-2]==0)  //判断箱子前面是否为空地 
				{
					map[k][i][j-2]=4;
					map[k][i][j-1]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i][j-2]==3)    //判断箱子前面是否为目的地 
				{
					map[k][i][j-2]=7;
					map[k][i][j-1]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count++;
				}
					
			}
			//判断前面是否为目的地的箱子 
			if(map[k][i][j-1]==7)
			{
				if(map[k][i][j-2]==0)  //判读在目的地的箱子前面是否为空地 
				{
					map[k][i][j-2]=4;
					map[k][i][j-1]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i][j-2]==3)  //判读在目的地的箱子前面是否为目的地  
				{
					map[k][i][j-2]=7;
					map[k][i][j-1]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
			}
			break;
		case 's':
		//判断前面是否为空地 
			if(map[k][i+1][j]==0)
			{
				map[k][i+1][j]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//判断前面是否为目的地 
			if(map[k][i+1][j]==3)
			{
				map[k][i+1][j]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//判断前面是否为箱子 
			if(map[k][i+1][j]==4)
			{
				if(map[k][i+2][j]==0)  //判断箱子前面是否为空地 
				{
					map[k][i+2][j]=4;
					map[k][i+1][j]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i+2][j]==3)    //判断箱子前面是否为目的地 
				{
					map[k][i+2][j]=7;
					map[k][i+1][j]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count++;
				}
					
			}
			//判断前面是否为目的地的箱子 
			if(map[k][i+1][j]==7)
			{
				if(map[k][i+2][j]==0)  //判读在目的地的箱子前面是否为空地 
				{
					map[k][i+2][j]=4;
					map[k][i+1][j]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i+2][j]==3)  //判读在目的地的箱子前面是否为目的地  
				{
					map[k][i+2][j]=7;
					map[k][i+1][j]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
			}
			break;
		case 'd':
			//判断前面是否为空地 
			if(map[k][i][j+1]==0)
			{
				map[k][i][j+1]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//判断前面是否为目的地 
			if(map[k][i][j+1]==3)
			{
				map[k][i][j+1]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//判断前面是否为箱子 
			if(map[k][i][j+1]==4)
			{
				if(map[k][i][j+2]==0)  //判断箱子前面是否为空地 
				{
					map[k][i][j+2]=4;
					map[k][i][j+1]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i][j+2]==3)    //判断箱子前面是否为目的地 
				{
					map[k][i][j+2]=7;
					map[k][i][j+1]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count++;
				}
					
			}
			//判断前面是否为目的地的箱子 
			if(map[k][i][j+1]==7)
			{
				if(map[k][i][j+2]==0)  //判读在目的地的箱子前面是否为空地 
				{
					map[k][i][j+2]=4;
					map[k][i][j+1]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i][j+2]==3)  //判读在目的地的箱子前面是否为目的地  
				{
					map[k][i][j+2]=7;
					map[k][i][j+1]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
			}
			break;
		}
		if(count==score)
		{
			system("CLS");
			printf("恭喜你，通过第%d关\n",chapter);
			printf("按任意键进入下一关");
			chapter++;
			//判断关卡，改变相应的地图大小，通关分数，初始得分 
			if(chapter==2)
				{
					count=4;
					score=5;
					m=9,n=6;
				}
				else if(chapter==3)
				{
					count=4;
					score=5;
					m=9,n=7;
				}
				else if(chapter==4)
				{
					count=0;
					score=3;
					m=7,n=8;
				}
				else if(chapter==5)
				{
					count=2;
					score=3;
					m=7,n=6;
				}
					input=getch();
			    if(chapter==6)
				{
					system("CLS");
					printf("你已通过所有关卡，谢谢你对本游戏的支持");
					break;
					 
				 }	 
		}	
	}
	return 0;
}


