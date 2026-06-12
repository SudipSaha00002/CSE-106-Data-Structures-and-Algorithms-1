#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class coordinate {
    public:
    int x;
    int y;

    coordinate(int x, int y){
        this->x=x;
        this->y=y;
    }

     int clockWise(coordinate point1,coordinate point2, coordinate point3){
        int n=(point2.x-point1.x)*(point3.y-point2.y)-(point3.x-point2.x)*(point2.y-point1.y);
        if(n<0){
            return 1;
        }
        else{
            return 0;
        }
     }
  
    vector<coordinate>fence(vector<coordinate> coordinates){
        
        vector<coordinate> line;

        int Point;
        int i=0;
        while(i<coordinates.size()){
            if(coordinates[i].x <coordinates[Point].x){
                Point=i;
            }
            i++;
        } 
        int firstPoint=Point;

        while(coordinates.size()>3){
            line.push_back(coordinates[firstPoint]);
            int lastPoint=firstPoint+1;
            for(int i=0;i<coordinates.size();i++){
                if (clockWise(coordinates[firstPoint], coordinates[i], coordinates[lastPoint])==1) {
                lastPoint = i;
            }
            }
        
           if (lastPoint == Point) {
            break;
        }

        firstPoint = lastPoint;                  
         }
        
        return line;
        }
    
};

int main(){
    ifstream input("in.txt");
    ofstream output("out.txt");

    int N;
    input>> N;
    int x,y;
    coordinate P(x,y);
    vector<coordinate> coordinates;

    for (int i = 0; i < N; i++) {
        input >> x >> y;
        coordinates.push_back({x, y});
    }
    
    coordinates=P.fence(coordinates);
    for(coordinate i:coordinates){
        output<<i.x<<" "<<i.y<<endl;
    }
   
    

    return 0;
}