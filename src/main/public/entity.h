#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <algorithm>

#if defined(DLL_EXPORT)
#  define DECLSPEC __declspec(dllexport)
#else
#  define DECLSPEC
#endif  // defined(DLL_EXPORT)

class DECLSPEC Entity {
  public:
    explicit Entity(const std::string& name) : name_(name) {};
    Entity() : name_("World") {};
    void Greet();
    int GetNameLength();
  private:
    std::string name_;
};

#endif  // GREETER_H_