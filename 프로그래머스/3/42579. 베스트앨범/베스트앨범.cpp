#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Song {
    int id;
    string genre;
    int play;
    Song(int _id, string _genre, int _play) : id(_id), genre(_genre), play(_play) {}
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> gp;
    map<string, vector<Song>> gs;
    for (int i = 0; i < genres.size(); i++) {
        gp[genres[i]] += plays[i];
        gs[genres[i]].emplace_back(i, genres[i], plays[i]);
    }
    
    vector<string> uniGenre;
    for (const auto &kvp : gp) uniGenre.push_back(kvp.first);
    sort(uniGenre.begin(), uniGenre.end(), [&](const string &a, const string &b){
        return gp[a] > gp[b];
    });
    
    
    
    for (string &g : uniGenre) {
        sort(gs[g].begin(), gs[g].end(), [](const Song &a, const Song &b) {
            if (a.play != b.play) return a.play > b.play;
            return a.id < b.id;
        });
        for (int i = 0; i < 2 && i < gs[g].size(); i++) {
            answer.push_back(gs[g][i].id);
        }
    }
    return answer;
}