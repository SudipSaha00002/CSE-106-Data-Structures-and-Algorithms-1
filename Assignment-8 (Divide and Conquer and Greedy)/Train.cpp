#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

#define MAX 100000

 class train{
    public:
    int *arrival;
    int *departure;
    int N;
    train(int N){
        this->N=N;
        arrival =new int[MAX] ;
        departure =new int[MAX] ;
    }

int platformNeed(){

    int i=0,j=0;
    int platform=0;
    int need=0;
    while( i<N && j<N){
        if(arrival[i]< departure[j]){
            platform++;
            i++;
        }
        else{
            platform--;
            j++;
        }

        if(platform>need){
            need=platform;
        }
    }

    return need;
}
 };
int main(){
    ifstream input("in1.txt"); 
    ofstream output("out1.txt");
    int N;
    input>>N;
    train T(N);
 
    for(int i=0;i<T.N;i++){
        input>>T.arrival[i]>>T.departure[i];
    }

    sort(T.arrival,T. arrival+N);
    sort(T.departure, T.departure+N);
    int n=T.platformNeed();
    output<<n<<endl;

}