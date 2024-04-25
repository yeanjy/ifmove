/**
 * \author Éder Augusto Penharbel (oederaugusto)
 * \date September 17, 2023
 * \version September 17, 2023
 * \brief Functions to build meshes
 * \param c (Vector3) top left corner 
 * \param l (double) side lenght's of square
 **/
#ifndef IFMOVE_MESH_UTILS_H
#define IFMOVE_MESH_UTILS_H

#include "mesh2.h"
#include <cmath>
#include <iostream>
using namespace std;

#define MESH_DEFAULT_CIRCLE_N 30

/**
 * \author Éder Augusto Penharbel (oederaugusto)
 * \date September 17, 2023
 * \version September 17, 2023
 * \brief function for build a circle mesh2
 * \param c (Vector3) circle's center
 * \param l (double) radius of circle
 * \param n (ssize_t) number of points in this mesh
 **/
Mesh2 buildCircleMesh(const Vector3<double> &c, double r = 1.0, 
    ssize_t n = MESH_DEFAULT_CIRCLE_N);

/**
 * \author Éder Augusto Penharbel (oederaugusto)
 * \date September 17, 2023
 * \version September 17, 2023
 * \brief function for build a square mesh2
 * \param c (Vector3) top left corner 
 * \param l (double) side lenght's of square
 **/
Mesh2 buildSquareMesh(const Vector3<double> &r, double l = 1.0);

/**
 * \author Éder Augusto Penharbel (oederaugusto)
 * \date September 20, 2023
 * \version September 20, 2023
 * \brief function for build a triangle mesh2
 * \param p1 (Vector2) first triangle point
 * \param p2 (Vector3) second triangle point
 * \param p3 (Vector3) third triangle point
 **/
Mesh2 buildTriangleMesh(const Vector3<double> &p1,
            const Vector3<double> &p2,
            const Vector3<double> &p3);

#endif
