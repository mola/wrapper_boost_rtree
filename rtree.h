#ifndef RTREE_H
#define RTREE_H

#include <QObject>
#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>

namespace bg  = boost::geometry;
namespace bgi = boost::geometry::index;

typedef bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>  point_t;
typedef bg::model::box<point_t>                                                box_t;
// typedef std::pair<box_t, uint64_t>                   value_t;
typedef std::pair<point_t, uint64_t> value_t;

typedef bgi::rtree<value_t, bgi::quadratic<8, 4>> rtree_t;

class RTree: public QObject
{
    Q_OBJECT

public:
    explicit RTree(QObject *parent = nullptr);

    void            insert(value_t t);

    QList<value_t>  query(box_t search_box);

    QList<value_t>  nearset(point_t center);

signals:

private:
    rtree_t *mTree = nullptr;
};

#endif // RTREE_H
