//
//  Album.h
//  TimeSpan
//
//  Created by Artem Kovtunenko on 10/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __Album__
#define __Album__

#include <stdio.h>

class Album
{
public:
    
    Album();
    Album(string albumName);
    Album(string albumName, int year);
    string getAlbumName()const;
    string getAlbumSong(int trackNumber)const;
    string getCoverName()const;
    int getTrackNumber(const string songName)const;
    int getTotalSongs()const;
    double getSongDuration(const string songName)const;
    int getAlbumYear()const;
    
    void setAlbumName(string albumName);
    void setAlbumYear(int year);
    
    void addSong(const string artistName, const string songName);
    void removeSong(const string songName,const string artistName);
    void shuffle();
    
    bool hasMovieSoundtrack()const;
    bool hasLyrics(const string songName)const;
    void sortByName()const;
    void sortByDuration()const;
    
    ~Album();
};

#endif /* defined(__TimeSpan__Album__) */
