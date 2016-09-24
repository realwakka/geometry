#ifndef REALWAKKA_GEOMETRY_POINT_H_
#define REALWAKKA_GEOMETRY_POINT_H_

#include <algorithm>

#include "geometry/type.h"

namespace geometry
{

template<dim D>
class BasicPoint
{
 public:
  BasicPoint(value_type* data);
  BasicPoint(const BasicPoint& point);
  value_type get(dim d) const { return data[d]; }

 private:
  value_type data_[D];
};

template<dim D>
BasicPoint(value_type* data)
{
  std::copy(data, data + D * sizeof(value_type), data_ );
}


template<dim D>
BasicPoint::BasicPoint(const BasicPoint& point)
{
  std::copy(point.data_, point.data_ + D * sizeof(value_type), data_ );
}

typedef Point BasicPoint<2>;

}

#endif
