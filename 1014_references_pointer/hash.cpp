#include <iostream>
#include <unordered_map>
#include <map>

int main() {
  std::unordered_map<std::string, int> country_codes
                                      {{"India", 91},
                                      {"Italy", 39},
                                      {"Italy", 27}};

  country_codes.insert({"Thailand", 66});
  country_codes.insert({"Peru", 51});
  country_codes.insert({"Peru", 9});	// Duplicate key is not inserted

  country_codes.erase("Thailand");
  country_codes.erase("Italy");

  country_codes["Japan"] = 81;
  country_codes["Turkey"] = 90;

  if (country_codes.count("Belgium")) {
    std::cout << "There is a code for Belgium\n";
  }
  else {
   std::cout << "There isn't a code for Belgium\n";
  }

  std::cout << country_codes["Japan"] << "\n";

  std::cout << country_codes.size() << "\n";

  std::cout << country_codes.empty() << "\n";

  for(auto it: country_codes){
    std::cout << it.first << " " << it.second << "\n";
  }

  return 0;
}