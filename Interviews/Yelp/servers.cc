/*
 * =====================================================================================
 *
 *       Filename:  servers.cc
 *
 *    Description:  设计一个数据结构，对服务器Server类支持以下操作：

                    加入一个Server。
                    删除一个Server。
                    随机选择一个Server。
                    以上所有操作的时间复杂度都必须为O(1) 
 *
 *        Created:  02/16/2015 23:14:16
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Servers{
public:
    void add(Server &server){
        servers.push_back(server);
        map[Server] = servers.size() - 1;
    }

    void remove(Server &server){
        int index = map[server];
        map.erase(server);
        
        // move the last server to the removed position, update the index 
        servers[index] = servers.back();
        map[servers.back()] = index;
        servers.pop_back();
    }

    Server randomSelect(){
        // gurantee it's not empty
        if(!servers.empty()){
            return servers[rand()%servers.size()];
        }
    }

private:
    vector<Server> servers;          // store the servers
    unordered_map<Server, int> map;  // map Server to its index in the array
    
    // thought:
    // can also use list instead of vector, in this way, hashmap maps Server to iterator of the list,
    // then there is no need to move around the vector when removing a Server
};

