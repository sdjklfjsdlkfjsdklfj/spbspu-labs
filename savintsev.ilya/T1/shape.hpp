#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace savintsev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double x, double y) = 0;
    void scale(double k);
  private:
    virtual void doScale(double k) = 0;
  };
}
#endif
