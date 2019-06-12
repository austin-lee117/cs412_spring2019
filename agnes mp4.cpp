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
int uniquecount(int arr[], int n){
  int ret = 1;
  for(int i = 1; i<n; i++){
    int j = 0;
    for(; j<i; j++){
      if(arr[i]==arr[j]) break;
    }
      if(i==j)
        ret++;
    }
    return ret;
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

    for(int i = 0; i<n; i++){
          assign[i] = i;
        }

    int unique = (assign, n);

    while(unique>k){
      Point * temp1;
      Point * temp2;
      int pos1;
      int pos2;
      float smallest = 0;
      int x,y;
      x = 0;
      for(auto it = points.begin(); it!=points.end(); it++){
        Point * a = (*it);
        auto itt = it;
        y = x;
        y++;
        itt++;
        for(; itt!=points.end(); itt++){
          Point * b = (*itt);
          float dist = distance(a, b);
          if((smallest==0)||(dist<smallest)){

            if(assign[x]!=assign[y]){

            smallest = dist;
            temp1 = a;
            temp2 = b;
            pos1 = x;
            pos2 = y;
          }
          }
          y++;
        }
        x++;
      }

      int q = assign[pos1];
      int r = assign[pos2];
      if(q<r) assign[pos2] = assign[pos1];
      else if(r<q) assign[pos1] = assign[pos2];
      int check = uniquecount(assign, n);
      unique = check;

  }

    for(int i = 0; i<n; i++){
      cout<<assign[i]<<endl;
    }
  return 0;

}
