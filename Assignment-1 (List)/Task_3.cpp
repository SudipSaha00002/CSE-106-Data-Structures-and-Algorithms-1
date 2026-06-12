#include "arr.cpp"
#include "LL.cpp"


int main() {
    store carsystem;
    int X,Y,Z;
    cin>>X>>Y>>Z;
    lList availCars;
    lList* garages=new lList[Y];

    carsystem.X=X;
    carsystem.Y=Y;
    carsystem.Z=Z;
    carsystem.init();
    
    int g=1;
    int carCount =0,carIndex=0;
    char c;
    int Garage=0;
    for (int i=0;i<Y;i++) {
        for (int j=0;j<Z;j++) {
            int car;
            cin>>car;
            lList* n =new lList;
            n->value=car;
            n->next=NULL;
            lList* tail= carsystem.garages[i].cars.next;
            if (tail==NULL) {
                carsystem.garages[i].cars.next=n;
            }
            else {
                while (tail->next!=NULL) {
                    tail=tail->next;
                }
                tail->next=n;
            }
       
    
    }
    }

    

     string user_input;
    while (user_input!="end") {
        cin >> user_input;
        if (user_input=="req") {
            bool carAssigned=false;
            for (int i=0;i<Y;i++) {
                lList* currgarage=&(carsystem.garages[i].cars);
                if (currgarage->next!=NULL) {
                    lList* clearCar=currgarage->next;
                    currgarage->next=clearCar->next;
                    carAssigned=true;
                    break;
                }
            }
        }
          else if (user_input == "ret") {
            int Car;
            cin >> Car;
            int count[Y];
            for(int i=0;i<Y;i++){
                count[i]=0;
            }
            for(int i=0;i<Y;i++){
                (garages+i-1)->curr=(garages+i-1);
                while((garages+i-1)->curr!=(garages+i-1)->tail){
                    count[i]++;
                    (garages+i-1)->next;
                }
                if((garages+i-1)->curr!=(garages+i-1)){
                    count[i]++;
                }
            }
          }
            
    }

    carsystem.displayStatus();
    
    return 0;
}



