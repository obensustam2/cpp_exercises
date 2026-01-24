
#include "17_movies.h"


void add_movie(Movies &movies_, std::string movie_name, std::string movie_rating, int watched_counter){
    if(movies_.contains(movie_name)){
        std::cout << movie_name << " already exists" << std::endl;
        return;
    }

    Movie new_movie(movie_name, movie_rating, watched_counter);
    movies_.add_new_movie(new_movie);
}

void increment_watched(Movies &movies_, std::string movie_name){
    if(movies_.contains(movie_name) == false){
        std::cout << movie_name << " movie doesn't exist\n" << std::endl;
        return;
    }

    movies_.increase_watched(movie_name);
}


int main(){

    Movies my_movies;
    
    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);
    
    my_movies.display();
    
    add_movie(my_movies, "Cinderella", "PG", 7);
    add_movie(my_movies, "Ice Age", "PG", 12);

    my_movies.display();

    increment_watched(my_movies, "Big");
    increment_watched(my_movies, "Ice Age");

    my_movies.display();

    increment_watched(my_movies, "XXX");

    return 0;
}