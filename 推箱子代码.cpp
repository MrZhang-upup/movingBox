#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	int m=5,n=7 ;         //��¼��ͼ�Ĵ�С ����ֵ5��7�ǵ�һ�صĵ�ͼ��С�� 
	int chapter=1;    //��¼�ǵڼ��� 
	int score=4;		//ͨ�ط��� ��4Ϊ��һ��ͨ�ط����� 
	int i,j,k; 
	char input;
	int count=0;     //�û���ǰ�÷� 
	//��¼ÿһ�صĳ�ʼ��ͼ 
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
		system("CLS");  //���� 
		k=chapter-1;     //�ؿ�����һ���ڶ�Ӧ�ؿ��ĵ�ͼID 
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					switch(map[k][i][j])
					{
					case 0:
						printf(" ");  //����յ� 
						break;
					case 1:
						printf("#");   //����ǽ 
						break;
					case 2:
						printf(" ");   //����ǽ��Ե�Ŀյ� 
						break;
					case 3:
						printf("*");   //����Ŀ�ĵ� 
						break;
					case 4:
						printf("O");   //�������� 
						break;
					case 6:
						printf("@");   //������ 
						break;
					case 7:
						printf("!");   //�������Ŀ�ĵص����� 
						break;
					case 9:
						printf("@");   //�������Ŀ�ĵص��� 
						break;
					}
				}
				printf("\n");
			}
		//�ҵ���ҵ����� 
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
		input=getch();     //���ð��س���ȡ��ҵ����߷��� 
		switch(input)
		{
		case 'w':
			//�ж�ǰ���Ƿ�Ϊ�յ� 
			if(map[k][i-1][j]==0)
			{
				map[k][i-1][j]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//�ж�ǰ���Ƿ�ΪĿ�ĵ� 
			if(map[k][i-1][j]==3)
			{
				map[k][i-1][j]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//�ж�ǰ���Ƿ�Ϊ���� 
			if(map[k][i-1][j]==4)
			{
				if(map[k][i-2][j]==0)  //�ж�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i-2][j]=4;
					map[k][i-1][j]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i-2][j]==3)    //�ж�����ǰ���Ƿ�ΪĿ�ĵ� 
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
			//�ж�ǰ���Ƿ�ΪĿ�ĵص����� 
			if(map[k][i-1][j]==7)
			{
				if(map[k][i-2][j]==0)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i-2][j]=4;
					map[k][i-1][j]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i-2][j]==3)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�ΪĿ�ĵ�  
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
			//�ж�ǰ���Ƿ�Ϊ�յ� 
			if(map[k][i][j-1]==0)
			{
				map[k][i][j-1]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//�ж�ǰ���Ƿ�ΪĿ�ĵ� 
			if(map[k][i][j-1]==3)
			{
				map[k][i][j-1]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//�ж�ǰ���Ƿ�Ϊ���� 
			if(map[k][i][j-1]==4)
			{
				if(map[k][i][j-2]==0)  //�ж�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i][j-2]=4;
					map[k][i][j-1]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i][j-2]==3)    //�ж�����ǰ���Ƿ�ΪĿ�ĵ� 
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
			//�ж�ǰ���Ƿ�ΪĿ�ĵص����� 
			if(map[k][i][j-1]==7)
			{
				if(map[k][i][j-2]==0)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i][j-2]=4;
					map[k][i][j-1]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i][j-2]==3)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�ΪĿ�ĵ�  
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
		//�ж�ǰ���Ƿ�Ϊ�յ� 
			if(map[k][i+1][j]==0)
			{
				map[k][i+1][j]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//�ж�ǰ���Ƿ�ΪĿ�ĵ� 
			if(map[k][i+1][j]==3)
			{
				map[k][i+1][j]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//�ж�ǰ���Ƿ�Ϊ���� 
			if(map[k][i+1][j]==4)
			{
				if(map[k][i+2][j]==0)  //�ж�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i+2][j]=4;
					map[k][i+1][j]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i+2][j]==3)    //�ж�����ǰ���Ƿ�ΪĿ�ĵ� 
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
			//�ж�ǰ���Ƿ�ΪĿ�ĵص����� 
			if(map[k][i+1][j]==7)
			{
				if(map[k][i+2][j]==0)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i+2][j]=4;
					map[k][i+1][j]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i+2][j]==3)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�ΪĿ�ĵ�  
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
			//�ж�ǰ���Ƿ�Ϊ�յ� 
			if(map[k][i][j+1]==0)
			{
				map[k][i][j+1]=6;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;
			}
			//�ж�ǰ���Ƿ�ΪĿ�ĵ� 
			if(map[k][i][j+1]==3)
			{
				map[k][i][j+1]=9;
				if(map[k][i][j]==9)
				map[k][i][j]=3;
				else
				map[k][i][j]=0;		
			}
			//�ж�ǰ���Ƿ�Ϊ���� 
			if(map[k][i][j+1]==4)
			{
				if(map[k][i][j+2]==0)  //�ж�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i][j+2]=4;
					map[k][i][j+1]=6;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
				}
				if(map[k][i][j+2]==3)    //�ж�����ǰ���Ƿ�ΪĿ�ĵ� 
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
			//�ж�ǰ���Ƿ�ΪĿ�ĵص����� 
			if(map[k][i][j+1]==7)
			{
				if(map[k][i][j+2]==0)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�Ϊ�յ� 
				{
					map[k][i][j+2]=4;
					map[k][i][j+1]=9;
					if(map[k][i][j]==9)
						map[k][i][j]=3;
					else
						map[k][i][j]=0;
					count--;
				}
				if(map[k][i][j+2]==3)  //�ж���Ŀ�ĵص�����ǰ���Ƿ�ΪĿ�ĵ�  
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
			printf("��ϲ�㣬ͨ����%d��\n",chapter);
			printf("�������������һ��");
			chapter++;
			//�жϹؿ����ı���Ӧ�ĵ�ͼ��С��ͨ�ط�������ʼ�÷� 
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
					printf("����ͨ�����йؿ���лл��Ա���Ϸ��֧��");
					break;
					 
				 }	 
		}	
	}
	return 0;
}


