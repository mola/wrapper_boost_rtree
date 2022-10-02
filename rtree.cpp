#include "rtree.h"

RTree::RTree(QObject *parent):
    QObject{parent}
{
    mTree = new rtree_t;
}

void  RTree::insert(value_t t)
{
    mTree->insert(t);
}

QList<value_t>  RTree::query(box_t search_box)
{
    QList<value_t>  r;

    mTree->query(bgi::intersects(search_box), std::back_inserter(r));

    return r;
}

QList<value_t>  RTree::nearset(point_t center)
{
    QList<value_t>  r;

    mTree->query(bgi::nearest(center, 1), std::back_inserter(r));

    return r;
}
