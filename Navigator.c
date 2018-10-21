#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <windows.h>
#define INFINITY 9999
#define MAX 10
COORD coord = {0, 0};
char cityname[MAX][20]={"Rajkot","Ahemdabad","Udaipur","Bikaner","Srinagar","Chandigarh","New Delhi","Agra","Lucknow","Varanasi"};
int city[MAX][2]={
			{165,253},
			{195,242},
			{212,215},
			{207,162},
			{250,59},
			{262,121},
			{269,146},
			{284,175},
			{328,184},
			{357,210}
};

int G[MAX][MAX]={          					//city weights
                    {0,16,0,36,0,0,0,0,0,0},			//Rajkot
                    {16,0,17,0,0,0,0,0,0,0},			//Ahm
                    {0,17,0,19,0,0,32,29,0,0},			//Udai
                    {36,0,19,0,0,25,23,0,0,0},			//Bikaner
                    {0,0,0,0,0,23,0,0,0,0},			//Srinagar
                    {0,0,0,25,23,0,9,0,0,0},			//Chandi
                    {0,0,32,23,0,9,0,13,25,0},			//NewD
                    {0,0,29,0,0,0,13,0,0,29},			//Agra
                    {0,0,0,0,0,0,25,0,0,14},			//Lucknow
                    {0,0,0,0,0,0,0,0,29,14}			//Varanasi
            };
int dept,dest;
void gotoxy (int, int);
void drawCities();
void menu();
void bfs(int G[MAX][MAX],int startnode,int dest);
int main()
{
	int gd=DETECT,gm;
	int jk[]={208,24,208,15,216,9,222,9,226,5,236,3,244,6,247,4,253,12,267,22,268,27,281,34,292,27,303,26,312,30,319,35,315,48,304,60,298,61,298,72,303,73,304,78,307,83,298,89,293,84,291,86,284,84,277,78,273,80,268,75,259,74,251,79,250,85,245,87,237,84,233,78,226,77,221,68,219,48,229,39,225,36,223,30,214,24,209,24,208,24};
	int him[]={245,87,256,102,265,114,276,121,280,119,280,109,284,107,293,106,294,99,294,91,291,86,284,84,277,78,273,80,268,75,259,74,251,79,250,85,245,87};
	int pb[]={245,87,256,102,265,114,261,122,254,127,254,131,248,128,241,132,237,128,222,126,217,123,222,119,223,113,229,109,233,107,232,104,233,101,232,93,236,91,245,87};
	int utt[]={276,121,280,119,280,109,284,107,293,106,301,106,325,125,317,133,317,144,313,148,304,141,294,139,292,133,283,133,283,125,276,121};
	int raj[]={217,123,213,127,207,139,197,145,194,152,185,158,178,157,172,158,165,153,150,169,149,174,153,177,160,179,160,188,162,193,166,195,173,213,187,214,195,219,202,220,204,224,221,244,227,238,232,232,231,215,234,212,239,216,244,218,246,229,253,226,266,222,261,216,264,213,270,210,262,208,256,204,259,197,284,182,273,184,275,175,271,165,264,166,264,160,255,160,247,155,242,149,242,140,236,140,235,135,229,134,229,127,223,127,217,123};
	int hyna[]={271,165,264,166,264,160,255,160,247,155,242,149,242,140,236,140,235,135,229,134,229,127,237,128,241,132,248,128,254,131,254,127,261,122,265,114,276,121,269,128,267,133,268,140,267,148,274,157,274,162,271,165};
	int up[]={276,121,283,125,283,133,292,133,294,139,304,141,313,148,320,154,324,154,340,165,344,165,350,170,360,174,364,173,370,174,380,188,376,187,373,188,373,190,375,194,374,197,382,201,372,205,364,211,362,214,367,222,363,226,363,231,358,235,353,234,353,222,345,220,340,214,333,213,328,217,322,213,316,214,316,208,313,209,306,214,302,210,293,208,289,211,295,222,295,228,285,222,282,216,285,210,285,204,288,202,294,203,295,197,296,190,297,187,284,182,273,184,275,175,271,165,274,162,274,157,267,148,268,140,267,133,269,128,276,121};
	int guj[]={173,213,187,214,195,219,202,220,204,224,221,244,224,249,218,252,218,263,212,266,212,269,215,275,211,277,210,286,205,284,205,294,193,291,196,287,196,280,192,276,189,257,188,263,187,270,183,274,169,280,164,282,159,280,136,249,144,248,153,246,156,244,158,241,151,241,147,244,144,243,130,233,128,228,129,224,135,216,140,215,150,217,153,220,160,215,164,215,166,217,167,219,169,217,173,213};
    	menu();
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	setlinestyle(0, 0, 1);
	setfillstyle(9,2);
	fillpoly(45,jk);
	setfillstyle(9,3);
	fillpoly(19,him);
	setfillstyle(9,4);
	fillpoly(20,pb);
	setfillstyle(9,5);
	fillpoly(16,utt);
	setlinestyle(1, 0, 2);
	setlinestyle(0, 0, 1);
	setfillstyle(9,6);
	fillpoly(53,raj);
	setfillstyle(9,7);
	fillpoly(26,hyna);
	setfillstyle(9,8);
	fillpoly(65,up);
	setfillstyle(9,9);
	fillpoly(48,guj);
	setfillstyle(1,0);
	outtextxy(400,100,"Map of North India");
	setlinestyle(2, 0, 2);
	drawCities();
	bfs(G,--dept,--dest);
	getch();
	closegraph();
}
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void menu()
{   int i=5;
	gotoxy(30,i++);
	printf("Guide for North India");
 	gotoxy(30,i++);
    	printf("==================== ");
	gotoxy(30,i++);
	printf(" 1. Rajkot");
	gotoxy(30,i++);
	printf(" 2. Ahemdabad");
	gotoxy(30,i++);
	printf(" 3. Udaipur");
	gotoxy(30,i++);
	printf(" 4. Bikaner");
	gotoxy(30,i++);
	printf(" 5. Srinagar");
	gotoxy(30,i++);
	printf(" 6. Chandigarh");
	gotoxy(30,i++);
	printf(" 7. New Delhi");
	gotoxy(30,i++);
	printf(" 8. Agra");
	gotoxy(30,i++);
	printf(" 9. Lucknow ");
	gotoxy(30,i++);
	printf(" 10. Varanasi ");
	gotoxy(30,i++);
	printf(" Enter your city of departure:");
	scanf("%d", &dept);
	gotoxy(30,i++);
	printf(" Enter your destination city:");
	scanf("%d", &dest);
	gotoxy(30,21);
}
void drawCities(){
    int i;
    for(i=0;i<MAX;i++){
    fillellipse(city[i][0],city[i][1],2,2);
    moveto(city[i][0],city[i][1]);
    outtext(cityname[i]);
    }
}
void bfs(int G[MAX][MAX],int startnode,int dest)
{
    int n=MAX;
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

    //print the path and distance of each node
       // for(i=0;i<n;i++)
        if(dest!=startnode)
        {
            moveto(city[dest][0],city[dest][1]);
//	moveto(city[0][0],city[0][1]);
//	lineto(city[1][0],city[1][1]);
            j=dest;
            do
            {
                j=pred[j];
                lineto(city[j][0],city[j][1]);
            }while(j!=startnode);
    }
    bgiout << "Here is the shortest path from "<<cityname[startnode]<<" to "<<cityname[dest];
    bgiout << "\nThe distance between "<<cityname[startnode]<<" and "<<cityname[dest]<<" is "<<distance[dest]*19<<"km";
    bgiout  << "\nIt would take "<<(distance[dest]*19)/60<<" hours and "<<(distance[dest]*19)%60<<" minutes to travel."; //Average speed in India is considered as 60 kmph
    outstreamxy(150,350);
}
