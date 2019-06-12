#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;


struct Point{
  vector<float> coord;
};
float distance(Point* p1, Point* p2){
  float dist;
  float rootme = 0;
  auto itt = p2->coord.begin();
  for(auto it = p1->coord.begin(); it!=p1->coord.end(); it++){
    float one = (*it);
    float two = (*itt);
    float three = one - two;
    float four = pow(three, 2);
    rootme +=four;
    itt++;
  }
  dist = sqrt(rootme);
return dist;
}

int main() {
    int n;
    int k;
    vector<Point*> points;
    vector<Point*> clusters;

    cin>>n;
    cin>>k;
    int assign[n];
    cin.ignore();
    for(int x = 0; x<n; x++){
        string tempstr;
        getline(cin, tempstr);
        Point *p1 = new Point();
        vector<string> tv;
        string temp2;
        stringstream ss;
        ss<<tempstr;
        while(ss>>temp2){
          tv.push_back(temp2);
        }
        for(auto it = tv.begin(); it!=tv.end(); it++){
          float f = stof((*it));
          p1->coord.push_back(f);
        }
        points.push_back(p1);
      }
    for(int x = 0; x<k; x++){
          string tempstr;
          getline(cin, tempstr);
          Point *p1 = new Point();
          vector<string> tv;
          string temp2;
          stringstream ss;
          ss<<tempstr;
          while(ss>>temp2){
            tv.push_back(temp2);
          }
          for(auto it = tv.begin(); it!=tv.end(); it++){
            float f = stof((*it));
            p1->coord.push_back(f);
          }
          clusters.push_back(p1);
        }
    for(int i = 0; i<n; i++){
          assign[i] = -1;
        }
//everything ready!
    for(int i = 0; i<n; i++){
      Point *currp = points[i];
      int closest = 0;
      float smallest = distance(currp, clusters[0]);
      for(int j = 1; j<k; j++){
        Point *currc = clusters[j];
        float dist = distance(currp, currc);
        if(dist < smallest){
          smallest = dist;
          closest = j;
        }
      }
      assign[i] = closest;
    } //initial assignments
    for(int i = 0; i<k; i++){
      bool flag = false;
      int count  = 0;
      vector<float> sum;
      for(auto it = points[0]->coord.begin(); it!=points[0]->coord.end(); it++){
        sum.push_back(0);
      }
      for(int j = 0; j<n; j++){
        if(assign[j] == i){
          flag = true;
          count++;
          Point * temp = points[j];
          auto itt = sum.begin();
          for(auto it = temp->coord.begin(); it!= temp->coord.end(); it++){
            float one = (*itt);
            float two = (*it);
            float three = one + two;
            (*itt) = three;
            itt++;
          }
        }// end if
      } //LOOP FOR EACH POINT
      if(flag){
      for(auto it = sum.begin(); it!=sum.end(); it++){
        (*it) = (*it) / count;
      }
      auto itt = sum.begin();
      for(auto it = clusters[i]->coord.begin(); it!= clusters[i]->coord.end(); it++){
      (*it) = (*itt);
      itt++;
      }
    }
    } //LOOP FOR EACH CLUSTER
    // for(auto it = clusters.begin(); it!=clusters.end(); it++){
    //   for(auto itt = (*it)->coord.begin(); itt!=(*it)->coord.end(); itt++){
    //     cout<<(*itt)<<endl;
    //   }
    // }
    bool flag = true;
    while(flag){
      flag = false;
      for(int i = 0; i<n; i++){
        Point *currp = points[i];
        int closest = 0;
        float smallest = distance(currp, clusters[0]);
        for(int j = 1; j<k; j++){
          Point *currc = clusters[j];
          float dist = distance(currp, currc);
          if(dist < smallest){
            smallest = dist;
            closest = j;
          }
        }
        assign[i] = closest;
      } //initial assignments
      for(int i = 0; i<k; i++){
        int count  = 0;
        bool yuh = false;
        vector<float> sum;
        for(auto it = points[0]->coord.begin(); it!=points[0]->coord.end(); it++){
          sum.push_back(0);
        }
        for(int j = 0; j<n; j++){
          if(assign[j] == i){
            yuh = true;
            count++;
            Point * temp = points[j];
            auto itt = sum.begin();
            for(auto it = temp->coord.begin(); it!= temp->coord.end(); it++){
              float one = (*itt);
              float two = (*it);
              float three = one + two;
              (*itt) = three;
              itt++;
            }
          }// end if
        } //LOOP FOR EACH POINT
        if(yuh){
        for(auto it = sum.begin(); it!=sum.end(); it++){
          (*it) = (*it) / count;
        }
        auto itt = sum.begin();
        for(auto it = clusters[i]->coord.begin(); it!= clusters[i]->coord.end(); it++){
          if((*it)!=(*itt)){
            flag = true;
          }
        (*it) = (*itt);
        itt++;
        }
      }
      }
    //  cout<<"end while loop"<<endl;
    }


    for(int i = 0; i<n; i++){
      cout<<assign[i]<<endl;
    }
  return 0;

}
