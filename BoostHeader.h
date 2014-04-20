
#ifndef __BOOSTHEADER_H__
#define __BOOSTHEADER_H__

#include <boost/polygon/interval_concept.hpp>
#include <boost/polygon/polygon.hpp>
#include <boost/polygon/polygon_90_data.hpp>
#include <boost/polygon/polygon_90_set_data.hpp>

#include <vector>

namespace gtl = boost::polygon;
using namespace boost::polygon::operators;

typedef gtl::point_data<int> Point;
typedef gtl::polygon_data<int> Polygon;
//typedef gtl::polygon_traits<Polygon>::point_type Point;
typedef gtl::polygon_90_data<int> Polygon90;
typedef std::vector<Polygon90> Poly90Set;


#endif
