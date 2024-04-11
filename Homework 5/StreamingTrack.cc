// Copyright 2024 Aarsh Patel
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "StreamingTrack.h"

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(const string& title,
    const string& primary_artist,
    const int duration, const int num_artists,
    const string& primary_genre, const int num_streams) :
    SongRecording(title, primary_artist, duration, num_artists),
    num_streams_(num_streams) {
  genres_ = new string[1];
  genres_[0] = primary_genre;
  num_genres_ = 1;
}

StreamingTrack::StreamingTrack(const StreamingTrack& other_song) :
  SongRecording(other_song) {
  num_streams_ = other_song.num_streams_;
  genres_ = new string[other_song.num_genres_];
  for (int i = 0; i < other_song.num_genres_; i++) {
    genres_[i] = other_song.genres_[i];
  }
  num_genres_ = other_song.num_genres_;
}

StreamingTrack& StreamingTrack::operator=(const StreamingTrack& other_song) {
  if (this == &other_song) {
    return *this;
  }
  SongRecording::operator=(other_song);
  num_streams_ = other_song.num_streams_;
  delete[] genres_;
  genres_ = new string[other_song.num_genres_];
  for (int i = 0; i < other_song.num_genres_; i++) {
    genres_[i] = other_song.genres_[i];
  }
  num_genres_ = other_song.num_genres_;
  return *this;
}

StreamingTrack::StreamingTrack(const SongRecording& song,
  const string& primary_genre, const int num_streams) : SongRecording(song) {
  num_streams_ = num_streams;
  genres_ = new string[1];
  genres_[0] = primary_genre;
  num_genres_ = 1;
}

StreamingTrack::~StreamingTrack() {
  delete[] genres_;
}

void StreamingTrack::SetStreams(const int num_streams) {
  if (num_streams > 0) {
    num_streams_ = num_streams;
  }
}

void StreamingTrack::AddStreams(const int num_streams) {
  if (num_streams >= 0) {
    num_streams_ += num_streams;
  }
}

string StreamingTrack::GetGenre(int index) const {
  if (index > 0 && index <= num_genres_) {
    return genres_[index - 1];
  }
  return "out of bounds";
}

bool StreamingTrack::IsGenre(const string& genre) const {
  for (int i = 0; i < num_genres_; i++) {
    if (genres_[i] == genre) {
      return true;
    }
  }
  return false;
}

void StreamingTrack::AddGenre(const string& genre) {
  if (IsGenre(genre)) {
    return;
  }
  string* temp = new string[num_genres_ + 1];
  for (int i = 0; i < num_genres_; i++) {
    temp[i] = genres_[i];
  }
  temp[num_genres_] = genre;
  delete[] genres_;
  genres_ = temp;
  num_genres_++;
}

void StreamingTrack::RemoveGenre(const string& genre) {
  if (!IsGenre(genre)) {
    return;
  }
  string* temp = new string[num_genres_ - 1];
  int j = 0;
  for (int i = 0; i < num_genres_; i++) {
    if (genres_[i] != genre) {
      temp[j] = genres_[i];
      j++;
    }
  }
  delete[] genres_;
  genres_ = temp;
  num_genres_--;
}

}  // namespace csce240_programming_assignment_5

