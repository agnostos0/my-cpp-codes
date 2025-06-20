#include<iostream>
#include<vector>
using namespace std;
class Job{ public:
    int idx;
    int time;
    int profit;
   
    Job(int idx,int time,int profit){
        this->idx =idx;
        this->time = time;
        this->profit = profit;
    }
};
void maxprofit( vector<pair<int,int>> job) 
{int n = job.size();
    vector<Job> jobs;
    for(int i=0;i<n;i++){
     jobs.emplace_back(i,job[i].first,job[i].second);
    }

    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){
        return a.profit>b.profit;
    });
     int profit = jobs[0].profit;
    int safe =  jobs[0].time;
       char ch = 'A'+ jobs[0].idx;
     cout<<"job ->"<<ch<<"="<<jobs[0].profit<<","<<jobs[0].time<<endl;
    for(int i=1;i<n;i++)
{
     if(jobs[i].time>safe){
        profit+=jobs[i].profit;
        safe = jobs[i].time;
        ch = 'A'+ jobs[i].idx;
        cout<<"job ->"<<ch<<"="<<jobs[i].time<<","<<jobs[i].profit<<endl;
     }
}
cout<<profit<<endl;
}



int main(){
     vector<pair<int,int>> job(4,make_pair(0,0));
    job[0] = make_pair(4,20);
    job[1] = make_pair(1,10);
    job[2] = make_pair(1,40);
    job[3] = make_pair(1,30);
    maxprofit(job);
   
}
