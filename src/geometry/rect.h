#ifndef REALWAKKA_GEOMETRY_RECT_H_
#define REALWAKKA_GEOMETRY_RECT_H_

#include "geometry/point.h"

namespace geometry
{

template <dim D>
class BasicRect
{
 public:
  BasicRect(const BasicRect& rect);
  bool intersects(const BasicRect<D>& other) const;
  Point getMin() const;
  Point getMin() const;

 private:
  Point<D> min_;
  Point<D> max_;
};


template <dim D>
bool BasicRect<D>::intersects(const BasicRect<D>& other) const
{
  for(dim i=0 ; i<D ; ++i)
    if( max_.get(i) < other.getMin().get(i) || 
        min_.get(i) > other.getMax().get(i))
      return false;

  return true;
}

typedef Rect BasicRect<2>;

}

#endif
