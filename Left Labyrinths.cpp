#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int n,m;
int g[100][100];
int dir;
int stepX[4] = {-1,0,1,0};
int stepY[4] = {0,1,0,-1};

int currentX, currentY;

int looop[100][100][4];

bool isCorridor(int x,int y);
bool isYard(int x, int y){
    int a = 0;
    if (isCorridor(x,y))
    	return false;
    if (g[x-1][y]==0&&g[x-1][y+1]==0&&g[x][y+1]==0)
    	return true;
    if (g[x-1][y]==0&&g[x-1][y-1]==0&&g[x][y-1]==0)
    	return true;
    if (g[x+1][y]==0&&g[x+1][y+1]==0&&g[x][y+1]==0)
    	return true;
    if (g[x+1][y]==0&&g[x+1][y-1]==0&&g[x][y-1]==0)
    	return true;
    else return false;
    		
}

bool isCorridor(int x, int y){
	if (g[x][y]==1) return false;
	else if (g[x-1][y] ==1 && g[x+1][y]==1)
		return true;
	else if (g[x][y+1] ==1 && g[x][y-1]==1)
		return true;
	else return false;
}

int main()
{
    int numberOfCases;
    scanf("%d", &numberOfCases);
    while (numberOfCases--){
        
        scanf("%d%d", &n, &m);//n: Number of Lines, m: Number of charactors in a line.
        memset(looop,0,sizeof(looop));
        char c;
        cin.get(c);
        for (int i=0;i<n;i++)
        {
            //cin.get(c);
            for (int j=0;j<m;j++){
                cin.get(c);
                g[i][j]=(c=='.')?0:1;
            }
            cin.get(c);
        }
        //cout << "test:" << g[3][6] << endl;
        
        int startX = -1,startY = -1;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++)
            {
                if (g[i][j] == 1){
                    startX = i;
                    startY = j-1;
                    break;
                }
            }
            if (startX!=-1) break;
        }         //Direction right 0 , down: 1, left 2, up 3
        
        currentX = startX;
        currentY = startY;//(3,4)
        //cout << currentX << " "<< currentY<< endl;

        dir = 1;
        looop[startX][startY][dir] = 1;
        
        bool loop = 0;
        bool flag = 0;
        int x = 0, y = 0;

        while (true){
            int j = 0;
            for (int i=dir;i<dir+4;i++){ //Move Your Way!
                j = i%4;
                x = currentX+stepX[j];
                y = currentY+stepY[j];
                if (x >= 0 && y>= 0 && x < n && y < m)
                    if (g[x][y] == 0)
                        break;
            }
            currentX = x;
            currentY = y;
            dir = (j+3)%4;

          //  cout << currentX << " "<< currentY<< endl;

            if (looop[x][y][dir]==1){
                loop = 1;
                break;
            }
            else if (!isYard(currentX,currentY)){
                flag = 1;
                //cout << "yard"<<isYard(currentX,currentY)<<"HI"<< endl;
                break;
            }            
        }
        int inX = currentX;
        int inY = currentY;
        int inDir = dir;
        //cout <<"in"<<inX<<inY<<inDir<<endl;
        while (true){
            int j = 0;
            for (int i=dir;i<dir+4;i++){ //Move Your Way!
                j = i%4;
                x = currentX+stepX[j];
                y = currentY+stepY[j];
                if (x >= 0 && y>= 0 && x < n && y < m)
                    if (g[x][y] == 0)
                        break;
            }
            currentX = x;
            currentY = y;
            dir = (j+3)%4;
           // cout << currentX << "." << currentY <<"." << dir<< endl;


            if (looop[x][y][dir]==1){
                loop = 1;
                break;
            }
            else if (currentX==inX&&currentY==inY&&dir==((inDir+2)%4)){
            	loop = 1;
            	//cout << "loop";
            	break;
            }

            else if (isYard(currentX,currentY)){
                flag = 2;
                //cout << "isyard"<<currentX << " "<< currentY<< endl;
                break;
            }
     
        }
       /* cout << "test";
                cout << isCorridor(20,19);
                cout << isCorridor(20,21);
                cout << isCorridor(19,20);
                cout << isCorridor(21,20);
                cout << isYard(20,20);*/

        
        if (loop)
            cout << "NO\n";
        else if (flag)
            cout << "YES\n";
        if (numberOfCases) cout << endl;
        
        
    }
    
    return 0;
}
