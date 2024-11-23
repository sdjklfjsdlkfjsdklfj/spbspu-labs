#ifndef STRING_MANAGEMENT_HPP
#define STRING_MANAGEMENT_HPP

namespace kizhin {
  namespace detail {
    void setString(const char*);
    const char* position();
    void incrementPosition();
    void releaseString();
  }
}

#endif
