#include "gmesh2.h"

#include <iostream>

GMesh2::GMesh2(const Mesh2 &m, const RGBA<unsigned char> &dColor):
    Mesh2{m},
    _dColor{dColor}
{
}

void GMesh2::draw(Window &w)
{
    Graphics::draw(w);
    RGBA<unsigned char> rgba;
    for (size_t i = 0; i < es.size(); i++)
    {
        ssize_t ib = es[i].first;
        ssize_t ie = es[i].second;
        rgba = eColor(i);
        w.drawLine(getVertex(ib),getVertex(ie), rgba);
    }
}

void GMesh2::draw(Window &w, const Matrix<double> &t)
{
    Graphics::draw(w);
    RGBA<unsigned char> rgba;
    for (size_t i = 0; i < es.size(); i++)
    {
        ssize_t ib = es[i].first;
        ssize_t ie = es[i].second;
        rgba = eColor(i);
        Vector3<double> b = t * getVertex(ib);
        Vector3<double> e = t * getVertex(ie);
        w.drawLine(b, e, rgba);
    }
}

RGBA<unsigned char> GMesh2::dColor()
{
    return _dColor;
}

void GMesh2::dColor(const RGBA<unsigned char> &rgba)
{
    _dColor = rgba;
}

RGBA<unsigned char> GMesh2::eColor(size_t e)
{
    if (esColors.count(e) > 0 )
    {
        return esColors[e];
    }
    else
        return _dColor;
}

void GMesh2::eColor(size_t e, const RGBA<unsigned char> &rgba)
{
    esColors[e] = rgba;
}

