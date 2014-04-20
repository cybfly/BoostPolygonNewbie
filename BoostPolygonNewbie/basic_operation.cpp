
#include "basic_operation.h"

using std::vector;
using std::cout;
using std::endl;

/// create polygon90 data.
void createPolygon90()
{
	// create polygon with vector<Point>
	vector<Point> posGroup;
	posGroup.push_back(Point(0, 0));
	posGroup.push_back(Point(2, 0));
	posGroup.push_back(Point(2, 2));
	posGroup.push_back(Point(0, 2));

	Polygon90 poly;
	poly.set(posGroup.begin(), posGroup.end());
	cout << "Area of poly: " << gtl::area(poly) << endl;

	// create polygon with Point array
	Point pts[] = {
		gtl::construct<Point>(2, 2),//(1, 2) poly | poly1--》size() == 1
		gtl::construct<Point>(2, 4),
		gtl::construct<Point>(4, 4),
		gtl::construct<Point>(4, 2)
	};
	Polygon90 poly1;
	gtl::set_points(poly1, pts, pts + 4);
	cout << "Area of poly: " << gtl::area(poly1) << endl;

	vector<Point> getPosGroup;
	travelPosOfPolygon90(getPosGroup, poly);
}

/// use poly.begin() and poly.end() to visit the points of polygon.
void travelPosOfPolygon90(vector<Point> &getPosGroup, const Polygon90 &poly)
{
	Polygon90::iterator_type it = poly.begin();

	cout << "Polygon: ";
	while (it != poly.end())
	{
		getPosGroup.push_back(*it);
		cout << (*it).x() << ":" << (*it).y() << " ";
		++it;
	}
	cout << endl;
}

/// do polygon or, "using namespace boost::polygon::operators;" is needed. 
void polygonOR()
{
	vector<Point> posGroup;
	posGroup.push_back(Point(0, 0));
	posGroup.push_back(Point(2, 0));
	posGroup.push_back(Point(2, 2));
	posGroup.push_back(Point(0, 2));

	Polygon90 poly;
	poly.set(posGroup.begin(), posGroup.end());
	cout << "Area of poly: " << gtl::area(poly) << endl;

	Polygon90 poly1;
	Point pts[] = {
		gtl::construct<Point>(2, 2),
		gtl::construct<Point>(2, 4),
		gtl::construct<Point>(4, 4),
		gtl::construct<Point>(4, 2)
	};
	gtl::set_points(poly1, pts, pts + 4);
	cout << "Area of poly: " << gtl::area(poly1) << endl;

	Polygon90 poly2;
	Point pts1[] = {
		gtl::construct<Point>(1, 2),
		gtl::construct<Point>(2, 4),
		gtl::construct<Point>(4, 4),
		gtl::construct<Point>(4, 2)
	};
	gtl::set_points(poly2, pts1, pts1 + 4);
	cout << "Area of poly: " << gtl::area(poly2) << endl;

	Poly90Set polySet;
	// 点接壤-->取并集size()为2
	// 多点接壤-->取并集size()为1
	assign(polySet, poly | poly1);
	cout << "Area of poly | poly1: " << gtl::area(polySet) << " size:" << polySet.size() << endl;

	Poly90Set polySet1;
	polySet1 += (poly | poly2);
	cout << "Area of poly | poly1: " << gtl::area(polySet1) << " size:" << polySet1.size() << endl;
}
