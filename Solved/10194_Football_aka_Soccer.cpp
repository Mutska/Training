#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std; 


struct TeamFotball{
    string name;
    int  game_plays,wins,ties,losses,goals_scored,goals_against;

    TeamFotball(string name1){
        name=name1; 
        game_plays=0; 
        wins=0; 
        ties=0; 
        losses=0; 
        goals_scored=0;
        goals_against=0; 
    }
    
};

bool str_cmp (const string& s0, const string& s1) {
    string str0(s0.length(),' ');
    string str1(s1.length(),' ');
    transform(s0.begin(), s0.end(), str0.begin(),::tolower);
    transform(s1.begin(), s1.end(), str1.begin(),::tolower);
    if  (!str0.empty() and !str1.empty() and str0.front()==str1.front()) {
            // do a standard lexicographic sort if the first character is the same
        return s0 < s1;
    }
    else {
            // otherwise, do a case-insensitive lexicographic sort using the lowercased strings
        return str0 < str1;
    }
}

bool TF_cmp(const TeamFotball &a,const TeamFotball &b){
    if(3*a.wins+a.ties != 3*b.wins +b.ties ){
        return 3*a.wins+a.ties >3*b.wins +b.ties; 
    }
    else if(a.wins != b.wins){
        return a.wins >b.wins; 
    }
    else if(a.goals_scored-a.goals_against != b.goals_scored-b.goals_against){
        return  a.goals_scored-a.goals_against > b.goals_scored-b.goals_against;
    }
    else if(a.goals_scored!=b.goals_scored){
        return a.goals_scored >b.goals_scored;
    }
    else if(a.game_plays != b.game_plays){
        return  a.game_plays < b.game_plays;
    }
    else {
        return str_cmp(a.name, b.name);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, T, G;  
    string Tournament,aux,line; 
    int cont; 

    cin>>N; 
    cin.ignore();
    while(N--){
        getline(cin,Tournament);
        cont=0; 
        vector<TeamFotball> Torneo; 
        map<string,int> NamesIndex; 
        cin>> T; 
        cin.ignore();
        while(T--){
            getline(cin,aux); 
            NamesIndex[aux]=cont++;
            Torneo.push_back(TeamFotball(aux)); 
        }
        cin>>G; 
        cin.ignore();
        while(G--){
            getline(cin,line);
            int first   =  line.find_first_of('#');
            int last    =  line.find_last_of('#');
            int middle  =  line.find_first_of('@');
            string a    =  line.substr(0, first);
            string b    =  line.substr(last + 1);
            string sA   =  line.substr(first + 1, middle - first - 1);
            string sB   =  line.substr(middle + 1, last - middle - 1);
            int pointsA =  stoi(sA);
            int pointsB =  stoi(sB);
            Torneo[NamesIndex[a]].game_plays++;
            Torneo[NamesIndex[a]].goals_scored+=pointsA;
            Torneo[NamesIndex[a]].goals_against+=pointsB;
            Torneo[NamesIndex[b]].game_plays++;
            Torneo[NamesIndex[b]].goals_scored+=pointsB;
            Torneo[NamesIndex[b]].goals_against+=pointsA;

            if(sA>sB){
                Torneo[NamesIndex[a]].wins++; 
                Torneo[NamesIndex[b]].losses++; 
            }
            else if(sA<sB){
                Torneo[NamesIndex[b]].wins++; 
                Torneo[NamesIndex[a]].losses++;
            }
            else{
                Torneo[NamesIndex[a]].ties++; 
                Torneo[NamesIndex[b]].ties++;
            }
        }

        sort(Torneo.begin(),Torneo.end(),TF_cmp);
        cout<<Tournament<<"\n"; 
        for(int i=0;i<Torneo.size();i++){
            int aux=i; 
            cout<<++aux<<") "; 
            cout<<Torneo[i].name<<" ";
            cout<<3*Torneo[i].wins +Torneo[i].ties<<"p, ";
            cout<<Torneo[i].game_plays<<"g "; 
            cout<<"("<<Torneo[i].wins<<"-"<<Torneo[i].ties<<"-"<<Torneo[i].losses<<"), ";
            cout<<Torneo[i].goals_scored-Torneo[i].goals_against<<"gd "; 
            cout<<"("<<Torneo[i].goals_scored<<"-"<<Torneo[i].goals_against<<")\n";
        }
        if(N) cout<<"\n"; 
    }
}