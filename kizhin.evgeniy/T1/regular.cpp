#include "regular.hpp"
#include <cassert>
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "point_utils.hpp"

kizhin::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3)
{
  if (!isRightTriangle(p1, p2, p3)) {
    throw std::invalid_argument("Invalid Triangle Points");
  }
  center_ = p1;
  const double r1 = std::sqrt(kizhin::computeDistanceSqr(p1, p2));
  const double r2 = std::sqrt(kizhin::computeDistanceSqr(p1, p3));
  outerRadius_ = std::max(r1, r2);
  innerRadius_ = std::min(r1, r2);
  computeFrameRect();
}

double kizhin::Regular::getArea() const
{
  return 10;
}

kizhin::rectangle_t kizhin::Regular::getFrameRect() const
{
  return frameRect_;
}

void kizhin::Regular::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void kizhin::Regular::move(const point_t& newPos)
{
  const double dx = newPos.x - center_.x;
  const double dy = newPos.y - center_.y;
  move(dx, dy);
}

void kizhin::Regular::scale(double scaleFactor)
{
  assert(scaleFactor > 0);
  // TODO
  outerRadius_ *= scaleFactor;
  innerRadius_ *= scaleFactor;
  computeFrameRect();
}

void kizhin::Regular::computeFrameRect()
{
  frameRect_ = { 2 * outerRadius_, 2 * outerRadius_, center_ };
}

