#include <iostream>
#include <cpr/cpr.h>
#include <ncurses.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  initscr();
  cpr::Response r = cpr::Get(cpr::Url{"http://localhost:8080/api/happy-hours/now"});

  printw("Status Code: %ld\n", r.status_code);

  printw("Headers:\n");
  for (const auto& header : r.header) {
      printw("  %s: %s\n" ,header.first.c_str(), header.second.c_str());
  }
  printw("Body:\n");

  json data = json::parse(r.text);
  std::string formatted_body_str = data.dump(4);

  printw("%s\n", formatted_body_str.c_str());

  refresh();

  getch();

  endwin();

  return 0;
}
