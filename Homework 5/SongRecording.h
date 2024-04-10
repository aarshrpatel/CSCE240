// Copyright 2024 Aarsh Patel
#ifndef SONGRECORDING_H_
#define SONGRECORDING_H_

#include <iostream>
#include <string>
using std::string;

namespace csce240_programming_assignment_5 {

 class SongRecording {
  private:
   string title_;
   string * artists_;
   int num_artists_;
   int duration_;
 
  public:
   explicit SongRecording(const string& title = "untitled",
    const string& primary_artist = "unknown",
    int duration = 0, int num_artists = 1);
   
   // Copy Constructor
   SongRecording(const SongRecording& other_song);
 
   // Overloaded Assignment Operator
   SongRecording& operator=(const SongRecording& other_song);
 
   // Destructor
   ~SongRecording();
   
   // Getters
   string GetTitle() const{return title_;}
   int GetNumArtists() const{return num_artists_;}
   string GetArtist(const int index = 1) const;
   int GetTrackLength() const{return duration_ < 0 ? 0 : duration_;}
 
   // Setters
   void SetTitle(const string title);
   void SetNumArtists(const int num_artists);
   void SetArtist(const string& artist_name, int index = 1);
   void SetTrackLength(const int duration);
 };
} // namespace cscs240_programming_assignment_5

#endif  // SONGRECORDING_H_