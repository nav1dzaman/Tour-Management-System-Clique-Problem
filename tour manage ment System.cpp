#include <bits/stdc++.h>
using namespace std;
int graph[10000][10000];          // adjacency list representation
vector<vector<int>> store_clique; // vector to store clique
int degree[100000];
int keep[100000];
int v=5,e=7;
int cnt = 0;



void clique(int start, int value, int clique_size) // clique checking function
{
    int limit = v - (clique_size - value); // find minimum number of nodes for
                                           //which we need to check clique
    for (int i = start+1; i <= limit; i++)
    {
        if (degree[i] >= clique_size - 1)// checking degree size
        {
            keep[value] = i;
            bool connected_node = true;

            for (int j = 1; j < value + 1; j++)
            {
                for (int k = j + 1; k < value + 1; k++)
                {
                    if (graph[keep[j]][keep[k]] == 0)// checking if its a click
                    {
                        connected_node = false;
                        break;
                    }
                }
            }

            if (connected_node)// if number of nodes is greater than or equal clique_size
            {
                if (value < clique_size)
                {
                    int xy = value + 1;
                    clique(i, xy, clique_size);
                }
                else
                {
                    vector<int> tmp; // a temporary vector to store cliques
                    cnt++;
                    for (int l = 1; l < value + 1; l++)
                    {
                        tmp.push_back(keep[l]);
                    }
                    store_clique.push_back(tmp);
                    tmp.clear();
                }
            }
        }
    }
}

map <int,string> city;

struct service{
    string hotel;
    string dhakar_bus;
    string fenir_bus;
    string comillar_bus;
    string noakhalir_bus;
    string ctg_bus;
    int bus_cost;
    int hotel_cost;
} ;
service dhaka,chittagong;
void our_data(){

   
   dhaka.hotel="Hotel East West";
   dhaka.dhakar_bus="GreenLine";
   dhaka.fenir_bus="Star Line";
   dhaka.comillar_bus="Star Line";
   dhaka.noakhalir_bus="Hanif";
   dhaka.ctg_bus="Shohag Paribahan";
   dhaka.bus_cost=1500;
   dhaka.hotel_cost=1500;

  chittagong.hotel="Hotel East West";
  chittagong.dhakar_bus="GreenLine";
  chittagong.fenir_bus="Star Line";
  chittagong.comillar_bus="Star Line";
  chittagong.noakhalir_bus="Hanif";
  chittagong.ctg_bus="Ena";
  chittagong.bus_cost=500;
  chittagong.hotel_cost=1500;



   city[1]="Dhaka";
   city[5]="Chittagong";
   city[2]="Comilla";
   city[3]="Noakhali";
   city[4]="Feni";
   degree[1]=4;
   degree[2]=2;
   degree[3]=2;
   degree[4]=2;
   degree[5]=4;

    graph[1][2]=1;
    graph[2][1]=1;
    graph[1][3]=1;
    graph[3][1]=1;
    graph[4][1]=1;
    graph[1][4]=1;
    graph[5][1]=1;
    graph[1][5]=1;
    graph[5][2]=1;
    graph[2][5]=1;
    graph[4][5]=1;
    graph[5][4]=1;
    graph[3][5]=1;
    graph[5][3]=1;
}

void intro(){

    cout<<"         Welcome to Tourist Service     "<<endl<<endl;
    cout<<" Currently service available to these cities : "<<endl;
    cout<<"1.Dhaka  5.Chittagong 2.Comilla 3.Noakhali 4.Feni"<<endl;
    cout<<endl;

}

int main()
{


    our_data();
    intro();


   for(int k=2;k<=3;k++){
        clique(0, 1, k);
   }
   int x,y;
   cout<<"Enter City Code: ";
   cin>>x;
   cout<<"Enter Destination City Code: ";
   cin>>y;
     map <int , vector <string>> routes;

   int rut_no=0;
   for(int i=0;i<store_clique.size();i++){
     vector <int> tmp;
     tmp=store_clique[i];

        int cnt=0;


       for(int j=0;j<tmp.size();j++){
             if(tmp[j]==x){
                cnt++;
             }
             if(tmp[j]==y){
                cnt++;
             }
            // cout<<tmp[j]<<" ";

       }

    //   cout<<"Cnt "<<cnt<<endl;

        if(cnt==2){
                rut_no++;
                vector <string> tmp2;
                 for(int uu=0;uu<tmp.size();uu++){
                         tmp2.push_back(city[tmp[uu]]);

                        // cout<<city[tmp[uu]]<<" ";
                 }

                routes[rut_no]=tmp2;


             }





   }
    
    cout<<"Found routes "<<routes.size()<<endl;
    for(auto i:routes){
        vector <string> tm;
        tm=i.second;
        cout<<"Route - "<<i.first<<" ";
        for(int jj=0;jj<tm.size();jj++){
            cout<<tm[jj]<<" ";
        }
        cout<<endl;
    }

    int pakage;
    cout<<"Choose your Route : "<<endl;
    cin>>pakage;

    //done 

    vector <string> chose;
     for(auto i:routes){
       if(pakage==i.first){

       
         vector <string> tm=i.second;
       for(int jj=0;jj<tm.size();jj++){
           chose.push_back(tm[jj]);
        }
       } 
    }

    for(int i=0;i<chose.size()-1;i++){
        if(chose[i]=="Dhaka" && chose[i+1]=="Chittagong"){

            cout<<chose[i]<<" TO "<<chose[i+1]<<" TO "<<chose[i]<<endl;
            cout<<"Bus Service :"<<dhaka.ctg_bus<<endl;
            cout<<"Bus fare : "<<dhaka.bus_cost<<endl;
            cout<<"Hotel Service : "<<dhaka.hotel<<endl;
            cout<<"Hotel Fare : "<<dhaka.hotel_cost<<endl;
        }
    }





   //cout<<store_clique.size()<<endl;







}
