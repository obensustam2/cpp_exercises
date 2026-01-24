#ifndef _MOVIES_
#define _MOVIES_

#include "17_movie.h"
#include <vector>

class Movies{
private:
    std::vector<Movie> movies;
    
public:
    void display();
    void add_new_movie(Movie);
    bool contains(std::string);
    void increase_watched(std::string);
};

#endif // _MOVIES_