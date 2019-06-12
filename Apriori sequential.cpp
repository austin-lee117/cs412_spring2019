
//things to change from MP1:
//fixed minsup = 2
//additional restraints ( pattern length )
//do not sort input from stdin
//
//differences in algorithm:
//do not map 1-length patterns
//use 1-length patterns to prune and form combo candidates
//check if LAST word and FIRST word are matching
//3-length combo = 2+2 with 1 overlap
//4-length combo = 3+2 with 1 overlap
//5-length combo = 4+2 with 1 overlap


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
  int minsup = 2;
  map<string, int> min;
  map<string, int> m;
  vector<string> vlines;
  vector<string> v;
  string temp;
  bool flag = false;
  while(getline(cin, temp)){
    vlines.push_back(temp);
  }
  for(auto it = vlines.begin(); it!=vlines.end(); it++){
  //  cout<<(*it)<<endl;
    string temp2 = (*it);
    string temp3;
    stringstream ss;
    ss<<temp2;
    while(ss >>temp3){
      v.push_back(temp3);
    }
  } //vlines holds each transaction, v holds each individual unit
  for(auto it = v.begin(); it!=v.end(); it++){
    //cout<<(*it)<<" "<<endl;
      string ch = (*it);
      if (min.find(ch)==min.end()){
          min[ch] = 1;        }
      else{
          int currcount = min[ch];
          min[ch] = currcount+1;
          flag = true;        }}
            //we now have an unordered map with the counts of all 1-length
  auto it = min.begin();
  while(it!=min.end()){
    int count = it->second;
    if(count<minsup){ //anything that doesn't appear more than once is killed
      auto kill = it;
      it++;
      min.erase(kill);
      continue;      }
    it++;    }
    int k = 2;
        vector<string> lenone;
        vector<string> lentwo;
        vector<string> lenthree;
        vector<string> lenfour;

        for(auto it = v.begin(); it!=v.end(); it++){
          lenone.push_back((*it));
        }
      while(flag&&(k<6)){
          flag = false; //reset flag
          if(k==2){
            vector<string> alltemp;
            for(auto it = lenone.begin(); it!=lenone.end(); it++){
              auto it2 = it;
              it2++;
              for(; it2!=lenone.end(); it2++){
                string tempk2 = (*it);
                tempk2+=" ";
                tempk2+=(*it2);
                string t2;
                stringstream ss2;
                ss2<<tempk2;
                vector<string> check2;
                while(ss2>>t2){
                  check2.push_back(t2); //check 2 holds the candidate
                }
                for(auto vlit = vlines.begin(); vlit!=vlines.end(); vlit++){
                  bool exists = false;
                  stringstream ssvlit;
                  string tempvlit;
                  string currvlit = (*vlit);
                  ssvlit<<currvlit;
                  vector<string> data;
                  while(ssvlit>>tempvlit){
                    data.push_back(tempvlit);
                  }
                  for(auto x = check2.begin(); x!=check2.end(); x++){
                    for(auto y = data.begin(); y!=data.end(); y++){
                      auto a = x;
                      auto b = y;
                      if((*x)==(*y)){
                        a++;
                        b++;
                        if(a!=check2.end()&&b!=data.end()&&(*a)==(*b)){
                          exists = true;
                          break;
                        }
                      }
                    }
                    if(exists){break;}
                  }
                  if(exists){
                    if(m.find(tempk2) == m.end()){
                      m[tempk2] =0;
                    }
                    bool repeat = false;
                    for(auto ree = alltemp.begin(); ree!=alltemp.end(); ree++){
                      if((*ree)==tempk2){
                        repeat = true;
                        break;
                      }
                    }
                    if(!repeat){
                      flag=true;
                    alltemp.push_back(tempk2);
                  }
                  }
                }
              }//end it2 for loop
            }//end it for loop
            for(auto it= alltemp.begin(); it!=alltemp.end(); it++){
              //map to m
                bool exists = false;
                string check = (*it);
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
                  int times = 0;
                  for(auto x = checkwords.begin(); x!=checkwords.end(); x++){
                    for(auto y = datawords.begin(); y!=datawords.end(); y++){
                      exists = false;
                        if((*x)==(*y)){
                        exists = true;
                        auto q = x;
                        auto r = y;
                        for(int i = 0; i < 1 ; i++){
                          q++;
                          r++;
                          if(q==checkwords.end()) {exists = false;
                            break;
                          }
                          else if(r==datawords.end()) {exists = false;
                            break;
                          }
                          else if((*q)!=(*r)) {exists = false;
                            break;}
                        }
                      }
                        if(exists){
                          int count = m[check];
                          count++;
                          m[check] = count;
                        }
                      }
                  }
              }
            }
            for(auto doe = alltemp.begin(); doe!=alltemp.end(); doe++){
              string doto = (*doe);
              if(m[doto]>=2){
                lentwo.push_back(doto);
              }
            }
          }//end k==2 if block
          if(k==3){
            vector<string> alltemp;
            for(auto it = lentwo.begin(); it!=lentwo.end(); it++){
    //          cout<<(*it)<<endl;
              for(auto it2 = lentwo.begin(); it2!=lentwo.end(); it2++){
                if(it==it2) continue;
        //        cout<<"and "<<(*it2)<<endl;
                string potato = (*it);
                string tomato = (*it2);
                stringstream pot;
                stringstream tom;
                pot<<potato;
                tom<<tomato;
                string poto;
                string tomo;
                vector<string> poo;
                vector<string> too;
                while(pot>>poto) poo.push_back(poto);
                while(tom>>tomo) too.push_back(tomo);
              //  cout<<"1"<<endl;
                auto pah = poo.end();
                auto tah = too.begin();
                pah--;
            //    cout<<"checking "<<((*pah))<<" and "<<((*tah))<<endl;
                if((*pah)==(*tah)){
                tah++;
                string tempk2 = (*it);
                for(;tah!=too.end(); tah++){
                  tempk2+=" ";
                  tempk2+=(*tah);
        //          cout<<tempk2<<endl;
                }
                string t2;
                stringstream ss2;
                ss2<<tempk2;
                vector<string> check2;
                while(ss2>>t2){
                  check2.push_back(t2); //check 2 holds the candidate
                }
                for(auto vlit = vlines.begin(); vlit!=vlines.end(); vlit++){
                  bool exists = false;
                  stringstream ssvlit;
                  string tempvlit;
                  string currvlit = (*vlit);
                  ssvlit<<currvlit;
                  vector<string> data;
                  while(ssvlit>>tempvlit){
                    data.push_back(tempvlit);
                  }
                  for(auto x = check2.begin(); x!=check2.end(); x++){
                    for(auto y = data.begin(); y!=data.end(); y++){
                      auto a = x;
                      auto b = y;
                      auto c = x;
                      auto d = y;
                      if((*x)==(*y)){
                        a++;
                        b++;
                        c++;
                        if(c==check2.end()) break;
                        c++;
                        d++;
                        if(d==data.end()) break;
                        d++;
                        //cout<<(*x)<<(*y)<<(*a)<<(*b)<<(*c)<<(*d)<<endl;
                        if(a!=check2.end()&&b!=data.end()&&(*a)==(*b)){
                          if(c!=check2.end()&&d!=data.end()&&(*c)==(*d)){
                          exists = true;
                          break;
                        }
                      }
                      }
                    }
                    if(exists){break;}
                  }
                  if(exists){
                    //cout<<"?"<<endl;
                    if(m.find(tempk2) == m.end()){
                      m[tempk2] =0;
                    }
                    bool repeat = false;
                    for(auto ree = alltemp.begin(); ree!=alltemp.end(); ree++){
                      if((*ree)==tempk2){
                        repeat = true;
                        break;
                      }
                    }
                    if(!repeat){
                      flag=true;
                    alltemp.push_back(tempk2);
                    //cout<<"pushing "<<tempk2<<endl;
                  }
                  }
                }
              }
              }//end it2 for loop
              //cout<<"err"<<endl;
            }//end it for loop
            //cout<<"!>>>!"<<endl;
            for(auto it= alltemp.begin(); it!=alltemp.end(); it++){
              //cout<<"durr"<<endl;
              //map to m
                bool exists = false;
                string check = (*it);
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
                  int times = 0;
                  for(auto x = checkwords.begin(); x!=checkwords.end(); x++){
                    for(auto y = datawords.begin(); y!=datawords.end(); y++){
                      exists = false;
                        if((*x)==(*y)){
                        exists = true;
                        auto q = x;
                        auto r = y;
                        for(int i = 0; i < 2 ; i++){
                          q++;
                          r++;
                          if(q==checkwords.end()) {exists = false;
                            break;
                          }
                          else if(r==datawords.end()) {exists = false;
                            break;
                          }
                          else if((*q)!=(*r)) {exists = false;
                            break;}
                        }
                      }
                        if(exists){
                          int count = m[check];
                          count++;
                          m[check] = count;
                        }
                      }
                  }
              }
            }
            for(auto doe = alltemp.begin(); doe!=alltemp.end(); doe++){
              string doto = (*doe);
              if(m[doto]>=2){
                lenthree.push_back(doto);
              }
            }

          }
          if(k==4){
            vector<string> alltemp;
            for(auto it = lenthree.begin(); it!=lenthree.end(); it++){
    //          cout<<(*it)<<endl;
              for(auto it2 = lentwo.begin(); it2!=lentwo.end(); it2++){
  //            cout<<"and "<<(*it2)<<endl;
                string potato = (*it);
                string tomato = (*it2);
                stringstream pot;
                stringstream tom;
                pot<<potato;
                tom<<tomato;
                string poto;
                string tomo;
                vector<string> poo;
                vector<string> too;
                while(pot>>poto) poo.push_back(poto);
                while(tom>>tomo) too.push_back(tomo);
              //  cout<<"1"<<endl;
                auto pah = poo.end();
                auto tah = too.begin();
                pah--;
            //    cout<<"checking "<<((*pah))<<" and "<<((*tah))<<endl;
                if((*pah)==(*tah)){
                tah++;
                string tempk2 = (*it);
                for(;tah!=too.end(); tah++){
                  tempk2+=" ";
                  tempk2+=(*tah);
        //          cout<<tempk2<<endl;
                }
                string t2;
                stringstream ss2;
                ss2<<tempk2;
                vector<string> check2;
                while(ss2>>t2){
                  check2.push_back(t2); //check 2 holds the candidate
                }
                for(auto vlit = vlines.begin(); vlit!=vlines.end(); vlit++){
                  bool exists = false;
                  stringstream ssvlit;
                  string tempvlit;
                  string currvlit = (*vlit);
                  ssvlit<<currvlit;
                  vector<string> data;
                  while(ssvlit>>tempvlit){
                    data.push_back(tempvlit);
                  }
                  for(auto x = check2.begin(); x!=check2.end(); x++){
                    for(auto y = data.begin(); y!=data.end(); y++){
                      auto a = x;
                      auto b = y;
                      auto c = x;
                      auto d = y;
                      auto e = x;
                      auto f = y;
                      if((*x)==(*y)){
                        a++;
                        b++;
                        c++;
                        if(c==check2.end()) break;
                        c++;
                        d++;
                        if(d==data.end()) break;
                        d++;
                        e++;
                        e++;
                        if(e==check2.end()) break;
                        e++;
                        f++;
                        f++;
                        if(f==data.end()) break;
                        f++;
                        //cout<<(*x)<<(*y)<<(*a)<<(*b)<<(*c)<<(*d)<<endl;
                        if(a!=check2.end()&&b!=data.end()&&(*a)==(*b)){
                          if(c!=check2.end()&&d!=data.end()&&(*c)==(*d)){
                            if(e!=check2.end()&&f!=data.end()&&(*e)==(*f)){
                          exists = true;
                          break;
                        }
                        }
                      }
                      }
                    }
                    if(exists){break;}
                  }
                  if(exists){
                    //cout<<"?"<<endl;
                    if(m.find(tempk2) == m.end()){
                      m[tempk2] =0;
                    }
                    bool repeat = false;
                    for(auto ree = alltemp.begin(); ree!=alltemp.end(); ree++){
                      if((*ree)==tempk2){
                        repeat = true;
                        break;
                      }
                    }
                    if(!repeat){
                      flag=true;
                    alltemp.push_back(tempk2);
                    //cout<<"pushing "<<tempk2<<endl;
                  }
                  }
                }
              }
              }//end it2 for loop
              //cout<<"err"<<endl;
            }//end it for loop
            //cout<<"!>>>!"<<endl;
            for(auto it= alltemp.begin(); it!=alltemp.end(); it++){
              //cout<<"durr"<<endl;
              //map to m
                bool exists = false;
                string check = (*it);
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
                  int times = 0;
                  for(auto x = checkwords.begin(); x!=checkwords.end(); x++){
                    for(auto y = datawords.begin(); y!=datawords.end(); y++){
                      exists = false;
                        if((*x)==(*y)){
                        exists = true;
                        auto q = x;
                        auto r = y;
                        for(int i = 0; i < 3 ; i++){
                          q++;
                          r++;
                          if(q==checkwords.end()) {exists = false;
                            break;
                          }
                          else if(r==datawords.end()) {exists = false;
                            break;
                          }
                          else if((*q)!=(*r)) {exists = false;
                            break;}
                        }
                      }
                        if(exists){
                          int count = m[check];
                          count++;
                          m[check] = count;
                        }
                      }
                  }
              }
            }
            for(auto doe = alltemp.begin(); doe!=alltemp.end(); doe++){
              string doto = (*doe);
              if(m[doto]>=2){
                lenfour.push_back(doto);
              }
            }
          }
          if(k==5){
            vector<string> alltemp;
            for(auto it = lenfour.begin(); it!=lenfour.end(); it++){
    //          cout<<(*it)<<endl;
              for(auto it2 = lentwo.begin(); it2!=lentwo.end(); it2++){
  //            cout<<"and "<<(*it2)<<endl;
                string potato = (*it);
                string tomato = (*it2);
                stringstream pot;
                stringstream tom;
                pot<<potato;
                tom<<tomato;
                string poto;
                string tomo;
                vector<string> poo;
                vector<string> too;
                while(pot>>poto) poo.push_back(poto);
                while(tom>>tomo) too.push_back(tomo);
              //  cout<<"1"<<endl;
                auto pah = poo.end();
                auto tah = too.begin();
                pah--;
            //    cout<<"checking "<<((*pah))<<" and "<<((*tah))<<endl;
                if((*pah)==(*tah)){
                tah++;
                string tempk2 = (*it);
                for(;tah!=too.end(); tah++){
                  tempk2+=" ";
                  tempk2+=(*tah);
        //          cout<<tempk2<<endl;
                }
                string t2;
                stringstream ss2;
                ss2<<tempk2;
                vector<string> check2;
                while(ss2>>t2){
                  check2.push_back(t2); //check 2 holds the candidate
                }
                for(auto vlit = vlines.begin(); vlit!=vlines.end(); vlit++){
                  bool exists = false;
                  stringstream ssvlit;
                  string tempvlit;
                  string currvlit = (*vlit);
                  ssvlit<<currvlit;
                  vector<string> data;
                  while(ssvlit>>tempvlit){
                    data.push_back(tempvlit);
                  }
                  for(auto x = check2.begin(); x!=check2.end(); x++){
                    for(auto y = data.begin(); y!=data.end(); y++){
                      auto a = x;
                      auto b = y;
                      auto c = x;
                      auto d = y;
                      auto e = x;
                      auto f = y;
                      auto g = x;
                      auto h = y;
                      if((*x)==(*y)){
                        a++;
                        b++;
                        c++;
                        if(c==check2.end()) break;
                        c++;
                        d++;
                        if(d==data.end()) break;
                        d++;
                        e++;
                        e++;
                        if(e==check2.end()) break;
                        e++;
                        f++;
                        f++;
                        if(f==data.end()) break;
                        f++;
                        g++;
                        g++;
                        g++;
                        if(g==check2.end()) break;
                        g++;
                        h++;
                        h++;
                        h++;
                        if(h==data.end()) break;
                        h++;
                        //cout<<(*x)<<(*y)<<(*a)<<(*b)<<(*c)<<(*d)<<endl;
                        if(a!=check2.end()&&b!=data.end()&&(*a)==(*b)){
                          if(c!=check2.end()&&d!=data.end()&&(*c)==(*d)){
                            if(e!=check2.end()&&f!=data.end()&&(*e)==(*f)){
                              if(g!=check2.end()&&h!=data.end()&&(*g)==(*h)){
                          exists = true;
                          break;
                        }
                        }
                        }
                      }
                      }
                    }
                    if(exists){break;}
                  }
                  if(exists){
                    //cout<<"?"<<endl;
                    if(m.find(tempk2) == m.end()){
                      m[tempk2] =0;
                    }
                    bool repeat = false;
                    for(auto ree = alltemp.begin(); ree!=alltemp.end(); ree++){
                      if((*ree)==tempk2){
                        repeat = true;
                        break;
                      }
                    }
                    if(!repeat){
                      flag=true;
                    alltemp.push_back(tempk2);
                    //cout<<"pushing "<<tempk2<<endl;
                  }
                  }
                }
              }
              }//end it2 for loop
              //cout<<"err"<<endl;
            }//end it for loop
            //cout<<"!>>>!"<<endl;
            for(auto it= alltemp.begin(); it!=alltemp.end(); it++){
              //cout<<"durr"<<endl;
              //map to m
                bool exists = false;
                string check = (*it);
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
                  int times = 0;
                  for(auto x = checkwords.begin(); x!=checkwords.end(); x++){
                    for(auto y = datawords.begin(); y!=datawords.end(); y++){
                      exists = false;
                        if((*x)==(*y)){
                        exists = true;
                        auto q = x;
                        auto r = y;
                        for(int i = 0; i < 4 ; i++){
                          q++;
                          r++;
                          if(q==checkwords.end()) {exists = false;
                            break;
                          }
                          else if(r==datawords.end()) {exists = false;
                            break;
                          }
                          else if((*q)!=(*r)) {exists = false;
                            break;}
                        }
                      }
                        if(exists){
                          int count = m[check];
                          count++;
                          m[check] = count;
                        }
                      }
                  }
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

      } //end while loop

      // for(auto it = m.begin(); it!=m.end(); it++){
      //   cout<<it->first<<" "<<it->second<<endl;
      // }
      int xyz = 0;
      while(!m.empty()&&xyz<20){
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
      cout<<"["<<currmax->second<<", '"<<currmax->first<<"']"<<endl;
      m.erase(currmax);
      xyz++;
      }


          return 0;
      }
