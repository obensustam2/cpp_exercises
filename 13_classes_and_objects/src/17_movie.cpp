#include "17_movie.h"

std::string Movie::get_name(){
    return name;
}

std::string Movie::get_rating(){
    return rating;
}

int Movie::get_watched(){
    return watched;
}

void Movie::increase_watch(){
    watched +=1;
    std::cout << name << " watched increased to " << watched << std::endl;
}

Movie::Movie(std::string default_name, std::string default_rating, int default_watched) : 
    name(default_name), rating(default_rating), watched(default_watched){
}