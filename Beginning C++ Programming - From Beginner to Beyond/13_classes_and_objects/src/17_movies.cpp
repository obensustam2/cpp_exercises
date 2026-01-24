#include "17_movies.h"


void Movies::display(){
    if(movies.size() == 0){
        std::cout << "Sorry, no movies to display" << std::endl;
        return;
    }

    std::cout << "\n================================" << std::endl;
    
    // for(int i=0; i<movies.size(); i++){
    //     std::cout << movies.at(i).get_name() << ", " << movies.at(i).get_rating() << ", " << movies.at(i).get_watched() << std::endl;
    // }

    for(Movie movie_ : movies){
        std::cout << movie_.get_name() << ", " << movie_.get_rating() << ", " << movie_.get_watched() << std::endl;
    }
    
    std::cout << "================================\n" << std::endl;
}


void Movies::add_new_movie(Movie new_movie){
    movies.emplace_back(new_movie);
    std::cout << new_movie.get_name() << " is added." << std::endl;
}


bool Movies::contains(std::string movie_name){
    for(Movie movie_ : movies){
        if (movie_.get_name() == movie_name){
            return true;
        }
    }
    return false;
}


void Movies::increase_watched(std::string movie_name){
    for(Movie &movie_ : movies){
        if(movie_.get_name() == movie_name){
            movie_.increase_watch();
        }
    }
}