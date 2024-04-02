// Copyright 2024 Aarsh Patel
#include <iostream>
#include <string>
using std::string;
#include "SongRecording.h"


namespace csce240_programming_assignment_5 {

// Default Constructor
SongRecording::SongRecording(const string& title,
 const string& primary_artist, int duration, int num_artists) :
 title_(title), num_artists_(num_artists), duration_(duration) {
  artists_ = new string[num_artists_];
  SetArtist(primary_artist, 0);
}

// Copy Constructor
SongRecording::SongRecording(const SongRecording& other_song) :
 title_(other_song.title_), num_artists_(other_song.num_artists_),
 duration_(other_song.duration_) {
  artists_ = new string[num_artists_];
  for (int i = 0; i < num_artists_; i++) {
    artists_[i] = other_song.artists_[i];
  }

}

// Overloaded Assignment Operator
SongRecording& SongRecording::operator=(const SongRecording& other_song) {
  if (this != &other_song) {
    delete[] artists_;
    title_ = other_song.title_;
    num_artists_ = other_song.num_artists_;
    duration_ = other_song.duration_;
    artists_ = new string[num_artists_];
    for (int i = 0; i < num_artists_; i++) {
      artists_[i] = other_song.artists_[i];
    }
  }
  return *this;
}

// Destructor
SongRecording::~SongRecording() {
  delete[] artists_;
}

// Getters
string SongRecording::GetArtist(int index) const {
  if (index < 1 || index > num_artists_) {
    return "out of bounds";
  }
  return artists_[index];
}

// Setters
void SongRecording::SetTitle(const string title) {
  if (title.length() > 0) {
      title_ = title;
  }
}

void SongRecording::SetNumArtists(const int num_artists) {
  if (num_artists > 0) {
    num_artists_ = num_artists;
  }
  delete[] artists_;
  artists_ = new string[num_artists_];
}

void SongRecording::SetArtist(const string& artist_name, int index) {
  if (index < 0 || index > num_artists_
   || artist_name.length() == 0) {
    return;
  }
  artists_[index] = artist_name;
}

void SongRecording::SetTrackLength(const int duration) {
  if (duration > 0) {
    duration_ = duration;
  }
}

}  // namespace cscs240_programming_assignment_5