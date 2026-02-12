#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  cpr::Response r = cpr::Get(cpr::Url{"http://localhost:8080/api/happy-hours/now"});

  // Access the response details
  std::cout << "Status Code: " << r.status_code << std::endl;
  std::cout << "Headers:" << std::endl;
  for (const auto& header : r.header) {
      std::cout << "  " << header.first << ": " << header.second << std::endl;
  }
  std::cout << "Body:" << std::endl;

  json data = json::parse(r.text);
  std::string formatted_body_str = data.dump(4);

  std::cout << formatted_body_str << std::endl;

  return 0;
}
