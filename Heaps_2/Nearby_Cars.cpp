#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Car{
    public:
    int dist;
    int idx;
    Car(int d,int i){
        dist=d;
        idx=i;
    }
bool operator< (const Car &other) const{
        return this->dist >other.dist;
    }
};

void nearbyCar(vector<pair<int,int>> pos,int k){
    vector<Car> c;
    for(int i=0;i<pos.size();i++){
         int distsq = pos[i].first*pos[i].first+pos[i].second*pos[i].second;
        c.push_back(Car(distsq,i));

    }
    priority_queue <Car> pq(c.begin(),c.end());
    for(int i=0;i<k;i++){
        cout<<"car"<<" "<<pq.top().idx<<endl;
        pq.pop();
    }
}
int main(){
vector<pair<int,int>> pos;
pos.push_back(make_pair(3,2));
pos.push_back(make_pair(22,4));
pos.push_back(make_pair(2,4));
int k=2;
nearbyCar(pos,k);
}