#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int minsup = 0;
    string minsup_str;
    map<string, int> m;
    vector<string> vlinestemp;
    vector<string> vlines;
    vector<string> v;
    getline(cin,minsup_str);
    minsup = stoi(minsup_str);
    string temp;
    bool flag = false;
    while(getline(cin, temp)){
      vlinestemp.push_back(temp);
    }
    for(auto it = vlinestemp.begin(); it!=vlinestemp.end(); it++){
      string temp2 = (*it);
      vector<string> tempvector;
      string tempstring;
      stringstream sstemp;
      sstemp<<temp2;
      while(sstemp>>tempstring){
        tempvector.push_back(tempstring);
      }
      sort(tempvector.begin(), tempvector.end());
      string pushthis="";
      for(auto ittt = tempvector.begin(); ittt!=tempvector.end(); ittt++){
        pushthis = pushthis + (*ittt);
        pushthis = pushthis + " ";
      }
      vlines.push_back(pushthis);
    }
    for(auto it = vlines.begin(); it!=vlines.end(); it++){
      string temp2 = (*it);
      string temp3;
      stringstream ss;
      ss<<temp2;
      while(ss >>temp3){
        v.push_back(temp3);
      }
    } //vlines holds each transaction, v holds each individual unit
    for(auto it = v.begin(); it!=v.end(); it++){
        string ch = (*it);
        if (m.find(ch)==m.end()){
            m[ch] = 1;        }
        else{
            int currcount = m[ch];
            m[ch] = currcount+1;
            flag = true;        }}    //we now have an unordered map with the counts of all 1-length
    auto it = m.begin();
    while(it!=m.end()){
      int count = it->second;
      if(count<minsup){
        auto kill = it;
        it++;
        m.erase(kill);
        continue;      }
      it++;    }     //erase all elements that don't satisfy minsup
      //first scan is complete.
    int k = 2;
    vector<string> candlist;
    for(auto it = m.begin(); it!=m.end(); it++){
      candlist.push_back(it->first);
    }
  while(flag){
      flag = false; //reset flag
      vector<string>candidates;
      for(auto it = candlist.begin(); it!=candlist.end(); it++){
        candidates.push_back(*it);
        }
      candlist.clear();
      //all previous candidates are now in candidates, and candlist (outside variable) is now emptied
      for(auto it = candidates.begin(); it!=candidates.end(); it++){
        auto it2 = it;
        it2++;
        string str1 = (*it);
        // stringstream sst;
        // sst<<str1;
        for(; it2!=candidates.end(); it2++){
          string str2 = (*it2);
          stringstream sst2;
          sst2<<str2;
          if(k==2){
            string newstr = str1;
            newstr = newstr+ " ";
            newstr = newstr+ str2;
            candlist.push_back(newstr);
            flag = true;
          //  cout<<"Pushing "<<newstr<<endl;
          }
          else{
            //cout<<"cp1"<<endl;
            //check if one, two, etc. elements match
            bool commelem = false;
            int common = k-2;
            vector<string> firstcand;
            vector<string> seccand;
            string first;
            string second;
            stringstream sst;
            sst<<str1;
            while(sst>>first){
              firstcand.push_back(first);
            }
            while(sst2>>second){
              seccand.push_back(second);
            }
            for(int x = 0; x<common; x++){
              if(firstcand[x] == seccand[x]){ commelem = true;}
              else {commelem = false;}
            }
            if(commelem){
              string newstr = str1;
              stringstream sst3;
              sst3<<str2;
              for(int x = 0; x<common*2; x++){
                string trash;
                trash = sst3.get();
              }
              string sarah;
              while(sst3>>sarah){
              newstr +=" ";
              newstr +=sarah;
              }
              //check if there are repeated values in newstr
              //check if newstr already exists in candlist
              stringstream sst4;
              sst4<<newstr;
              vector<string>newcheck;
              string medi;
              while(sst4>>medi){
                newcheck.push_back(medi);
              }
              bool repeat = false;
              for(auto bot = newcheck.begin(); bot!=newcheck.end(); bot++){
                auto top = bot;
                top++;
              for(; top!=newcheck.end(); top++){
                  if((*top)==(*bot)){repeat = true;}
                }
              for(auto candit = candlist.begin(); candit!=candlist.end(); candit++){
                if((*candit)==newstr){repeat = true;}
              }
              }
              if(!repeat){
              flag = true;
              candlist.push_back(newstr);
            //  cout<<"Pushing "<<newstr<<endl;
            }
            }
          } //this one closes the else
          }
        }
      for(auto it = candlist.begin(); it!=candlist.end(); it++){

        bool exists = false;
        string check = (*it);
        if(m.find(check)==m.end()){
          m[check] == 0;  }
        stringstream checkword;
        checkword<<check;
        vector<string> checkwords;
        string tempword;
        while(checkword>>tempword){
          checkwords.push_back(tempword);
        }
        for(auto vit = vlines.begin(); vit!=vlines.end(); ++vit){

          string data = (*vit);
          stringstream dataword;
          dataword<<data;
          vector<string> datawords;
          string tempdata;
          while(dataword>>tempdata){
            datawords.push_back(tempdata);
          }
          for(auto x = checkwords.begin(); x!=checkwords.end(); x++){
            for(auto y = datawords.begin(); y!=datawords.end(); y++){
                if((*x)==(*y)){
                exists = true;
                break;
              }
              auto b = y;
              b++;
              if(b==datawords.end()){
                exists = false;
              }
            }
            if(!exists){break;}
          }
          if(exists){
            int count = m[check];
            count++;
            m[check] = count;
          }
      }
    }
    auto it = m.begin();
    while(it!=m.end()){
      int count = it->second;
      if(count<minsup){
        auto kill = it;
        it++;
        m.erase(kill);
        continue;      }
      it++;    }
      k++;
  //    cout<<flag<<endl;
  } //end while loop when no more possible candidates

map<string, int> maxpatt;
map<string, int> closedpatt;
for(auto it = m.begin(); it!=m.end(); it++){
  string s = it->first;
  int num = it->second;
  maxpatt[s] = num;
  closedpatt[s] = num;
}

    while(!m.empty()){
      auto currmax = m.begin();
      for(auto it = m.begin(); it!=m.end(); it++){
        if(it->second > currmax->second){
          currmax = it;
        }
        else if(it->second == currmax->second){
          if(currmax->first > it->first){
            currmax = it;
          }
        }
      }
      cout<<currmax->second<<" ["<<currmax->first<<"]"<<endl;
      m.erase(currmax);
      }
cout<<endl;
      //closed patterns: no superset has the same support
      map<string, int>closedprint;
          //max patterns: no superset is frequent
          for(auto it = closedpatt.begin(); it!=closedpatt.end(); it++){
            string curr = it->first;
            stringstream ss;
            ss<<curr;
            vector<string> currelem;
            string temp;
            while(ss>>temp){
              currelem.push_back(temp);
            }
            bool superset = false;
            for(auto it2 = closedpatt.begin(); it2!=closedpatt.end(); it2++){
              if(it->first==it2->first){ continue;}
              else{
                string check = it2->first;
                stringstream ss2;
                ss2<<check;
                vector<string> checkelem;
                string tomp;
                while(ss2>>tomp){
                  checkelem.push_back(tomp);
                }

                for(auto x = currelem.begin(); x!=currelem.end(); x++){
                  for(auto y = checkelem.begin(); y!=checkelem.end(); y++){
                      if((*x)==(*y)) {
                      superset = true;
                      break;
                    }
                    auto b = y;
                    b++;
                    if(b==checkelem.end()){
                      superset = false;
                    }
                  }
                   if(!superset){break;}
                }
                if(superset){
                    int me = it->second;
                    int them = it2->second;
                    if(me==them){
                      break;
                    }
                    else{
                      closedprint[it->first] = it->second;
                    }
              }         }         }
              if(!superset){
                closedprint[it->first] = it->second;
            }
          }
          while(!closedprint.empty()){
            auto currmax = closedprint.begin();
            for(auto it = closedprint.begin(); it!=closedprint.end(); it++){
              if(it->second > currmax->second){
                currmax = it;
              }
              else if(it->second == currmax->second){
                if(currmax->first > it->first){
                  currmax = it;
                }
              }
            }
            cout<<currmax->second<<" ["<<currmax->first<<"]"<<endl;
            closedprint.erase(currmax);
            }

cout<<endl;
  map<string, int>maxprint;
      //max patterns: no superset is frequent
      for(auto it = maxpatt.begin(); it!=maxpatt.end(); it++){
        string curr = it->first;
        stringstream ss;
        ss<<curr;
        vector<string> currelem;
        string temp;
        while(ss>>temp){
          currelem.push_back(temp);
        }
        bool superset = false;
        for(auto it2 = maxpatt.begin(); it2!=maxpatt.end(); it2++){
          if(it->first==it2->first){ continue;}
          else{
            string check = it2->first;
            stringstream ss2;
            ss2<<check;
            vector<string> checkelem;
            string tomp;
            while(ss2>>tomp){
              checkelem.push_back(tomp);
            }

            for(auto x = currelem.begin(); x!=currelem.end(); x++){
              for(auto y = checkelem.begin(); y!=checkelem.end(); y++){
                  if((*x)==(*y)) {
                  superset = true;
                  break;
                }
                auto b = y;
                b++;
                if(b==checkelem.end()){
                  superset = false;
                }
              }
               if(!superset){break;}
            }
            if(superset){
                break;
          }         }         }
          if(!superset){
            maxprint[it->first] = it->second;
        }
      }
      while(!maxprint.empty()){
        auto currmax = maxprint.begin();
        for(auto it = maxprint.begin(); it!=maxprint.end(); it++){
          if(it->second > currmax->second){
            currmax = it;
          }
          else if(it->second == currmax->second){
            if(currmax->first > it->first){
              currmax = it;
            }
          }
        }
        cout<<currmax->second<<" ["<<currmax->first<<"]"<<endl;
        maxprint.erase(currmax);
        }



    return 0;
}
