#include <iostream>
#include "profile.hpp"

Profile::Profile(std::string name_,
                 int age_,
                 std::string city_,
                 std::string pronouns_,
                 std::string country_)
    : name(name_), age(age_), city(city_), country(country_), pronouns(pronouns_) {
    age = age_ > 18 ? age_ : 0;
}

std::string Profile::view_profile(void) {
    std::string ret;
    ret += "Name: " + name + "\n";
    ret += "Age: " + std::to_string(age) + "\n";
    ret += "City: " + city + "\n";
    ret += "Pronouns: " + pronouns + "\n";
    ret += "Country: " + country + "\n";
    ret += "Hobbies: \n";
    for(auto hobby : hobbies) {
        ret += "+ " + hobby + "\n";
    }
    return ret;
}

void Profile::add_hobby(std::string hobby) {
    hobbies.push_back(hobby);
}
