#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace mozhegova
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t p1, point_t p2, point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t pCent_;
    point_t pVert_;
    point_t pHori_;
  };
}

#endif
