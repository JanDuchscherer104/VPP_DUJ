#include <string>
#include <vector>

class Profile{
    private:
        std::string name;
        int age;
        std::string city;
        std::string pronouns;
        std::string country;
        std::vector<std::string> hobbies;

    public:
        Profile(std::string name_, int age_, std::string city_, std::string country_, std::string pronouns_ = "they/them");
        std::string view_profile(void);
        void add_hobby(std::string hobby);
};