/*
 * =====================================================================================
 *
 *       Filename:  classify_log_file.cc
 *
 *    Description:  classify log file 
 *
 *        Created:  02/25/2015 20:50:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <boost/algorithm/string.hpp>
#include <cstdlib>
#include <unordered_map>

using namespace std;

void printSessionInfo(queue<pair<int, int> > &session){
     // output session info
     int sess_size = session.size();
     int first_user_id = session.front().first;
     int last_user_id = session.back().first;

     cout << "Seesion # of log: " << sess_size << ", "
          << "first user id: " << first_user_id << ", "
          << "last user id: " << last_user_id << endl;
     cout << endl; 
}

/* classify log file by timestamp, 200 is the range */
void printLogInfo_1(){
    ifstream logfile("log.txt");
    if(!logfile){
        cerr << "Error opening the log file!" << endl;
        return;
    }
    
    string line;
    vector<string> log_info;
    queue<pair<int, int> > session;  // store <user_id, timestamp> info

    while(getline(logfile, line)){
        boost::split(log_info, line, boost::is_any_of(" \t"));
        int user_id = atoi(log_info[0].c_str());
        int timestamp = atoi(log_info[1].c_str());

        if(session.empty()){
            session.push(make_pair(user_id, timestamp));
        }
        else{
            auto top = session.front();
            if(timestamp - top.second >= 200){
                // output session info
                printSessionInfo(session);

                // clear the quque to save memory
                session = {};
            }
            
            // push the current log info into queue
            session.push(make_pair(user_id, timestamp));
        }
    }
    
    // output the last session info
    printSessionInfo(session);
    
    session = {};
    logfile.close();
}

/* classify log file by key and timestamp */
void printLogInfo_2(){
    ifstream logfile("log.txt");
    if(!logfile){
        cerr << "Error opening the log file!" << endl;
        return;
    }
    
    string line;
    vector<string> log_info;
    unordered_map<int, queue<pair<int, int> > > keyToSession;  // key to session info

    while(getline(logfile, line)){
        boost::split(log_info, line, boost::is_any_of(" \t"));
        int user_id = atoi(log_info[0].c_str());
        int timestamp = atoi(log_info[1].c_str());
        int key = atoi(log_info[2].c_str());

        if(keyToSession.find(key) == keyToSession.end()){
            keyToSession[key].push(make_pair(user_id, timestamp));
        }
        else{
            auto sess_queue = keyToSession[key];
            if(timestamp - sess_queue.front().second >= 200){
                cout << "Key: " << key << endl;
                printSessionInfo(sess_queue);
                keyToSession[key] = {};
            }
            
            keyToSession[key].push(make_pair(user_id, timestamp));
        }
    }

    // output the rest of session
    for(auto itr : keyToSession){
        cout << " ---Key: " << itr.first << endl;
        printSessionInfo(itr.second);
        keyToSession[itr.first] = {};
    }
}

int main(){
    //printLogInfo_1();
    
    printLogInfo_2();

    return 0;
}
