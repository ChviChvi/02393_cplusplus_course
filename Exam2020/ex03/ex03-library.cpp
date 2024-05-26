#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    // Iterate over the list of song titles stored in the 'songs' vector
    for (string title : songs) {
        // Retrieve the Info structure corresponding to the current song title
        Info songInfo = songsInfo[title];
        // Print the song information in the specified format
        cout << "title=" << title
             << "; url=" << songInfo.url
             << "; score=" << songInfo.score
             << endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    // Check if the song title is already in the database
    if (songsInfo.find(title) != songsInfo.end()) {
        return false; // The song title is already present
    }
    // Check if the score is greater than 10
    if (score > 10) {
        return false; // Invalid score
    }
    // Add the song title to the 'songs' vector
    songs.push_back(title);
    // Add the song information to the 'songsInfo' map
    songsInfo[title] = {url, score};
    return true; // Song successfully added
}

// Task 3(c).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    // Determine the score range based on the howGood argument
    int minScore = -1, maxScore = -1;
    if (howGood == "abysmal") {
        minScore = 0; maxScore = 2;
    } else if (howGood == "lousy") {
        minScore = 3; maxScore = 4;
    } else if (howGood == "meh") {
        minScore = 5; maxScore = 6;
    } else if (howGood == "cool") {
        minScore = 7; maxScore = 8;
    } else if (howGood == "OMG") {
        minScore = 9; maxScore = 10;
    } else {
        return; // Invalid howGood value
    }

    // Iterate over the list of song titles
    for (string title : songs) {
        // Retrieve the song information
        Info songInfo = songsInfo[title];
        // Check if the song's score falls within the specified range
        if (songInfo.score >= minScore && songInfo.score <= maxScore) {
            // Print the song information in the specified format
            cout << "title=" << title
                 << "; url=" << songInfo.url
                 << "; score=" << songInfo.score
                 << endl;
        }
    }
}
