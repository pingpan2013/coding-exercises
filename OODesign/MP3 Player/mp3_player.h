/*
 * =====================================================================================
 *
 *       Filename:  mp3_player.h
 *
 *    Description:  ood for a mp3 player
 *
 *        Created:  03/08/2015 03:26:43
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Player{
    public:
        Player(){}
        ~Player() { clear();}

        // basic operations
        bool add_song(Song &song);
        bool remove_song(Song &song);
        void clear();

        bool play_song();
        bool Pause();
        bool Stop();
        
        bool set_volume(int volume);
        int get_volume();

        // access private members
        void get_playlist();
        void set_playlist(Playlist &_plist);

    private:
        Playlist p;
        int volume;
        bool ready;
};


class Playlist{
    public:
        Playlist(vector<Song> &plist) : playlist(plist){}
        
        Song get_next_song(){
            return Playlist[cur_song_num % Playlist.size()];
        }

        void add_song(Song &song);

    private:
        int cur_song_num = 0;
        vector<Song> playlist;
};


class Song{
    public:
        Song(int _d, string &_name, string &_singer) :
            duration(_d), name(_name), singer(_singer) {}

    private:
        int duration;
        string &name;
        string &singer;
};


class User{  
};
