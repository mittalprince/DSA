#include<bits/stdc++.h>
using namespace std;

int main(){
    long long test_Case;
    cin>>test_Case;
    while(test_Case--){
        long long No_of_elements, K_segemnts;
        cin>>No_of_elements>>K_segemnts;

        long long tp = 1;
        long long ct = 1;
        long long firsy_element;
        cin>>firsy_element;

        long long s = firsy_element;
        long long N = No_of_elements-1;

        vector<long long> a;

        while(N--){
            long long next_num;
            cin>>next_num;

            if(next_num >= 0){
                long long l = K_segemnts - tp;

                if(l == 0){
                    s += next_num;
                    ct++;
                    continue;
                }
                else if(l == 1){
                    tp++;
                    a.push_back(ct);
                    ct = 1;
                    s = next_num;
                }
                else{
                    if(s >= 0){
                        a.push_back(ct);
                        tp++;
                        ct = 1;
                        s = next_num;
                    }
                    else{
                        s += next_num;
                        ct++;
                    }
                }
            }
            else{
                if(s >= 0){
                    if(s+next_num >= 0){
                        s+= next_num;
                        ct++;
                    }
                    else{
                        long long remain_p = K_segemnts - tp;
                        if(remain_p == 0){
                            ct++;
                            s += next_num;
                        }
                        else{
                            a.push_back(ct);
                            ct = 1;
                            s = next_num;
                            tp++;
                        }
                    }
                }
                else{
                    ct++;
                    s += next_num;
                }
            }
        }


        if(K_segemnts-tp == 0){
            if(s >= 0){
                cout<<"YES"<<endl;
                a.push_back(ct);
                for(auto i: a){
                    cout<<i<<" ";
                }
                cout<<endl;
            }   
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
