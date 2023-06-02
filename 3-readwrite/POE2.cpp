#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> names;

    names.insert("Segbefia");
    names.insert("Ryan Gosling (literally me)");
    names.insert("Patrick Bateman");

    for(const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    names.erase("Patrick Bateman");

    for(std::string name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    names.insert("Ryan Gosling (literally me)");

    for(std::string const& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    // names.insert(69420);

    std::cout << names.size() << std::endl;
}