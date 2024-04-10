// Copyright 2024 Aarsh Patel
#ifndef _STREAMINGTRACK_H_
#define _STREAMINGTRACK_H_
#include "SongRecording.h"
#include <string>
using std::string;

namespace csce240_programming_assignment_5 {
 class StreamingTrack : public SongRecording {
  private:
   int num_streams_;
   string* genres_;
   int num_genres_;
 
  public:
   explicit StreamingTrack(const string& title = "untitled",
                           const string& primary_artist = "unknown",
                           int duration = 0, int num_artists = 1,
                           const string& primary_genre = "pop",
                           int num_streams = 0);
   
   // Copy Constructor
   StreamingTrack(const StreamingTrack& other_song);
 
   // Overloaded Assignment Operator
   StreamingTrack& operator=(const StreamingTrack& other_song);
 
   // Constructor
   explicit StreamingTrack(const SongRecording& song,
                           const string& primary_genre = "pop",
                           int num_streams = 0);
   
   // Destructor
   ~StreamingTrack();
 
   // Stream Getters and Setters
   int GetStreams() const { return num_streams_; }
   void SetStreams(const int num_streams);
   void AddStreams(const int num_streams);
   int GetNumGenres() const { return num_genres_; }
   string GetGenre(int index = 1) const;
   bool IsGenre(const string& genre) const;
   void AddGenre(const string& genre);
   void RemoveGenre(const string& genre);
 
 };
}

#endif  // _STREAMINGTRACK_H_