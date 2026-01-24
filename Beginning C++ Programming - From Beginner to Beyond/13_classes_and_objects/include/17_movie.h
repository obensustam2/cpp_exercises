#ifndef _MOVIE_
#define _MOVIE_

#include <iostream>
#include <string>

class Movie{
private: 
    std::string name;
    std::string rating;
    int watched;

public: 
    std::string get_name();
    std::string get_rating();
    int get_watched();
    void increase_watch();
    
    Movie(std::string default_name = "book", std::string default_rating = "PG", int default_watched = 1);
};

#endif // _MOVIE_