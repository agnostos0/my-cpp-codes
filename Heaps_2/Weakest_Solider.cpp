#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Row{
    public:
    int scount;
    int idx;
    Row(int scount,int idx){
        this->idx =idx;
        this->scount = scount;
    }

    bool operator < (const Row& other) const{
        if(this->scount == other.scount){
            return this->idx > other.idx;
        }
        return this->scount > other.scount;
}
};
void Weakestrow(vector<vector<int>> matrix,int k)
{   vector<Row> row;
    for(int i = 0; i < matrix.size(); i++){
        int count = 0;
        for(int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++){
            count++;
    }
    row.push_back(Row(count,i));
}
priority_queue<Row> pq(row.begin(),row.end());
for(int i = 0; i < k; i++){
    cout<<"Row "<<pq.top().idx<<" "<<endl;
    pq.pop();
}
}
int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,1,0},{1,0,1}};
    int k = 2;
    Weakestrow(matrix,k);

}